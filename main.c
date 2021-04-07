
///Nomes: Noé Medina Calixto , Matheus Valverde Paiva
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct animais_abandonados pet;
typedef struct animais_adotados struct_adotados;
typedef struct racas_diferentes struct_raca;

struct racas_diferentes

{
    char racaraca[50];
    int cont;
    struct racas *prox;
};

struct animais_abandonados
{
    char nome[50];
    char sexo[5];
    int  idade;
    char especie[50];
    char raca[50];
    char cg[100];
    int id;
    int con; //1 = adotado, 2 = excluido, 0 = presente

    struct pets *prox;
};

struct animais_adotados
{
    char nome[50];
    char especie[50];
    char raca[50];
    char sexo[5];
    int  idade;
    char cg[100];
    int  id;
    int  con;

    struct animal_adotados *prox;
};

void incluir_animal(pet **inicio_pet,int *reg[],int *cont,struct_raca **inicio_raca)
{
    int  i, letra;
        system("cls");
        pet *novo = malloc(sizeof(pet));
        if(novo==NULL)
        {
            return;
        }
        printf("\n Registrar um animal \n");
        fflush(stdin);
        printf("\n Nome:");
        gets(novo->nome);
        letra = novo->nome[0];
        novo->nome[0] = letra;
        fflush(stdin);
        printf(" Espécie: ");
        gets(novo->especie);
        letra = novo->especie[0];
        novo->especie[0] = letra;
        if(verificar_especie(*inicio_raca,novo)==1)
        {
            struct_raca *novo2 = malloc(sizeof(struct_raca));

            strcpy(novo2->racaraca,novo->especie);
            novo2 -> cont = 1;

            novo2 -> prox = (*inicio_raca);
            (*inicio_raca) = novo2;
        }
        fflush(stdin);
        printf(" Raça: ");
        gets(novo->raca);

        letra = novo->raca[0];
        novo->raca[0] = letra;

        fflush(stdin);
        printf(" Sexo do animal(Macho/Femea):");
        gets(novo->sexo);

        letra = novo->sexo[0];
        novo->sexo[0] = letra;

        printf(" Idade: ");
        fflush(stdin);
        scanf("%d",&novo->idade);

        fflush(stdin);
        printf(" Características gerais: ");
        gets(novo->cg);

        novo->con=0;

        system("cls");

        novo->id = 1;
        reg [*cont] = novo->id;

        //verifica se ID ja existe, ou ja foi cadastrado um dia
        for(int i=0;i<*cont;i++)
        {
            if(reg[i]==novo->id)
           {
                while(reg[i]==novo->id)
                {
                    novo->id++;
                    reg[*cont] = novo->id;
                }
            }
        }
        (*cont)++;
        novo -> prox = (*inicio_pet);
        (*inicio_pet) = novo;
}

int verificar_especie(struct_raca *inicio_raca,pet *novo)
{
    while(inicio_raca!=NULL)
    {
        if(strcasecmp(novo->especie,inicio_raca->racaraca)==0)
        {
            inicio_raca -> cont = (inicio_raca -> cont)+1;
            return 0;
        }
        inicio_raca=inicio_raca->prox;
    }
    return 1;
}

void mostrar_contador(pet *inicio_pet)
{
    system("cls");
    int quantidade=0;

        while(inicio_pet!=NULL)
        {
            inicio_pet = inicio_pet -> prox;
            quantidade++;
        }
        printf("\n Quantidade de animais cadastrados: %d\n\n",quantidade);

    system("pause");
    system("cls");
}

