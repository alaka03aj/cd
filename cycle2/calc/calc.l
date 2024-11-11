%{
    #include "calc.tab.h"
%}

%%

[0-9]+ {yylval = atoi(yytext); return number;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"(" {return '(';}
")" {return ')';}
[ \t]+ {}
\n {return 0;}
. {printf("Unexpected char");}

%%

int yywrap() {
    return 1;
}