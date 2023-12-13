#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input, *foptab, *intermediate, *symtab, *length, *rsymtab;
    int loc,len,straddr;
    // input - input.txt , optab.txt
    // output - intermediate.txt, symtab.txt, length.txt

    input = fopen("input.txt","r");
    foptab = fopen("optab.txt","r");
    rsymtab = fopen("symtab.txt","r");

    intermediate = fopen("intermediate.txt","w+");
    symtab = fopen("symtab.txt","w+");
    length = fopen("length.txt","w+");

    char label[20], opcode[20], operand[20];
    

    fscanf(input,"%s %s %d",label,opcode,&straddr);
    if(strcmp(opcode,"START") == 0){
        loc = straddr;
        fscanf(input,"%s %s %s",label,opcode,operand);

    }
    else
        loc = 0;
    while(strcmp(opcode,"END") != 0){
        // search if label in symtab 
        char sym[20];
        int add_sym;
        printf("%s\n",label);
        if(strcmp(label,"**") != 0){
        while(!feof(rsymtab)){
            fscanf(rsymtab,"%s %d\n",sym,&add_sym);
            if(strcmp(label,sym) == 0){
                printf("Error : Duplicate symbol\n");
                return 1;
                
            }
        }
        // if not add (label, locctr) to symtab 
        printf("%s %d\n",label,loc);
        fprintf(symtab,"%s %d\n",label,loc);
        }
        // search in optab 
        while (!feof(foptab))
        {
            fscanf(foptab,"%s %d",sym,&add_sym);
            if(strcmp(opcode,sym) == 0){
                loc += 3;
                break;
            }

        }

        if(strcmp(opcode,"RESB") == 0)
            loc += atoi(operand);
        else if(strcmp(opcode,"RESW") == 0)
            loc += 3*atoi(operand);
        else if(strcmp(opcode,"BYTE") == 0){
            if(operand[0] == 'X')
                loc += 1;
            else
                loc += strlen(operand) - 2;
        }
        else if(strcmp(opcode,"WORD") == 0)
            loc += 3;
        
        
        fprintf(intermediate,"%d %s %s %s\n",loc,label,opcode,operand);
        printf("%d %s %s %s\n",loc,label,opcode,operand);
        fscanf(input,"%s %s %s",label,opcode,operand);

        

    }
        printf("%s\n",opcode);

    printf("%d %s %s %s\n",loc,label,opcode,operand);

    fprintf(intermediate,"%d %s %s %s\n",loc,label,opcode,operand);
    len = loc - straddr;
    fprintf(length,"%d",len);
    fclose(input);
    fclose(foptab);
    fclose(intermediate);
    fclose(symtab);
    fclose(length);
    return 0;



}
