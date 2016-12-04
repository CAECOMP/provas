#ifndef CANDIDATO_H
#define CANDIDATO_H
typedef struct candidato{
	char nome[100];
	char sexo;
	int idade;
	char experiente;
}Candidato;



void lerLista(Candidato *ptr, int dimensao);
void mostraLista(Candidato *ptr, int dimensao);
void lerCandidato(Candidato *ptr);
void mostraCandidato(Candidato *ptr);
void relatorios(Candidato *ptr, int dimensao);

#endif // CANDIDATO_H_INCLUDED