void modificar(pet *inicio_pet)
{

    int id,es=0; //cria as variaves
    char letra;
    int ida,idd;

    printf("ID: ");
    scanf("%d",&id); //digita id que voce vai querer alterar

    //verifica se id existe

    system("cls"); //limpa tela
    while (inicio_pet!= NULL) //anda com a lista
    {
            if(id == inicio_pet -> id) //se ID for encontrado, ele compara no a no para achar
            {
                printf("\n Nome: %s\n",inicio_pet->nome);
                printf(" Espécie: %s\n",inicio_pet->especie);
                printf(" Raça: %s\n",inicio_pet->raca);
                printf(" Sexo: %s\n",inicio_pet->sexo);
                printf(" Idade: %d\n",inicio_pet->idade);
                printf(" Características gerais : %s\n",inicio_pet->cg);

                printf("\n 1 - Modificar         |\n"
                         " 0 - voltar ao menu    |\n"
                         "\n Escolha: ");
                scanf("%d",&es);

                if(es == 0) //se for igual a 0
                {
                    system("cls"); //lima a tela
                    return; //retorna para funcao principal
                }
                //Faz a releitura do NO, que no caso seria o cadastro
                if(es == 1)
                {
                    fflush(stdin);
                    printf("\n Nome:");
                    gets(inicio_pet->nome);

                    letra = inicio_pet->nome[0];
                    inicio_pet->nome[0] = letra;

                    fflush(stdin);
                    printf(" Espécie: ");
                    gets(inicio_pet->especie);

                    letra = inicio_pet->especie[0];
                    inicio_pet->especie[0] = letra;

                    fflush(stdin);
                    printf(" Raça: ");
                    gets(inicio_pet->raca);

                    letra = inicio_pet->raca[0];
                    inicio_pet->raca[0] = letra;

                    fflush(stdin);
                    printf(" Sexo,(F)fêmea ou (M)Macho: ");
                    gets(inicio_pet->sexo);

                    letra = inicio_pet->sexo[0];
                    inicio_pet->sexo[0] = letra;

                    fflush(stdin);
                    printf(" Idade: ");
                    scanf("%d",&ida);

                    inicio_pet->idade = ida;

                    fflush(stdin);
                    printf(" Características gerais: ");

                    gets(inicio_pet->cg);
                    fflush(stdin);

                    system("PAUSE\n");
                    system("cls");
                }
            }
            inicio_pet = inicio_pet -> prox;
    }
    system("cls");
    // verifica resposta 1: edicao do cadastro, 2: excluir, 0: return
}

void buscar_especies_racas(pet *inicio_pet)
{
    char raca[50],especie[50];
    int  volta1=0,volta=0,cont=0,escolha=99;

    printf("Nome do raca: ");
    fflush(stdin);
    gets(raca);

    printf("Especie do animal: ");
    fflush(stdin);
    gets(especie);

    system("cls");
    printf("\n\n _ Resultados de busca _ \n");

    while(inicio_pet != NULL)
    {
        //verifica a volta do valor para depois (no if) selecionar um caso em que as opcoes estejam batendo com o escrito anteriormente
        volta = strcmp(inicio_pet->especie,especie);
        volta1 = strcmp(inicio_pet->raca,raca);
            if(volta == 0 && volta1 == 0 )
            {
                printf("\n Nome: %s\n",inicio_pet->nome);
                printf(" Espécie: %s\n",inicio_pet->especie);
                printf(" Raça: %s\n",inicio_pet->raca);
                printf(" Sexo: %s\n",inicio_pet->sexo);
                printf(" Idade: %d\n",inicio_pet->idade);
                printf(" Características gerais : %s\n",inicio_pet->cg);
                printf(" ID:%d",inicio_pet->id);
                cont ++;
            }
            inicio_pet = inicio_pet -> prox;
    }
    system("pause");
    system("cls");
}

void buscar_especies_racas_sexos(pet *inicio_pet)
{
    char raca[50],especie[50],sexo[02];
    int  volta1=0,volta=0,volta3=0,cont=0,escolha=99;

    printf("\nSexo: ");
    fflush(stdin);
    gets(sexo);

    printf("Raça: ");
    fflush(stdin);
    gets(raca);

    printf("Especie do animal: ");
    fflush(stdin);
    gets(especie);

    system("cls");
     printf("\n\n |  Resultados de busca  | \n\n\n");

    while(inicio_pet != NULL)
    {
        //verifica a volta do valor para depois (no if) selecionar um caso em que as opcoes estejam batendo com o escrito anteriormente
        volta = strcmp(inicio_pet->especie,especie);
        volta1 = strcmp(inicio_pet->raca,raca);
        volta3 = strcmp(inicio_pet->sexo,sexo);

            if(volta == 0 && volta1 == 0 && volta3 == 0)
            {
                printf("\n Nome: %s\n",inicio_pet->nome);
                printf(" Espécie: %s\n",inicio_pet->especie);
                printf(" Raça: %s\n",inicio_pet->raca);
                printf(" Sexo: %s\n",inicio_pet->sexo);
                printf(" Idade: %d\n",inicio_pet->idade);
                printf(" Características gerais : %s\n",inicio_pet->cg);
                printf(" ID:%d",inicio_pet->id);
                printf("\n----------------------------------------\n");
                cont ++;
            }
            inicio_pet = inicio_pet -> prox;
    }
    system("pause");
    system("cls");
}

