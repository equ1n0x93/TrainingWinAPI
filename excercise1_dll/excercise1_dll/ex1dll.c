//ex1dll.c

#include "ex1dll.h"


int createEchoProcess(createHidden)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	int createFlags = 0;
	LPTSTR szCmdline = _tcsdup(TEXT("cmd /c echo hi>ex1_dll.txt"));

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

int createExcerciseProcess()
{
	int createProcessResultCode = createEchoProcess(FALSE);
	return createProcessResultCode;
}
