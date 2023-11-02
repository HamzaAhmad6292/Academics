[org 0x0100]

mov ax,25h
mov bx,20
mov dx,ax
mov ax,bx
mov bx,dx

mov cx,0x270]
mov ax,[num1]
mov si,4
loop1:
mov
mov ax,[num1+si]
sub si,2
cmp si,0
jne loop1
mov ax,0x4c00
int 21;

num1:dw 12,25,10


