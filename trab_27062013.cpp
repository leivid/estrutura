#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Temp
{
    int info;
    struct Temp *ante;
    struct Temp *prox;
} TElemento;


typedef struct lista
{
    TElemento *inicio;
    TElemento *fim;
} TLista;


void CriaLista(TLista *lista)
{
   lista->inicio = NULL;
   lista->fim = NULL;
}

int Insere_inicio(TLista *lista)
{
    TElemento *p, *aux;
    p =  (TElemento *) malloc(sizeof(TElemento));

    printf("Informe um Numero: ");
    scanf("%d", &p->info);
    p->prox = NULL;
    p->ante = NULL;

    if (lista->inicio==NULL)
    {
        lista->inicio = p;
        lista->fim = p;
    }
    else
    {

        aux = lista->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = p;
        p->ante = aux;
        lista->fim = p;
    }
}
int Insere_fim(TLista *lista)
{
    TElemento *p, *aux;
    p =  (TElemento *) malloc(sizeof(TElemento));

    printf("Informe um Numero: ");
    scanf("%d", &p->info);
    p->prox = NULL;
    p->ante = NULL;
    if (lista->fim==NULL)
    {
        lista->inicio = p;
        lista->fim = p;
    }
    else
    {

        aux = lista->fim;
        while (aux->ante != NULL)
            aux = aux->ante;
        aux->ante = p;
        p->prox = aux;
        lista->inicio = p;
    }
}

void Imprime(TLista *lista)
{
    TElemento *ptr, *aux1, *aux2;
    if (lista->inicio == NULL)
    {
        printf("--- fim da lista ---\n\n");
        return;
    }
    // Caso a lista nao esteja vazia
    ptr = lista->inicio;
    while (ptr !=NULL)
    {
        aux1 = ptr->prox;
        aux2 = ptr->ante;
        printf("Info = %d\n",ptr->info);
        if (aux1 != NULL)
            printf("Tem como proximo o: %d\n", aux1->info);
        else
            printf("Nao possui proximo.\n");
        if (aux2 != NULL)
            printf("E o anterior e: %d\n\n", aux2->info);
        else
            printf("E nao possui anterior. \n\n");
        ptr = ptr->prox;
    }
    printf("--- fim da lista ---\n\n");
    getch();
}
void Imprime_fim(TLista *lista)
{
    TElemento *ptr, *aux1, *aux2;
    if (lista->inicio == NULL)
    {
        printf("--- fim da lista ---\n\n");
        return;
    }
    // Caso a lista nao esteja vazia
    ptr = lista->inicio;
    while (ptr !=NULL)
    {
        aux1 = ptr->prox;
        aux2 = ptr->ante;
        printf("Info = %d\n",ptr->info);
        if (aux1 != NULL)
            printf("Tem como proximo o: %d\n", aux1->info);
        else
            printf("Nao possui proximo.");
        if (aux2 != NULL)
            printf("E o anterior e: %d\n", aux2->info);
        else
            printf("E nao possui anterior. \n");
        ptr = ptr->prox;
    }
    printf("--- fim da lista ---\n\n");
    getch();
}
void imprime_inicio(TLista *lista)
{
    TElemento *ptr;
    if (lista->inicio == NULL)
    {
        printf("--- fim da lista ---\n\n");
    }
    // Caso a lista nao esteja vazia
    ptr = lista->inicio;
    while (ptr !=NULL)
    {
        printf("Info = %d\n",ptr->info);
        ptr = ptr->prox;
    }
    printf("--- fim da lista ---\n\n");
    getch();
}
void imprime_fim(TLista *lista)
{
    TElemento *ptr;
    if (lista->fim == NULL)
    {
        printf("--- fim da lista ---\n\n");
    }
    // Caso a lista nao esteja vazia
    ptr = lista->fim;
    while (ptr !=NULL)
    {
        printf("Info = %d\n",ptr->info);
        ptr = ptr->ante;
    }
    printf("--- fim da lista ---\n\n");
    getch();
}
//--------------------------------------------------------
// Funcao que busca um elemento na lista.
TElemento *BuscaDado(int dado,TLista *lista)
{
    TElemento *ptr;
    if (lista->inicio == NULL)
    {
        return NULL;  // Lista Vazia
    }
    // Caso a lista nao esteja vazia
    ptr = lista->inicio;
    while (ptr !=NULL)
    {
        if (ptr->info == dado)  // achou !!
        {
            return (ptr);
        }        // retorna um ponteiro para
        //o inicio da lista
        else
            ptr = ptr->prox;
    }
    //printf("O elemento nao se encontra na lista");

    return NULL;
}
//--------------------------------------------------------
// Funcao que remove um elemento especificado por 'dado'
// Retorna:
// 0 - se nao conseguiu achar
// 1 - se conseguiu remover
int remover_inicio(TLista *lista)
{
    TElemento *elem_atual, *elem_proximo, *elem_anterior;
    int dado;

    printf("Informe Numero a ser removido: ");
    scanf("%d", &dado);
    if (lista->inicio==NULL)
    {
        return 0;  // Lista vazia !!!
    }
    else
    {
        // Caso a lista nao esteja vazia
        elem_atual = lista->inicio;
        while (elem_atual != NULL)
        {
            elem_proximo = elem_atual->prox;
            elem_anterior = elem_atual->ante;
            if (elem_atual->info == dado) // achou !!
                if (elem_anterior != NULL)
                    if (elem_proximo != NULL)
                    {
                        elem_anterior->prox = elem_proximo;
                        elem_proximo->ante = elem_anterior;
                        free(elem_atual);
                        break;
                    }
                    else
                    {
                        elem_anterior->prox = NULL; //elem_atual->prox;
                        lista->fim = elem_anterior;
                        free(elem_atual);
                        break;
                    }
                else if (elem_proximo != NULL)
                {
                    elem_proximo->ante = NULL;
                    lista->inicio = elem_proximo;
                    free (elem_atual);
                    break;
                }
                else
                {
                    free(elem_atual);
                }
            else                 elem_atual = elem_atual->prox;
        }
        printf("O elemento nao se encontra na lista\n");
    }
}
int remover_fim(TLista *lista)
{
    TElemento *elem_atual, *elem_proximo, *elem_anterior;
    int dado;

    printf("Informe Numero a ser removido: ");
    scanf("%d", &dado);
    if (lista->fim==NULL)
    {
        return 0;  // Lista vazia !!!
    }
    else
    {
        // Caso a lista nao esteja vazia
        elem_atual = lista->fim;
        while (elem_atual != NULL)
        {
            elem_proximo = elem_atual->prox;
            elem_anterior = elem_atual->ante;
            if (elem_atual->info == dado) // achou !!
                if (elem_anterior != NULL)
                    if (elem_proximo != NULL)
                    {
                        elem_anterior->prox = elem_proximo;
                        elem_proximo->ante = elem_anterior;
                        free(elem_atual);
                        break;
                    }
                    else
                    {
                        elem_anterior->prox = NULL;
                        lista->fim = elem_anterior;
                        free(elem_atual);
                        break;
                    }
                else if (elem_proximo != NULL)
                {
                    elem_proximo->ante = NULL;
                    lista->inicio = elem_proximo;
                    free (elem_atual);
                    break;
                }
                else
                {
                    free(elem_atual);
                    break;
                }
            else
                elem_atual = elem_atual->prox;
        }
        printf("O elemento nao se encontra na lista\n");
    }
}


