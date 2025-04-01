#include <stdio.h> //biblioteca de comunicação com usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

#define admin_user "admin"
#define adm_pass "adm"
#define file_name "usuarios.txt"
//O COMANDO #DEFINE, É UTILIZADO PARA SETAR UM NOME "PADRÃO" PARA VARIÁVEL DESEJADA.
//EXEMPLO: TODO LUGAR QUE ESTIVER file_name, será "usuarios.txt", INDEPENDENTE DE ONDE ESTIVER NO CODIGO
//POSSIBILITA A FACILIDADE DE MANUTENÇÃO NO CODIGO.



void login()//sistema de login do programa
{
	char login[50], senha[50], senhaarmazenada[50];
	
	
	printf("\t\t\tDigite seu login:\n\n");
	
	scanf("%s",login);//armazenando o login
	
	FILE*file = fopen(login, "r");//abrindo o arquivo
	if (file == NULL)
	{
		printf("\t\t\tUsuário não cadastrado!\n\n");
		return;
	}
	
	fscanf(file, "%*[^,], %s", senhaarmazenada);//Lê a senha armazenada no arquivo (ignora o login)
	fclose(file);
	
	
	printf("\t\t\tDigite sua senha:\n\n");
	scanf("%s",senha);//armazenando senha
	
	if(strcmp(senha, senhaarmazenada) == 0)//compara a senha digitada com armazenada
	{
		menu();
	}
	else
		printf("\t\t\tSenha incorreta!\n\n");
}

void cadastro()//sistema de criação de login do programa
{
	char adm[20];
	char arquivo[50];
	char login[50], senha[50];
	
	printf("Digite a senha do administrador para realizar um novo cadastro:\n\n");
	scanf("%s", adm);
	
	if(strcmp(adm, adm_pass) ==0)//compara a senha digitada com a definida em #define
	{
		
		printf("\t\t\tDigite seu login a ser cadastrato:\n\n");
		scanf("%s", &login);
	
		FILE*file = fopen(login, "r");
		if (file != NULL)
		{
			printf("\t\t\tLogin já cadastrato!\n\n");
			fclose(file);
			return;
		}

		printf("\t\t\tDigite sua senha:\n\n");
		scanf("%s", &senha);
	
		strcpy(arquivo, login);//criando o arquivo para armazenar o login e senha
		file = fopen(arquivo, "w");
		fprintf(file, "%s, %s", login, senha);
		fclose(file);
	
		printf("\t\t\tLogin cadastrato com sucesso!\n\n");
		system("pause");
	}
	else
		printf("\t\t\tSenha incorreta!\n\n");
	
}

int registro()//função para cadastrar usuário
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char escolha;
	
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
	system("timeout 1");// aguarda o tempo para liberar o arquivo
	
	printf("\n\n");
	printf("\tCadastro realizado com sucesso!\n\n");
	
	system("pause");
	
	system("cls");
	
	printf("\tDeseja realizar mais algum cadastro?\n\n (1)SIM \n (2)NÃO \n\n");
	scanf("%d",&escolha);//capturar a resposta
	
	system("cls");
	
		switch (escolha)
		{
			case 1:
				registro();
				break;
			
			case 2:
				printf("\tSaindo do sistema...\n\n");
				return 0;
				break;
				
		}
	
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
	fclose(file);
	system("pause");
	
}


