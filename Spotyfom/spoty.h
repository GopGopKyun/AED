#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct musica{
char titulo[256];
char artista[256];
char letra[256];
int codigo;
int execucoes;
};

//LDE
struct desc_LDE
{
  struct nodo_LDE *comeco;
  struct nodo_LDE *fim;
  int tamanho;
};

struct nodo_LDE
{
  struct musica *music;
  struct nodo_LDE *prox;
  struct nodo_LDE *ant;
};

//Pilha
struct nodo_Pilha{
struct nodo_Pilha *prox;
struct musica *info;
};

struct desc_Pilha{
struct nodo_Pilha *Pilha;
int tamanho;
};
//Fila
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

void carregar(struct desc_LDE *lista, char *arq);
void insercao(struct desc_LDE *lista, struct musica *NewMusica, int posicao);
void imprimir(struct desc_LDE *lista, struct musica *NewMusica, int posicao);
void imprimeuma(struct musica *music);
//LDE
struct musica *procuratitulo(struct desc_LDE *lista, const char *titulo);
struct musica *procuraartista(struct desc_LDE *lista, const char *artista);
struct musica *procuraletra(struct desc_LDE *lista, const char *letra);
struct musica *procuracodigo(struct desc_LDE *lista, int codigo);
struct desc_LDE *criadesc_LDE();
//Pilha
struct desc_Pilha *criadesc_pilha(void);
struct nodo_Pilha *crianodo_pilha(struct musica *NewMusica);
struct musica *criamusica(char *titulo, char *artista, char *letra, int codigo);
void push(struct desc_Pilha *descPilha, struct nodo_Pilha *nodo);
struct nodo_Pilha *pop(struct desc_Pilha *descPilha);
void imprimir_pilha(struct desc_Pilha *descPilha);
struct musica *artistaplay(struct desc_LDE *lista, const char *artista);
void executacustom(struct desc_Pilha *descPilha);
//Fila
struct desc_queue *criadesc_queue();
struct nodo_queue *crianodo_queue(struct musica *NewMusica);
void enqueue(struct desc_queue *queue, struct nodo_queue *X);
struct nodo_queue *dequeue(struct desc_queue *queue);
void deleter(struct desc_queue *queue);
void criaplaylistaleatoria(struct desc_LDE *lista, struct desc_queue *NewQueue, int tamanho);
void imprimir_queue(struct desc_queue *queue);
void executaaleatoria(struct desc_queue *queue);
//Arquivos
void relatorioacervo(struct desc_LDE *lista);
void relatorioplaylistcustom(struct desc_Pilha *descPilha);
void relatorioplaylistaleatoria(struct desc_queue *queue);
