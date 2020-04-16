#include <math.h>
#include <stdio.h>
#include <string.h>
#include<stdbool.h>

int existe(char palavra[], char frase[]){
	int tamP = strlen(palavra);
	int tamF = strlen(frase);
	int quant=0,x=0,i2=0,i,j;
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
int main(){
	int ver;
	/*char *res;
	char frase[50] = "Tres Russos e Tres Ingleses";
	char palavra[10] = "popo";
	res = strstr(frase, palavra);

	if (res != NULL) {
	    printf("Contem palavra na frase!");
	} else {
	    printf("Nao contem palavra na frase");
	}*/
	char frase[50],palavra[10];
	fgets(frase, 40, stdin);
	fgets(palavra, 10, stdin);
	ver=existe(palavra,frase);
	printf("%d\n",ver);
return 0;
}
