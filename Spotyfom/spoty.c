#include "spoty.h"


//LDE
struct desc_LDE *criadesc_LDE()
{
  struct desc_LDE *DescLDE = malloc(sizeof(struct desc_LDE));

  DescLDE->comeco = NULL;
  DescLDE->fim = NULL;
  DescLDE->tamanho = 0;

  return DescLDE;
}

struct musica *criamusica(char *titulo, char *artista, char *letra, int codigo)
{
  struct musica *NewMusica = (struct musica *) malloc(sizeof(struct musica));

  strcpy(NewMusica->titulo, titulo);
  strcpy(NewMusica->artista, artista);
  strcpy(NewMusica->letra, letra);
  NewMusica->codigo = codigo;
  NewMusica->execucoes = 0;
  
  return NewMusica;
}

void carregar(struct desc_LDE *lista, char *arq)
{
 FILE *file = fopen(arq, "r"); 
  if(file == NULL)
  {
    printf("\nErro ao abrir arquivo!\n");
  }

  char linha[1024];
  int posicao = 0;

  while(fgets(linha, 1023, file))
    {
      char *artista = strtok(linha, ";");
      char *code = strtok(NULL, ";");
      char *titulo = strtok(NULL, ";");
      char *letra = strtok(NULL, ";");

      if(artista && code && titulo && letra) 
      {
        int codigo = atoi(code);

        insercao(lista, criamusica(titulo, artista, letra, codigo), posicao);
        posicao++;
      }
    }
}

void insercao(struct desc_LDE *lista, struct musica *NewMusica, int posicao)
{
  if(lista == NULL)
  {
    printf("\nErro ao carregar a lista\n");
  }
  if(NewMusica == NULL)
    {
      printf("\nErro ao carregar a acervo\n");
    }
  struct nodo_LDE *NewNodo = (struct nodo_LDE *)malloc(sizeof(struct nodo_LDE));

  NewNodo->music = NewMusica;
  NewNodo->ant = NULL;
  NewNodo->prox = NULL;

  if(posicao == 0 || lista->comeco == NULL)
  {
    NewNodo->prox = lista->comeco;
    if(lista->comeco != NULL)
    {
      lista->comeco->ant = NewNodo;
    }
    lista->comeco = NewNodo;
    if(lista->fim == NULL)
    {
      lista->fim = NewNodo;
    }
  }
  else
  {
    struct nodo_LDE *aux = lista->comeco;
    int cont=0;
    while(aux->prox != NULL && cont < posicao - 1)
      {
        aux = aux->prox;
        cont++;
      }
    NewNodo->prox = aux->prox;
    NewNodo->ant = aux;
    if(aux->prox !=NULL)
    {
      aux->prox->ant = NewNodo;
    }
    aux->prox = NewNodo;
    if(lista->fim == aux)
    {
      lista->fim = NewNodo; 
    }
  }
  lista->tamanho++;
}

struct musica *procuratitulo(struct desc_LDE *lista, const char *titulo)
{
  struct nodo_LDE *aux = lista->comeco;


  while(aux != NULL) 
    {
      if(strcasecmp(aux->music->titulo, titulo) == 0)
      {

        return aux->music;
      }
      aux = aux->prox;
    }
  return NULL;
}

struct musica *procuraartista(struct desc_LDE *lista, const char *artista)
{
  struct nodo_LDE *aux = lista->comeco;

  while(aux != NULL) 
    {
      if(strcasecmp(aux->music->artista, artista) == 0)
      {
        while(strcasecmp(aux->music->artista, artista) == 0)
        {
          printf("\nTitulo: %s\n", aux->music->titulo);
          printf("Artista: %s\n", aux->music->artista);
          printf("Letra: %s\n", aux->music->letra);
          printf("Codigo: %d\n", aux->music->codigo);
          aux = aux->prox;
        }
        return aux->music;
      }
      aux = aux->prox;
    }
  return NULL;
}

struct musica *procuraletra(struct desc_LDE *lista, const char *letra)
{
  struct nodo_LDE *aux = lista->comeco;


  while(aux != NULL) 
    {
      if(strcasecmp(aux->music->letra, letra) == 0)
      {
        return aux->music;
      }
      aux = aux->prox;
    }
  return NULL;
}

