[org 0x100]
mov bx,num1
mov cx,0
loop1:
add ax,[bx+cx]
add cx,2;
cmp cx,24
jne loop1


mov ax,0x4c00
int 0x21

arr dw 111,999,888,888,11,99,88,88,19,8,8;