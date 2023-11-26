.data
    hello db "hello$"
    hi db "xin chao$"
    cref db 13,10,"$" 
    N equ 6;
MAIN Proc    
    MOV AX, @Data; nap du lieu
    MOV DS, AX 
    
    mov ah, 9;  lenh in
    mov dx, offset hi; 
    int 21h  
    
    mov dx, offset cref      
    mov cx, N   ; in n lan cref
lap:
    int 21h
    loop lap      
          
    mov dx, offset hello;
    int 21h


       
MAIN Endp
    END MAIN