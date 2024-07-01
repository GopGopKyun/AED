//Gabriel De Oliveira Pellegrini Louzada
//24/06
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main(void) {
  int escolha=-1,codigomusica;
  struct desc_queue *NewQueue = NULL;
  struct musica *NewMusica = NULL;
  struct nodo_queue *NewNodo = NULL;

  while(escolha!=0)
    {
    printf("\n1-Cria fila\n2-Inserir musica\n3-Remover Musica\n4-Procurar uma musica\n5-Esvaziar playlist\n6-Imprime\n7-Mostrar tamanho\n0-Sair"); 
    printf("\nInsira o desejado:");
    scanf("%d", &escolha);
    switch(escolha){
      case 1:
        if(NewQueue == NULL)
        {
          NewQueue = criardesc_queue();
          if(NewQueue != NULL)
          {
            printf("\nFila criada com sucesso!\n");
          }
          else
          {
            printf("\nErro! Fila não criada");
          }
        }
        else
        {
          printf("\nA fila já foi criada!");
        }

      break;

      case 2:
        if(NewQueue != NULL)
        {
          NewMusica=criamusica();
          NewNodo=criarnodo_queue(NewMusica);
          enqueue(NewQueue, NewNodo);
        }
        else
        {
          printf("A pilha não foi criada.");
        }
        break;
        case 3:
            if(NewQueue != NULL)
            {
              dequeue(NewQueue);
            }  
            else
            {
              printf("A pilha não foi criada.");
            }
            break; 
          
      case 4:
        if(NewQueue != NULL)
        {
          printf("\nInsira o codigo da musica:");
          scanf("%d", &codigomusica);
          procura(NewQueue, codigomusica);
        }
        else
        {
          printf("A pilha não foi criada.");  
        }
        break;

      case 5:
        if(NewQueue != NULL)
        {
          deleter(NewQueue);
          break;
        }
      case 6:
        if(NewQueue != NULL)
        {
          ShowQueue(NewQueue);
          break;
        }
        case 7:
          
            printf("\nA pilha tem %d elementos\n", lenght(NewQueue));
            break;
          
        case 0:
          
        printf("\nSaindo...");
        return -1;
        break;
          
        default:
          printf("Comando Indesejado. Tente novamente.\n");
          break;
    }
    }
    return 0;
}
  
