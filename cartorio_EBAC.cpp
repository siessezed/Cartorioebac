#include<stdio.h>//biblioteca de comunica��o com o usu�rio
#include<stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de loca��o de texto de acordo com a regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings

int registrar() //fun��o respons�vel pelo registro do usu�rio no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	// fim da cria��o de vari�veis/string
	
	printf("\tDigite o CPF a ser cadastrado:\n "); //coletando informa��o "CPF" do usu�rio
	scanf ("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores das strings
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file, " - "); //adiciona o caracter "-" ao arquivo com prop�sito de organizar as informa��es
	fclose(file);//fecha o arquivo
	
	printf("\tDigite o nome a ser cadastrado:\n "); //coletando informa��o "nome" do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualiz�-lo
	fprintf(file, nome); //salva o valor da vari�vel "nome" obtido do usu�rio no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualiz�-lo
	fprintf(file, " - "); //adiciona o caracter "-" ao arquivo
	fclose(file); //fecha o arquivo
	
	printf("\tDigite o sobrenome a ser cadastrado:\n "); //coletando informa��o "sobrenome" do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualiz�-lo
	fprintf(file, sobrenome); //salva a vari�vel "sobrenome" obtida do usu�rio ao arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualiz�-lo
	fprintf(file, " - "); //adiciona o caracter "-" ao arquivo
	fclose(file); //fecha o arquvio
	
	printf("\tDigite o cargo a ser cadastrado:\n "); //coletando informa��o "cargo" do usu�rio
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualiz�-lo
	fprintf(file, cargo); //salva a vari�vel "cargo" obtida do usu�rio ao arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consultar() //fun��o respons�vel pela consulta de usu�rios j� cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//in�cio da cria��o de vari�veis/string
	char cpf [40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("\tDigite o CPF a ser consultado:\n "); //informando-se qual usu�rio ser� consultado por meio da vari�vel "cpf"
	scanf("%s",cpf);
	FILE *file; //busca o arquivo no banco de dados
	file = fopen(cpf, "r"); //busca o valor da vari�vel informado pelo usu�rio
	
	if(file == NULL) //caso o valor da vari�vel informado n�o seja encontrado
	{
		system("cls");
		printf("\tO CPF n�o foi encontrado.");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso o valor da vari�vel informado seja encontrado
	{
		printf("\nInforma��es do usu�rio:\n");
		printf("%s", conteudo); //exp�e as informa��es do usu�rio solicitado
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //fun��o respons�vel por deletar usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//in�cio da cria��o de vari�veis/string
	char cpf[40];
	//final da cria��o de vari�veis/string
	
	printf("\tDigite o CPF a ser deletado:\n\n"); //informando-se qual usu�rio ser� deletado por meio da vari�vel "cpf
	scanf("%s", cpf);
	
	remove(cpf); //apaga o valor da vari�vel no banco de dados
	
	FILE *file; //busca o arquivo no banco de dados
	file = fopen(cpf,"r"); //busca o valor da vari�vel informado pelo usu�rio
	
	if(file == NULL) //caso o valor da vari�vel informado n�o seja encontrado
	{
		system("cls");
		printf("\tO CPF informado n�o existe no sistema.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)//configurando repeti��o
	{
        system ("cls");	//apgar tela ap�s repeti��o
		
    	setlocale(LC_ALL, "Portuguese");//definindo a linguagem usada 
        printf("\t    -- O que deseja fazer? --\n\n");//mostrando as op��es do programa
    	printf("\t      1. - Registrar nomes\n");//op��o 1 
    	printf("\t      2. - Consultar nomes\n");//op��o 2 
    	printf("\t       3. - Deletar nomes\n");//op��o 3 e fim do menu
    	printf("\t      4. - Sair do sistema\n\n");
	
    	printf("  Digite o n�mero correspondente ao servi�o desejado.\n\n");//instru��o de escolha de op��o
    	scanf("%d", &opcao);//armazenar escolha do usu�rio
	
    	system ("cls");//apagar tela anterior
    	
    	
    		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registrar(); //chamada de fun��o "registro"
			break;
			
			case 2:
			consultar(); //chamda de fun��o "consultar"
    		break;
    		
    		case 3:
    		deletar(); //chamada de fun��o "deletar"
    		break;
    		
    		case 4:
    		printf("\t Obrigado por utilizar o sistema.\n");
    		return 0;
    		break;
    		
    		default: //caso o usu�rio escolha uma op��o diferentes das apresentadas
    		printf(" Essa op��o n�o est� dispon�vel.\n\n");
    		system ("pause");
    		break;//final da sele��o
    		
		}    
   	}
}
