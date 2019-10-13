#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE !FALSE



typedef struct arvore{
	int info;
	struct arvore *esquerda;
	struct arvore *direita;
}Arvore;


Arvore* inicializa(){

    return NULL;
}


Arvore* criaRaiz(int info, Arvore *sae, Arvore *sad){
    Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
    novo->info = info;
    novo->esquerda = sae;
    novo->direita = sad;
    return novo;
}



int vazia(Arvore *arvore){
    return arvore == NULL;
}

void imprimirArvore2(Arvore *arvore){
    //printf("<");
    if(!vazia(arvore)){
        printf(" %d ", arvore->info);
        imprimirArvore2(arvore->esquerda);
        imprimirArvore2(arvore->direita);
    }
    //printf(">");

}



void imprimirArvore(Arvore *arvore){
    //printf("<");
    if(!vazia(arvore)){
        printf(" %d ", arvore->info);
        if(!vazia(arvore->direita)){
            printf("Minha direita %d ", arvore->direita->info);
        }
        if(!vazia(arvore->esquerda)){
            printf("Minha esquerda %d ", arvore->esquerda->info);
        }
        printf("\n\n");
        imprimirArvore(arvore->esquerda);
        imprimirArvore(arvore->direita);
    }
    //printf(">");

}

Arvore* inserir(int item, Arvore *arvore) {

    if(arvore == NULL){

        arvore = (Arvore*)malloc(sizeof(Arvore));
        arvore->info = item;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
        return arvore;
    }else{
        if(item < arvore->info)
        {
            arvore->esquerda = inserir(item, arvore->esquerda);
            return arvore;
        }else{

            arvore->direita = inserir(item, arvore->direita);
            return arvore;
        }
    }

}


Arvore* liberaArvore(Arvore*a){
	if(!vazia(a)){
		liberaArvore(a->esquerda);
		liberaArvore(a->direita);
		free(a);
	}
	return NULL;
}

int pesquisa(Arvore* a, int x){
    if(vazia(a))
        return 0;
    else
        return a->info == x || pesquisa(a->esquerda, x) || pesquisa(a->direita, x);

}

int pesquisaPreOrdem(Arvore* a, int x){
    if(vazia(a))
        return 0;
    //return a->info == x || pesquisa(a->esquerda, x) || pesquisa(a->direita, x);
    if(x == a->info)
        return TRUE;
    else if(pesquisaPreOrdem(a->esquerda, x))
        return TRUE;
     else
        return pesquisaPreOrdem(a->direita, x);
}
int pesquisaEmOrdem(Arvore* a, int x){
    if(vazia(a))
        return 0;
    //return  pesquisa(a->esquerda, x) || a->info == x || pesquisa(a->direita, x);
    if(pesquisaEmOrdem(a->esquerda, x))
        return 1;
    if(x == a->info)
        return TRUE;
     else
        return pesquisaEmOrdem(a->direita, x);
}
int pesquisaPosOrdem(Arvore* a, int x){
    if(vazia(a))
        return 0;
    //return pesquisa(a->esquerda, x)|| pesquisa(a->direita, x) || a->info == x;

    if(pesquisaPosOrdem(a->esquerda, x))
        return TRUE;
    else if(pesquisaPosOrdem(a->direita, x))
        return TRUE;
    else if(x == a->info)
        return TRUE;
}

int excluir(Arvore** a, int x){
    Arvore *aux;
    if(vazia(*a)){
        return FALSE;
    }
    if((*a)->info == x){
        if(vazia((*a)->esquerda) && vazia((*a)->direita)){
            free(*a);
            *a = NULL;
        }
        else if(vazia((*a)->esquerda) && !vazia((*a)->direita)){

            *a = (*a)->direita;
        }
        else if(!vazia((*a)->esquerda) && vazia((*a)->direita)){

            *a = (*a)->esquerda;
        }else if(!vazia((*a)->esquerda) && !vazia((*a)->direita)){
            chegaNumaPonta(*a);
            (*a)->info = aux->info;
            excluir(&aux, (*a)->info);
        }
        return TRUE;
    }else{
        return excluir(&(*a)->esquerda, x) || excluir(&(*a)->direita, x);
    }

}
void chegaNumaPonta(Arvore *arvore){
   return;

}

int main(){
    Arvore *raiz = inicializa();
    raiz = inserir(14, raiz);
    raiz = inserir(10, raiz);
    raiz = inserir(3, raiz);
    raiz = inserir(2, raiz);
    raiz = inserir(55, raiz);
    if(pesquisaEmOrdem(raiz, 14)){
        printf("Achei!!!\n");
    }
    else{
        printf("Nao achei!!!\n");
    }
    imprimirArvore(raiz);

    if(excluir(&raiz, 3)){
        printf("Achei");
    }

    printf("\n");
    imprimirArvore(raiz);
    liberaArvore(raiz);
	return 0;
}


