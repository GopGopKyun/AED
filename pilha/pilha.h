#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct musica{
char titulo[256];
char artista[256];
char letra[256];
int codigo;
int execucoes;
};

struct nodo_Pilha{
struct nodo_Pilha *prox;
struct musica *info;
};

struct desc_Pilha{
struct nodo_Pilha *Pilha;
int tamanho;
};

struct desc_Pilha *criadesc_pilha(void);
struct nodo_Pilha *crianodo_pilha(struct musica *NewMusica);
struct musica *criamusica();
void push(struct desc_Pilha *desc, struct nodo_Pilha *novo);
struct nodo_Pilha *pop(struct desc_Pilha *desc);
void procura(struct desc_Pilha *desc, int codigomusica);
int empty(struct desc_Pilha *desc);
void esvaziar(struct desc_Pilha *desc);
void imprimir(struct desc_Pilha *desc);
