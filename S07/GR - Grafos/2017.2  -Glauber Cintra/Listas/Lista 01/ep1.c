/*     1º Exercício Programa da disciplina de Grafos     */ 
/*												         */ 
/* Implementação do Algoritmo de Dijkstra                */
/* Implementado pelos alunos:			                 */
/* Ana Carolina, Luisa Macedo e Vitor Guimarães          */
/* Data: 05/10/2017									     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 150
#define INFINITO 10000

void dijkstra(int vertices, int origem, int destino, int *custos){ 
	int i = 0; 		   //contador
	int v = 0;         //variável auxiliar vértice v
	int ant[MAXV];     //vetor dos predecessores 
	int z[MAXV];       //vértices para os quais se conhece o caminho mínimo
	double min;        //variável auxiliar 
	double dist[MAXV]; //vetor com os custos dos caminhos 
	
	//Inicialização
	for(i = 0; i < vertices; i++){
		if(custos[i] != -1){
			ant[i] = origem-1; 
			dist[i] = custos[i];
		}
		else{
			ant[i] = -1;
			dist[i] = INFINITO;
		}
		z[i] = 0;
	}
	z[origem-1] = 1;    
	dist[origem-1] = 0; 

	//Insere o novo vértice que se conhece o caminho mínimo no conjunto z  
	while(v != destino-1 && min != INFINITO){ 
		min = INFINITO; 
		
		for(i = 0; i < vertices; i++){
			if(z[i] == 0){ 
				if(dist[i] >= 0 && dist[i] < min){ 
					min = dist[i]; 
					v = i; 
				}
			}
		}

		//Distâncias dos novos vizinhos de z
		if(min != INFINITO && v != destino-1){ 
			z[v] = 1; 
			for(i = 0; i < vertices; i++)
				if(z[i] == 0){ 
					if(custos[v*vertices+i] != -1 && dist[v]+custos[v*vertices+i] < dist[i]){ 
						dist[i] = dist[v]+custos[v*vertices+i]; 
						ant[i] = v; 
					}
				}
		}
  }//Fim de while(v != destino-1 && min != INFINITO)

  //Imprime caminho mínimo de origem a destino
	if(min == INFINITO)
		printf("\nNão existe caminho entre os vértices %d e %d.\n", origem, destino);
	else{
		printf("\nCaminho mínimo do vértice %d para o vértice %d: \n",
		   origem, destino);
   
		i = destino;
		printf("%d", i);
		i = ant[i-1];
		
		while(i !=-1) {
			printf(" <- %d", i+1);
			i = ant[i];
		}
		printf("\nCusto = %d\n", (int)dist[destino-1]);
	}
}//dijkstra

int main(){

	int vertices = 0;   	//quantidade de vértices do grafo
	int arcos    = 0; 		//quantidade de arcos do grafo
	int origem   = 0;     	//vértice origem dijkstra
	int destino  = 0;    	//vértice destino dijkstra
	int origemU  = 0;    	//vértice origem de cada arco do grafo
	int destinoV = 0;   	//vértice destino de cada arco do grafo
	int *custos  = NULL; 	//lista de adjacências 
	int i = 0;				//variável auxiliar
	int j = 0;				//variável auxiliar

	FILE *arquivo = NULL;
	char caminhoDoArquivo[50];

	while(arquivo == NULL){
		printf("Insira o caminho do arquivo e pressione Enter: \n");
		fgets(caminhoDoArquivo, sizeof(caminhoDoArquivo), stdin);
		//Remove o último caractere do caminho, pois o fgets armazena a quebra de linha '\n'
		char *p_chr = strchr(caminhoDoArquivo, '\n'); 
		if(p_chr != NULL) 
			*p_chr = '\0';
		arquivo = fopen(caminhoDoArquivo, "r");
	}

	//Lê o arquivo e armazena os valores nas variáveis
	fscanf(arquivo, "%d %d %d %d", &vertices, &arcos, &origem, &destino); //Lê a primeira linha do arquivo
	
	free(custos);
	custos = (int*)malloc(sizeof(int)*vertices*vertices);
	for(i = 0; i <= vertices*vertices; i++)
		custos[i] = -1;

	//Lê o arquivo a partir da segunda linha e armazena as variáveis
	for(j = 0; j < arcos; j++){ 
		fscanf(arquivo, "%d %d", &origemU, &destinoV);
		//Armazena os custos na lista de adjacências
		fscanf(arquivo, "%d", &custos[(origemU-1)*vertices+destinoV-1]); 
	}
	fclose(arquivo);

	dijkstra(vertices, origem, destino, custos);

  return 0;
}
