%{
	#include <bits/stdc++.h>
	#include<string.h>
	#include <string>
	#include <stdio.h>
	#include <stdlib.h>
	#include <map>
	#include <vector>
	#include <fstream>
	#include<stack>
	using namespace std;
	#define YYSTYPE holder_union
	extern int yyparse(void);
	extern int yylex();
	extern int mylineno ;
	extern char* yytext ;
	extern int yyleng;
	ofstream fp;
	
	void yyerror(string);
	int flag=0;
	struct node_struct {
		string code_node;
		vector<node_struct*> v_node;
		string id_node;
		string dtype_node;
	};
	union holder_union {
		node_struct* node_holder;
		char* s_holder;
	};
	vector< map<string,string> > symbol_table(3000);

	map<string,string> symbol_global;
	int scope_var = 0;

	int global_scope_var=2000;
	bool semant_error = false;
	bool syntacticError = false;
	int counter_par=0;
	int get_scope(string id)
	{
		for(int i=scope_var;i>=0;i--)
		{
			if(symbol_table[i].find(id) != symbol_table[i].end()  )	return i;
			

		}
		if(symbol_global.find(id)!=symbol_global.end())
		{
			return 2000;
		}
		return -1;
	}
	node_struct* root_node_struct=NULL;	
%}

%token INT FLOAT BOOL VOID
%token INT_NUM FLOAT_NUM TRUE FALSE IDENTIFIER  
%token SEMI LP RP COMMA LCB RCB 
%token MAIN INPUT OUTPUT WHILE FOR IF IFX ELSE BREAK RETURN
%token EQUALS DOUBLE_EQ GREATER GREATER_EQ LESS LESS_EQ NOT_EQ 
%token MULT DIV INCR DECR AND OR NOT PLUS MINUS
%left PLUS MINUS
%left MULT DIV
%left LESS GREATER DOUBLE_EQ
%left NEGATION
%start START_CODE

%%

START_CODE		:	global main LP parameters_list RP Compound_statements
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "START_CODE";
					root_node_struct = new_node_struct;
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					(new_node_struct->v_node).push_back($4.node_holder);
					(new_node_struct->v_node).push_back($6.node_holder);
					$$.node_holder = new_node_struct;
				}
  			;
  			
main 		:	MAIN 
			{
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "main";
				new_node_struct->id_node = string(yytext,yyleng);
				$$.node_holder = new_node_struct;
			}
		;

global  		: 	declaration_list			
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "global_declaration_list";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	/*empty input*/
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "global_empty";
					$$.node_holder = new_node_struct;
				}
			;
						
declaration_list	:	declaration_list declaration
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_list";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}		
			|	declaration
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}							
			;
						
declaration		:	variable_declaration
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_variable";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}					
			|		function_declaration					
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_function";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|global_variable_declaration
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "declaration_variable";

					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;


				}
			;

global_variable_declaration : type_specifier identifier equals number SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "global_variable";

					if(symbol_global.find(($2.node_holder)->id_node)==symbol_global.end())
					{
						symbol_global[($2.node_holder)->id_node] = ($1.node_holder)->id_node;

					}
					else
					{
						semant_error = true;
						
					cout<<($2.node_holder)->id_node<<" "<<"multiple times declared"<<"at line no."<<mylineno<<endl;
					}	

					(new_node_struct->v_node).push_back($2.node_holder);
					(new_node_struct->v_node).push_back($4.node_holder);
					$$.node_holder = new_node_struct;
				}
			
			;



variable_declaration	:	type_specifier identifier  SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "variable declaration";
				

					if(symbol_table[scope_var].find(($2.node_holder)->id_node)==symbol_table[scope_var].end())
					{
						symbol_table[scope_var][($2.node_holder)->id_node] = ($1.node_holder)->id_node;
					}
				else
				{
				semant_error = true;
				cout<<($2.node_holder)->id_node<<" "<<"multiple times declared "<<"at line no. "<<mylineno<<endl;
					
				}	
				
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;


				}
			|	type_specifier identifier  error 	{flag=1;}
			;
			
