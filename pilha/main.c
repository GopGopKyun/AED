//Gabriel De Oliveira Pellegrini Louzada 
//24/06
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) {
  int escolha=-1,codigomusica;;
  struct desc_Pilha *NewPilha = NULL;
  struct musica *NewMusica = NULL;
  struct nodo_Pilha *NewNodo = NULL;
  
  while(escolha!=0)
    {
    printf("\n1-Cria Pilha\n2-Inserir musica\n3-Remover Musica\n4-Procurar uma musica\n5-Esvaziar playlist\n6-Imprime\n0-Sair"); 
    printf("\nInsira o desejado:");
    scanf("%d", &escolha);
    switch(escolha){
      case 1:
        if(NewPilha == NULL)
        {
          NewPilha = criadesc_pilha();
          if(NewPilha != NULL)
          {
           printf("\nPilha criada com sucesso!\n");
          }
          else
          {
            printf("\nErro! Pilha não criada");
          }
        }
        else
        {
          printf("\nA pilha já foi criada!");
        }
        
      break;
      
      case 2:
        if(NewPilha != NULL)
        {
          NewMusica=criamusica();
          NewNodo=crianodo_pilha(NewMusica);
          push(NewPilha, NewNodo);
        }
        else
        {
          printf("A pilha não foi criada.");
        }
        break;
        
      case 3:
        if(NewPilha != NULL)
        {
            pop(NewPilha);
        }
        else
        {
          printf("A pilha não foi criada.");
        }
        break; 
      case 4:
        if(NewPilha != NULL)
        {
          printf("Insira o codigo da musica:");
          scanf("%d", &codigomusica);
          procura(NewPilha, codigomusica);
        }
        else
        {
          printf("A pilha não foi criada.");  
        }
        break;
        
      case 5:
        esvaziar(NewPilha);
        break;  
      case 6:
        if(NewPilha != NULL)
        {
          imprimir(NewPilha);
        }
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
