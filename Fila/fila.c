#include "fila.h"

struct desc_queue *criardesc_queue(void)
{
  struct desc_queue *queue = (struct desc_queue *)malloc(sizeof(struct desc_queue));

  queue->head = NULL;
  queue->tail = NULL;
  queue->tamanho = 0;
  return queue;
}

struct nodo_queue *criarnodo_queue(struct musica *NewMusica)
{
  struct nodo_queue *nodo = (struct nodo_queue *)malloc(sizeof(struct nodo_queue));

  nodo->info = NewMusica;
  nodo->prox = NULL;
  nodo->ant = NULL;
  
  return nodo;
}

void enqueue(struct desc_queue *queue, struct nodo_queue *X)
{
  if (queue->head == NULL)
  {
    queue->head = X;
    queue->tail = X;
  }
  else
  {
    queue->tail->prox = X;
    queue->tail = X;
  }
  queue->tamanho++;
}

struct nodo_queue *dequeue(struct desc_queue *queue)
{
  struct nodo_queue *aux = queue->head;
    queue->head = queue->head->prox;
    queue->tamanho--;
    return aux;
}

void deleter(struct desc_queue *queue)
  {
    while(empty(queue) == 0)
      {
        free(dequeue(queue));
      }
  }
int empty(struct desc_queue *queue)
{
  if(queue->head == NULL)
    return 1;
  else
    return 0;
}

int lenght(struct desc_queue *queue)
{
  return queue->tamanho;
}


struct musica *criamusica()
{
  struct musica *musica = (struct musica *)malloc(sizeof(struct musica));

  char titulo[256], artista[256], letra[256];
  int codigo, execucoes;

  printf("Insira o titulo da musica: ");
  getchar();
  fgets(titulo, 255, stdin);
  titulo[strcspn(titulo, "\n")] = '\0';

  strcpy(musica->titulo, titulo);


  printf("Insira o artista da musica: ");
  fgets(artista, 255, stdin);
  artista[strcspn(artista, "\n")] = '\0';

  strcpy(musica->artista, artista);


  printf("Insira a letra da musica: ");
  fgets(letra, 255, stdin);
  letra[strcspn(letra, "\n")] = '\0';

  strcpy(musica->letra, letra);

  printf("Insira o codigo da musica: ");
  scanf("%d", &codigo);

  musica->codigo = codigo;

  printf("Insira o numero de execucoes da musica: ");
  scanf("%d", &execucoes);

  musica->execucoes = execucoes;

  return musica;
}

void procura(struct desc_queue *queue, int codigomusica)
{
  struct nodo_queue *aux = queue->head;

    while(aux != NULL)
    {
      if(aux->info->codigo == codigomusica)
      {
        printf("\nTitulo: %s", aux->info->titulo);
        printf("\nArtista: %s", aux->info->artista);
        printf("\nLetra: %s", aux->info->letra);
        printf("\nCodigo: %d", aux->info->codigo);
        printf("\nExecucoes: %d\n", aux->info->execucoes);
      }
      aux=aux->prox;
    }
}
void ShowQueue(struct desc_queue *queue)
{
  struct nodo_queue *aux= queue->head;

  while(aux != NULL)
    {
      printf("\nTitulo: %s", aux->info->titulo);
      printf("\nArtista: %s", aux->info->artista);
      printf("\nLetra: %s", aux->info->letra);
      printf("\nCodigo: %d", aux->info->codigo);
      printf("\nExecucoes: %d\n", aux->info->execucoes);
      aux = aux->prox;
    }

}