identifier	:	IDENTIFIER	
			{
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "identifier";
				
				new_node_struct->id_node = string(yytext,strlen(yytext)) ;
				$$.node_holder = new_node_struct;
			}
		;
			
type_specifier		:	int
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "dtype_node_int";
					new_node_struct->id_node = string(yytext,yyleng);
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	float
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "dtype_node_float";
					new_node_struct->id_node = string(yytext,yyleng);
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	bool
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "dtype_node_bool";
					new_node_struct->id_node = string(yytext,yyleng);
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			
			|	error	{flag=1;}
			;

int 		:	INT
			{
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "INT";
				new_node_struct->id_node = string(yytext,strlen(yytext));
				$$.node_holder = new_node_struct;
			}
		;
		
float 		:	FLOAT
			{
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "FLOAT";
				new_node_struct->id_node = string(yytext,strlen(yytext));
				$$.node_holder = new_node_struct;
			}
		;

bool 		:	BOOL
			{
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "BOOL";
				new_node_struct->id_node = string(yytext,strlen(yytext));
				$$.node_holder = new_node_struct;
			}
		;
			


function_declaration :identifier LP parameters_list RP Compound_statements
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "function_declaration";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					(new_node_struct->v_node).push_back($5.node_holder);
					
					$$.node_holder = new_node_struct;
				}		
			;


parameters_list		:	parameters_list COMMA parameters
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "param_list";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					$$.node_holder = new_node_struct;
				}
			|		parameters
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "param";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	/*empty*/
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "empty_param";
					$$.node_holder = new_node_struct;
				}
			;
							
parameters		:	type_specifier	identifier
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "parameters";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}
			;

Statement_list		:	Statement_list	Statements	
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Statements list";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}				
			|	/*empty*/
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "emptyStatement_list";
					$$.node_holder = new_node_struct;
				}										
			;	

Statements		:	Output_statements
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Output Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	Input_statements
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "input Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	Function_call_statements
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "function Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			
			|	Compound_statements
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Compound Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	Loop_statements
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Loop Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	Condition_statements
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Condition Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	Expression_statements 
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "expr Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	Break_statement
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "break Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	Return_statement
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "return Statements";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			;



Function_call_statements	:	
						identifier LP Identifier_list RP SEMI
					{
						node_struct *new_node_struct = new node_struct;
						new_node_struct->code_node = "Function_Statements2";
						(new_node_struct->v_node).push_back($1.node_holder);
						(new_node_struct->v_node).push_back($3.node_holder);
						$$.node_holder = new_node_struct;
					}
				| 	identifier LP Identifier_list RP error		{flag=1;}
				;
				
Identifier_list		:	Identifier_list COMMA identifier
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Identifier_list";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	identifier
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Identifier_list_single";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	/*empty*/
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Identifier_list_empty";
					$$.node_holder = new_node_struct;
				}
			;

Output_statements	:	OUTPUT  identifier SEMI
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Print_statement";
					(new_node_struct->v_node).push_back($2.node_holder);
					
					$$.node_holder = new_node_struct;
				}
			;			

					
Input_statements	:	INPUT  identifier SEMI
				{
					node_struct *new_node_struct = new node_struct;
					new_node_struct->code_node = "Input_statement";
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}
			;			

		
Compound_statements	:	LCB
					{
						map <string,string>	temp;
						symbol_table.push_back(temp);
						scope_var++;
					}	
					local_declaration Statement_list RCB
					{
					

						node_struct *new_node_struct = new node_struct;
						new_node_struct->code_node = "Compound_Statements";
						(new_node_struct->v_node).push_back($3.node_holder);
						(new_node_struct->v_node).push_back($4.node_holder);
						$$.node_holder = new_node_struct;
						symbol_table.pop_back();
						scope_var--;
					
					}
			;
						
