[org 0x0100]

mov ax,200h
mov bx,150h
add cx,[0xx200]
add dx,[0x250]

mov cx,cx
mov dx,dx

mov dx,50h
mov cx,25h
 mov ax,cx
mov cx,dx

mov ax,0x4c00
int 21
array:sw1,2,6,5,10