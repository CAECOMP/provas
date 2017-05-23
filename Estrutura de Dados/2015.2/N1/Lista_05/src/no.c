#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "no.h"


No* inserirInicio(No* lista, char conteudo){
	No* novo = (No*)malloc(sizeof(No));
	novo->operador = conteudo;
	novo->proximo = lista;
	return novo;
}


No* inserirNumero(No* lista, int conteudo){
	No* novo = (No*)malloc(sizeof(No));
	novo->operador = '_';
	novo->numero = conteudo;
	novo->proximo = lista;
	return novo;
}

void noPrint(No*no){

	if(no->operador == '_'){
		printf("%d", no->numero);
	}else{
		printf("%c", no->operador);
	}


}
void boxListar(No* lista){
	No *p;
	printf("\n\n-----------Resultado-----------\n\n");
	for(p = lista; p != NULL; p = p->proximo){
		noPrint(p);
	}
	printf("\n\n-----------Resultado-----------\n\n");
}

No* strEmpilhar(char *palavra){
	int i, flag;
	char subPalavra[100];
	No*lista = NULL;

	flag = 0;
	for(i = 0; TRUE; i++){

		if(isdigit(palavra[i])){
			subPalavra[flag] = palavra[i];
			subPalavra[flag+1] = '\0';
			flag++;
		}
		else{
			if(flag){
				subPalavra[i] = '\0';
				lista =  inserirNumero(lista, atoi(subPalavra));
				subPalavra[0] = '\0';
				flag = 0;
			}
			if(palavra[i] != '\0'){
				lista = inserirInicio(lista, palavra[i]);
			}else{
				break;
			}
		}
	}
	return lista;

}

No* excluirPrimeiro(No*lista){
    No*excluido;
    excluido = lista;
    lista = lista->proximo;
    free(excluido);
    return lista;
}

int opera(int a, int b, char operador){
	switch(operador){
		case '+':
			printf("\n%d+%d=%d\n", b, a, a+b);
			return  a+b;
		break;
		case '-':
			printf("\n%d-%d=%d\n", b, a, b-a);
			return b-a;
		break;
		case '/':
			printf("\n%d/%d=%d\n", b, a, b/a);
			return b/a;
		break;
		case '*':
			printf("\n%d*%d=%d\n",b, a, b*a);
			return a*b;
		break;
		default:
			return  a+b;
		break;
	}

}



No* resolvePilha(No* lista){
	No *p;
	No *anterior;
	int resultado;
	int parenteses = 0;
	anterior = lista;

	for(p = lista;p->proximo != NULL ; p = p->proximo){

		if(p->proximo->proximo != NULL)
		{
			p->proximo->proximo->numero = opera(p->numero, p->proximo->proximo->numero, p->proximo->operador);
			p = excluirPrimeiro(p);
			p = excluirPrimeiro(p);


		}
		p = resolvePilha(p);
		break;
	}
	return p;
}

