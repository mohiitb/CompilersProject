%{
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include<stack>
#include <sstream>
using namespace std;
void yyerror(string);
extern char *yytext;
#define YYSTYPE char *
extern int mylineno ;
int yylex(void);
map <string,int> variable_store;
string generate_new_label();
int check_variable(char *);
FILE *read_fp;
FILE *write_fp;
int label_counter=0;

%}

%start start_code

%token 	BIN_OPERATOR
%token 	PLUS MINUS MULT DIV 
%token  DOUBLE_EQ GREATER LESS EQUALS
%token 	NEGATION
%token 	GO_TO PARAM
%token 	LABEL
%token IF
%token IDENTIFIER NUMBER1 NUMBER2
%token OUTPUT CALL NEWLINER
%token COMMA
%%
start_code :  start_code start 
			|  

start      :binary_expression   {printf("1\n");}
			|assign_expression  {printf("2\n");}
		 	|conditional_statement  {printf("3\n");}
			|unconditional_statement  {printf("4\n");}
			|parameter_list  {printf("5\n");}
			|labeler  {printf("6\n");}
			|output   {printf("7\n");}
		
			|newliner   {printf("9\n");}
			



identifier : IDENTIFIER
				{
					$$=strdup(yytext);
				}


number : NUMBER1 
			{
				$$ = strdup(yytext);
			}
		| NUMBER2
			{
				$$ = strdup(yytext);
				
			}


output  :    OUTPUT identifier
			{
				int chk=check_variable($2);
				if(chk==-1)
				{
					fprintf(write_fp,"li $a0 %s\n",$2);
				}
				else
				{
					fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk- 4);

				}
				fprintf(write_fp,"li $v0, 1 \n");
				//fprintf(write_fp,"move $a0, $t1 \n");
				fprintf(write_fp,"syscall \n");

			}
			| OUTPUT newliner
			{
					
					int chk=check_variable($2);
					if(chk==-1)
					{
						fprintf(write_fp,"li $a0 %s\n",$2);
					}
					else
					{
						fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk- 4);

					}
					//fprintf(write_fp,"la $a0,newLine\n");
					fprintf(write_fp,"li $v0, 4 \n");
					
    				
    				fprintf(write_fp,"syscall \n");


			}
newliner : NEWLINER
			{
				
			
				$$ = strdup(yytext);
			
			}
conditional_statement :IF identifier GO_TO label
					 {
					 	
					 	int leng=strlen($4);
					 	
					 	int chk=check_variable($2);
					 	int q=0;
					 	$4[leng-1]=q;
					 	fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk-4);
				   	 	fprintf(write_fp,"li $t1 0\n");
				   	 	fprintf(write_fp,"bne $a0 $t1 %s\n",$4);
											
					 }
				   | IF number GO_TO label 
				   	 {
				   	 	
				   	 	int leng=strlen($4);
				   	 	int q=0;
					 	$4[leng-1]=q;
				   	 	fprintf(write_fp,"li $a0 %s\n",$1);
				   	 	fprintf(write_fp,"li $t1 0\n");
				   	 	fprintf(write_fp,"bne $a0 $t1 %s\n",$4);
				   	 }
unconditional_statement : GO_TO label
					 {
					 
					 	int leng=strlen($2);
					 	$2[leng-1]=0;
					 	fprintf(write_fp,"b %s\n",$2);
					 }
parameter_list      : PARAM identifier
					|PARAM number

labeler: label
		{
			fprintf(write_fp,"%s\n",$1);
		}

