.Model
.Stack 100
.Data 
        TBao DB 'Go vao 1 so he hai(max 16 bit, go CR de thoi):$'
.Code
MAIN    Proc
        MOV AX, @Data
        MOV DS, AX  
        
        MOV AH, 9
        LEA DX, TBao
        INT 21H   
        
        XOR BX, BX 
        
        MOV AH, 1
   TIEP:INT 21H
        CMP AL, 13
        JE THOIDOC
        AND AL, 0FH
        SHL BX, 1
        OR BL, AL
        JMP TIEP
   THOIDOC: MOV CX, 16
        MOV AH, 2
   HIEN: XOR DL, DL
        ROL BX, 1
        ADC DL, 30H
        INT 21H
        LOOP HIEN
        MOV AH, 4CH
        INT 21H
MAIN    Endp
        END MAIN