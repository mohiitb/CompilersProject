%{
#include<stdio.h>
#include<iostream>
#include "y.tab.h"
int mylineno=1;
using namespace std;
%}


DIGIT			[0-9]  
LETTER			[a-zA-Z_]
IDENTIFIER		{LETTER|"_"}+{DIGIT}*
NUMBER1          {DIGIT}+| {DIGIT}*"."{DIGIT}*
NUMBER2          '-'?{DIGIT}+| '-'?{DIGIT}*"."{DIGIT}*
%%
[ \t]			;
\n			{ mylineno++ ; 	}
call 			{return(CALL);}
if 					{ return(IF);}
output               {return(OUTPUT);}
newl 				{return(NEWLINER) ;}
goto                 {return(GO_TO);}

{LETTER}+{DIGIT}*	{ return(IDENTIFIER);}


[-+*/<>] 		{	return(BIN_OPERATOR);}

[=]				{ return(EQUALS);	}
[a-zA-z]+[a-zA-z0-9]*[:] {return(LABEL);}
"=="				{return (DOUBLE_EQ);}
","					{return(COMMA);}
{DIGIT}+|{DIGIT}*.{DIGIT}*	 {return (NUMBER1);}
-{DIGIT}+|-{DIGIT}*.{DIGIT}*	 {return (NUMBER2);}


%%
int yywrap()
{
	return 1;
}