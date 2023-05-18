#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Apartamento.h"

#define NUMERO_MAXIMO_DE_CARACTERES_INQUILINO 71

typedef struct apartamento
{
    int numero_do_apartamento;
    char disponibilidade_do_apartamento[15];
    float valor_do_aluguel;
    char localizacao_do_apartamento[177];
    char inquilino[NUMERO_MAXIMO_DE_CARACTERES_INQUILINO];

} Apartamento;

typedef struct lista2
{
    Apartamento *dado;
    struct lista2 *prox;

} Lista2;

Lista2 *list_cria(void)
{
    return NULL;
}

Apartamento *AdicionaAp(void)
{
    Apartamento *apa = (Apartamento *)malloc(sizeof(Apartamento));

    if (apa == NULL)
    {
        printf("HOUVE UM ERRO AO ALOCAR MEMORIA");
        exit(1);
    }

    printf("\n    #-------------------------------------------------------------------------#");
    printf("\n    |                        CADASTRO DO APARTAMENTO                          |");
    printf("\n    #-------------------------------------------------------------------------#");
    printf("\n");

    printf("\n\n Exemplo: 156 \n");
    printf("\n Numero do apartamento: ");
    scanf("%d", &apa->numero_do_apartamento);

    system("cls");

    printf("\n\n Exemplo: Nao disponivel \n");
    printf("\n Disponibilidade do apartamento: ");
    scanf(" %[^\n]", apa->disponibilidade_do_apartamento);

    system("cls");

    printf("\n\n Exemplo: R$ 500 \n");
    printf("\n Valor do aluguel: R$ ");
    scanf("%f", &apa->valor_do_aluguel);

    system("cls");

    printf("\n\n Exemplo: Martins/Rio Grande do Norte \n");
    printf("\n Localizacao do apartamento: ");
    scanf(" %[^\n]", apa->localizacao_do_apartamento);

    system("cls");

    printf("\n\n Exemplo: Cibely \n");
    printf("\n Nome: ");
    scanf(" %[^\n]", apa->inquilino);

    FILE *arquivo;

    arquivo = fopen("Arquivo_de_Mikael.txt", "a");
    if (arquivo == NULL)
    {
        printf("HOUVE UM ERRO AO ABRIR O ARQUIVO");
        exit(1);
    }
    fprintf(arquivo, "Disponibilidade: %s\nNumero do apartamento: %d\nLocalizacao do apartamento: %s\nNome do inquilino: %s\nValor do aluguel: %f\n", apa->disponibilidade_do_apartamento, apa->numero_do_apartamento, apa->localizacao_do_apartamento, apa->inquilino, apa->valor_do_aluguel);
    printf("\n    #--------------------------------------------------------------------------------------------#");
    printf("\n    |                       OS DADOS FORAM ADICIONADOS AO ARQUIVO                                |");
    printf("\n    #--------------------------------------------------------------------------------------------#");

    fclose(arquivo);

    return apa;
}

Lista2 *InsereAp(Lista2 *l)
{
    Apartamento *Ap = AdicionaAp();
    Lista2 *novo = (Lista2 *)malloc(sizeof(Lista2));
    novo->dado = Ap;
    novo->prox = l;

    return novo;
}

int list_vazia(Lista2 *l)
{
    return (l == NULL);
}

void ListarAp(Lista2 *l)
{
    Lista2 *apa;
    for (apa = l; apa != NULL; apa = apa->prox)
    {
        printf("\nDisponibilidade: %s\n Numero do apartamento: %d\n Localizacao do apartamento: %s\nNome do inquilino: %s\nValor do aluguel: %f\n ", apa->dado->disponibilidade_do_apartamento, apa->dado->numero_do_apartamento, apa->dado->localizacao_do_apartamento, apa->dado->inquilino, apa->dado->valor_do_aluguel);
    }
}

Lista2 *ExcluirAp(Lista2 *l, int codigo)
{
    Lista2 *antes = NULL;
    Lista2 *apa = l;

    while (apa->dado->numero_do_apartamento != codigo)
    {
        if (apa == NULL)
            return l;

        antes = apa;
        apa = apa->prox;
    }
    if (antes == NULL)
    {
        l = apa->prox;
    }
    else
    {
        antes->prox = apa->prox;
    }
    free(apa);
    return l;
}

Lista2 *l_buscar(Lista2 *l)
{
    int cod;
    printf("Numero do apartamento para realizar a busca: \n");
    scanf("%d", &cod);

    Lista2 *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->dado->numero_do_apartamento == cod)
        {
            printf("Numero do apartamento %d encontrado \n", cod);
            printf("\n\n");
            return p;
        }
    }
    printf("Numero do apartamento nao encontrado \n");
    printf("\n\n");
    return NULL;
}

void EditarAp(Lista2 *l)
{
    int cod = 0;

    printf("\nNumero do apartamento anterior para realizar a edicao: \n");
    scanf("%d", &cod);

    Lista2 *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->dado->numero_do_apartamento == cod)
        {
            printf("\n");
            printf("\n    #-------------------------------------------------------------------------#");
            printf("\n    |                        APARTAMENTO ENCONTRADO                           |");
            printf("\n    #-------------------------------------------------------------------------#");
            printf("\n");

            printf("Digite o novo numero do apartamento: ");
            scanf("%d", &p->dado->numero_do_apartamento);
            
            system("cls");
            
            printf("Disponibilidade do apartamento: \n");
            scanf(" %[^\n]", p->dado->disponibilidade_do_apartamento);
            
            system("cls");
            
            printf("Novo valor do aluguel: \n");
            scanf("%f", &p->dado->valor_do_aluguel);
            
            system("cls");
            
            printf("Nova localizacao do apartamento: \n");
            scanf(" %[^\n]", p->dado->localizacao_do_apartamento);
            
            system("cls");
            
            printf("Novo nome do inquilino: \n");
            scanf(" %[^\n]", p->dado->inquilino);
        }
    }
}

void disponivel(Lista2 *l)
{
    Lista2 *p;
    int ap = 50;

    for (p = l; p != NULL; p = p->prox)
    {
        ap--;
    }
    printf("Quantidade de apartamentos disponiveis: %d\n", ap);
}
