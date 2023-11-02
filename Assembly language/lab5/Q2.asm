[org 0x100]
jmp str
1s:
push cx

push ax

push bx

shl ax,1

mov bx,0

mov cx,0

jc l1

add cx,1
cmp cx,16

jne 1s

add cx,1

add bx,1

cmp cx,16

jne 1s


ret
str:
mov ax,5659
call 1s

mov ax,0x4c00
int 21
