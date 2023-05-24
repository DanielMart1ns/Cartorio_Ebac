#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca de trabalho com strings

int registro();
int consulta(); // M�todo de prot�tipo de fun��es (Os comandos das fun��es ficam ap�s o main)
int deletar();

int main () 
{
	int opcao = 0; // Definindo a vari�vel
	int laco = 1;
	int resposta;
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("\t### BEM-VINDO(A)! ### \n\n");
	
	do
	{
		printf("Selecione a op��o desejada:\n");
		printf("[1] Acessar ao MENU EBAC\n");
		printf("[0] Sair\n\n");
		
		printf("Insira a op��o desejada: ");
		scanf("%d", &resposta);
		
		printf("\n\n");
	
		if (resposta == 1)
		{
			system("cls");
	
			printf("\t### MENU EBAC ### \n\n"); // �nicio do menu
	
			printf("Insira a op��o desejada: \n\n");
	
			printf("\t 1- Registrar Nomes \n");
			printf("\t 2- Consultar Nomes \n");
			printf("\t 3- Deletar Nomes \n\n"); // Fim do menu
	
			printf("Selecione a op��o desejada: ");
			scanf("%d", &opcao); // Armazenando a escolha do usu�rio
			system("cls"); // Clean screen
		
				switch (opcao)
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
				
					default:
					printf("Escolha inv�lida. \n\n");
					system("pause");
					break;
				}
	
		}
	}while (resposta == 1);
	
	printf("Saindo...\n\n");
}

// ===================================================================================================

	int registro() //Fun��o respons�vel por cadastrar os usu�rios
	{
		setlocale (LC_ALL, "Portuguese");
		// Inicio da cria��o de vari�veis/strings na fun��o
		char arquivo [40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		int resp;
		//Final da cria��o de vari�veis
		
	do 
	{
		system("cls"); //Limpa a tela sempre que for incluir mais dados
		printf("Insira o CPF a ser cadastrado: "); //Coletando informa��o do user
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); // destino, origem (Neste caso a variavel arquivo recebe cpf)
		
		FILE *file; //cria o arquivo
		
		//CPF
		file = fopen(arquivo, "w"); //cria o arquivo "w" siginifica que estos criando
		fprintf(file, "CPF: "); // Titulo antes da inser��o do dado "cpf"
		fprintf(file, cpf); //escreve o valor do CPF no banco de dados (somente)
		fprintf(file, "\n"); // Pula uma linha
		fclose(file);//fecha o arquivo
		
		//NOME
		printf("Digite o primeiro nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo,"a"); // "a" siginifica que vamos inserir informa��es no arquivo, j� que ele j� foi criado no comando anterior
		fprintf(file, "Nome: ");
		fprintf(file, nome);
		fprintf(file," "); // Inseri um espa�o para que o sobrenome aparece ao lado do nome
		fclose(file);
		
		//SOBRENOME
		printf("Digite o sobrenome: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file, sobrenome); //Neste caso n�o inclui o titulo "sobrenome" pois ele j� ser� inserido ao lado do nome
		fprintf(file, "\n");
		fclose(file);
		
		//CARGO
		printf("Insira o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, "Cargo: ");
		fprintf(file, cargo);
		fprintf(file, "\n");
		fclose(file);
		
		
		printf("\n\t===== Usu�rio Cadastrado com Sucesso! =====\n\n");
		
		system("pause");
		system("cls");
		
		printf("Deseja REGISTRAR mais usu�rios? [1]Sim [0]N�o");
		printf("\nInsira a sua resposta: ");
		scanf("%d", &resp); // Recebe o dado condicional, se o usu�rio deseja incluir mais dados ou n�o.
		printf("\n\n");
		
	} while (resp == 1); // Repita todo este comando ENQUANTO a "resp" == 1, sendo possivel a inser��o de mais dados sem voltar ao menu.
		
		printf("------------------------------------\n"); // Est�tica
		system("pause");
		system("cls");
	}
	
// ===================================================================================================
	
	int consulta() // Fun��o respons�vel por consultar usu�rios j� cadastrados
	{
		setlocale (LC_ALL, "Portuguese");
		
		char cpf [40];
		char conteudo [200];
		int resp;
		
	do
	{
		system("cls");
		printf("Insira o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file; 
		file = fopen(cpf, "r"); // "r" de read
		
		printf("\n\n \t===== Dados Encontrados =====\n\n");
		
		if (file == NULL) // Se n�o encontrar fa�a
		{
			printf("* Usu�rio n�o localizado! *");
		}	
		
		while (fgets(conteudo, 200, file) != NULL) // Enquanto a condi��o for DIFERENTE de nulo o "conteudo" recebe os dados do file
		{
			printf("%s", conteudo); // Se encotrar os dados, o sistema vai mostrar o conte�do do usu�rio
		}
		fclose(file); // Logo ap�s, fecha o arquivo cpf.
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		printf("Deseja CONSULTAR mais usu�rios? [1]Sim [0]N�o");
		printf("\nInsira a sua resposta: ");
		scanf("%d", &resp); // Recebe o dado condicional, se o usu�rio deseja consultar mais dados ou n�o.
		printf("\n\n");
		
	}while (resp == 1); // Repete-se o ciclo ENQUANTO "resp" == 1
	
		printf("------------------------------------\n"); // Est�tica
		system("pause");
		system("cls");
	}
	
// ===================================================================================================
	
	int deletar() // Fun��o respons�vel por deletar dados
	{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf [40];
		char conteudo [200];
		int confirm, resp;
		
		
	do
	{
		system("cls");
		printf("Insira o CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r"); // Vai abrir o arquivo correspondente e vai "l�-lo".
		
		printf("\n\n\t DADOS DO USU�RIO \n\n");
		
		if (file == NULL) // Se o usu�rio n�o existir no meu sistema
		{
			printf("* Usu�rio n�o cadastradado *\n\n");
		}
		
		if (file != NULL) //Se o usu�rio existir
		{
			while (fgets(conteudo, 200, file) != NULL) // Enquanto a condi��o for DIFERENTE de nulo o "conteudo" recebe os dados do file
			{
				printf("%s", conteudo); // Mostra o conte�do do usu�rio
			}
			
			
			
			fclose(file); //Fecha arquivo
			printf("\n\nDeseja excluir os dados acima [1] Sim [0] N�o?\n");
			printf("Insira sua resposta: "); // Confirma��o de exclus�o de dados ap�s sua verifica��o mostrada pelo sistema acima
			scanf("%d", &confirm); 
			
			if (confirm == 1) // SE "confirm" == 1 deleta-se os dados
			{
				remove(cpf); // comando de exclus�o de dados
				printf("\n\n\t===== Usu�rio Deletado com Sucesso! =====");
			}	
		}
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		printf("\nDeseja DELETAR mais usu�rios? [1]Sim [0]N�o");
		printf("\nInsira a sua resposta: ");
		scanf("%d", &resp); // Recebe o dado condicional, se o usu�rio deseja deletar mais dados ou n�o.
		printf("\n\n");
		
	}while (resp == 1);
		printf("------------------------------------\n"); // Est�tica
		system("pause");
		system("cls");
	}
