// excercise1.c : Defines the entry point for the console application.
//

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include "stdafx.h"



int createEchoProcess(createHidden)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	int createFlags = 0;
	LPTSTR szCmdline = _tcsdup(TEXT("cmd /c echo \"hi\">ex1_executable.txt"));

	if (createHidden) {
		createFlags = CREATE_NO_WINDOW;
	}

	SecureZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);

	SecureZeroMemory(&pi, sizeof(pi));

	if (!CreateProcess(NULL,		           // Module name
		szCmdline,                             // Commandline
		NULL,						           // Process attributes
		NULL,						           // Thread attributes
		FALSE,						           // Does inherit handles from parent process
		createFlags,		                   // Startup flags
		NULL,						           // Environment block pointer
		TEXT("C:\\Users\\User\\Desktop"),      // Process start CWD
		&si,						           // StartupInfo Address(Pointer)
		&pi)) 						           // ProcessInfo Address(Pointer)
	{
		printf("Process creation failed(error:%d).\n", GetLastError());
		Sleep(3000);
		return 1;
	}

	printf("Process created successfully\n");

	WaitForSingleObject(pi.hProcess, INFINITE);

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}

int main()
{
	int createProcessResultCode = createEchoProcess(FALSE);
	return createProcessResultCode;
}
