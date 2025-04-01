#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings

#define admin_user "admin"
#define adm_pass "adm"
#define file_name "usuarios.txt"
//O COMANDO #DEFINE, � UTILIZADO PARA SETAR UM NOME "PADR�O" PARA VARI�VEL DESEJADA.
//EXEMPLO: TODO LUGAR QUE ESTIVER file_name, ser� "usuarios.txt", INDEPENDENTE DE ONDE ESTIVER NO CODIGO
//POSSIBILITA A FACILIDADE DE MANUTEN��O NO CODIGO.



void login()//sistema de login do programa
{
	char login[50], senha[50], senhaarmazenada[50];
	
	
	printf("\t\t\tDigite seu login:\n\n");
	
	scanf("%s",login);//armazenando o login
	
	FILE*file = fopen(login, "r");//abrindo o arquivo
	if (file == NULL)
	{
		printf("\t\t\tUsu�rio n�o cadastrado!\n\n");
		return;
	}
	
	fscanf(file, "%*[^,], %s", senhaarmazenada);//L� a senha armazenada no arquivo (ignora o login)
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

void cadastro()//sistema de cria��o de login do programa
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
			printf("\t\t\tLogin j� cadastrato!\n\n");
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

int registro()//fun��o para cadastrar usu�rio
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char escolha;
	
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
	system("timeout 1");// aguarda o tempo para liberar o arquivo
	
	printf("\n\n");
	printf("\tCadastro realizado com sucesso!\n\n");
	
	system("pause");
	
	system("cls");
	
	printf("\tDeseja realizar mais algum cadastro?\n\n (1)SIM \n (2)N�O \n\n");
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
	fclose(file);
	system("pause");
	
}


void atualizar() // Fun��o para atualizar dados dos usu�rios
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40], nome[40], sobrenome[40], cargo[40];
    char novocpf[40], cpf_original[40]; // CPF original para refer�ncia
    int opcao;

    printf("\t\t\tDigite o CPF que deseja alterar:\n\n");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r"); // Conferindo se o CPF est� cadastrado
    if (file == NULL)
    {
        printf("\tCPF n�o encontrado!\n\n");
        system("pause");
        return;
    }

    // Lendo os dados do arquivo
    fscanf(file, "%[^,],%[^,],%[^,],%s", cpf, nome, sobrenome, cargo);
    fclose(file);

    // Salvamos o CPF original antes de qualquer altera��o
    strcpy(cpf_original, cpf);

    printf("\tInforma��es atuais:\n\n");
    printf("1 - CPF: %s\n", cpf);
    printf("2 - Nome: %s\n", nome);
    printf("3 - Sobrenome: %s\n", sobrenome);
    printf("4 - Cargo: %s\n\n", cargo);
    printf("Digite o n�mero de qual informa��o deseja alterar: ");
    scanf("%d", &opcao);

    // Escolhendo a op��o de altera��o
    if (opcao == 1)
    {
        printf("Digite o novo CPF: ");
        scanf("%s", novocpf);

        // Verifica se o novo CPF j� existe
        FILE *teste = fopen(novocpf, "r");
        if (teste != NULL)
        {
            printf("\tCPF j� cadastrado!\n\n");
            fclose(teste);
            return;
        }

        // Copia o novo CPF para a vari�vel CPF
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
        printf("\tOp��o inv�lida!\n\n");
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

    printf("\t\t\tInforma��es atualizadas com sucesso!\n\n");
    system("pause");

    menu();
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


int menu()// MENU DO SISTEMA
{
	int opcao=0;//declarando a vari�vel
	int x=1;
	
	for(x=1;x=1;)
	{
			
		system("cls");//responsavel para limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//utilizado para setar a linguaguem e ativar os acentos
	
				
		printf("\t\t\t***CART�RIO EBAC*** \n");//comando "\t � para dar espa�o antes de iniciar o texto
		printf("\tSeja bem vindo ao sistema de cadastro de alunos\n\n");
		printf("Escolha a op��o desejada no menu: \n \n");//comando \n � para dar par�grafo
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Atualizar dados \n");
		printf("\t4 - Deletar nomes \n");
		printf("\t5 - Sair\n\n\n");
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
				atualizar();
				break;
			case 4:
				deletar();
				break;
			case 5:
				printf("\tVoc� escolheu sair\n\n");
				system("pause");
				exit(0);
				break;
			default:
				printf("\tEssa op��o n�o est� dispon�vel\n\n");
				system("pause");
				break;
		}
		
	}
	
	return 0;
	
}

int main()//fun��o principal, a primeira de todas
{
	
	int opcao=0;//declarando a variavel
	int x =1;

	while(1)
		{
			system("cls");//limpando a tela do sistema
			
			setlocale(LC_ALL, "Portuguese");//habilitando a linguagem portugues e acentos
			
			printf("\t\t\t***CART�RIO EBAC***\n");
			printf("\tBem vindo ao sistema de cadastro de alunos da Ebac!\n");
			printf("\tFa�a login para acessar o sistema ou cadastre-se.\n");
			printf("\tDigite sua op��o:\n\n1 - Fazer login\n2 - Cadastrar-se\n3 - Sair\n\n");
			
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
						printf("\t\t\tOp��o inv�lida!\n\t\t\tTente novamente.\n\n");
				}
			system("pause");
		}
	return 0;
}
