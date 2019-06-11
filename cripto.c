#include <math.h>
#include <stdio.h>
#include <string.h>
#include<ctype.h>



int existe(char palavra[], char frase[]){
	int tamP = strlen(palavra);
	int tamF = strlen(frase);
	int x=0,i,j;
	for(i=0;i<tamF;i++){
		if (palavra[0]==frase[i]){
			j=i;
			for(int a=0;a<=tamP;a++){
				if(palavra[a] == frase[j]){
					j++;
					x++;
				}
			}		
		
		}	
	}
	if(x >= tamP-1)
		return 1;
	else
		return 0;
}

//MAIN COMECA AKI 
int main(){
	typedef struct {
	char agente[102];
	char id[5];
	char frase[102],cript[102];
	char depar[45];	
	}Frase;
	Frase salva[1000];
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
		fflush(stdin);
		switch (escolha){
			case 1:{//OK - RODANDO
				printf("****ADICIONAR MENSAGEM****\n");
				//esse primeiro fgets é uma gambiarra pq ele ignora o primeiro n sei pq
				fgets(salva[cont].agente, 102, stdin);
				fflush(stdin);
				printf("Digite o nome do Agente:\n");
				fgets(salva[cont].agente, 102, stdin);
				fflush(stdin);
				
				printf("Digite o departamento:\n");
				fgets(salva[cont].depar, 45, stdin);
				fflush(stdin);
				printf("Digite a mensagem a ser criptografada:\n");
				fgets(salva[cont].frase, 100, stdin);
				printf("Digite o numero de identificacao do agente:\n");
				fgets(salva[cont].id, 5, stdin);
				char ajuda[102],fim[102];
				strcpy(ajuda, salva[cont].frase);
				
				i = 0;
				while(ajuda[i] != '\0'){
					ajuda[i]=toupper(ajuda[i]);
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
			case 2:{ 
				//Ver se a palavra ja esta no sistema
				char palavra[42];
				char frase2[102];
				int qtd=0;
				printf("****ENCONTRAR PADROES****\n");
				printf("Digite o padrao a ser encontrado:\n");
				
				fgets(palavra, 42, stdin);
				fgets(palavra, 42, stdin);
								
				for(int k=0;k< cont;k++){
					
					strcpy(frase2,salva[k].frase);
						if(existe(palavra,frase2) == 1){
							qtd++;	
						}
				}
					if(qtd>0){
						printf("****Padrao encontrado em %d mensagens!****\n",qtd);
						
					}
					else{
						printf("***Padrao nao encontrado!****\n");
									      					
					}
					qtd=0;		
				break;
			}
			case 3:{//ainda tentando
				printf("****DESCRIPTOGRAFAR MENSAGEM****\n");
				printf("Digite a mensagem criptografada:\n");
				char busca[102];
				fgets(busca, 102, stdin);
				fgets(busca, 102, stdin);
				int a=0,aux=0,b=0;
				aux=strlen(busca);
				busca[aux-1] = '\0';
				for(int u=0;u<cont;u++){
					a=strcmp(busca,salva[u].cript);
					if(a == 0){
						printf("%s",salva[u].agente);
						printf("%s",salva[u].depar);
						printf("%s",salva[u].frase);
						printf("%s\n",salva[u].id);
						b++;
					}
						
				}
				
				if(b == 0)
					printf("****Mensagem nao encontrada!****\n");
				
				break;
			}
			case 4:{//OK-funcionando
					fflush(stdin);
					int todos = cont;
					int vazio = strlen(salva[0].id);					
					if (vazio != 0){
						printf("****VISUALIZAR TODAS AS MENSAGENS****\n");
						for(int k=0;k<todos;k++){
							printf("%s",salva[k].agente);
							printf("%s",salva[k].depar);
							printf("%s\n",salva[k].cript);
							printf("%s\n",salva[k].id);
						}
					}else{
						printf("****Sistema Vazio!****\n");
					}
					
			}
			
   			default:{
				fflush(stdin);
				if(escolha > 4)		
					printf("****Opcao Invalida, tentar novamente****\n");
				
			}
		}
		
	}
return 0;
}
