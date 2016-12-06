#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#define FALSE 0
#define TRUE !FALSE


/*Cada elemento pode ser um
Numero ou um operador.
Caso o caractere seja '_'
    o valor significa
    um Numero
Senão
    O valor significa um Operador
    no char operador.
*/

typedef struct no{
	int numero;
	char operador;
	struct no *proximo;
}No;
No* inserirInicio(No* lista, char conteudo);
No* inserirNumero(No* lista, int conteudo);
void noPrint(No*no);
void boxListar(No* lista);
No* strEmpilhar(char *palavra);
No* excluirPrimeiro(No*lista);
int opera(int a, int b, char operador);
No* resolveParenteses(No* lista);
No* resolvePilha(No* lista);




#endif // NO_H_INCLUDED
