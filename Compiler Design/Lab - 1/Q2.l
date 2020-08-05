%{  
int k = 0 ;
int i = 0;
int op = 0;   
%} 

%%  
  
"while"|"if"|"else"|"for"|"return"|"printf"|"long"|"int"|"double" {k++;printf("\t Keywords : %s", yytext);}   
  
"int"|"float" {k++;printf("\t Keywords : %s", yytext);}    
  
[a-zA-Z_][a-zA-Z0-9_]* {i++;printf("\t Identifier : %s", yytext);}  
  
"<="|"=="|"="|"++"|"-"|"*"|"+" {op++;printf("\t Operator : %s", yytext);} 
  
.    ; 
%%  

int yywrap(void) 
{ 
    return 1; 
} 
int main()  
  
{  
    extern FILE* yyin; 
    yyin = fopen("input_copied.c", "r");
    yylex(); 
      
    printf("\n Total No. of Keywords = %d\n", k);
    printf("\n Total No. of Identifiers = %d\n", i);
    printf("\n Total No. of Operators = %d\n", op);    
       
}  