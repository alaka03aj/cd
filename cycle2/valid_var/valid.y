%{
    #include <stdio.h>
    int valid = 1;
    int yyerror();
%}

%token letter digit

%%

start : letter s
s : letter s | digit s | ;

%%

int yyerror(){
    valid = 0;
    printf("Not a valid identifier\n");
    return 0;
}

int main() {
    printf("Enter identifier: ");
    yyparse();
    if (valid) { printf("Valid\n");}
}