#include <stdio.h>
#include <stdlib.h>

typedef struct Matriz {
int li,co,**m;
}Matriz;

//EXERCICIO 01 
Matriz* criaMatriz(int li, int co){
	Matriz mat;
	mat.m = malloc(li * sizeof(int*));
	for (int i = 0; i < li; i++){
		mat.m[i] = (int*) malloc(co * sizeof(int));
		for (int j = 0; j < co; j++){ 
            mat.m[i][j] = 0; 
       }
	}
	printf("\n Matriz com %d colunas e %d linhas\n",co,li);
	return &mat;
}

//EXERCICIO 02 - ok
void freeMatriz(Matriz *ma){
	for (int i=0; i<ma->li; i++) free (ma->m[i]);
	free (ma->m);
	printf("matriz liberada\n");
}

//EXERCICIO 03 - ok
void imprime(Matriz *m){
	for(int i = 0;i<m->li;i++){
		for(int k = 0;k<m->co;k++){
			printf("%d",m->m[i][k]);	
		}
		printf("\n");
	}
}

//EXERCICIO 04
Matriz * multiplica(Matriz *a, Matriz *b){
//seu código vem aqui
}

int main(){
	int linha,coluna;
	printf("Digite o numero de linhas: ");
	scanf("%d",&linha);
	printf("Digite o numero de colunas: ");
	scanf("%d",&coluna);
	Matriz *mat=criaMatriz(linha,coluna);
	imprime(mat);
	freeMatriz(mat);
return 0;
}
