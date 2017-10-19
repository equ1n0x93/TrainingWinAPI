// excercise1dllimporttest.c : Defines the entry point for the console application.
// Need to copy ex1dll.dll to one of the paths in PATH system env variable
// Add the dll path to Project Props -> VC++Directories(Source/Linker/Library)
// Add the lib file to Project Props -> Linker -> Input -> Additional dependencies

#include "stdafx.h"

int main(int argc, char * argv[])
{
	int procCreationResult;

	procCreationResult = createExcerciseProcess();
	printf("Success: (%d)\n", procCreationResult);
	Sleep(5000);

	return 0;
}
