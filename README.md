# TrainingWinAPI
WinAPI Training:

Exercise 1:
   - create an executable that creates another a cmd that writes “hi” to a file
   - do the same with a dll with an exported function
   - bonus round: create the process hidden
  coding is strictly C with winapi, i advise using visual studio
  after setting up this should take roughly 4h.


**Edit
adding another training that we should finish until we meet when XX and XX2 are back, please open tickets for yourselves:
- after you finished the first assignment you should have a dll with an exported function
please run procmon and notice dll load timing (if it exist):
- create an executable, link to the other dll and call the function
- delay load the dll
- dynamically load the dll by path and call the function (loadmodule, getprocaddress)
- build the dll without an exported function (https://msdn.microsoft.com/en-us/library/e7tsx612.aspx), load it by ordinal instead of function name.
bonus round:
- statically link the dll

open question:
- what dlls are loaded into your process, what makes them load? 
- which dlls can be removed as a dependency? 
- how would you do that?
