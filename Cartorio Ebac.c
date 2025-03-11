#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings


int registro()//fun��o para cadastrar usu�rio
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\tDigite o CPF a ser cadastrado\n\n");//coletar informa��o do usu�rio
	scanf("%s",cpf);//%s refere=se a string
	
	FILE *file = fopen(cpf, "r");//primeiro vamos ler o arquivo
	
	if (file != NULL)// verificar se j� tem o cpf cadastrado
	{
		printf("\tEste CPF j� est� cadastrado!\n\n");
		fclose(file);
		system("pause");
		return;
	}
	fclose(file);
	
	strcpy(arquivo,cpf);//respons�vel por copiar os valores da string
	
	
	file = fopen(arquivo, "w");// a letra "W" � para criar o arquivo
	fprintf(file,cpf);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//letra "A" � para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o nome a ser cadastrado\n\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//letra "A" � para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o sobrenome a ser cadastrado\n\n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("\tDigite o cargo a ser cadastrado\n\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	fflush(NULL);//for�a a sincroniza��o do sistema operacional
	system("timeout 5");// aguarda o tempo para liberar o arquivo
	
	printf("\n\n");
	printf("\tCadastro realizado com sucesso!\n\n");
	
	system("pause");
	
	}

int consulta()//fun��o para consultar usuario usu�rio
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("\tDigite o CPF a ser consultado\n\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//lendo o arquivo cpf "R" para ler 
	
	if(file == NULL)//SE n�o achar o cpf cadastrado
	{
		printf("\tCPF n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//ler o arquivo enquanto tiver informa��o
	{
		printf("\tEssas s�o as informa��es\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()//fun��o para deletar usu�rio
{
	char cpf[40];
	
	printf("\tDigite o CPF do usu�rio a ser deletado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\tCPF n�o encontrado!\n");
		system("pause");
		return;
	}
	
	fclose(file);
	
	if (remove(cpf) ==0)
	{
		printf("\tUsu�rio deletado com sucesso!\n");
	}
	else
	{
		perror("\tErro ao deletar usu�rio\n");
	}
	system("pause");
	return;
	
}


int main()//fun��o principal "MENU"
	{
	int opcao=0;//declarando a vari�vel
	int x=1;
	
	for(x=1;x=1;)
	{
			
		system("cls");//responsavel para limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//utilizado para setar a linguaguem e ativar os acentos
	
				
		printf("\tCART�RIO EBAC \n \n");//comando "\t � para dar espa�o antes de iniciar o texto
		printf("Escolha a op��o desejada no menu: \n \n");//comando \n � para dar par�grafo
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair\n\n\n");
		printf("Op��o: ");

		scanf("%d", &opcao);// armazenando a escolha do usu�rio

		system("cls");
	
		switch(opcao)
		{
			case 1:
				registro();
				break;
			case 2:
				consulta();
				break;
			case 3:
				deletar();
				break;
			case 4:
				printf("\tVoc� escolheu sair\n\n");
				system("pause");
				return 0;
				break;
			default:
				printf("\tEssa op��o n�o est� dispon�vel\n\n");
				system("pause");
				break;
		}
		
	}
	
	return 0;
	
}
