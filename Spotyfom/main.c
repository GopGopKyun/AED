#include "spoty.h"

int main(void) 
{
    //LDE
    struct musica *NewMusica = NULL;
    struct desc_LDE *lista = criadesc_LDE();

    char tituloN[256], artistaN[256], letraN[256];
    int codigoN;
  
    //Pilha
    struct desc_Pilha *NewPilha = criadesc_pilha();
    struct nodo_Pilha *NewNodoPilha = NULL;

    //Fila
    struct desc_queue *NewQueue = criadesc_queue();
    struct nodo_queue *NewNodoQueue = NULL;

    srand(time(NULL));
    
    int escolha=-1, escolha2=-1, escolha3=-1,choice=0;
    while(escolha!=0)
  {
    escolha2 = -1;
    printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
    printf("ᯤ      Bem-vindo ao Spotyfom     ᯤ\n");
    printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
    printf("ᯤ       Insira o desejado        ᯤ\n");
    printf("ᯤ       1-Carregar acervo        ᯤ\n");
    printf("ᯤ           2-Musica             ᯤ\n");
    printf("ᯤ          3-Playlist            ᯤ\n");
    printf("ᯤ       4-Fazer relatorio        ᯤ\n");
    printf("ᯤ            0-Sair              ᯤ\n");
    printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
    scanf("%d", &escolha);
        
    switch(escolha)
    {
      case 1:
        { 
          if (lista != NULL && lista->tamanho == 0)
          {
          carregar(lista,"musicas.txt");
          if(lista!=NULL)
            {
            printf("\nAcervo carregado com sucesso!\n");
            }
          else
            {
            printf("\nErro ao carregar o acervo!\n");
            }
          }
          else
          {
            printf("\nO acervo ja foi carregado!\n");
          }
          break;
        }
      case 2:
        {
          if (lista != NULL && lista->tamanho == 0)
          {
            printf("\nCarregue o acervo antes!\n");
            break;
          }
        while(escolha2!=0)
          {
        escolha3 = -1;
        printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
        printf("ᯤ            Musica              ᯤ\n");
        printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
        printf("ᯤ       Insira o desejado        ᯤ\n");
        printf("ᯤ       1-Procurar Musica        ᯤ\n");
        printf("ᯤ       2-Imprimir Musicas       ᯤ\n");
        printf("ᯤ       0-Voltar ao menu         ᯤ\n");
        printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
        scanf("%d", &escolha2);
          switch(escolha2)
            {
              case 1:
                {
                  while (escolha3 != 0)
                  {
                  printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                  printf("ᯤ        Procurar Musica         ᯤ\n");
                  printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                  printf("ᯤ       Insira o desejado        ᯤ\n");
                  printf("ᯤ     1-Procurar por titulo      ᯤ\n");
                  printf("ᯤ     2-Procurar por artista     ᯤ\n");
                  printf("ᯤ      3-Procurar por letra      ᯤ\n");
                  printf("ᯤ     4-Procurar por codigo      ᯤ\n");
                  printf("ᯤ       0-Voltar ao menu         ᯤ\n");
                  printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
                  scanf("%d", &escolha3);
                    switch(escolha3)
                      {
                        case 1:
                        {
                          printf("\nInsira o titulo da musica:\n");
                          getchar();
                          fgets(tituloN, 255, stdin);
                          tituloN[strcspn(tituloN, "\n")] = '\0';
                          
                          struct musica *music = procuratitulo(lista, tituloN);
                          if(music != NULL)
                          {
                            imprimeuma(music);
                          }
                          else
                          {
                            printf("\nMusica nao encontrada!\n");    
                          }
                          break;
                        }
                        case 2:
                        {
                          printf("\nInsira o artista da musica:\n");
                          getchar();
                          fgets(artistaN, 255, stdin);
                          artistaN[strcspn(artistaN, "\n")] = '\0';

                          struct musica *music = procuraartista(lista, artistaN);

                          if(music == NULL)
                          {
                            printf("\nMusica nao encontrada!\n");    
                          }
                          break;
                        }
                        case 3:
                        {
                          printf("Procure a letra da musica:\n");
                          getchar();
                          fgets(letraN, 255, stdin);
                          letraN[strcspn(letraN, "\n")] = '\0';
                          
                          struct musica *music = procuraletra(lista, letraN);
                          
                          if(music != NULL)
                          {
                            imprimeuma(music);
                          }
                          if(music == NULL)
                          {
                            printf("\nMusica nao encontrada!\n");
                          }
                          break;
                        }
                        case 4:
                          {
                          printf("Procure o codigo da musica:\n");
                          scanf("%d", &codigoN);
                          
                          struct musica *music = procuracodigo(lista, codigoN);

                          if(music != NULL)
                          {
                            imprimeuma(music);
                          }
                          if(music == NULL)
                          {
                            printf("\nMusica nao encontrada!\n");
                          }
                          break;
                        }
                        case 0:
                          break;
                        default:
                          printf("\nOpcao invalida!\n");
                      }
                    }
                    break;
                  }
                
              case 2:
                {
                  imprimir(lista, NewMusica, 0);
                  break;
                }
              case 0:
                break;
              default:
                printf("\nOpcao invalida!\n");
            }
          }
        break;
        }
      case 3:
        {
          if (lista != NULL && lista->tamanho == 0)
            {
              printf("\nCarregue o acervo antes!\n");
              break;
            }
          while(escolha2!=0)
          {
          escolha3 = -1;
        printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
        printf("ᯤ           Playlist             ᯤ\n");
        printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
        printf("ᯤ       Insira o desejado        ᯤ\n");
        printf("ᯤ     1-Playlist customizada     ᯤ\n");
        printf("ᯤ      2-Playlist aleatoria      ᯤ\n");
        printf("ᯤ      3-Imprimir playlist       ᯤ\n");
        printf("ᯤ      4-Executar playlist       ᯤ\n");
        printf("ᯤ       0-Voltar ao menu         ᯤ\n");
        printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
        scanf("%d", &escolha2);
            switch(escolha2)
              {
                case 1:
                  {
                    if(NewPilha == NULL)
                    {
                      NewPilha = criadesc_pilha();
                      if(NewPilha != NULL)
                      {
                        printf("\nPlaylist criada com sucesso!\n");
                      }
                      if(NewPilha == NULL)
                      {
                        printf("\nErro ao criar playlist!\n");
                      }
                    }
                    if(NewPilha != NULL)
                    {
                      
                      printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                      printf("ᯤ         Inserir Musica         ᯤ\n");
                      printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                      printf("ᯤ       Insira o desejado        ᯤ\n");
                      printf("ᯤ      1-Inserir por titulo      ᯤ\n");
                      printf("ᯤ      2-Inserir por artista     ᯤ\n");
                      printf("ᯤ      3-Inserir por letra       ᯤ\n");
                      printf("ᯤ      4-Inserir por codigo      ᯤ\n");
                      printf("ᯤ       0-Voltar ao menu         ᯤ\n");
                      printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
                      scanf("%d", &escolha3);
                      
                        switch(escolha3)
                        {
                          case 1:
                          {
                            printf("\nInsira o titulo da musica:\n");
                            getchar();
                            fgets(tituloN, 255, stdin);
                            tituloN[strcspn(tituloN, "\n")] = '\0';

                            struct musica *music = procuratitulo(lista, tituloN);
                            
                            if(music != NULL)
                            {
                              imprimeuma(music);
                              printf("\nDeseja adicionar a musica a playlist? (1-Sim/2-Nao)\n");
                              scanf("%d", &choice);
                                if(choice == 1)
                                {
                                  NewNodoPilha = crianodo_pilha(music);
                                  push(NewPilha, NewNodoPilha);
                                }
                                else
                                {
                                  printf("\nMusica nao adicionada!\n");
                                }
                            }
                            else
                            {
                              printf("\nMusica nao encontrada!\n");    
                            }
                            break;
                          }
                          case 2:
                          {
                            printf("Insira o artista da musica:\n");
                            getchar();
                            fgets(artistaN, 255, stdin);
                            artistaN[strcspn(artistaN, "\n")] = '\0';
                            
                            struct musica *music = artistaplay(lista, artistaN);
                            
                            if(music != NULL)
                              {
                                NewNodoPilha = crianodo_pilha(music);
                                push(NewPilha, NewNodoPilha);
                              }
                            else
                              {
                                printf("\nMusica nao encontrada!\n");    
                              }
                              break;
                          }
                          case 3:
                          {
                            printf("\nInsira a letra da musica:\n");
                            getchar();
                            fgets(letraN, 255, stdin);
                            letraN[strcspn(letraN, "\n")] = '\0';

                            struct musica *music = procuraletra(lista, letraN);

                            if(music != NULL)
                            {
                              imprimeuma(music);
                              printf("\nDeseja adicionar a musica a playlist? (1-Sim/2-Nao)\n");
                              scanf("%d", &choice);
                              if (choice == 1)
                              {
                              NewNodoPilha = crianodo_pilha(music);
                              push(NewPilha, NewNodoPilha);
                              }
                              else
                              {
                                printf("\nMusica nao adicionada!\n");
                              }
                            }
                            else
                            {
                              printf("\nMusica nao encontrada!\n");
                            }
                            break;
                          }
                          case 4:
                          {
                            printf("\nInsira o codigo da musica:\n");
                            scanf("%d", &codigoN);
                            
                            struct musica *music = procuracodigo(lista, codigoN);

                            if(music != NULL)
                            {
                              imprimeuma(music);
                              printf("\nDeseja adicionar a musica a playlist? (1-Sim/2-Nao)\n");
                              scanf("%d", &choice);
                              if(choice == 1)
                              {
                              NewNodoPilha = crianodo_pilha(music);
                              push(NewPilha, NewNodoPilha);
                              }
                              else
                              {
                                printf("\nMusica nao adicionada!\n");
                              }
                            }
                            else
                            {
                              printf("\nMusica nao encontrada!\n");
                            }
                          }
                          case 0:
                            break;
                          default:
                            printf("\nOpcao invalida!\n");
                        }
                    }
                    break;
                  }
                            case 2:
                            {
                              int size;
                              printf("Insira o tamanho da sua playlist aleatoria: ");
                              scanf("%d", &size);

                                criaplaylistaleatoria(lista, NewQueue, size);
                                break;
                            }
                            case 3:
                              {
                                printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                printf("ᯤ           Playlist             ᯤ\n");
                                printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                printf("ᯤ       Insira o desejado        ᯤ\n");
                                printf("ᯤ   1-Ver playlist customizada   ᯤ\n");
                                printf("ᯤ    2-Ver Playlist aleatoria    ᯤ\n");
                                printf("ᯤ       0-Voltar ao menu         ᯤ\n");
                                printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
                                scanf("%d", &escolha3);
                                switch(escolha3)
                                 {
                                  case 1:
                                  {
                                    if(NewPilha == NULL || NewPilha->Pilha == NULL)
                                      {
                                       printf("\nCrie uma playlist antes!\n"); 
                                        break;
                                      }
                                    printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                    printf("            Sua Playlist            \n");
                                    imprimir_pilha(NewPilha);
                                    printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                    break;
                                  }
                                 case 2:
                                   {
                                     if(NewQueue == NULL || NewQueue->head == NULL)
                                       {
                                        printf("\nCrie uma playlist antes!\n"); 
                                         break;
                                       }
                                     printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                     printf("            Sua Playlist            \n");
                                     imprimir_queue(NewQueue);
                                     printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                     break;
                                   }
                                   case 0:
                                     break;
                                   default:
                                     printf("\nOpcao invalida!\n");
                                }
                                break;
                              }
                            case 4:
                              {
                                printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                printf("ᯤ        Executar Playlist       ᯤ\n");
                                printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
                                printf("ᯤ       Insira o desejado        ᯤ\n");
                                printf("ᯤ     1-Playlist customizada     ᯤ\n");
                                printf("ᯤ      2-Playlist aleatoria      ᯤ\n");
                                printf("ᯤ       0-Voltar ao menu         ᯤ\n");
                                printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
                                scanf("%d", &escolha3);

                                switch(escolha3)
                                  {
                                    case 1:
                                      {
                                        if(NewPilha == NULL)
                                        {
                                         printf("\nCrie uma playlist antes!\n"); 
                                        }
                                        executacustom(NewPilha);
                                        break;
                                      }
                                    case 2:
                                      {
                                        if(NewQueue == NULL)
                                          {
                                           printf("\nCrie uma playlist antes!\n"); 
                                          }
                                        executaaleatoria(NewQueue);
                                        break;
                                      }
                                    case 0:
                                      break;
                                    default:
                                      printf("\nOpcao invalida!\n");
                                  }
                              }
                case 0:
                  break;
                default:
                  printf("\nOpcao invalida!\n");
              }
          }
        break;
        }
      case 4:
        {
          if (lista != NULL && lista->tamanho == 0)
            {
              printf("\nCarregue o acervo antes!\n");
              break;
            }
        
            escolha3 = -1;
            printf("\nᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
            printf("ᯤ           Relatorio            ᯤ\n");
            printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n");
            printf("ᯤ       Insira o desejado        ᯤ\n");
            printf("ᯤ     1-Relatorio do acervo      ᯤ\n");
            printf("ᯤ 2-Relatorio da playlist custom ᯤ\n");
            printf("ᯤ 3-Relatorio da playlist random ᯤ\n");
            printf("ᯤ       0-Voltar ao menu         ᯤ\n");
            printf("ᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤᯤ\n\n");
            scanf("%d", &escolha2);
            switch(escolha2)
              {
                case 1:
                  relatorioacervo(lista);
                  break;
                case 2:
                  relatorioplaylistcustom(NewPilha);
                  break;
                case 3:
                  relatorioplaylistaleatoria(NewQueue);
                  break;
                case 0:
                  break;
                default:
                  printf("\nOpcao invalida!\n");
              }
          break;
        }
      case 0:
        {
           printf("\nSaindo...\n");
           break;
        }
        default:
          {
            printf("\nComando indesejado.\n");
          }
    }  
  }
}
  
