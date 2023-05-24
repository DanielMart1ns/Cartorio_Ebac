#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca de trabalho com strings

int registro();
int consulta(); // Método de protótipo de funções (Os comandos das funções ficam após o main)
int deletar();

int main () 
{
	int opcao = 0; // Definindo a variável
	int laco = 1;
	int resposta;
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("\t### BEM-VINDO(A)! ### \n\n");
	
	do
	{
		printf("Selecione a opção desejada:\n");
		printf("[1] Acessar ao MENU EBAC\n");
		printf("[0] Sair\n\n");
		
		printf("Insira a opção desejada: ");
		scanf("%d", &resposta);
		
		printf("\n\n");
	
		if (resposta == 1)
		{
			system("cls");
	
			printf("\t### MENU EBAC ### \n\n"); // Ínicio do menu
	
			printf("Insira a opção desejada: \n\n");
	
			printf("\t 1- Registrar Nomes \n");
			printf("\t 2- Consultar Nomes \n");
			printf("\t 3- Deletar Nomes \n\n"); // Fim do menu
	
			printf("Selecione a opção desejada: ");
			scanf("%d", &opcao); // Armazenando a escolha do usuário
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
					printf("Escolha inválida. \n\n");
					system("pause");
					break;
				}
	
		}
	}while (resposta == 1);
	
	printf("Saindo...\n\n");
}

// ===================================================================================================

	int registro() //Função responsável por cadastrar os usuários
	{
		setlocale (LC_ALL, "Portuguese");
		// Inicio da criação de variáveis/strings na função
		char arquivo [40];
		char cpf [40];
		char nome [40];
		char sobrenome [40];
		char cargo [40];
		int resp;
		//Final da criação de variáveis
		
	do 
	{
		system("cls"); //Limpa a tela sempre que for incluir mais dados
		printf("Insira o CPF a ser cadastrado: "); //Coletando informação do user
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); // destino, origem (Neste caso a variavel arquivo recebe cpf)
		
		FILE *file; //cria o arquivo
		
		//CPF
		file = fopen(arquivo, "w"); //cria o arquivo "w" siginifica que estos criando
		fprintf(file, "CPF: "); // Titulo antes da inserção do dado "cpf"
		fprintf(file, cpf); //escreve o valor do CPF no banco de dados (somente)
		fprintf(file, "\n"); // Pula uma linha
		fclose(file);//fecha o arquivo
		
		//NOME
		printf("Digite o primeiro nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo,"a"); // "a" siginifica que vamos inserir informações no arquivo, já que ele já foi criado no comando anterior
		fprintf(file, "Nome: ");
		fprintf(file, nome);
		fprintf(file," "); // Inseri um espaço para que o sobrenome aparece ao lado do nome
		fclose(file);
		
		//SOBRENOME
		printf("Digite o sobrenome: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file, sobrenome); //Neste caso não inclui o titulo "sobrenome" pois ele já será inserido ao lado do nome
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
		
		
		printf("\n\t===== Usuário Cadastrado com Sucesso! =====\n\n");
		
		system("pause");
		system("cls");
		
		printf("Deseja REGISTRAR mais usuários? [1]Sim [0]Não");
		printf("\nInsira a sua resposta: ");
		scanf("%d", &resp); // Recebe o dado condicional, se o usuário deseja incluir mais dados ou não.
		printf("\n\n");
		
	} while (resp == 1); // Repita todo este comando ENQUANTO a "resp" == 1, sendo possivel a inserção de mais dados sem voltar ao menu.
		
		printf("------------------------------------\n"); // Estética
		system("pause");
		system("cls");
	}
	
// ===================================================================================================
	
	int consulta() // Função responsável por consultar usuários já cadastrados
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
		
		if (file == NULL) // Se não encontrar faça
		{
			printf("* Usuário não localizado! *");
		}	
		
		while (fgets(conteudo, 200, file) != NULL) // Enquanto a condição for DIFERENTE de nulo o "conteudo" recebe os dados do file
		{
			printf("%s", conteudo); // Se encotrar os dados, o sistema vai mostrar o conteúdo do usuário
		}
		fclose(file); // Logo após, fecha o arquivo cpf.
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		printf("Deseja CONSULTAR mais usuários? [1]Sim [0]Não");
		printf("\nInsira a sua resposta: ");
		scanf("%d", &resp); // Recebe o dado condicional, se o usuário deseja consultar mais dados ou não.
		printf("\n\n");
		
	}while (resp == 1); // Repete-se o ciclo ENQUANTO "resp" == 1
	
		printf("------------------------------------\n"); // Estética
		system("pause");
		system("cls");
	}
	
// ===================================================================================================
	
	int deletar() // Função responsável por deletar dados
	{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf [40];
		char conteudo [200];
		int confirm, resp;
		
		
	do
	{
		system("cls");
		printf("Insira o CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r"); // Vai abrir o arquivo correspondente e vai "lê-lo".
		
		printf("\n\n\t DADOS DO USUÀRIO \n\n");
		
		if (file == NULL) // Se o usuário não existir no meu sistema
		{
			printf("* Usuário não cadastradado *\n\n");
		}
		
		if (file != NULL) //Se o usuário existir
		{
			while (fgets(conteudo, 200, file) != NULL) // Enquanto a condição for DIFERENTE de nulo o "conteudo" recebe os dados do file
			{
				printf("%s", conteudo); // Mostra o conteúdo do usuário
			}
			
			
			
			fclose(file); //Fecha arquivo
			printf("\n\nDeseja excluir os dados acima [1] Sim [0] Não?\n");
			printf("Insira sua resposta: "); // Confirmação de exclusão de dados após sua verificação mostrada pelo sistema acima
			scanf("%d", &confirm); 
			
			if (confirm == 1) // SE "confirm" == 1 deleta-se os dados
			{
				remove(cpf); // comando de exclusão de dados
				printf("\n\n\t===== Usuário Deletado com Sucesso! =====");
			}	
		}
		
		printf("\n\n");
		system("pause");
		system("cls");
		
		printf("\nDeseja DELETAR mais usuários? [1]Sim [0]Não");
		printf("\nInsira a sua resposta: ");
		scanf("%d", &resp); // Recebe o dado condicional, se o usuário deseja deletar mais dados ou não.
		printf("\n\n");
		
	}while (resp == 1);
		printf("------------------------------------\n"); // Estética
		system("pause");
		system("cls");
	}