void mostrar_especies(struct_raca *inicio_raca)
{
    system("cls");
    printf("                  Especies                             \n\n");

    while(inicio_raca!=NULL)
    {
        printf("\n\t| Especie: %s \ Quantidade: %d|\n",inicio_raca->racaraca,inicio_raca->cont);
        inicio_raca = inicio_raca -> prox; //anda com a lista para o proximo NO
    }
    printf("\n\n"); //pula linha
    system("pause"); //pausa o programa
    system("cls"); //limpa a tela
}

void deletar(struct_adotados **inicio_adotados,pet **inicio_pet,struct_raca **inicio_raca)
{
    int id,es=0,es1=1,ida,idd;
    char condicao[15]="Adotado";
    int cont=0,volta=1;

    pet *novo3 = malloc(sizeof(pet));

    //cria ponteiro do tipo da struct e quarta a cabeca inicial, para a lista n perder nenhum NO
    pet *aux;
    pet *oldinicio_pet = malloc(sizeof(pet));
    struct_raca *oldinicio_raca = malloc(sizeof(pet));

    //guarda inicio para nao perder a lista toda
    oldinicio_pet = (*inicio_pet);
    oldinicio_raca = (*inicio_raca);

    //guarda ponteiro anterior e o proximo
    pet *pet_prox = malloc(sizeof(pet));
    pet *pet_ant = malloc(sizeof(pet));

    printf("ID: ");
    scanf("%d",&id);
    //verifica se id existe
    system("cls");
    //anda com a lista

    while ((*inicio_pet)!= NULL)
    {
        pet_prox = (*inicio_pet)->prox;

        //se ID for encontrado, ele compara no a no para achar
        if(id == (*inicio_pet) -> id)
        {
            printf("\n Nome: %s\n",(*inicio_pet)->nome);
            printf(" Espécie: %s\n",(*inicio_pet)->especie);
            printf(" Raça: %s\n",(*inicio_pet)->raca);
            printf(" Sexo: %s\n",(*inicio_pet)->sexo);
            printf(" Idade: %d\n",(*inicio_pet)->idade);
            printf(" Características gerais : %s\n",(*inicio_pet)->cg);
            printf(" 1 - Excluir           \n"
                   " 0 - voltar ao menu    \n"
                   " Escolha: ");

            scanf("%d",&es);

            if(es == 0)
            {
                system("cls");
                (*inicio_pet)=oldinicio_pet;
                return;
            }

            printf("\n\nO animal foi adotado ?\n\n"
                   " 1 - Sim\n"
                   " 2 - Não\n"
                   " Escolher: ");

            scanf("%d",&es1);

            // Guarda o animal adotado e deletado
            if(es1 == 1 || es1 == 2)
            {
                //passa as informacoes de uma struct para outra

                strcpy(novo3 -> nome,(*inicio_pet)->nome);
                strcpy(novo3 -> especie,(*inicio_pet)->especie);
                strcpy(novo3 -> raca,(*inicio_pet)->raca);
                strcpy(novo3 -> sexo,(*inicio_pet)->sexo);
                strcpy(novo3 -> cg,(*inicio_pet)->cg);
                novo3 -> idade = (*inicio_pet)->idade;
                novo3 -> id = (*inicio_pet)->id;
                if(es1 == 1) novo3 -> con = (*inicio_pet)->con+1;
                if(es1 == 2) novo3 -> con = (*inicio_pet)->con+2;

                //adiciona no a lista de adotados

                novo3 -> prox = (*inicio_adotados);
                (*inicio_adotados) = novo3;
                //(*inicio3) = (*inicio3)->condicao;
            }
            if(es == 1)
            {
                system("cls");
                //deleta o primeiro no da lista
                if(cont == 0)
                {
                    //ZERA a quantidade da especie
                    while((*inicio_raca)!=NULL)
                    {
                        if(volta = strcmp((*inicio_raca)->racaraca,(*inicio_pet)->especie)==0)
                        {
                            (*inicio_raca)->cont = ((*inicio_raca)->cont)-1;
                            break;
                        }
                        (*inicio_raca)=(*inicio_raca)->prox;
                    }
                    //deleta ANIMAL na struct
                    oldinicio_pet = (*inicio_pet);
                    aux = (*inicio_pet);
                    (*inicio_pet)=(*inicio_pet)->prox;
                    free(aux);
                    break;
                }
                //deleta no do meio e final da lista
                if(cont > 0 && (*inicio_pet)->id == id)
                {
                    while((*inicio_raca)!=NULL)
                    {
                        if(volta = strcmp((*inicio_raca)->racaraca,(*inicio_pet)->especie)==0)
                        {
                            (*inicio_raca)->cont = ((*inicio_raca)->cont)-1;
                            break;
                        }
                        (*inicio_raca)=(*inicio_raca)->prox;
                    }

                    printf("entrou");

                    aux = (*inicio_pet);

                    (*inicio_pet)= pet_ant;
                    (*inicio_pet)->prox = pet_prox;

                    free(aux);
                    break;
                }
            }
        }
        pet_ant = (*inicio_pet);
        (*inicio_pet)=(*inicio_pet)->prox;

        //contador para realizar a contagem em qual posicao o no esta
        cont++;
    }
    //caso nao for o primeiro,voltaremos a lista no inicio
    if(cont > 0)
    {
        (*inicio_pet)=oldinicio_pet;
    }

    (*inicio_raca)=oldinicio_raca;
    //inicio da lista e realocado novamente para o valor do começo
}