local_declaration	:	local_declaration variable_declaration
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "Local declaration";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}						
			| 	/*empty*/
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "local empty";
					$$.node_holder = new_node_struct;
				}											
			;

Loop_statements		:	WHILE LP expression RP 	Compound_statements
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "while_LOOP";
					
					(new_node_struct->v_node).push_back($3.node_holder);
					(new_node_struct->v_node).push_back($5.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	WHILE LP error RP 	{flag=1;}
			|	WHILE LP expression RP  error '\n' 	{flag=1;}
			|	FOR LP Expression_statements expression SEMI Expression_statements RP 	Compound_statements	
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "for_LOOP";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					(new_node_struct->v_node).push_back($4.node_holder);
					(new_node_struct->v_node).push_back($6.node_holder);
					(new_node_struct->v_node).push_back($8.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	FOR LP error RP		{flag=1;}
			;



Condition_statements	:	IF LP expression RP Compound_statements	
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "if";
					
					(new_node_struct->v_node).push_back($3.node_holder);
					(new_node_struct->v_node).push_back($5.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	IFX LP expression RP Compound_statements ELSE Compound_statements
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "ifx";
					
					(new_node_struct->v_node).push_back($3.node_holder);
					(new_node_struct->v_node).push_back($5.node_holder);
					(new_node_struct->v_node).push_back($7.node_holder);
					$$.node_holder = new_node_struct;
				}
			|   IF LP error RP 			{flag=1;}
			| 	IF LP expression RP error 	{flag=1;}
			|	IFX LP error RP 		{flag=1;}
			|	IFX LP expression RP Compound_statements error RCB 	{flag=1;}
			;



	

Expression_statements	:	identifier equals expression  SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "expr1";
					(new_node_struct->v_node).push_back($1.node_holder);
					int scope_2 = get_scope(($1.node_holder)->id_node);
					
					if(scope_2 == -1)
					{
						semant_error = true;
							
						cout<<($1.node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;
					}
					else
					{
						($$.node_holder)->dtype_node = symbol_table[scope_2][($1.node_holder)->id_node];
						
					} 
					(new_node_struct->v_node).push_back($2.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					$$.node_holder = new_node_struct;

				}	
			
			|	identifier incr	SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "post incr";
					(new_node_struct->v_node).push_back($1.node_holder);
					int scope_2 = get_scope(($1.node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<($1.node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;	
					}
					else
					{
						($$.node_holder)->dtype_node = symbol_table[scope_2][($1.node_holder)->id_node];
					} 
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}
			
			|	identifier decr	SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "post decr";
					(new_node_struct->v_node).push_back($1.node_holder);
					int scope_2 = get_scope(($1.node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<($1.node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;	
					}
					else
					{
						($$.node_holder)->dtype_node = symbol_table[scope_2][($1.node_holder)->id_node];
					} 
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}
			
			|	incr identifier SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "pre incr";
					(new_node_struct->v_node).push_back($1.node_holder);

					(new_node_struct->v_node).push_back($2.node_holder);
					int scope_2 = get_scope(($2.node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<($2.node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;
					}
					else
					{
						($$.node_holder)->dtype_node = symbol_table[scope_2][($1.node_holder)->id_node];
					} 
					$$.node_holder = new_node_struct;
				}
			
			|	decr identifier	SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "pre decr";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					int scope_2 = get_scope(($1.node_holder)->id_node);
					if(scope_2 == -1)
					{
						semant_error = true;
						cout<<($2.node_holder)->id_node<<" "<<"Undeclared at "<<"line no. "<<mylineno<<endl;
					}
					else
					{
						($$.node_holder)->dtype_node = symbol_table[scope_2][($2.node_holder)->id_node];
					} 
					$$.node_holder = new_node_struct;
				}
			
			|	expression SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "exprstmt expr";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			
			;
					
equals	:	EQUALS
		{
			node_struct *new_node_struct = new node_struct;
			new_node_struct->code_node = "EQUALS";
			new_node_struct->id_node = string(yytext,yyleng);
			$$.node_holder = new_node_struct;
		}
	;

incr	:	INCR
		{
			node_struct *new_node_struct = new node_struct;
			new_node_struct->code_node = "INCR";
			new_node_struct->id_node = string(yytext,yyleng);
			$$.node_holder = new_node_struct;
		}
	;

decr	:	DECR
		{
			node_struct *new_node_struct = new node_struct;
			new_node_struct->code_node = "DECR";
			new_node_struct->id_node = string(yytext,yyleng);
			$$.node_holder = new_node_struct;
		}
	;


expression:			LP expression RP
					{
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "expression";
						(new_node_struct->v_node).push_back($2.node_holder);
						$$.node_holder = $2.node_holder;

					}		
					|number
					{
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "expression";
						(new_node_struct->v_node).push_back($1.node_holder);
						$$.node_holder = $1.node_holder;
					}
				| identifier 
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "expression";

					int scope_2 = get_scope(($1.node_holder)->id_node);
					
					if(scope_2 == -1)
					{
						semant_error = true;
						cout << "Undeclared variable " << ($1.node_holder)->id_node << " line no. " << mylineno+1 << endl;	
					}
					else
					{
						($$.node_holder)->dtype_node = symbol_table[scope_2][($1.node_holder)->id_node];
					} 
					$$.node_holder = $1.node_holder;
				}
				| expression PLUS expression
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "PLUS";
				
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					
					
					new_node_struct->dtype_node = ($3.node_holder)->dtype_node;
					
					$$.node_holder = new_node_struct;
				}
				| expression MINUS expression
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "MINUS";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);

				
					$$.node_holder = new_node_struct;
				}
				| expression MULT expression
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "MULT";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					
					
					new_node_struct->dtype_node = ($3.node_holder)->dtype_node;
					
					$$.node_holder = new_node_struct;
				}
				| expression DIV expression
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "DIV";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					
					
					new_node_struct->dtype_node = ($3.node_holder)->dtype_node;
					
					$$.node_holder = new_node_struct;
				}
				| expression LESS expression
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "LESS";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					
					
					new_node_struct->dtype_node = ($3.node_holder)->dtype_node;
					
					$$.node_holder = new_node_struct;
				}
				| expression GREATER expression
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "GREATER";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					
					
					new_node_struct->dtype_node = ($3.node_holder)->dtype_node;
					
					$$.node_holder = new_node_struct;
				}
				| expression DOUBLE_EQ expression
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "DOUBLE_EQ";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($3.node_holder);
					
					
					new_node_struct->dtype_node = ($3.node_holder)->dtype_node;
					
					$$.node_holder = new_node_struct;
				}
				|NEGATION LP expression RP  %prec NEGATION
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "NEGATION";
					(new_node_struct->v_node).push_back($3.node_holder);
					$$.node_holder = new_node_struct;
				}
				;

