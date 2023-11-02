[org 0x100]
mov ax,0;
add ax,[n1];
add ax,[n2];
add ax,[n3];
add ax,[n4];
add ax.[n5];
mov [sum],ax;
mov ax,0x4c00
int 21
sum: dw 0
n1:dw 10
n2:dw 20
n3:dw 30
n4:dw 40
n5:dw 50