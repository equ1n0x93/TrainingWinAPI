// ex1dll.h - Contains declaration of Function class  
#pragma once  

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define DLL_EXPORT __declspec(dllexport)

DLL_EXPORT int createExcerciseProcess();
