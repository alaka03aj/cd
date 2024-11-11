#include <stdio.h>
#include <string.h>

void gen_code_for(char *input, char op, char *reg){
    int i = 0, j = 0;
    char temp[100];

    while (input[i] != '\0'){
        if (input[i] == op){
            printf("%c\t%c\t%c\t%c\n", op, *reg, input[i - 1], input[i + 1]);
            temp[j-1] = *reg;
            i += 2;
            (*reg)--;
            continue;
        }
        temp[j] = input[i];
        i++;
        j++; 
    }

    temp[++j] = '\0';
    strcpy(input,temp);
}

void gen_code(char *input){
    char reg = 'Z';
    gen_code_for(input,'/',&reg);
    gen_code_for(input,'*',&reg);
    gen_code_for(input,'+',&reg);
    gen_code_for(input,'-',&reg);
    gen_code_for(input,'=',&reg);
}

void main() {
    char input[100];
    printf("Enter expression: ");
    scanf("%s", input);

    printf("Op  \tDestn\tArg1\tArg2\n");
    gen_code(input);
}