void listar_animais_adotados(pet *inicio_adotados)
{
    system("cls");
    if(inicio_adotados == NULL)
    {
        printf("\n Nenhum animal cadastrado\n\n");
    }
    else
    {
        printf("\n> Listagem de animais adotados\n");
        while(inicio_adotados != NULL)
        {
            printf("\n Nome: %s\n",inicio_adotados->nome);
            printf(" Espécie: %s\n",inicio_adotados->especie);
            printf(" Raça: %s\n",inicio_adotados->raca);
            printf(" Sexo: %s\n",inicio_adotados->sexo);
            printf(" Idade: %d\n",inicio_adotados->idade);
            printf(" Características gerais : %s\n",inicio_adotados->cg);
            printf(" id: %d\n",inicio_adotados->id);
            if (inicio_adotados->con == 1) printf("\n\n ADOTADO\n");
            if (inicio_adotados->con == 2) printf("\n\n EXCLUIDO\n");

            inicio_adotados = inicio_adotados -> prox;
        }
    }
    system("pause");
    system("cls");
}

void buscar_nomes_adotados(pet *inicio_adotados)
{
    char nome[50];
    int  volta=0,cont=0;
    system("cls");

        printf("Nome do animal: ");
        fflush(stdin);
        gets(nome);

    system("cls");

    if(inicio_adotados == NULL)
    {
        return;
    }

    while(inicio_adotados != NULL)
    {
            volta = strcmp(inicio_adotados->nome,nome);
            if(volta == 0)
            {
                printf("\n Nome: %s\n",inicio_adotados->nome);
                printf(" Espécie: %s\n",inicio_adotados->especie);
                printf(" Raça: %s\n",inicio_adotados->raca);
                printf(" Sexo: %s\n",inicio_adotados->sexo);
                printf(" Idade: %d\n",inicio_adotados->idade);
                printf(" Características gerais : %s\n",inicio_adotados->cg);
                printf(" ID:%d",inicio_adotados->id);
                cont ++;
            }
            inicio_adotados = inicio_adotado -> prox;
    }
    system("pause");
    system("cls");
}

