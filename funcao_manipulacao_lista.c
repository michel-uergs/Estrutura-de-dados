


/*
 TODAS AS FUNCOES DESENVOLVIDAS EM AULA
    - Nao implementei a funcao insere ordenado porem a funcao insere meio ja insere de forma ordenada
      e a funcao insere ante ou depois de K insere no meio na posicao desejada
      
    - Nenhuma funcao tem todas as validaçoes entao cuidar com algumas inserçoes
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int cod;
    struct no *prox;
    struct no *ant;
}no;

void imprimi(no **lista)
{
    no *aux;

    aux = *lista;
    
    while (aux != NULL)
    {
        printf("dado: %d endereco: %d proximo: %d\n", aux->cod, aux, aux->prox);
        aux = aux->prox;
    }
}

void insere_fim(no **lista, int num)
{
    no *novo;
    no *aux;

    novo = (no*) malloc(sizeof(no));
    aux = *lista;

    novo->cod   = num;
    novo->prox  = NULL;

    if(novo)
    {
        if(*lista==NULL)
        {
            *lista = novo;
        }
        else
        {
            while (aux->prox !=NULL)
            {
                aux = aux->prox;
            }

            aux->prox = novo;
        }
    }
    else
    {
        printf("\nErro ao Alocar memoria! \n");
    }
     
}

void insere_meio(no **lista, int num)
{
    no *novo;
    no *aux;
    no *ant;
    
    novo = (no*) malloc(sizeof(no));
    
    aux = *lista;
    ant = aux;
    novo->cod = num;
    novo->prox = NULL;
    
    if(novo)
    {
        if(*lista==NULL)
        {
            *lista = novo;
        }
        else
        {
            if(aux->cod >= num)
            {
                // Insere no inicio 
                novo->prox = aux;
                *lista = novo;
            }
            else
            {
                while (aux !=NULL && aux->cod < num)
                {
                    ant = aux;
                    aux = aux->prox;
                }
                novo->prox = aux;
                ant->prox = novo;
            }
        }
    }
    else
    {
        printf("\nErro ao Alocar memoria! \n");
    }
    
}

void insere_inicio(no **lista, int num)
{
    no *novo;
    novo = (no*) malloc(sizeof(no));

    if(novo)
    {
      
        novo->cod =num;
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        printf("\nErro ao Alocar memoria! \n");
    }
    
}

void excluir_fim(no **lista)
{
    no *aux;
    no *aux_2;
    
    aux = *lista;
    aux_2 = aux;
    
    if(*lista !=NULL)
    {
        while(aux->prox !=NULL)
        {
            aux_2 = aux;
            aux = aux->prox;
        }
        free(aux);
        aux_2->prox = NULL;
    }
    else
    {
        printf("\nlista vazia");
    }
}

void excluir_inicio(no **lista)
{
    no *aux;
    aux = *lista;
    
    if(*lista !=NULL)
    {
        if(aux->prox==NULL)
        {
            free(aux);
            *lista = NULL;
        }
        else
        {
            aux = aux->prox;
            free(*lista);
            *lista = aux;
        }

    }
}

void excluir_meio(no **lista, int num)
{
    no *aux;
    no *anterior;
    
    aux = *lista;
    anterior = aux;
    
    if(*lista != NULL) 
    {
        if(aux->cod == num)
        {
            *lista = aux->prox;
            free(aux);
        }
        else
        {
            while(aux!=NULL && aux->cod!=num)
            {
                anterior = aux;
                aux = aux->prox;    
            }
        
            if(aux==NULL)
            {
                printf("\n Item nao encontrado! ");
            }
            else
            {
                anterior->prox = aux->prox;
                free(aux);
            }
        }
    }
    
}

int busca_valor(no **lista, int num)
{
    no *aux;
    aux = *lista;
    if(aux ==NULL)
    {
        printf("\n Lista Vazia!");
        return 0;
    }
    else
    {
        while(aux!=NULL && aux->cod != num)
        {
            aux = aux->prox;
        }
        if(aux->cod == num)
        {
            printf("\n valor: %d endereco: %d proximo_endereco: %d", aux->cod, aux, aux->prox);
            return 1;
        }
        else
        {
            printf("\n Valor Nao Encontrado!");
            return 0;
        }
        
    }
}

void inserir_antes_k(no **lista, int num, int valor)
{
    no *aux;
    no *ant;
    no *novo;
    novo = (no*) malloc(sizeof(no));
    aux = *lista;
    ant = aux;
    
    if(novo)
    {
        novo->cod = valor;
        novo->prox = NULL;
        
        if(aux->cod == num)
        {
            novo->prox = aux;
            *lista = novo;
        }
        else
        {
            while(aux!=NULL && aux->cod != num)
            {
                ant = aux;
                aux = aux->prox;
            }
            novo->prox = aux;
            ant->prox = novo;
        }
    }
}

void inserir_depois_k(no **lista, int num, int valor)
{
    
    no *aux;
    no *ant;
    no *novo;
    novo = (no*) malloc(sizeof(no));
    aux = *lista;
    ant = aux;
    
    if(novo)
    {
        novo->cod = valor;
        novo->prox = NULL;
        
        if(aux->cod == num)
        {
            novo->prox = aux;
            *lista = novo;
        }
        else
        {
            while(aux!=NULL && aux->cod != num)
            {
                ant = aux;
                aux = aux->prox;
            }
            if(aux !=NULL )
            {
                novo->prox = aux->prox;
                aux->prox = novo;
            }
        }
    }
}

int busca_no(no **lista, int valor)
{
    if((*lista) == NULL)
    {
        printf("\n Lista Vazia!");
        return 0;
    }
    else
    {
        if((*lista)->cod == valor)
        {
            return 1;
        }
        else
        {
            return busca_no(&(*lista)->prox, valor);
        }
    }
}

void tranforma_circular(no **lista)
{
    no *aux;
    no *ant;
    aux = *lista;
    ant = aux;
    
    if(aux==NULL)
    {
        printf("\nLista Vazia!");
    }
    else
    {
        if(aux->prox==NULL)
        {
            printf("\n Um unico elemento impossivel transformar em circular");
        }
        else
        {
            while(aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = *lista;
        }
    }
}

void imprimi_circular(no **lista)
{
    no *aux;
    aux = *lista;
    
    if(aux!=NULL)
    {
        do{
            printf("\n dado: %d enderco: %d proximo: %d", aux->cod, aux, aux->prox);
            aux = aux->prox;
            
        }while(aux != *lista);
    }   
    else
    {
        printf("\nLista Vazia!");
    }
}

int main()
{
    int numero, valor, op, cont=1;
    no *lista;
    //no *lista_fim;

    lista = NULL;
    
    while (cont)
    {
        printf("\n Escolha uma opcao ");
        printf("\n 1  - Sair");
        printf("\n 2  - Imprimir lista");
        printf("\n 3  - Insere inicio");
        printf("\n 4  - Insere meio");
        printf("\n 5  - Insere fim");
        printf("\n 6  - Excluir fim");
        printf("\n 7  - Excluir inicio");
        printf("\n 8  - Excluir no meio");
        printf("\n 9  - Busca valor");
        printf("\n 10 - Inserir antes de K-valor");
        printf("\n 11 - Inserir depois de K-valor ");
        printf("\n 12 - Buscar valor recursivo ");
        printf("\n 13 - Transforma em Circular ");
        printf("\n 14 - Imprimi Circular \n op:");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                cont = 0;
                break;
            case 2:
                imprimi(&lista);
                break;
            case 3:
                printf("\nDigite um valor: ");
                scanf("%d", &numero);
                insere_inicio(&lista, numero);
                break;
            case 4:
                printf("\nDigite um valor: ");
                scanf("%d", &numero);
                insere_meio(&lista, numero);
                break;
            case 5:
                printf("\nDigite um valor: ");
                scanf("%d", &numero);
                insere_fim(&lista, numero);
                break;
            case 6:
                excluir_fim(&lista);
                break;
            case 7:
                excluir_inicio(&lista);
                break;
            case 8:
                printf("\nDigite um valor a ser excluido: ");
                scanf("%d", &numero);
                excluir_meio(&lista, numero);
            case 9:
                printf("\nDigite um valor a ser buscado: ");
                scanf("%d", &numero);
                busca_valor(&lista, numero);
                break;
            case 10:
                printf("\nDigite qual o valor que voce quer inserir antes: ");
                scanf("%d", &numero);
                printf("\nDigite um valor a ser inserir: ");
                scanf("%d", &valor);
                inserir_antes_k(&lista, numero, valor);
                break;
            case 11:
                printf("\nDigite qual o valor que voce quer inserir antes: ");
                scanf("%d", &numero);
                printf("\nDigite um valor a ser inserir: ");
                scanf("%d", &valor);
                inserir_depois_k(&lista, numero, valor);
                break;
            case 12:
                printf("\nDigite um valor a buscar: ");
                scanf("%d", &numero);
                if(busca_no(&lista, numero))
                {
                    printf("\n Achou! ");
                }
                else
                {
                    printf("\n Nao Achou!");
                }
                break;
            case 13:
                tranforma_circular(&lista);
                break;
            case 14:
                imprimi_circular(&lista);
                break;
            default:
                break;
        }
    }
    
    return 0;
}