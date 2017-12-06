// ex1dll.h - Contains declaration of Function class  
#pragma once  

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

// Defining bool type
typedef int bool;
#define true 1
#define false 0

// Exporting functions
#define DLL_EXPORT __declspec(dllexport)
DLL_EXPORT int createExcerciseProcess();