//--------------------------------------------------
// Programa principal
int main(void)
{
    int i, opcao;
    TLista listagem;
    TElemento *aux;
    CriaLista(&listagem);

    do
    {
        system("cls");
        printf("\nOpcoes: \n\n");
        printf(" 1 - a) Inserir numero no inicio\n");
        printf(" 2 - b) Inserir numero no fim\n");
        printf(" 3 - Consultar numero pelo inicio\n");
        printf(" 4 - Remover numero pelo inicio\n");
        printf(" 5 - Remover numero pelo fim\n");
        printf(" 6 - Listar os numeros pelo inicio mostrando sucessor e antecessor\n");
        printf(" 7 - Listar todos os numeros pelo inicio\n");
        printf(" 8 - Listar todos os numeros pelo fim\n");
        printf(" 0 - para sair \n\n");
        printf("Entre com a sua opcao: ");
        scanf("%d", &opcao); /* Le a opcao do usuario */
        switch (opcao)
        {
        case 1:
            Insere_inicio(&listagem);
            break;
        case 2:
            Insere_fim(&listagem);
            break;
        case 3:
            printf("Informe Numero a ser consultado: ");
            scanf("%d", &i);
            aux = BuscaDado(i,&listagem);
            if (aux != NULL)
                printf("+++Achou o %d\n", aux->info);
            else
                printf("---Nao achou o %d\n", i);
            getch();
            break;
        case 4:
            remover_inicio(&listagem);
            break;
        case 5:
            remover_fim(&listagem);
            break;
            case 6:
                Imprime(&listagem);
                break;
        case 7:
            imprime_inicio(&listagem);
            break;
        case 8:
            imprime_fim(&listagem);
            break;
        case 0:
            break;
        default:
            printf("\n\n Opcao invalida");
            getche();
            break;
        }
    }
    while (opcao != 0);
}
