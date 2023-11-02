[org 0x100]
mov ax 1100010100100100b;
mov bx,1111000011110000b;
mov dx,0000111100001111b;
and bx,ax
and dx,ax
or ax,bx
mov [f],ax
mov ax,0x4c00
int 0x21
f:dw 0


int 0x21         
