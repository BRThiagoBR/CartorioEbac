#include <stdio.h> //biblioteca de comunicação com usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings


int registro()//função para cadastrar usuário
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\tDigite o CPF a ser cadastrado\n\n");//coletar informação do usuário
	scanf("%s",cpf);//%s refere=se a string
	
	FILE *file = fopen(cpf, "r");//primeiro vamos ler o arquivo
	
	if (file != NULL)// verificar se já tem o cpf cadastrado
	{
		printf("\tEste CPF já está cadastrado!\n\n");
		fclose(file);
		system("pause");
		return;
	}
	fclose(file);
	
	strcpy(arquivo,cpf);//responsável por copiar os valores da string
	
	
	file = fopen(arquivo, "w");// a letra "W" é para criar o arquivo
	fprintf(file,cpf);
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//letra "A" é para atualizar o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("\tDigite o nome a ser cadastrado\n\n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//letra "A" é para atualizar o arquivo
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
	
	fflush(NULL);//força a sincronização do sistema operacional
	system("timeout 5");// aguarda o tempo para liberar o arquivo
	
	printf("\n\n");
	printf("\tCadastro realizado com sucesso!\n\n");
	
	system("pause");
	
	}

int consulta()//função para consultar usuario usuário
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("\tDigite o CPF a ser consultado\n\n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//lendo o arquivo cpf "R" para ler 
	
	if(file == NULL)//SE não achar o cpf cadastrado
	{
		printf("\tCPF não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//ler o arquivo enquanto tiver informação
	{
		printf("\tEssas são as informações\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()//função para deletar usuário
{
	char cpf[40];
	
	printf("\tDigite o CPF do usuário a ser deletado: \n");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\tCPF não encontrado!\n");
		system("pause");
		return;
	}
	
	fclose(file);
	
	if (remove(cpf) ==0)
	{
		printf("\tUsuário deletado com sucesso!\n");
	}
	else
	{
		perror("\tErro ao deletar usuário\n");
	}
	system("pause");
	return;
	
}


int main()//função principal "MENU"
	{
	int opcao=0;//declarando a variável
	int x=1;
	
	for(x=1;x=1;)
	{
			
		system("cls");//responsavel para limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//utilizado para setar a linguaguem e ativar os acentos
	
				
		printf("\tCARTÓRIO EBAC \n \n");//comando "\t é para dar espaço antes de iniciar o texto
		printf("Escolha a opção desejada no menu: \n \n");//comando \n é para dar parágrafo
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair\n\n\n");
		printf("Opção: ");

		scanf("%d", &opcao);// armazenando a escolha do usuário

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
				printf("\tVocê escolheu sair\n\n");
				system("pause");
				return 0;
				break;
			default:
				printf("\tEssa opção não está disponível\n\n");
				system("pause");
				break;
		}
		
	}
	
	return 0;
	
}
