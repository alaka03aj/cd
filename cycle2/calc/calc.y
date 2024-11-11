%{
    #include <stdio.h>
    int yyerror();
%}

%token number

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

start : e { printf(" Result is : %d\n", $1); }
;         

e : e '+' e          { $$ = $1 + $3; }
  | e '-' e          { $$ = $1 - $3; }
  | e '*' e          { $$ = $1 * $3; }
  | e '/' e          { $$ = $1 / $3; }
  | '(' e ')'        { $$ = $2; }
  | number           { $$ = $1; }
  ;
%%

int main(){
    printf("Enter expression: ");
    yyparse();
    return 1;
}

int yyerror(){
    printf("Error");
}
