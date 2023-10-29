#include <stdio.h> //biblioteca que se comunica com o usuário
#include <stdlib.h> //biblioteca responsável por alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int main () //Função do menu principal
	{
	int opcao=0; //Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
		{
	
		system("cls");//Limpar a tela
		
		setlocale (LC_ALL, "Portuguese"); //define a linguagem como português
	
		//O cabeçalho do menu
		printf ("### Cartório da EBAC ###\n\n");
		//Opções do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes;\n");
		printf ("\t2 - Consultar nomes;\n");
		printf ("\t3 - Deletar nomes.\n");
		printf ("\t4 - Sair do Sistema.\n\n");
		printf ("Opção:");//Fim do menu
	
		scanf("%d",&opcao); //Armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao) //Mesma coisa de if, mas simplifica o processo, inicio da seleção de menu
		{
			case 1:
				registro(); //Estamos chamando a função
				break;
			
			case 2:
				consulta(); //Estamos chamando a função
				break;
			
			case 3:
				deletar(); //Estamos chamando a função
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			
			default:
			printf("Essa opção não existe!\n");
			system("pause");
			break;
		}
		}//Fim da seleção
		
	}
	
int registro() //Função de registro
{
	//Inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings

	printf("Digite o CPF a ser cadastrado: ");//Coletando informação
	scanf("%s", cpf);// %S refere-se a strings
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string
	
	//Cria o arquivo no banco de dados dentro do computador
	FILE *file;
	file = fopen(arquivo, "W");
	// Salva o valor da variável no arquivo
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta() //Função de consulta
{
	
	setlocale (LC_ALL, "Portuguese"); //Define a linguagem como português
	
	char cpf[40];
	char conteudo[200]; //Criamos o conteudo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);	
	
	FILE *file;
	file = fopen(cpf,"r"); //R de read
	
	if(file== NULL) //Caso o arquivo não exista
	{
		printf("Não foi possível localizar o arquivo!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //Caso exista
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo); //Imprime o conteudo na tela
		printf("\n\n");
	}
	
	system("pause"); //Sempre pausar
}

int deletar() //Função de deletar
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf); //Scaneia os arquivos de string
	
	remove(cpf);

	FILE *file;
	file = fopen(cpf,"r"); //fopen para abrir arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o usuário no sistema!\n");// printf imprime a mensagem
		system ("pause");
	}
	
	while(fgets(cpf, 40, file) !=NULL) //Caso exista
	{
		printf("\nEssas usuário foi deletado com sucesso:");
		printf("%s", cpf); //Imprime o conteudo na tela
		printf("\n\n");
	}
	
	system("pause");

}






















