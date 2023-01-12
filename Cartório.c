#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respos�vel por cuidar das strings

int registro() //fun��o de registro de novos usu�rios
{
	char nome[40]; //definindo vari�veis
	char sobreNome[40];
	char cpf[40];
	char cargo[40];
	char arquivo[40];
	int resposta = 1;
	
	while(resposta == 1){		
		printf("Digite o cpf a ser cadastrado: "); //cadastrando a vari�vel cpf
		scanf("%s",cpf);
		
		strcpy(arquivo,cpf); //Copiando o valor da string
		
		FILE * file; // criando o arquivo
		file = fopen(arquivo,"w");
		fclose(file); // fechando o arquivo
		
		file = fopen(cpf,"a"); //atualizando o arquivo 
		fprintf(file,"CPF: ");
		fclose(file);
		
		file = fopen(cpf,"a"); //atualizando o arquivo com a var�avel cpf
		fprintf(file,cpf);
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo 
		fprintf(file," \n");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: "); //cadastrando a vari�vel nome
		scanf("%s",nome);
		
		file = fopen(cpf,"a"); //atualizando o arquivo
		fprintf(file,"Nome: ");
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com a vari�vel nome
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com um virgula
		fprintf(file," \n");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: "); //cadastrando a vari�vel sobreNome
		scanf("%s",sobreNome);
		
		file = fopen(cpf,"a"); //atualizando o arquivo
		fprintf(file,"Sobrenome: ");
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com a vari�vel sobreNome
		fprintf(file,sobreNome);
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com um virgula
		fprintf(file," \n");
		fclose(file);
		
		printf("Digite o cargo: "); //cadastrando a vari�vel cargo
		scanf("%s",cargo);
		
		file = fopen(cpf,"a"); //atualizando o arquivo
		fprintf(file,"Cargo: ");
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com a vari�vel cargo
		fprintf(file,cargo);
		fclose(file);
		
		file = fopen(cpf,"a");
		fprintf(file,"\n");
		fclose(file);
		
		printf("\nDeseja inserir mais algum usu�rio ?\n");
		printf("1- Sim\n");
		printf("2- N�o\n");
		scanf("%d",&resposta);
		printf("\n");
	} 
		
}

int consultar() //fun��o de consultar usu�rios
{
	setlocale(LC_ALL, "portuguese"); //definindo o idioma
	
	char conteudo[200]; //definindo vari�veis
	char cpf[40];
	
	printf("Digite o cpf a ser consultado: "); //definindo a vari�vel cpf
	scanf("%s",cpf);
	
	FILE * file; //lendo o arquivo chamado cpf
	file = fopen(cpf,"r");
	
	if(file == NULL) //resposta caso o arquivo n�o exista
	{
		printf("O arquivo n�o foi localizado!\n");
	}
	
	else{
		printf("As informa��es do usu�rio s�o: \n\n");
		while(fgets(conteudo,200,file) != NULL){
			printf("%s",conteudo);
		}
	}
	printf("\n");
	system("pause");
}

int deletar() //fun��o de deletar usu�rios
{
	char cpf[40]; //definindo vari�veis
	char decisao[1];
	
	printf("Digite o cpf do usu�rio que voc� quer deletar: "); //definindo a vari�vel cpf
	scanf("%s",cpf);
	
	FILE*file; //lendo o arquivo chamado cpf
	file = fopen(cpf,"r");
	
	if(file == NULL){ //resposta caso o usu�rio n�o exista
		printf("O usu�rio n�o foi encontrado no sistema !\n "); 
		fclose(file);
	}
	
	else{ //deletando o arquivo do usu�rio
		printf("o usu�rio foi deletado do sistema!\n");
		fclose(file);
		remove(cpf);
	}
	
	system("pause");		
}

int main() //menu principal
	{		
	int opcao=0;  //definindo vari�veis
	int x=1;
	
	for(x=1;x=1;) //repeti��o do menu
	{
		system("cls"); //fun��o de limpar a tela 
		
		setlocale(LC_ALL, "Portuguese"); //defindo a linguagem
	
		printf("\t### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");	
		printf("\t3 - Deletar nomes\n\n"); //fim do menu
		printf("Op��o:");
	
		scanf("%d", &opcao); // armazenando a escolha
	
		system("cls");
		
		switch(opcao) // inicio da sele��o
		{
			case 1:
				registro();
			break;
			
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel !\n");
				system("pause");
			break; //fim da sele��o
		}
	}
	}