struct musica *procuracodigo(struct desc_LDE *lista, int codigo)
{
  struct nodo_LDE *aux = lista->comeco;


  while(aux != NULL) 
    {
      if(aux->music->codigo == codigo)
      {
        return aux->music;
      }
      aux = aux->prox;
    }
  return NULL;
}

void imprimir(struct desc_LDE *lista, struct musica *NewMusica, int posicao)
{
  struct nodo_LDE *aux = lista->comeco;
  
  while (aux != NULL)
    {
      printf("Titulo: %s\n", aux->music->titulo);
      printf("Artista: %s\n", aux->music->artista);
      printf("Letra: %s\n", aux->music->letra);
      printf("Codigo: %d\n", aux->music->codigo);
      aux = aux->prox;
    }
}
void imprimeuma(struct musica *music)
{

  printf("Titulo: %s\n", music->titulo);
  printf("Artista: %s\n", music->artista);
  printf("Letra: %s\n", music->letra);
  printf("Codigo: %d\n", music->codigo);
}

struct musica *artistaplay(struct desc_LDE *lista, const char *artista)
{
  struct nodo_LDE *aux = lista->comeco;
  int choices = -1;

  while (aux != NULL)
    {
      if(strcasecmp(aux->music->artista, artista) == 0)
      {
        printf("Titulo: %s\n", aux->music->titulo);
        printf("Artista: %s\n", aux->music->artista);
        printf("Letra: %s\n", aux->music->letra);
        printf("Codigo: %d\n", aux->music->codigo);
        printf("\nDeseja adicionar a musica a playlist? (1-Sim/2-Nao)\n");
        scanf("%d", &choices);
          if (choices == 1)
          {
          return aux->music;
          }
          else
          {
            printf("\nMusica nao adicionada!\n");
          }
        }
      aux = aux->prox;
      }
  return NULL;
}
//Pilha
struct desc_Pilha *criadesc_pilha(void)
{
  struct desc_Pilha *descPilha = (struct desc_Pilha *)malloc(sizeof(struct desc_Pilha));

  descPilha->Pilha = NULL;
  descPilha->tamanho = 0;

  return descPilha;
}

struct nodo_Pilha *crianodo_pilha(struct musica *NewMusica)
{
  struct nodo_Pilha *nodoPilha = (struct nodo_Pilha *)malloc(sizeof(struct nodo_Pilha));

  nodoPilha->info = NewMusica;
  nodoPilha->prox = NULL;
  return nodoPilha;
}

void push(struct desc_Pilha *descPilha, struct nodo_Pilha *nodo)
{
  nodo->prox =  descPilha->Pilha;
  descPilha->Pilha = nodo;
  descPilha->tamanho++;
}

struct nodo_Pilha *pop(struct desc_Pilha *descPilha)
{
  struct nodo_Pilha *aux = descPilha->Pilha;

  if(descPilha->tamanho == 0)
  {
    return 0;
  }
  
  descPilha->Pilha = descPilha->Pilha->prox;
  descPilha->tamanho--;
  return aux;
}

void imprimir_pilha(struct desc_Pilha *desc)
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

void executacustom(struct desc_Pilha *descPilha)
{
  if(descPilha == NULL)
  {
    printf("\nErro! Sua playlist esta vazia!\n");
  }

  struct nodo_Pilha *aux;
  while((aux = pop(descPilha)) != NULL)
  {
  struct musica *music = aux->info;
  printf("\nAgora Tocando: %s\n", music->titulo);
  printf("\n%s...\n", music->letra);
  music->execucoes++;
  free(aux);
  }
}

//Fila

struct desc_queue *criadesc_queue(void)
{
  struct desc_queue *queue = (struct desc_queue *)malloc(sizeof(struct desc_queue));

  queue->head = NULL;
  queue->tail = NULL;
  queue->tamanho = 0;
  return queue;
}

struct nodo_queue *crianodo_queue(struct musica *NewMusica)
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
    X->ant = queue->tail;
    queue->tail = X;
  }
  queue->tamanho++;
}

struct nodo_queue *dequeue(struct desc_queue *queue)
{
  if(queue->tamanho == 0)
  {
    return 0;
  }
  
