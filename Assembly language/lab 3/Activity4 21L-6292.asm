[org 0x0100]
    mov ax,0 
    mov bx,0 
    mov cx,24
max:
    mov ax,[array+bx]
    cmp [max],ax
    jg nomax
    mov [max],ax

nomax:
    add bx,2
    cmp bx,cx
    jne max
mov ax,0x4c00
int 0x21
array: dw 111, 999, 888, 888, 11, 99, 88, 88, 1, 9, 8, 8  
max: dw 0