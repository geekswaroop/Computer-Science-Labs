%{ 
#include<stdio.h> 
#include<string.h> 
char line[100]; 
char temp_line[100];
int i;
%}

%% 
['\n']    {	
		i = 0;
		while(i<strlen(line) && line[i]=='\t')	i++;
		strcpy(temp_line, line+i);
		if(!(strlen(temp_line)>=2 && temp_line[0] == '/' && temp_line[1] == '/')){			
			strcpy(line, temp_line);
			if(strcmp(line,"")!=0){
				fprintf(yyout,"%s\n",line); 
				strcpy(line,"");
			}
		}
	  }
"//".*\n {}
\/\*(.*\n)*.*\*\/  {};
(.*)      { 
		strcpy(line,yytext);
	  } 
%% 
 
int yywrap() 
{ 
    return 1; 
} 

int main() 
{ 
        extern FILE *yyin, *yyout;
        yyin=fopen("input.c","r"); 

        yyout=fopen("input_copied.c","w"); 
        yylex(); 
}