/*operator: 				
						 relational_operator			{$$.s_holder = $1.s_holder;}
						| binary_operator			{$$.s_holder = $1.s_holder;}
						;


relational_operator:			LESS			
						{				
							node_struct* new_node_struct = new node_struct;
							new_node_struct->id_node = string(yytext,yyleng);
							$$.s_holder = strdup("LESS");
						}
						| GREATER			
						{
							node_struct* new_node_struct = new node_struct;
							new_node_struct->id_node = string(yytext,yyleng);
							$$.s_holder = strdup("GREATER");
						}
						| DOUBLE_EQ			
						{
							node_struct* new_node_struct = new node_struct;
							new_node_struct->id_node = string(yytext,yyleng);
							$$.s_holder = strdup("DOUBLE_EQ");
						}
						;

binary_operator:				PLUS				
						{
							node_struct* new_node_struct = new node_struct;
							new_node_struct->id_node = string(yytext,yyleng);
							$$.s_holder = strdup("PLUS");
						}
						| MINUS			
						{
							node_struct* new_node_struct = new node_struct;
							new_node_struct->id_node = string(yytext,yyleng);
							$$.s_holder = strdup("MINUS");
						}
						| MULT
						{
							node_struct* new_node_struct = new node_struct;
							new_node_struct->id_node = string(yytext,yyleng);
							$$.s_holder = strdup("MULT");
						}
						| DIV			
						{
							node_struct* new_node_struct = new node_struct;
							new_node_struct->id_node = string(yytext,yyleng);
							$$.s_holder = strdup("DIV");
						}
						
					;

	
*/
number :  INT_NUM
					{
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "NUMBER";

						new_node_struct->id_node = string(yytext,yyleng);
							
						$$.node_holder = new_node_struct;

					}
					|
			FLOAT_NUM 
					{
						node_struct* new_node_struct = new node_struct;
						new_node_struct->code_node = "NUMBER";

						new_node_struct->id_node = string(yytext,yyleng);	
						$$.node_holder = new_node_struct;


					}
					;
			

