[org 0x100]
jmp Start
arr: dw 111,999,888,888,11,99,88,88,19,8,8;
max: dw 0


Start:
mov cx,0
mov bx,0

l1:
cmp cx,22
je end


cmp max,[arr+bx]
jb maximum

add cx,1
add bx,1
jmp l1

maximum:
mov max,[arr+bx]
add cx,1
add bx,1
jmp l1

end:
mov ax, 0x4c00
int 21