void atualizar() // Função para atualizar dados dos usuários
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40], nome[40], sobrenome[40], cargo[40];
    char novocpf[40], cpf_original[40]; // CPF original para referência
    int opcao;

    printf("\t\t\tDigite o CPF que deseja alterar:\n\n");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r"); // Conferindo se o CPF está cadastrado
    if (file == NULL)
    {
        printf("\tCPF não encontrado!\n\n");
        system("pause");
        return;
    }

    // Lendo os dados do arquivo
    fscanf(file, "%[^,],%[^,],%[^,],%s", cpf, nome, sobrenome, cargo);
    fclose(file);

    // Salvamos o CPF original antes de qualquer alteração
    strcpy(cpf_original, cpf);

    printf("\tInformações atuais:\n\n");
    printf("1 - CPF: %s\n", cpf);
    printf("2 - Nome: %s\n", nome);
    printf("3 - Sobrenome: %s\n", sobrenome);
    printf("4 - Cargo: %s\n\n", cargo);
    printf("Digite o número de qual informação deseja alterar: ");
    scanf("%d", &opcao);

    // Escolhendo a opção de alteração
    if (opcao == 1)
    {
        printf("Digite o novo CPF: ");
        scanf("%s", novocpf);

        // Verifica se o novo CPF já existe
        FILE *teste = fopen(novocpf, "r");
        if (teste != NULL)
        {
            printf("\tCPF já cadastrado!\n\n");
            fclose(teste);
            return;
        }

        // Copia o novo CPF para a variável CPF
        strcpy(cpf, novocpf);
    }
    else if (opcao == 2)
    {
        printf("Digite o novo nome: ");
        scanf("%s", nome);
    }
    else if (opcao == 3)
    {
        printf("Digite o novo sobrenome: ");
        scanf("%s", sobrenome);
    }
    else if (opcao == 4)
    {
        printf("Digite o novo cargo: ");
        scanf("%s", cargo);
    }
    else
    {
        printf("\tOpção inválida!\n\n");
        return;
    }

    // Criamos um novo arquivo com o nome do CPF atualizado
    file = fopen(cpf, "w");
    if (file == NULL)
    {
        printf("\t\t\tErro ao abrir o arquivo\n\n");
        return;
    }

    fprintf(file, "%s,%s,%s,%s", cpf, nome, sobrenome, cargo);
    fclose(file);

    // **Agora** podemos excluir o arquivo antigo (se o CPF foi alterado)
    if (opcao == 1)
    {
        remove(cpf_original);
    }

    printf("\t\t\tInformações atualizadas com sucesso!\n\n");
    system("pause");

    menu();
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


int menu()// MENU DO SISTEMA
{
	int opcao=0;//declarando a variável
	int x=1;
	
	for(x=1;x=1;)
	{
			
		system("cls");//responsavel para limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//utilizado para setar a linguaguem e ativar os acentos
	
				
		printf("\t\t\t***CARTÓRIO EBAC*** \n");//comando "\t é para dar espaço antes de iniciar o texto
		printf("\tSeja bem vindo ao sistema de cadastro de alunos\n\n");
		printf("Escolha a opção desejada no menu: \n \n");//comando \n é para dar parágrafo
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Atualizar dados \n");
		printf("\t4 - Deletar nomes \n");
		printf("\t5 - Sair\n\n\n");
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
				atualizar();
				break;
			case 4:
				deletar();
				break;
			case 5:
				printf("\tVocê escolheu sair\n\n");
				system("pause");
				exit(0);
				break;
			default:
				printf("\tEssa opção não está disponível\n\n");
				system("pause");
				break;
		}
		
	}
	
	return 0;
	
}

int main()//função principal, a primeira de todas
{
	
	int opcao=0;//declarando a variavel
	int x =1;

	while(1)
		{
			system("cls");//limpando a tela do sistema
			
			setlocale(LC_ALL, "Portuguese");//habilitando a linguagem portugues e acentos
			
			printf("\t\t\t***CARTÓRIO EBAC***\n");
			printf("\tBem vindo ao sistema de cadastro de alunos da Ebac!\n");
			printf("\tFaça login para acessar o sistema ou cadastre-se.\n");
			printf("\tDigite sua opção:\n\n1 - Fazer login\n2 - Cadastrar-se\n3 - Sair\n\n");
			
			scanf("%d", &opcao);//armazenando a escolha do cliente
			
			system("cls");//limpando tela
			
			switch(opcao)
				{
					case 1:
						login();
						break;
					case 2:
						cadastro();
						break;
					case 3:
						exit(0);
						break;
					default:
						printf("\t\t\tOpção inválida!\n\t\t\tTente novamente.\n\n");
				}
			system("pause");
		}
	return 0;
}