binary_expression :
						identifier EQUALS id_number bin_operator id_number 
						{
							
							if(strcmp($4,"+")==0)
							{
								cout<<$3<<endl;
								int chk=check_variable($3);
								cout<<"hi2"<<endl;
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$3);

								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk- 4);
								}

								fprintf(write_fp,"sw $a0 0($sp)\n");
								fprintf(write_fp,"addiu $sp $sp -4\n");


								chk=check_variable($5);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$5);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}
								fprintf(write_fp,"lw $t1 4($sp)\n");
								fprintf(write_fp,"addiu $sp $sp 4\n");
								fprintf(write_fp,"add $a0 $a0 $t1\n");
								chk=check_variable($1);
								
								fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk - 4);
										
							}

							else if(strcmp($4,"-")==0)
							{
								
								int chk=check_variable($3);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$3);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}

								
								fprintf(write_fp,"sw $a0 0($sp)\n");
								fprintf(write_fp,"addiu $sp $sp -4\n");


								chk=check_variable($5);
								if(chk==-1)
								{
								
								
									fprintf(write_fp,"li $a0 %s\n",$5);
								}
								else
								{
										fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}
								fprintf(write_fp,"lw $t1 4($sp)\n");
								fprintf(write_fp,"addiu $sp $sp 4\n");
								fprintf(write_fp,"sub $a0 $t1 $a0\n");
								chk=check_variable($1);
								
								fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk - 4);
										
							}
							else if(strcmp($4,"*")==0)
							{
								int chk=check_variable($3);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$3);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}

								
								fprintf(write_fp,"sw $a0 0($sp)\n");
								fprintf(write_fp,"addiu $sp $sp -4\n");


								chk=check_variable($5);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$5);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}
								fprintf(write_fp,"lw $t1 4($sp)\n");
								fprintf(write_fp,"addiu $sp $sp 4\n");
								fprintf(write_fp,"mul $a0 $a0 $t1\n");
								chk=check_variable($1);
								
								fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk - 4);
										
							}
							else if(strcmp($4,"/")==0)
							{
								int chk=check_variable($3);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$3);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}

							
								fprintf(write_fp,"sw $a0 0($sp)\n");
								fprintf(write_fp,"addiu $sp $sp -4\n");


								chk=check_variable($5);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$5);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}
								fprintf(write_fp,"lw $t1 4($sp)\n");
								fprintf(write_fp,"addiu $sp $sp 4\n");
								fprintf(write_fp,"div $a0 $a0 $t1\n");
								chk=check_variable($1);
								
								fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk - 4);
										
							}
							else if(strcmp($4,"==")==0)
							{
								
								int chk=check_variable($3);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$3);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}

								
								fprintf(write_fp,"sw $a0 0($sp)\n");
								fprintf(write_fp,"addiu $sp $sp -4\n");


								chk=check_variable($5);
								if(chk==-1)
								{
									
								
									fprintf(write_fp,"li $a0 %s\n",$5);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}

								fprintf(write_fp,"lw $t1 4($sp)\n");
								fprintf(write_fp,"addiu $sp $sp 4\n");
								

								string newlab1 = generate_new_label();
								cout<<"lb1"<<newlab1<<endl;
								string newlab2 = generate_new_label();
								cout<<"lb2"<<newlab2<<endl;

								fprintf(write_fp, "beq $a0 $t1 %s\n", newlab1.c_str() );
								fprintf(write_fp, "li $a0 0\n" );
								fprintf(write_fp, "b %s\n",newlab2.c_str() );
								fprintf(write_fp, "%s:",newlab1.c_str() );
								fprintf(write_fp, "li $a0 1\n" );
								fprintf(write_fp, "%s:",newlab2.c_str() );
								chk=check_variable($1);
								
								fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk - 4);
										
							}
							
							else if(strcmp($4,">")==0)
							{
								
								int chk=check_variable($3);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$3);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}

								
								fprintf(write_fp,"sw $a0 0($sp)\n");
								fprintf(write_fp,"addiu $sp $sp -4\n");


								chk=check_variable($5);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$5);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}
								fprintf(write_fp,"lw $t1 4($sp)\n");
								fprintf(write_fp,"addiu $sp $sp 4\n");
								fprintf(write_fp,"sub $a0 $t1 $a0\n");

								string newlab1 = generate_new_label();
								cout<<"lb1"<<newlab1<<endl;
								string newlab2 = generate_new_label();
								cout<<"lb2"<<newlab2<<endl;
								

								fprintf(write_fp, "bgtz $a0 %s\n", newlab1.c_str() );
								fprintf(write_fp, "li $a0 0\n" );
								fprintf(write_fp, "b %s\n",newlab2 .c_str() );
								fprintf(write_fp, "%s:",newlab1.c_str() );
								fprintf(write_fp, "li $a0 1\n" );
								fprintf(write_fp, "%s:",newlab2 .c_str() );

								chk=check_variable($1);
								
								fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk - 4);
										
							}
							else if(strcmp($4,"<")==0)
							{
								
								int chk=check_variable($3);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$3);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}

								
								fprintf(write_fp,"sw $a0 0($sp)\n");
								fprintf(write_fp,"addiu $sp $sp -4\n");


								chk=check_variable($5);
								if(chk==-1)
								{
									
									
									fprintf(write_fp,"li $a0 %s\n",$5);
								}
								else
								{
									fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk - 4);
								}
								fprintf(write_fp,"lw $t1 4($sp)\n");
								fprintf(write_fp,"addiu $sp $sp 4\n");
								fprintf(write_fp,"sub $a0 $a0 $t1\n");

								string newlab1 = generate_new_label();
								cout<<"lb1"<<newlab1<<endl;
								string newlab2 = generate_new_label();

								cout<<"lb2"<<newlab2<<endl;

								fprintf(write_fp, "bgtz $a0 %s\n", newlab1.c_str() );
								fprintf(write_fp, "li $a0 0\n" );
								fprintf(write_fp, "b %s\n",newlab2.c_str() );
								fprintf(write_fp, "%s:",newlab1.c_str() );
								fprintf(write_fp, "li $a0 1\n" );
								fprintf(write_fp, "%s:",newlab2.c_str() );
								chk=check_variable($1);
								
								fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk - 4);
										
							}
					}