  struct nodo_queue *aux = queue->head;
    queue->head = queue->head->prox;
    queue->tamanho--;
    return aux;
}

void criaplaylistaleatoria(struct desc_LDE *lista, struct desc_queue *NewQueue, int tamanho)
{
  if(tamanho > lista->tamanho)
    {
      printf("\nTamanho invalido! Tente um tamanho menor!\n");
      return;
    }
  
  int *vet = (int *)malloc(sizeof(int) * tamanho);
  
  for (int i = 0; i < tamanho; i++)
    {
      int escolhas, a;
      do
      { 
      escolhas = rand() % lista->tamanho;
      a=1;
      for(int j = 0; j < i; j++)
        {
          if(escolhas == vet[j])
          {
            a=0;
            break;
          }
        }
      }
      while(!a);
      vet[i] = escolhas;
      struct nodo_LDE *aux = lista->comeco;
      for(int j=0; j < escolhas; j++)
        {
          aux = aux->prox;
        }
      struct nodo_queue *nodo = crianodo_queue(aux->music);
      enqueue(NewQueue, nodo);
    }
  free(vet);
}

void imprimir_queue(struct desc_queue *queue)
{
  struct nodo_queue *aux = queue->head;

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

void executaaleatoria(struct desc_queue *queue)
{
  if(queue == NULL)
  {
    printf("\nErro! Sua playlist esta vazia!\n");
  }

  struct nodo_queue *aux;
  while((aux = dequeue(queue)) != NULL)
  {
  struct musica *music = aux->info;
  printf("\nAgora Tocando: %s\n", music->titulo);
  printf("\n%s...\n", music->letra);
  music->execucoes++;
  free(aux);
  }
}

//Arquivos

void relatorioacervo(struct desc_LDE *lista)
{
  FILE *arquivo = fopen("acervo.txt", "w");
  if(arquivo == NULL)
  {
    printf("\nErro ao abrir o arquivo!\n");
    return;
  }
  
  struct nodo_LDE *aux = lista->comeco;

  while (aux != NULL)
    {
      fprintf(arquivo, "\nTitulo: %s\n", aux->music->titulo);
      fprintf(arquivo, "Artista: %s\n", aux->music->artista);
      fprintf(arquivo, "Letra: %s\n", aux->music->letra);
      fprintf(arquivo,"Codigo: %d\n", aux->music->codigo);
      fprintf(arquivo, "Execucoes: %d\n", aux->music->execucoes);
      aux = aux->prox;
    }
  fclose(arquivo);
}

void relatorioplaylistcustom(struct desc_Pilha *descPilha)
{
  FILE *arquivo = fopen("Playlist Customizada.txt", "w");
  if(arquivo == NULL)
  {
    printf("\nErro ao abrir o arquivo!\n");
    return;
  }

  struct nodo_Pilha *aux = descPilha->Pilha;

  while (aux != NULL)
    {
      fprintf(arquivo, "\nTitulo: %s\n", aux->info->titulo);
      fprintf(arquivo, "Artista: %s\n", aux->info->artista);
      fprintf(arquivo, "Letra: %s\n", aux->info->letra);
      fprintf(arquivo,"Codigo: %d\n", aux->info->codigo);
      fprintf(arquivo, "Execucoes: %d\n", aux->info->execucoes);
      aux = aux->prox;
    }
  fclose(arquivo);
}

void relatorioplaylistaleatoria(struct desc_queue *queue)
{
  FILE *arquivo = fopen("Playlist aleatoria.txt", "w");
  if(arquivo == NULL)
  {
    printf("\nErro ao abrir o arquivo!\n");
    return;
  }

  struct nodo_queue *aux = queue->head;

  while (aux != NULL)
    {
      fprintf(arquivo, "\nTitulo: %s\n", aux->info->titulo);
      fprintf(arquivo, "Artista: %s\n", aux->info->artista);
      fprintf(arquivo, "Letra: %s\n", aux->info->letra);
      fprintf(arquivo,"Codigo: %d\n", aux->info->codigo);
      fprintf(arquivo, "Execucoes: %d\n", aux->info->execucoes);
      aux = aux->prox;
    }
  fclose(arquivo);
}
