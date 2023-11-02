[org 0x100]

jmp start

f: dd 0

num1: dd 0
num2: dd 0
conc: dd 0
mulitplyResult: dd 0
start:
mov ax, 5441h
mov [num1], ax
not ax
mov bx, ax
mov [num2], bx
not ax

call Addition

call mulitplication

call concatinant



mov ax, 0x4C00
int 21





Addition:       
 mov ax, [conc]

 add ax, [mulitplyResult]

 mov [f], ax

 mov ax, [conc + 2]

 adc ax, [mulitplyResult + 2]

 mov [f + 2], ax

 ret

concatinant:   
mov ax, [num1]
mov [conc], ax
mov bx, [num2]
mov [conc + 2], bx
mov ax, [mulitplyResult]
mov bx, [mulitplyResult + 2]
ret

mulitplication:  


mov cx, 17
l1: 
shr ax, 1
jnc s1
add [mulitplyResult], bx
s1:
shl bx, 1
dec cx
cmp cx, 1
jnc l1
ret

