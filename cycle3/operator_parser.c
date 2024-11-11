#include <stdio.h>
#include <string.h>

void main(){
    char stack[20], input[20], precedence_table[20][20], terminals[10];
    int i, j, k, num_terminals, top = 0, row, col;

    for (i = 0; i < 10; i++){
        stack[i] = '\0';
        input[i] = '\0';

        for (int j = 0; j < 10; j++){
            precedence_table[i][j] = '\0';
        }
    }

    printf("Enter no. of terminals: ");
    scanf("%d", &num_terminals);

    printf("Enter the terminals: ");
    scanf("%s", terminals);

    printf("\nEnter the table values:\n");
    for (i = 0; i < num_terminals; i++) {
        for (j = 0; j < num_terminals; j++) {
            printf("Enter the precedence relation for %c and %c: ", terminals[i], terminals[j]);
            scanf(" %c", &precedence_table[i][j]);
        }
    }

    printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
    printf("  ");
    for (i = 0; i < num_terminals; i++)
        printf("\t%c", terminals[i]);
    printf("\n");

    for (i = 0; i < num_terminals; i++) {
        printf("%c", terminals[i]);
        for (j = 0; j < num_terminals; j++)
            printf("\t%c", precedence_table[i][j]);
        printf("\n");
    }

    stack[top] = '$';
    printf("Enter the input string: ");
    scanf("%s", input);

    i = 0;

    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t", stack, input);

    while (i <= strlen(input)) {
        for (k = 0; k < num_terminals; k++){
            if(stack[top] == terminals[k]) row = k;
            if (input[i] == terminals[k]) col = k;
        }

        if ((stack[top] == '$') && (input[i] == '$')) {
            printf("String is accepted!\n");
            break;
        }
        else if (precedence_table[row][col] == '<' || precedence_table[row][col] == '='){
            stack[++top] = precedence_table[row][col];
            stack[++top] = input[i];
            printf("Shift %c", input[i]);
            i++;
        }
        else if (precedence_table[row][col] == '>') {
            while (stack[top] != '<'){
                --top;
            }
            top = top-1;
            printf("Reduce");
        }
        else {
            printf("String is not accepted");
            break;
        }

        printf("\n");
        for (k = 0; k <= top; k++) printf("%c", stack[k]);
        printf("\t\t\t");
        for (k = i; k < strlen(input); k++) printf("%c", input[k]);

    }
}