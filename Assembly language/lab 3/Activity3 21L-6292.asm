[org 0x100]
mov cx,42
mov dx,0
mov bx,0

l1:
mov ax,[arr+bx]
cmp ax,[num]
jz skip
add bx,2
cmp cx,bx
jnz l1
freq:
add dx,1
mov [freq],dx
cmp bx,cx
jnz l1
mov ax,ox4c00
int 21
arr: dw 1,9,9,9,8,8,8,8,8,8,1,1,9,9,8,8,8,8,1,9,8,8
num:dw 1
freq:dw 0
