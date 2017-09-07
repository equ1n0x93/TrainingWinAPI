// ex20basictokenimpersonation.c : Defines the entry point for the console application.
//

#include "stdafx.h"

PROCESS_INFORMATION createCmdLogonOtherUser() 
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	int CreateFlags = 0;

	SecureZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);

	if (!CreateProcessWithLogonW(L"TestUser",	//Username
		NULL,									//Domain
		L"t7744546",							//Password
		0,										//Logon Flags{{
		L"cmd.exe",								//App name
		NULL,									//Commandline
		CreateFlags,							//Creation Flags
		NULL,									//Environment
		NULL,									//Start Directory
		&si,
		&pi))
	{
		printf("Process creation failed(error:%d).\n", GetLastError());
		Sleep(3000);
		return pi;
	}

	printf("Process Created Successfully\n");
	Sleep(3000);
	return pi;

}

HANDLE getTokenDuplicationFromProcess(PROCESS_INFORMATION pFromHandle)
{
	HANDLE tSourceHandle;
	HANDLE tDuplicateHandle;
	
	if (!OpenProcessToken(pFromHandle.hProcess, TOKEN_DUPLICATE, &tSourceHandle)) {
		printf("Token open failed(error:%d).\n", GetLastError());
	}
	
	if (!DuplicateTokenEx(tSourceHandle, TOKEN_DUPLICATE, NULL, SecurityImpersonation, TokenImpersonation, &tDuplicateHandle)) {
		printf("Token duplication failed(error:%d).\n", GetLastError());
	}

	CloseHandle(tSourceHandle);

	return tDuplicateHandle;
}

void createCalcWithToken(HANDLE hToken) 
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	int logonFlags = 0;
	int createFlags = 0;

	if (!CreateProcessWithTokenW(hToken,
		logonFlags,
		"calc.exe",
		NULL,
		createFlags,
		NULL,
		NULL,
		&si,
		&pi)) 
	{
		printf("Create impersonated calculator failed(error:%d).\n", GetLastError());
	}

	printf("Impersonation completed successfully.\n", GetLastError());
	
	CloseHandle(pi.hProcess);
}

void main()
{
	PROCESS_INFORMATION piCmdNewUser;
	PROCESS_INFORMATION piCalcNewUser;
	HANDLE hImpersonateToken;
	
	// Create process from another user on the machine(requires user and password).
	piCmdNewUser = createCmdLogonOtherUser();

	// Duplicates process access token and returns the duplicated token handle.
	hImpersonateToken = getTokenDuplicationFromProcess(piCmdNewUser);
	CloseHandle(piCmdNewUser.hProcess);

	// Creates a calc process using the duplicated token from the created CMD.
	createCalcWithToken(hImpersonateToken);

	Sleep(5000);
}
