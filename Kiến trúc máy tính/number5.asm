.Model Small
.Stack 100
.Data
        Str1    DB 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'
        Tbao    DB 'Chuoi da duoc doi:', 10, 13
        Str2    DB 8 DUP(?) 
                DB '$'
                
.Code
MAIN    Proc
        MOV AX, @Data
        MOV DS, AX   
        MOV ES, AX
        LEA SI, Str1+7
        LEA DI, Str2+7
        STD
        MOV CX, 8
    LAP:LODSB
        SUB AL, 20H
        STOSB
        LOOP LAP
        LEA DX, Tbao
        MOV AH, 9
        INT 21H
        MOV AH, 4CH
        INT 21H
MAIN    Endp
        END MAIN
