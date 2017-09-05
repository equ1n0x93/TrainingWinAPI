// excercise1dllimporttest.c : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char * argv[])
{
	HMODULE libHandle;
	dllFunc _importedFunc;
	int procCreationResult;

	if ((libHandle = LoadLibrary(TEXT("C:\\dev\\TrainingWinAPI\\excercise1_dll\\Debug\\ex1dll.dll"))) == NULL)
	{
		printf("load failed\n");
		return 1;
	}

	_importedFunc = (dllFunc)GetProcAddress(libHandle, "createExcerciseProcess"); //Getting the pointer to the imported function by name

	if (_importedFunc == NULL)
	{
		printf("GetProcAddress failed\n");
		printf("%d\n", GetLastError());
		return 1;
	}

	procCreationResult = _importedFunc();
	printf("Success: (%d)\n", procCreationResult);
	Sleep(5000);

	return 0;
}
