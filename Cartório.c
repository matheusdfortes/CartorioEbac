#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca resposável por cuidar das strings

int registro() //função de registro de novos usuários
{
	char nome[40]; //definindo variáveis
	char sobreNome[40];
	char cpf[40];
	char cargo[40];
	char arquivo[40];
	int resposta = 1;
	
	while(resposta == 1){		
		printf("Digite o cpf a ser cadastrado: "); //cadastrando a variável cpf
		scanf("%s",cpf);
		
		strcpy(arquivo,cpf); //Copiando o valor da string
		
		FILE * file; // criando o arquivo
		file = fopen(arquivo,"w");
		fclose(file); // fechando o arquivo
		
		file = fopen(cpf,"a"); //atualizando o arquivo 
		fprintf(file,"CPF: ");
		fclose(file);
		
		file = fopen(cpf,"a"); //atualizando o arquivo com a varíavel cpf
		fprintf(file,cpf);
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo 
		fprintf(file," \n");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: "); //cadastrando a variável nome
		scanf("%s",nome);
		
		file = fopen(cpf,"a"); //atualizando o arquivo
		fprintf(file,"Nome: ");
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com a variável nome
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com um virgula
		fprintf(file," \n");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: "); //cadastrando a variável sobreNome
		scanf("%s",sobreNome);
		
		file = fopen(cpf,"a"); //atualizando o arquivo
		fprintf(file,"Sobrenome: ");
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com a variável sobreNome
		fprintf(file,sobreNome);
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com um virgula
		fprintf(file," \n");
		fclose(file);
		
		printf("Digite o cargo: "); //cadastrando a variável cargo
		scanf("%s",cargo);
		
		file = fopen(cpf,"a"); //atualizando o arquivo
		fprintf(file,"Cargo: ");
		fclose(file);
		
		file = fopen(arquivo,"a"); //atualizando o arquivo com a variável cargo
		fprintf(file,cargo);
		fclose(file);
		
		file = fopen(cpf,"a");
		fprintf(file,"\n");
		fclose(file);
		
		printf("\nDeseja inserir mais algum usuário ?\n");
		printf("1- Sim\n");
		printf("2- Não\n");
		scanf("%d",&resposta);
		printf("\n");
	} 
		
}

int consultar() //função de consultar usuários
{
	setlocale(LC_ALL, "portuguese"); //definindo o idioma
	
	char conteudo[200]; //definindo variáveis
	char cpf[40];
	
	printf("Digite o cpf a ser consultado: "); //definindo a variável cpf
	scanf("%s",cpf);
	
	FILE * file; //lendo o arquivo chamado cpf
	file = fopen(cpf,"r");
	
	if(file == NULL) //resposta caso o arquivo não exista
	{
		printf("O arquivo não foi localizado!\n");
	}
	
	else{
		printf("As informações do usuário são: \n\n");
		while(fgets(conteudo,200,file) != NULL){
			printf("%s",conteudo);
		}
	}
	printf("\n");
	system("pause");
}

int deletar() //função de deletar usuários
{
	char cpf[40]; //definindo variáveis
	char decisao[1];
	
	printf("Digite o cpf do usuário que você quer deletar: "); //definindo a variável cpf
	scanf("%s",cpf);
	
	FILE*file; //lendo o arquivo chamado cpf
	file = fopen(cpf,"r");
	
	if(file == NULL){ //resposta caso o usuário não exista
		printf("O usuário não foi encontrado no sistema !\n "); 
		fclose(file);
	}
	
	else{ //deletando o arquivo do usuário
		printf("o usuário foi deletado do sistema!\n");
		fclose(file);
		remove(cpf);
	}
	
	system("pause");		
}

int main() //menu principal
	{		
	int opcao=0;  //definindo variáveis
	int x=1;
	
	for(x=1;x=1;) //repetição do menu
	{
		system("cls"); //função de limpar a tela 
		
		setlocale(LC_ALL, "Portuguese"); //defindo a linguagem
	
		printf("\t### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");	
		printf("\t3 - Deletar nomes\n\n"); //fim do menu
		printf("Opção:");
	
		scanf("%d", &opcao); // armazenando a escolha
	
		system("cls");
		
		switch(opcao) // inicio da seleção
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
				printf("Essa opção não está disponível !\n");
				system("pause");
			break; //fim da seleção
		}
	}
	}