void reinserir_animal(pet **inicio_pet, struct_adotados **inicio_adotados)
{
    int id,es=0,cont=0;
    struct_adotados *novo3 = malloc(sizeof(struct_adotados));
    printf("\nProcurar id\n Caso não tenha o id, procure pelas informações do animal\n ID:");
    scanf("%d",&id);

    struct_adotados *aux = malloc(sizeof(struct_adotados));

    struct_adotados *oldhead = malloc(sizeof(struct_adotados));

    struct_adotados *pet_prox = malloc(sizeof(struct_adotados));
    struct_adotados *pet_ant = malloc(sizeof(struct_adotados));

    //guarda inicio lista
    oldhead = (*inicio_adotados);

    //procura pet por ID
    while((*inicio_adotados)!=NULL)
    {
        pet_prox = (*inicio_adotados)->prox;

        system("cls");
        if((*inicio_adotados)->id == id)
        {
            printf("\n Nome: %s\n",(*inicio_adotados)->nome);
            printf(" Sexo: %s\n",(*inicio_adotados)->sexo);
            printf(" Idade: %d\n",(*inicio_adotados)->idade);
            printf(" Espécie: %s\n",(*inicio_adotados)->especie);
            printf(" Raça: %s\n",(*inicio_adotados)->raca);
            printf(" Características gerais : %s\n",(*inicio_adotados)->cg);
            printf(" ID:%d",(*inicio_adotados)->id);
            if ((*inicio_adotados)->con == 1) printf("\n\n Condição: Adotado");
            if ((*inicio_adotados)->con == 2) printf("\n\n Condição: Exluido");

            printf("\n----------------------------------------\n");

            //verifica condicao e mostra para o usuario

            printf("\n|1.Realocar animal\n");
            printf("|2.Não realocar\n");
            printf("\nEscolha:");

            scanf("%d",&es);

            //realoca para lista lista principal
            if(es == 1)
            {
            //Passa para um NO novo3, para n causar erros

                strcpy(novo3 -> nome,(*inicio_adotados)->nome);
                strcpy(novo3 -> especie,(*inicio_adotados)->especie);
                strcpy(novo3 -> raca,(*inicio_adotados)->raca);
                strcpy(novo3 -> sexo,(*inicio_adotados)->sexo);
                strcpy(novo3 -> cg,(*inicio_adotados)->cg);
                novo3 -> idade = (*inicio_adotados)->idade;
                novo3 -> id = (*inicio_adotados)->id;
                novo3 -> con = 0;

                novo3 -> prox = (*inicio_pet);
                (*inicio_pet) = novo3;

                //DELETA NO do pet que foi REALOCADO
                if(cont == 0)
                {
                    (*inicio_adotados) = (*inicio_adotados)->prox;
                    aux = (*inicio_adotados);
                    free(aux);
                    return;
                }
                //se for um NO do meio ou fim
                if(cont > 0)
                {
                    aux = (*inicio_adotados);
                    (*inicio_adotados)= pet_ant;
                    (*inicio_adotados)->prox = pet_prox;
                    free(aux);
                }
            }
            if(es == 2) return;

            system("pause");
            system("cls");
        }
        pet_ant = (*inicio_adotados);

        (*inicio_adotados)=(*inicio_adotados)->prox;

        cont++;
    }
    (*inicio_adotados) = oldhead;
    system("cls");
}

void buscar_nomes(pet *inicio_pet)
{
    char nome[50];
    int  volta=0,cont=0;
    system("cls");

        printf("Nome do animal: ");
        fflush(stdin);
        gets(nome);

    system("cls");

    if(inicio_pet == NULL)
    {
        return;
    }

    while(inicio_pet != NULL)
    {
            volta = strcmp(inicio_pet->nome,nome);
            if(volta == 0)
            {
                printf("\n Nome: %s\n",inicio_pet->nome);
                printf(" Sexo: %s\n",inicio_pet->sexo);
                printf(" Idade: %d\n",inicio_pet->idade);
                printf(" Espécie: %s\n",inicio_pet->especie);
                printf(" Raça: %s\n",inicio_pet->raca);
                printf(" Características gerais : %s\n",inicio_pet->cg);
                printf(" ID:%d",inicio_pet->id);
                cont ++;
            }
            inicio_pet = inicio_pet -> prox;
    }
    system("pause");
    system("cls");
}