bin_operator : BIN_OPERATOR
				{
					$$ = strdup(yytext);
				}
id_number   : identifier
				{
					$$=$1;
				}
			| number
				{
					$$=$1;
				}
assign_expression :identifier EQUALS identifier 
				{
					int chk = check_variable($3);
					fprintf(write_fp,"lw $a0 %d($t0)\n",4*chk-4);
					chk = check_variable($1);
					fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk-4);
				}
			| identifier EQUALS number 	{
										int chk = check_variable($1);
										fprintf(write_fp,"li $a0 %s\n",$3);

										fprintf(write_fp,"sw $a0 %d($t0)\n",4*chk-4);
										
									}

label  : LABEL 
				{
					$$ = strdup(yytext);
				}	
	
%%
string generate_new_label()
{
	string newlab = "_lbl";
	stringstream ss;
	ss<<label_counter;
	label_counter=label_counter +1;
	cout<<label_counter<<endl;
	
	return newlab+ss.str();
}

int check_variable(char *x)
{
	int p=-1;
	
	
	string Str(x);

	if(variable_store.find(Str)!=variable_store.end())
	{	
		
		return variable_store[Str];
	}
	else 
	{
		return p;
	}

}
int main()
{
		read_fp=fopen("new.txt","r");
		int chk=1;
		 ssize_t read_str;
		char *lin = NULL;
		size_t lengt;

		char arr[1000];
	/*	while ((read_str = getline(&lin, &lengt, read_fp)) != -1)
		{
				string Str1 = std::string(lin);
				if(variable_store.find(Str1)==variable_store.end())
				{
					variable_store[Str1]=chk++;
				}
		}*/

		while(fscanf(read_fp,"%s",arr)!=EOF)
		{
			string Str2(arr);
			if(variable_store.find(Str2)==variable_store.end())
			{
				variable_store[Str2]=chk++;
			}
		}
	
		fclose(read_fp);
		write_fp=fopen("output.s","w");
		

		
		fprintf(write_fp,"main:\n");
		fprintf(write_fp,"move $t0 $sp\n");
		fprintf(write_fp,"addiu $sp $sp %d\n",-4*chk );
		yyparse ();
		fprintf(write_fp,"jr $ra\n" );
		fclose(read_fp);

		return 0;
}
void yyerror (string s_holder) {printf("Error in line: %d, text: %s_holder \n", mylineno, yytext);}