Break_statement		:	break SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "break only";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}	
			|		break error		{flag=1;}
			;

break		:	BREAK
			{
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "BREAK";
				new_node_struct->id_node = string(yytext,yyleng);
				$$.node_holder = new_node_struct;
			}
		;

Return_statement	:	return expression SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "return expr only";
					(new_node_struct->v_node).push_back($1.node_holder);
					(new_node_struct->v_node).push_back($2.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	return expression error		{flag=1;}
			|	return SEMI
				{
					node_struct* new_node_struct = new node_struct;
					new_node_struct->code_node = "return only";
					(new_node_struct->v_node).push_back($1.node_holder);
					$$.node_holder = new_node_struct;
				}
			|	return error		{flag=1;}
			;													
		
return		:	RETURN
			{
				node_struct *new_node_struct = new node_struct;
				new_node_struct->code_node = "RETURN";
				new_node_struct->id_node = string(yytext,yyleng);
				$$.node_holder = new_node_struct;
			}
		;



		

%%

void tree_traversal(node_struct *n,int cnt)
{
	//for easy node_struct recognition

	
	
	for(int i=0;i<cnt;i++) cout<<"-";
	if(n==NULL){
		cout<<"No CHILD NODE!\n";
		return;
	}
	cout <<"Code: "<<n->code_node<<"; Children: "<<(n->v_node).size()<<"; ID, if any: "<<n->id_node<<endl;
	for (int i = 1; i <= (n->v_node).size(); ++i)
		tree_traversal((n->v_node)[i-1],cnt+1);
}

string new_register()
{
	static int counter=0;
	stringstream ss;
	ss<<++counter;
	fp<<"reg"+ss.str()<<endl;
	return string("reg"+ss.str());
}

string new_label()
{
	static int labeler=0;
	stringstream ss;
	ss<<++labeler;
	return string("label"+ss.str()+":");
}

string code_generation(node_struct *n)
{
	if(n==NULL) 
	{
		return "";
	}
	if(n->code_node == "Compound_Statements")
	{
		scope_var++;
		map<string,string> temp_var;
		symbol_table.push_back(temp_var);
		
		for(int j=0;j<(n->v_node).size();j++)
		{
			code_generation((n->v_node)[j]);

		}

		scope_var--;
		symbol_table.pop_back();
		return "";
	}

	if(n->code_node == "if")
	{
		string reg1=code_generation((n->v_node)[0]);
		string label_1 = new_label();
		string label_2 = new_label();
		cout<<"if"<<reg1<<" goto "<<label_1<<endl;
		
		cout<<"goto "<<label_2<<endl;
		cout<<label_1<<endl;
		code_generation((n->v_node)[1]);
		string newReg=new_register();

		cout<<label_2<<endl;
		return "";
	}
	if(n->code_node == "expr1")
	{
		cout<<code_generation((n->v_node)[0])<<" = "<<code_generation((n->v_node)[2])<<endl;
		return "";

	}
	if(n->code_node == "NUMBER")
	{
		
		return n->id_node;
	}
	if(n->code_node=="identifier")
	{
			int z=get_scope(n->id_node);
			stringstream ss;
			
			ss<<z;
			string sl=n->id_node +ss.str();
			fp<<sl<<endl;
			if(ss.str()!="-1" && ss.str()!="2000")
			{
				return n->id_node +ss.str();
			}
			else
			if(ss.str()=="2000")
			{
				return n->id_node +"2000";
			}
			else
			{
				return n->id_node;
			}

		
	}
	if(n->code_node=="Print_statement")
	{
			cout<<"output"<<" "<<code_generation((n->v_node)[0])<<endl;
	}
	if(n->code_node=="PLUS")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" + "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="MINUS")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" - "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="MULT")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" * "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="DIV")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" / "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node=="LESS")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<reg1<<" < "<<reg2<<endl;
		
		return newRegister_1;
	}
	if(n->code_node == "DOUBLE_EQ")
	{
		string reg1=code_generation((n->v_node)[0]);
		string reg2=code_generation((n->v_node)[1]);
		string newRegister_1=new_register();
	
		cout<<newRegister_1<<" = "<<reg1<<" == "<<reg2<<endl;
		

		return newRegister_1;
	}
	if(n->code_node=="NEGATION")
	{
		string reg1=code_generation((n->v_node)[0]);
		string newRegister_1=new_register();
		
		cout<<newRegister_1<<" = "<<"-1"<<" "<<"*"<<" "<<reg1<<endl;
		return newRegister_1;
	}
	if(n->code_node=="while_LOOP")
	{
		string mylabel1= new_label();
		cout<<mylabel1<<endl;
		string reg1=code_generation((n->v_node)[0]);
		string mylabel2 = new_label();
		string mylabel3 = new_label();
		cout<<"if "<<reg1<<" goto "<<mylabel2<<endl;
		cout<<"goto "<<mylabel3<<endl;
		
		cout<<mylabel2<<endl;
		code_generation((n->v_node)[1]);
		cout<<"goto "<<mylabel1<<endl;
		cout<<mylabel3<<endl;
		return "";


	}
	if(n->code_node=="function_declaration")
	{
		string z=code_generation((n->v_node)[0]);
		int le =z.length();
		
		cout<<z<<":"<<" "<<endl;
		code_generation((n->v_node)[2]);
		return "";
	}
	if(n->code_node=="Identifier_list_single")
	{

		cout<<"param"<<" "<<code_generation((n->v_node)[0])<<endl;
		counter_par++;
		return "";

	}
	if(n->code_node=="Identifier_list")
	{

		cout<<"param"<<" "<<code_generation((n->v_node)[1])<<endl;
		counter_par++;
		code_generation((n->v_node)[0]);
		return "";

	}
	if(n->code_node=="Function_Statements2")
	{
		
		
		code_generation((n->v_node)[1]);
		cout<<"call"<<code_generation((n->v_node)[0])<<":"<<endl;
		counter_par=0;
		return "";
		

	}
	if(n->code_node=="global_variable")
	{
		cout<<code_generation((n->v_node)[0])<<"="<<code_generation((n->v_node)[1])<<endl;
		return "";

	}
	else
	{
		for (int k = 0; k < (n->v_node).size(); ++k)
		{
			code_generation((n->v_node)[k]);
		}
		return "";
	}


}

int main()
{
	yyparse();
	/*if(flag==1)
	{
		cout<<"TREE NOT FORMED BECUASE OF ERRORS\n";
	}
	else
	{
	tree_traversal(root_node_struct,0);
	}*/
	fp.open ("new.txt");
	if(semant_error==false && flag!=1)
	{
		code_generation(root_node_struct);
	}
	 fp.close();
}
void yyerror (string s_holder) { printf("Error in line: %d, text: %s_holder \n", mylineno, yytext);}



 					