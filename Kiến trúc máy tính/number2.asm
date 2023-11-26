.data
    hello db "hello$"
    hi db "xin chao", 13, 10, "$"     
    tb db "nhap so dong can cach: $"
    cref db 13,10,"$" 
    N db 0
MAIN Proc    
    MOV AX, @Data;
    MOV DS, AX 
    ; in dong dau tien
    mov ah, 9;
    mov dx, offset hi;
    int 21h      
    
    ; in thong bao nhap dong
    mov dx, offset tb
    int 21h
    
    ; nhap so dong can cach
    
nhap:    
    mov ah, 1; -> AL
    int 21h
    cmp al, "0"
    jb nhap
    jnb kiemtra
kiemtra:
    cmp al, "9"
    ja nhap
    jna dc  ; gia tri nhap vao thoa man
dc: 
    ; kiem tra so dong nhap vao co dung hay k
    mov ah, 2                          
    ;mov dl, al
    ;int 21h
    ; -> 'al' so lan lap   
    
    inc al, 1
    mov ah, 9; lenh in
lapwhile:
    cmp al, 30h ; 30h la ki tu so 0
    jne thuchien
    jmp ketthuc
thuchien:
    sub al ,1
    push ax  ; tranh thay doi gia tri cua AL                   
    mov dx, offset cref;
    int 21h  ; Gia tri cuar AL bi thay doi nen cho ax vao stack
    pop ax  ;  day ax ra khoi stack
    jmp lapwhile  
    
ketthuc:    
    mov dx, offset hello
    mov ah, 9;
    int 21h
    
       
       
MAIN Endp
    END MAIN
