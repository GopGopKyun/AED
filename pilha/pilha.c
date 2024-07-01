#include "pilha.h"

struct desc_Pilha *criadesc_pilha(void)
{
  struct desc_Pilha *desc = (struct desc_Pilha *)malloc(sizeof(struct desc_Pilha));

  desc->Pilha = NULL;
  desc->tamanho = 0;

  return desc;
}

struct nodo_Pilha *crianodo_pilha(struct musica *NewMusica)
{
  struct nodo_Pilha *nodo = (struct nodo_Pilha *)malloc(sizeof(struct nodo_Pilha));

  nodo->info = NewMusica;
  nodo->prox = NULL;
  return nodo;
}

struct musica *criamusica()
{
  struct musica *musica = (struct musica *)malloc(sizeof(struct musica));

  char titulo[256], artista[256], letra[256];
  int codigo, execucoes;

  printf("Insira o titulo da musica: ");
  getchar();
  fgets(titulo, 256, stdin);
  titulo[strcspn(titulo, "\n")] = '\0';

  strcpy(musica->titulo, titulo);
  
  
  printf("Insira o artista da musica: ");
  fgets(artista, 256, stdin);
  artista[strcspn(artista, "\n")] = '\0';

  strcpy(musica->artista, artista);

  
  printf("Insira a letra da musica: ");
  fgets(letra, 256, stdin);
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


void push(struct desc_Pilha *desc, struct nodo_Pilha *novo)
{
  novo->prox = desc->Pilha;
  desc->Pilha = novo;
  desc->tamanho++;

}

struct nodo_Pilha *pop(struct desc_Pilha *desc)
{
  struct nodo_Pilha *aux = desc->Pilha;
  desc->Pilha = desc->Pilha->prox;
  desc->tamanho--;
  return aux;
}

void procura(struct desc_Pilha *desc, int codigomusica)
{
  struct nodo_Pilha *aux = desc->Pilha;

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

void esvaziar(struct desc_Pilha *desc)
{
  struct nodo_Pilha *aux;
  while(desc->Pilha != NULL)
  {
    aux = pop(desc);
    free(aux->info);
    free(aux);
  }
}

void imprimir(struct desc_Pilha *desc)
{
  struct nodo_Pilha *aux = desc->Pilha;
  
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
