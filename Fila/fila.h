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

struct nodo_queue{
struct nodo_queue *prox;
struct musica *info;
struct nodo_queue *ant;
};

struct desc_queue{
struct nodo_queue *head;
struct nodo_queue *tail;
int tamanho;
};

struct desc_queue *criardesc_queue();
struct nodo_queue *criarnodo_queue(struct musica *NewMusica);
struct musica *criamusica();
void enqueue(struct desc_queue *queue, struct nodo_queue *X);
struct nodo_queue *dequeue(struct desc_queue *queue);
void deleter(struct desc_queue *queue);
int empty(struct desc_queue *queue);
int lenght(struct desc_queue *queue);
void procura(struct desc_queue *queue, int codigomusica);
void ShowQueue(struct desc_queue *queue);
