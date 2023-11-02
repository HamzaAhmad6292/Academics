[org 0x100]
jmp  start;
set1: db -3,-1,2,5,6,8,9;
set2: db -2,6,7,9;
result: db 0



start:

call difference
mov ax,0x4c00
int 21h



difference:

mov bl,[set1];
mov si,0;
mov bh,[set2];
mov di,0;
mov cl,0;

l1:

add si,1;
cmp si,7;
je End;

l2:
mov al,[set1+di];
cmp byte[set2+si],al;
je l1;
add di,1;
cmp di,3;
jne l2
mov ah,[set2+si]
mov byte[result+cl],ah;
add cl,1;


jmp l1;

End:
ret





