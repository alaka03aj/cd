%{
    #include <stdio.h>
    #include <string.h>
    int flag = 0;
    char name[80];
%}

%%
[a-zA-Z]* {
    for (int i = 0; i < yyleng; i++){
        if (yytext[i] == 'a' && yytext[i+1] == 'l' && yytext[i+2] == 'a' && yytext[i+3] == 'k') {
            flag = 1;
        } 
    }
    strcpy(name,yytext);
}

\n {
    if (flag == 1) {
        printf("%s contains substring of your name\n", name);
        flag = 0;
    } else {
        printf("%s doesn't contain substring of your name\n", name);
    }
    printf("Enter name: ");
}

%%

int main(){
    printf("Enter name: ");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}