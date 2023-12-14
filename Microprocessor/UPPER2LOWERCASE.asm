                     ; COMPARE TWO STRINGS 
ASSUME CS:CODE, DS:DATA

DATA SEGMENT 
    STR1 DB "HELLO WORLD$" 
    STR2 DB ? 
    
    COUNT EQU 0BH
    
    
    DATA ENDS 
CODE SEGMENT 
    START: MOV AX,DATA
    MOV DS,AX
    MOV ES,AX
    
    LEA SI,STR1
    LEA DI,STR2
    MOV CX,COUNT
    CLD
    
    CONVERT_LOOP: MOV AL,[SI]
    CMP AL,'$'
    JE END_PRGM
    
    CMP AL,'A'
    JB COPY
    
    CMP AL,'Z'
    JA COPY
    
    ADD AL,32
    
    COPY:  MOV [DI],AL  
    INC SI
    INC DI
    JMP CONVERT_LOOP
    
    
    END_PRGM: MOV [DI],'$'
    MOV AH,09H
    LEA DX,STR2
    INT 21H
    
    MOV AH,4CH
    INT 21H
    CODE ENDS
END START