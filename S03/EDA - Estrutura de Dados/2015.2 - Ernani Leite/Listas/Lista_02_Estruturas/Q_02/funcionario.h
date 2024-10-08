#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct funcionario{
	char nome[100];
	char sexo;
	int producao;

}Funcionario;


void lerLista(Funcionario *ptr, int dimensao);
void mostraLista(Funcionario *ptr, int dimensao);
void lerFuncionario(Funcionario *ptr);
void mostraFuncionario(Funcionario *ptr);
void relatorios(Funcionario *ptr, int dimensao);


#endif // FUNCIONARIO_H_INCLUDED
