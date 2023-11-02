[org 0x100]


jmp start

sum: dw 0
start:

mov ax, 0x7777
call binaryOnes
add dx, 5
call pyramid

mov ax, 0x4C00
int 21
binaryOnes:    
 mov dx, 00

                        
 loop1:  
 add cx,1
 add cx,1
 cmp cx, 16
 jnz loop2

  ret
  
 mov cx, 0
 loop2:    
 shr ax, 1
 jc loop1
 inc cx
 cmp cx, 16
 jnz loop2
 ret

pyramid: 
 mov cx, 1
 loop4:
 mov bx, 1
 mov si, 0

 loop5:    
 mov bx, 1
 l3:    
 add [sum], bx
 inc bx
 cmp bx, dx
 jbe loop3
 inc si
 cmp cx, si
 jnz loop5

 mov cx, 2

 dec dx

 cmp dx, 0

 jnz loop4

 ret
