#include <stdio.h> //biblioteca que se comunica com o usu�rio
#include <stdlib.h> //biblioteca respons�vel por aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int main () //Fun��o do menu principal
	{
	int opcao=0; //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
		{
	
		system("cls");//Limpar a tela
		
		setlocale (LC_ALL, "Portuguese"); //define a linguagem como portugu�s
	
		//O cabe�alho do menu
		printf ("### Cart�rio da EBAC ###\n\n");
		//Op��es do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes;\n");
		printf ("\t2 - Consultar nomes;\n");
		printf ("\t3 - Deletar nomes.\n");
		printf ("\t4 - Sair do Sistema.\n\n");
		printf ("Op��o:");//Fim do menu
	
		scanf("%d",&opcao); //Armazenando a escolha do usu�rio
	
		system("cls");
		
		
		switch(opcao) //Mesma coisa de if, mas simplifica o processo, inicio da sele��o de menu
		{
			case 1:
				registro(); //Estamos chamando a fun��o
				break;
			
			case 2:
				consulta(); //Estamos chamando a fun��o
				break;
			
			case 3:
				deletar(); //Estamos chamando a fun��o
				break;
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			
			default:
			printf("Essa op��o n�o existe!\n");
			system("pause");
			break;
		}
		}//Fim da sele��o
		
	}
	
int registro() //Fun��o de registro
{
	//Inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o de vari�veis/strings

	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o
	scanf("%s", cpf);// %S refere-se a strings
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
	
	//Cria o arquivo no banco de dados dentro do computador
	FILE *file;
	file = fopen(arquivo, "W");
	// Salva o valor da vari�vel no arquivo
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

int consulta() //Fun��o de consulta
{
	
	setlocale (LC_ALL, "Portuguese"); //Define a linguagem como portugu�s
	
	char cpf[40];
	char conteudo[200]; //Criamos o conteudo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);	
	
	FILE *file;
	file = fopen(cpf,"r"); //R de read
	
	if(file== NULL) //Caso o arquivo n�o exista
	{
		printf("N�o foi poss�vel localizar o arquivo!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //Caso exista
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo); //Imprime o conteudo na tela
		printf("\n\n");
	}
	
	system("pause"); //Sempre pausar
}

int deletar() //Fun��o de deletar
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf); //Scaneia os arquivos de string
	
	remove(cpf);

	FILE *file;
	file = fopen(cpf,"r"); //fopen para abrir arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar o usu�rio no sistema!\n");// printf imprime a mensagem
		system ("pause");
	}
	
	while(fgets(cpf, 40, file) !=NULL) //Caso exista
	{
		printf("\nEssas usu�rio foi deletado com sucesso:");
		printf("%s", cpf); //Imprime o conteudo na tela
		printf("\n\n");
	}
	
	system("pause");

}






















