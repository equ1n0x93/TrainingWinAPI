// excercise1dllimporttest.c : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char * argv[])
{
	HMODULE libHandle;
	dllFunc _importedFunc;
	int procCreationResult;
	LONG ordinalCall = MAKELONG(1,0); // ordinal is @1

	if ((libHandle = LoadLibrary(TEXT("C:\\dev\\TrainingWinAPI\\excercise1_dll_def_ordinal_import_explicit\\ex1dll.dll"))) == NULL)
	{
		printf("load failed\n");
		return 1;
	}

	_importedFunc = (dllFunc)GetProcAddress(libHandle, (LPCSTR)ordinalCall); //Getting the pointer to the imported function by ordinal

	if (_importedFunc == NULL)
	{
		printf("GetProcAddress failed\n");
		printf("%d\n", GetLastError());
		return 1;
	}

	procCreationResult = _importedFunc();
	printf("Success: (%d)\n", procCreationResult);
	Sleep(5000);

	FreeLibrary(libHandle);

	return 0;
}
