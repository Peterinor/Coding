;****************************************************
;File		:test.asm
;Author		:tangyu
;Date		:
;Version	:1.0.0
;Modify		:
;****************************************************
;nasm 和 gcc 混合编程测试

extern choose           ;int choose( int a,int b );
[section .data]         ;数据段开始
num1st dd 3
num2nd dd 4
[section .text]         ;代码段开始
global _start
global myprint
_start:
    mov eax,[num2nd]
    push eax
    mov eax,[num1st]
    push eax
    call choose
    add esp,8
    mov ebx,0
    mov eax,1
    int 0x80

myprint:                ;void myprint(char *msg,int len)
    mov edx,[esp+8]     ;len
    mov ecx,[esp+4]     ;msg
    mov ebx,1
    mov eax,4
    int 0x80
    ret
