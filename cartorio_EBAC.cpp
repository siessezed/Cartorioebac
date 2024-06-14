#include<stdio.h>//biblioteca de comunicação com o usuário
#include<stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de locação de texto de acordo com a região
#include <string.h>//biblioteca responsável por cuidar das strings

int registrar() //função responsável pelo registro do usuário no sistema
{
	//início da criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	// fim da criação de variáveis/string
	
	printf("\tDigite o CPF a ser cadastrado:\n "); //coletando informação "CPF" do usuário
	scanf ("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //abre o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar
	fprintf(file, " - "); //adiciona o caracter "-" ao arquivo com propósito de organizar as informações
	fclose(file);//fecha o arquivo
	
	printf("\tDigite o nome a ser cadastrado:\n "); //coletando informação "nome" do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizá-lo
	fprintf(file, nome); //salva o valor da variável "nome" obtido do usuário no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizá-lo
	fprintf(file, " - "); //adiciona o caracter "-" ao arquivo
	fclose(file); //fecha o arquivo
	
	printf("\tDigite o sobrenome a ser cadastrado:\n "); //coletando informação "sobrenome" do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizá-lo
	fprintf(file, sobrenome); //salva a variável "sobrenome" obtida do usuário ao arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizá-lo
	fprintf(file, " - "); //adiciona o caracter "-" ao arquivo
	fclose(file); //fecha o arquvio
	
	printf("\tDigite o cargo a ser cadastrado:\n "); //coletando informação "cargo" do usuário
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizá-lo
	fprintf(file, cargo); //salva a variável "cargo" obtida do usuário ao arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consultar() //função responsável pela consulta de usuários já cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//início da criação de variáveis/string
	char cpf [40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("\tDigite o CPF a ser consultado:\n "); //informando-se qual usuário será consultado por meio da variável "cpf"
	scanf("%s",cpf);
	FILE *file; //busca o arquivo no banco de dados
	file = fopen(cpf, "r"); //busca o valor da variável informado pelo usuário
	
	if(file == NULL) //caso o valor da variável informado não seja encontrado
	{
		system("cls");
		printf("\tO CPF não foi encontrado.");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //caso o valor da variável informado seja encontrado
	{
		printf("\nInformações do usuário:\n");
		printf("%s", conteudo); //expõe as informações do usuário solicitado
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //função responsável por deletar usuários do sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//início da criação de variáveis/string
	char cpf[40];
	//final da criação de variáveis/string
	
	printf("\tDigite o CPF a ser deletado:\n\n"); //informando-se qual usuário será deletado por meio da variável "cpf
	scanf("%s", cpf);
	
	remove(cpf); //apaga o valor da variável no banco de dados
	
	FILE *file; //busca o arquivo no banco de dados
	file = fopen(cpf,"r"); //busca o valor da variável informado pelo usuário
	
	if(file == NULL) //caso o valor da variável informado não seja encontrado
	{
		system("cls");
		printf("\tO CPF informado não existe no sistema.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)//configurando repetição
	{
        system ("cls");	//apgar tela após repetição
		
    	setlocale(LC_ALL, "Portuguese");//definindo a linguagem usada 
        printf("\t    -- O que deseja fazer? --\n\n");//mostrando as opções do programa
    	printf("\t      1. - Registrar nomes\n");//opção 1 
    	printf("\t      2. - Consultar nomes\n");//opção 2 
    	printf("\t       3. - Deletar nomes\n");//opção 3 e fim do menu
    	printf("\t      4. - Sair do sistema\n\n");
	
    	printf("  Digite o número correspondente ao serviço desejado.\n\n");//instrução de escolha de opção
    	scanf("%d", &opcao);//armazenar escolha do usuário
	
    	system ("cls");//apagar tela anterior
    	
    	
    		switch(opcao) //início da seleção do menu
		{
			case 1:
			registrar(); //chamada de função "registro"
			break;
			
			case 2:
			consultar(); //chamda de função "consultar"
    		break;
    		
    		case 3:
    		deletar(); //chamada de função "deletar"
    		break;
    		
    		case 4:
    		printf("\t Obrigado por utilizar o sistema.\n");
    		return 0;
    		break;
    		
    		default: //caso o usuário escolha uma opção diferentes das apresentadas
    		printf(" Essa opção não está disponível.\n\n");
    		system ("pause");
    		break;//final da seleção
    		
		}    
   	}
}
