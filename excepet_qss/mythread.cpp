#include "mythread.h"
#include <Windows.h>

// 执行命令行方式1（匿名管道方式）
int excuteCmdline1(const std::string &cmdline, std::string &response)
{
    HANDLE hReadPipe, hWritePipe;
    SECURITY_ATTRIBUTES sa = {0};
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;
    if (!CreatePipe(&hReadPipe, &hWritePipe, &sa, 0))
    {
        DWORD retError = GetLastError();
        return -1;
    }
    STARTUPINFO si = {0};
    si.cb = sizeof(STARTUPINFO);
    //GetStartupInfo(&si);
    si.hStdError = hWritePipe;
    si.hStdOutput = hWritePipe;
    si.hStdInput = NULL;
    si.wShowWindow = SW_HIDE;
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

    PROCESS_INFORMATION pi = { 0 };
    if (!CreateProcess( NULL, (char *)cmdline.c_str(), NULL, NULL, TRUE, HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi))
    {
        DWORD retError = GetLastError();
        CloseHandle(hReadPipe);
        CloseHandle(hWritePipe);
        return -1;
    }
//	 WaitForSingleObject( pi.hProcess, INFINITE );
    CloseHandle(hWritePipe);  // 不然readfile可能不会返回
/*
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    CloseHandle(hReadPipe);
    return -1;*/

    int nTotalByteRead = 0;
    char szBuffer[4096] = { 0 };
    response = "";
    DWORD dwAvail = 0;
    while (true)
    {
        DWORD dwBytesRead = 0;
        memset(szBuffer, 0, sizeof(szBuffer));
        /*
        if (!PeekNamedPipe(hReadPipe, NULL, NULL, &dwAvail, 0, 0) || dwAvail<=0)//管道是否有数据可读
        {
            break;
        }*/
        if (!ReadFile(hReadPipe, szBuffer, sizeof(szBuffer)-1, &dwBytesRead, NULL))
        {
            break;
        }
        szBuffer[dwBytesRead] = '\0';
        response += szBuffer;
        nTotalByteRead += dwBytesRead;
        Sleep(1);
    }

#ifdef _DEBUG
//	QX_LOGDBG("executeADBShellCmd finished. cmdline=%s, response=%s", cmdline.c_str(), response.c_str());
#endif
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    CloseHandle(hReadPipe);
    return 0;
}


MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

int MyThread::start()
{
    m_bStopThreadFlag = false;
    QThread::start();
    return 0;
}
void MyThread::stop()
{
    m_bStopThreadFlag = true;
    QThread::wait();
    QThread::quit();
}

void MyThread::run()
{
    while (!m_bStopThreadFlag)
    {
        std::string response;
        excuteCmdline1("adb devices", response);
        msleep(1);
    }
}
