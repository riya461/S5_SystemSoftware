#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input, *optab, *intermediate, *symtab, *length;
    int loc,length,straddr;
    // input - input.txt , optab.txt
    // output - intermediate.txt, symtab.txt, length.txt

    input = fopen("input.txt","r");
    optab = fopen("optab.txt","r");

    intermediate = fopen("intermediate.txt","r+");
    symtab = fopen("symtab.txt","r+");
    length = fopen("length.txt","r+");

    char label[20], opcode[20], operand[20];
    

    fscanf(input,"%s %s %d",label,opcode,&straddr);
    if(strcmp(opcode,'START') == 0){
        loc = straddr;
        fscanf(input,"%s %s %s",label,opcode,operand);

    }
    else
        loc = 0;
    while(opcode != 'END'){

    }


}