void buscar_especies(pet *inicio_pet)
{
    char especie[50];
    int  volta=0,cont=0;
    system("cls");

        printf("Especie do animal: ");
        fflush(stdin);
        gets(especie);

    system("cls");

    if(inicio_pet == NULL)
    {
        return;
    }

    while(inicio_pet != NULL)
    {
            volta = strcmp(inicio_pet->especie,especie);
            if(volta == 0)
            {
                printf("\n Nome: %s\n",inicio_pet->nome);
                printf(" Sexo: %s\n",inicio_pet->sexo);
                printf(" Idade: %d\n",inicio_pet->idade);
                printf(" Espécie: %s\n",inicio_pet->especie);
                printf(" Raça: %s\n",inicio_pet->raca);
                printf(" Características gerais : %s\n",inicio_pet->cg);
                printf(" ID:%d",inicio_pet->id);
                cont ++;
            }
            inicio_pet = inicio_pet -> prox;
    }
    system("pause");
    system("cls");
}

void listar_animais(pet *inicio_pet)
{
    system("cls"); //Limpa tela

    //se lista for vazia, printa a mensagem
    if(inicio_pet == NULL)
    {
      printf("\n Nenhum animal cadastrado\n\n");
    }
    else
    {
        printf("\n> Listagem de animais\n");
        //mostra ao usuario os animais cadastrados
        while(inicio_pet != NULL)
        {
            printf("\n Nome: %s\n",inicio_pet->nome);
            printf(" Espécie: %s\n",inicio_pet->especie);
            printf(" Raça: %s\n",inicio_pet->raca);
            printf(" Sexo: %s\n",inicio_pet->sexo);
            printf(" Idade: %d\n",inicio_pet->idade);
            printf(" Características gerais : %s\n",inicio_pet->cg);
            printf(" id: %d\n",inicio_pet->id);
            printf("\n------------------------------------------\n");

            inicio_pet = inicio_pet -> prox;
        }
    }
    system("pause");
    system("cls");
}

int main()
{
    system("COLOR F4");

    int n=44,idd=0000,reg[10000]={NULL},cont=0;
    pet *inicio_pet = NULL; //lista vazia
    struct_raca *inicio_raca = NULL; //lista de raca //lista vazia
    struct_adotados *inicio_adotados = NULL; //lista de animais apagados
    //menu
    do
    {

    printf("\n"
       "\t\t\t 1 - Adicionar Animal\n"
       "\t\t\t 2 - Remover animal\n"
       "\t\t\t 3 - Buscar animal por nome\n"
       "\t\t\t 4 - Buscar animais por espécie\n"
       "\t\t\t 5 - Buscar animal por espécie e raça\n"
       "\t\t\t 6 - Buscar de animais por espécie, raça e sexo\n"
       "\t\t\t 7 - Contagem de animais\n"
       "\t\t\t 8 - Contagem por espécie\n"
       "\t\t\t 9 - Listagem de todos os animais cadastrados\n"
       "\t\t\t 10 - Animais ja adotados\n"
       "\t\t\t 11 - Procurar animal ja adotado\n"
       "\t\t\t 12 - Reacolocar animal já excluido ou adotado\n"
       "\t\t\t 13 - Atualizar dados do animal\n"
       "\t\t\t 14 - Dark Mode\n"
       "\t\t\t 15 - White Mode\n"
       "\n\n\t\t\tEscolha: "
       );

    //funcao para ver se e um inteiro msm
        scanf("%d",&n);

    switch(n)
    {

        case 1:
            incluir_animal(&inicio_pet,&reg,&cont,&inicio_raca); //inclue novo animal
        break;

        case 2:
            deletar(&inicio_adotados,&inicio_pet,&inicio_raca);
        break;

        case 3:
            buscar_nomes(inicio_pet);
        break;

        case 4:
            buscar_especies(inicio_pet);
        break;

        case 5:
            buscar_especies_racas(inicio_pet);
        break;

        case 6:
            buscar_especies_racas_sexos(inicio_pet);
        break;

        case 7:
            mostrar_contador(inicio_pet);
        break;

        case 8:
            mostrar_especies(inicio_raca);
        break;

        case 9:
            listar_animais(inicio_pet);
        break;

        case 10:
            listar_animais_adotados(inicio_adotados);
        break;

        case 11:
            buscar_nomes_adotados(inicio_adotados);
        break;

        case 12:
            reinserir_animal(&inicio_pet,&inicio_adotados);
        case 13:
            modificar(inicio_pet);
        break;

        case 14:
            system("COLOR 6");
            system("cls");
        break;
        case 15:
            system("COLOR F4");
            system("cls");
        break;
        }

    }while(n!=0);

    return 0;
}