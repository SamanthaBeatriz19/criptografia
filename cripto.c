#include <math.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

bool testar(int teste[],int tam){
	for(int i=0;i<tam;i++){
		if(teste[i]==0){
			return false;
		}
	}
	return true;	
}

bool existe(char palavra[], char frase[]){
	int teste[strlen(palavra)];
	int aux;	
	//nao ta contida se for maior 
	if(strlen(palavra) > strlen(frase)){
		return false;
	}
	if(strcmp(palavra,frase)){
		return true;
	}
	//vai comparando ate achar a primeira letra da palavra
	for(int a=0;a<strlen(frase)-strlen(palavra);a++){
		if(frase[a]==palavra[0]){
			for(int p=0; p<strlen(palavra);p++){
				teste[p]=0;
			}
			aux=a;
			for(int i=0;i<strlen(palavra);i++){
				if(palavra[i]==frase[aux]){
					teste[i]=1;
					aux++;
				}
			}
			if(testar(teste,strlen(palavra))){
				return true;
			}
		}
	}
	return false;
}

//MAIN COMECA AKI 
int main(){
	typedef struct {
	char agente[100];
	char id[5];
	char frase[100],cript[100];
	char depar[40];	
	}Frase;
	Frase salva[10];
	int escolha=5,cont=0;
	int i;
	while(escolha != 0){
		printf("****MENU DE CRIPTOGRAFIA****\n");
		printf("1: Criptografar mensagem\n");
		printf("2: Encontrar padroes\n");
		printf("3: Descriptografar mensagem\n");
		printf("4: Visualizar todas as mensagens\n");
		printf("0: Sair!\n");
		scanf("%d",&escolha);
		switch (escolha){
			case 1:{//OK - RODANDO
				printf("****ADICIONAR MENSAGEM****\n");
				//esse primeiro fgets é uma gambiarra pq ele ignora o primeiro n sei pq
				fgets(salva[cont].agente, 100, stdin);
				fflush(stdin);
				printf("Digite o nome do Agente:\n");
				fgets(salva[cont].agente, 40, stdin);
				printf("Digite o departamento:\n");
				fgets(salva[cont].depar, 40, stdin);
				fflush(stdin);
				printf("Digite a mensagem a ser criptografada:\n");
				fgets(salva[cont].frase, 100, stdin);
				printf("Digite o numero de identificacao do agente:\n");
				fgets(salva[cont].id, 5, stdin);
				char ajuda[100],fim[100];
				strcpy(ajuda, salva[cont].frase);
				i = 0;
				while(ajuda[i] != '\0'){
					if(ajuda[i] == 32){
						fim[i] = ajuda[i];					
					}else{					
						fim[i] = ajuda[i]+5;
						if((ajuda[i] + 5) > 90)
						{
						    fim[i] -=26;
						}
						if((ajuda[i] + 5) < 65)
						{
						    fim[i] += 26;
						}
						
					}
				    i++;
					
				}
				fim[i-1] = '\0';
				strcpy(salva[cont].cript,fim);
				cont++;
			break;		
			}
			case 2:{ //Ver se a palavra ja esta no sistema
				char palavra[40];
				char frase2[100];
				int qtd=0;
				printf("****ENCONTRAR PADROES****\n");
				printf("Digite o padrao a ser encontrado:\n");
				fgets(palavra, 40, stdin);
				fgets(palavra, 40, stdin);
								
				for(int k=0;k< cont;k++){
					strcpy(frase2,salva[k].frase);
						if(existe(palavra,frase2)==true){
							
							qtd++;	
						}
				}
					if(qtd>0){
						printf("A palavra existe em %d vezes\n",qtd);
						qtd=0;
					}
					else{
						printf("n tem\n");					
					}
							
				break;
			}
		}
		
	}
return 0;
}
