[org 0x100]
num : dw 6292
mov ax 1100010100100100b;
mov bx,1111000011110000b;
mov dx,0000111100001111b;
and bx,ax
and dx,ax
shr bx,4
shl dx,4
or bx,dx
mov ax,bx

mov ax,0x4c00

int 0x21         
