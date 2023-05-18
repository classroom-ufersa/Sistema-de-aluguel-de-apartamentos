#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inquilino.h"

#define numero_maximo_de_caracteres_RG 12
#define numero_maximo_de_caracteres_CPF 15
#define numero_maximo_de_caracteres_nome 71

typedef struct data_de_entrada
{
	int dia;
	int mes;
	int ano; 
	
} Data_de_entrada;

typedef struct duracao_do_contrato
{
	int dia_contrato;
	int mes_contrato;
	int ano_contrato; 
	
} Duracao_do_contrato;

typedef struct documentos 
{
	char RG [numero_maximo_de_caracteres_RG];
	char CPF [numero_maximo_de_caracteres_CPF];
	
} Documentos;

typedef struct Inquilino 
{
	char nome [numero_maximo_de_caracteres_nome];
	Data_de_entrada data_de_entrada;
	Duracao_do_contrato duracao_do_contrato;
	Documentos documentos;
	int apartamento;
	
} Inquilino;

// Estrutura para a lista encadeada de inquilinos
typedef struct Lista
{
	Inquilino *info; 
	struct lista *prox;
	
} Lista;

Lista *lst_cria (void)
{
	return NULL;
}

Inquilino *coleta_de_dados (void)
{
	
	Inquilino *Dado = (Inquilino*) malloc (sizeof (Inquilino));
	
	if (Dado == NULL)
	{
		printf ("HOUVE UM ERRO AO ALOCAR MEMORIA");
		exit (1);
	}
		printf ("\n\n Exemplo: Cibely \n");
        printf ("\n Nome: ");
        scanf (" %[^\n]", &Dado->nome);
        
        system ("cls");
        
        printf ("\n Exemplo: 18/10/2000 \n");
        printf ("\n Data de entrada: ");
        scanf (" %d/%d/%d", &Dado->data_de_entrada.dia, &Dado->data_de_entrada.mes, &Dado->data_de_entrada.ano);
        
        system ("cls");
    
    	printf ("\n Exemplo: 18/10/2005 \n");
        printf ("\n Duracao do contrato: ");
        scanf (" %d/%d/%d", &Dado->duracao_do_contrato.dia_contrato, &Dado->duracao_do_contrato.mes_contrato, &Dado->duracao_do_contrato.ano_contrato);
        
        system ("cls");
        
        printf ("\n Exemplo: 007.666.911 \n");
        printf ("\n RG: ");
        scanf ("%s", &Dado->documentos.RG);
        
        system ("cls");
        
        printf ("\n Exemplo: 007.666.911-18 \n");
        printf ("\n CPF: ");
        scanf ("%s", &Dado->documentos.CPF);
        
        system ("cls");
        
        printf ("\n Exemplo: 156 \n");
        printf ("\n Numero do apartamento: ");
        scanf ("%d", &Dado->apartamento);
        printf ("\n");

	 FILE *arquivo;

     arquivo = fopen ("Arquivo_de_Mikael.txt" , "a");
     
     if (arquivo == NULL)
	 {
     	printf ("HOUVE UM ERRO AO ABRIR O ARQUIVO");
        exit (1);
	 }	
	 
        fprintf (arquivo, "Nome: %s\nData de entrada: %d/%d/%d\nFim do contrato: %d/%d/%d\nRG: %s\nCPF: %s\nApartamento: %d\n", Dado->nome, Dado->data_de_entrada.dia, Dado->data_de_entrada.mes, Dado->data_de_entrada.ano, Dado->duracao_do_contrato.dia_contrato, Dado->duracao_do_contrato.mes_contrato, Dado->duracao_do_contrato.ano_contrato, Dado->documentos.RG, Dado->documentos.CPF, Dado->apartamento);  
        printf("\n    #--------------------------------------------------------------------------------------------#");
    	printf("\n    |                       OS DADOS FORAM ADICIONADOS AO ARQUIVO                                |");
    	printf("\n    #--------------------------------------------------------------------------------------------#");
    	    	
  		fclose (arquivo);

	return Dado;
}

// Fun��o para inserir um novo inquilino no in�cio da lista
Lista *lst_insere (Lista* list)
{
	
	//A fun��o lst_insere recebe um ponteiro para uma lista como par�metro.
	//Ela chama a fun��o coleta_de_dados() para obter um novo elemento do tipo Inquilino.
	//Em seguida, aloca mem�ria para um novo elemento da lista (novo) utilizando malloc.
	//O ponteiro info do novo elemento � atribu�do ao dado coletado.
	//O ponteiro prox do novo elemento � atribu�do ao ponteiro para a lista passado como par�metro (list).
	//Por fim, a fun��o retorna o ponteiro para o novo elemento.
	
	Inquilino *Dado = coleta_de_dados ();
	Lista *novo = (Lista*) malloc (sizeof (Lista));
	novo -> info = Dado;
	novo -> prox = list;
	
	return novo;
}


// Fun��o para verificar se a lista est� vazia
int lst_vazia (Lista *l)
{
	return (l == NULL);
}

// Fun��o para excluir um inquilino da lista pelo nome
Lista *ExcluirInquilino(Lista *l, char *nome)
{
	//A fun��o ExcluirInquilino recebe um ponteiro para uma lista (l) e um ponteiro para uma string (nome) como par�metros.
	//Ela declara e inicializa dois ponteiros auxiliares, ant e inq, ambos do tipo Lista.
	//Um la�o while � utilizado para percorrer a lista (inq) at� encontrar o inquilino com o nome desejado ou at� o final da lista.
	//Dentro do la�o, o ponteiro ant � atualizado para apontar para o inquilino atual (inq), e inq � atualizado para apontar para o pr�ximo inquilino da lista (inq->prox).
	//Ap�s sair do la�o, � verificado se o ponteiro inq n�o � nulo, ou seja, se o inquilino foi encontrado.
	//Se o inquilino foi encontrado, � verificado se o ponteiro ant � nulo. Se for, significa que o inquilino a ser exclu�do � o primeiro da lista. Nesse caso, o ponteiro l � atualizado para apontar para o pr�ximo elemento (inq->prox).
	//Se o ponteiro ant n�o for nulo, significa que o inquilino a ser exclu�do n�o � o primeiro da lista. Nesse caso, o ponteiro prox do inquilino anterior (ant->prox) � atualizado para apontar para o pr�ximo elemento ap�s o inquilino atual (inq->prox).
	//Em seguida, a fun��o free � utilizada para liberar a mem�ria alocada para o inquilino exclu�do.
	//Por fim, � exibida uma mensagem de sucesso ou falha, dependendo se o inquilino foi encontrado.
	//A fun��o retorna o ponteiro para a lista atualizado (l).
    
	Lista *ant = NULL;
    Lista *inq = l;

    while (inq != NULL && strcmp(nome, inq->info->nome) != 0)
    {
        ant = inq;
        inq = inq->prox;
    }

    if (inq != NULL)
    {
        if (ant == NULL)
        {
            l = inq->prox;
        }
        else
        {
            ant->prox = inq->prox;
        }

        free(inq);
        printf("\nInquilino exclu�do com sucesso!\n");
    }
    else
    {
        printf("\nInquilino n�o encontrado.\n");
    }

    return l;
}

void ListarInquilino (Lista *l)
{
	
	//A fun��o ListarInquilino recebe um ponteiro para uma estrutura de dados chamada Lista como par�metro. 
	//Essa fun��o � respons�vel por percorrer a lista de inquilinos e imprimir informa��es sobre cada um deles.
	//A linha Lista *inq; declara um ponteiro chamado inq que ser� usado para percorrer a lista de inquilinos.
	//Em seguida, temos um loop for que come�a com inq apontando para o mesmo local que o ponteiro l (que � a lista passada como par�metro) e continua enquanto inq n�o for NULL. A cada itera��o do loop, o ponteiro inq avan�a para o pr�ximo elemento da lista usando inq = inq -> prox.
	//Dentro do loop, a fun��o printf � usada para imprimir as informa��es do inquilino, como nome, data de entrada, fim do contrato, RG, CPF e n�mero do apartamento. Essas informa��es s�o acessadas atrav�s de ponteiros e estruturas aninhadas.

	Lista *inq;
	
	for (inq = l; inq != NULL; inq = inq -> prox)
	{
		printf("\nNome: %s\nData de entrada: %d/%d/%d\nFim do contrato: %d/%d/%d\nRG: %sCPF: %s\nNumero do apartamento: %d\n ", inq->info->nome, inq->info->data_de_entrada.dia, inq->info->data_de_entrada.mes, inq->info->data_de_entrada.ano, inq->info->duracao_do_contrato.dia_contrato, inq->info->duracao_do_contrato.mes_contrato, inq->info->duracao_do_contrato.ano_contrato, inq->info->documentos.RG, inq->info->documentos.CPF, inq->info->apartamento);
	}
}

// Fun��o para buscar um inquilino pelo nome
Lista *fc_buscar (Lista *l)
{
	//A fun��o fc_buscar � respons�vel por buscar um inquilino pelo nome na lista. 
	//Ela tamb�m recebe um ponteiro para a estrutura Lista como par�metro e retorna um ponteiro para o elemento encontrado ou NULL se n�o for encontrado.
	//A vari�vel nome � declarada como um array de caracteres com tamanho 50 para armazenar o nome fornecido pelo usu�rio.
	//A fun��o printf � usada para exibir uma mensagem solicitando o nome do inquilino a ser buscado. Em seguida, a fun��o scanf � usada para ler o nome digitado pelo usu�rio e armazen�-lo na vari�vel nome.
	//O ponteiro p � declarado e � usado em um loop for para percorrer a lista de inquilinos, assim como no exemplo anteri//or. Se o nome do inquilino atual (p->info->nome) for igual ao nome procurado, uma mensagem informando que o inquilino foi encontrado � exibida e o ponteiro p � retornado.
	//Se nenhum inquilino com o nome especificado for encontrado, uma mensagem informando isso � exibida e NULL � retornado.

	char nome [50];
	
	printf ("Nome do inquilino para realizar a busca: \n");
	scanf (" %[^\n]", &nome);
	 
	 Lista *p;
	 
	 for (p = l; p != NULL; p = p -> prox)
	 {
		 if (strcmp (p -> info -> nome, nome) ==0)
		 {
			printf ("\n");
		 	printf (" \nO inquilino %s foi encontrado \n", nome);
		 	printf ("\n\n");
		 	
			return p;
		 }
	 }
	 
	 printf ("\n");
	 printf ("O inquilino nao foi encontrado");
	 printf ("\n");

	 return NULL;
}

void EditarInq (Lista *l)
{
	//A fun��o EditarInq � respons�vel por editar as informa��es de um inquilino na lista. Ela recebe um ponteiro para a estrutura Lista como par�metro.
	//A vari�vel num � declarada para armazenar o n�mero do apartamento que ser� usado para encontrar o inquilino a ser editado.
	//A fun��o printf � usada para exibir uma mensagem solicitando o n�mero do apartamento a ser editado. Em seguida, a fun��o scanf � usada para ler o n�mero digitado pelo usu�rio e armazen�-lo na vari�vel num.
	//O ponteiro p � declarado e � usado em um loop for para percorrer a lista de inquilinos, assim como nos exemplos anteriores. Se o n�mero do apartamento do inquilino atual (p->info->apartamento) for igual ao n�mero fornecido, o inquilino � encontrado e suas informa��es s�o editadas.
	//Dentro do bloco condicional, v�rias mensagens usando printf s�o usadas para solicitar ao usu�rio as novas informa��es do inquilino. As informa��es s�o lidas usando a fun��o scanf e armazenadas nos campos correspondentes da estrutura do inquilino (p->info->...).
	//Ap�s a edi��o das informa��es, a fun��o system("cls") � usada para limpar a tela.
	//Ao final da fun��o, h� uma linha em branco (printf("\n")) para melhorar a legibilidade da sa�da.
	
	int num;
	
	printf ("Digite o numero do apartamento para realizar a edicao: \n");
	scanf ("%d",&num);
	
	Lista *p;
	
	for (p = l; p != NULL; p = p -> prox)
	{
		if(p -> info -> apartamento == num)
		{
		
		printf ("\n");
		printf ("\n    #-------------------------------------------------------------------------#");
    	printf ("\n    |                        INQUILINO ENCONTRADO                             |");
    	printf ("\n    #-------------------------------------------------------------------------#");
	    printf ("\n");
		
			printf ("Novo nome: ");
			scanf (" %[^\n]", p->info->nome);
			
			system ("cls");
			
			printf ("\n Exemplo: 18/10/2000 \n");
        	printf ("\n Nova data de entrada do contrato: ");
			scanf ("%d/%d/%d", &p->info->data_de_entrada.dia, &p->info->data_de_entrada.mes, &p->info->data_de_entrada.ano);
			
			system ("cls");
			
			printf ("\n Exemplo: 18/10/2000 \n");
        	printf ("\n Nova data de duracao do contrato: ");
			scanf ("%d/%d/%d", &p->info->duracao_do_contrato.dia_contrato, &p->info->duracao_do_contrato.mes_contrato, &p->info->duracao_do_contrato.ano_contrato);
			
			system ("cls");
			
			printf ("Novo RG:");
			scanf ("%d", &p->info->documentos.RG);
			
			system ("cls");
			
			printf ("Novo CPF:");
			scanf ("%d", &p->info->documentos.CPF);
			
			system ("cls");
			
			printf ("Novo numero do apartamento: ");
			scanf ("%d", &p->info->apartamento);
			printf ("\n");
		}
		
	}
	
}

void quant (Lista *l)
{
	
	Lista *p;
	
	int i = 0;
	
	//In�cio de um loop for que percorre a lista l, iniciando com o ponteiro p apontando para o mesmo elemento que o ponteiro l.
	for(p = l; p != NULL; p = p -> prox)
	{
		i++;
	}
	
	printf ("\n");
	printf ("Quantidade de inquilinos: %d\n ", i);
}

void exclui_txt (Lista* l)
{
    FILE* arquivo;
    Lista* p = l;

    arquivo = fopen("Arquivo_de_Mikael.txt", "wt");
    if (arquivo == NULL) {
        printf("HOUVE UM ERRO AO ABRIR O ARQUIVO");
        exit(1);
    }
    do {
        if (p->prox == NULL) {
            fprintf(arquivo, "Nome: %s\nData de entrada: %d/%d/%d\nFim do contrato: %d/%d/%d\nRG: %s\nCPF: %s\nApartamento: %d\n", p->info->nome, p->info->data_de_entrada.dia, p->info->data_de_entrada.mes, p->info->data_de_entrada.ano, p->info->duracao_do_contrato.dia_contrato, p->info->duracao_do_contrato.mes_contrato, p->info->duracao_do_contrato.ano_contrato, p->info->documentos.RG, p->info->documentos.CPF, p->info->apartamento);
            return;
        }
        fprintf(arquivo, "Nome: %s\nData de entrada: %d/%d/%d\nFim do contrato: %d/%d/%d\nRG: %s\nCPF: %s\nApartamento: %d\n", p->info->nome, p->info->data_de_entrada.dia, p->info->data_de_entrada.mes, p->info->data_de_entrada.ano, p->info->duracao_do_contrato.dia_contrato, p->info->duracao_do_contrato.mes_contrato, p->info->duracao_do_contrato.ano_contrato, p->info->documentos.RG, p->info->documentos.CPF, p->info->apartamento);
        p = p->prox;
        if (p->prox == NULL) {
            fprintf(arquivo, "Nome: %s\nData de entrada: %d/%d/%d\nFim do contrato: %d/%d/%d\nRG: %s\nCPF: %s\nApartamento: %d\n", p->info->nome, p->info->data_de_entrada.dia, p->info->data_de_entrada.mes, p->info->data_de_entrada.ano, p->info->duracao_do_contrato.dia_contrato, p->info->duracao_do_contrato.mes_contrato, p->info->duracao_do_contrato.ano_contrato, p->info->documentos.RG, p->info->documentos.CPF, p->info->apartamento);
            return;
        }
    } while (p->prox != NULL);

    fclose(arquivo);
}

/*void editar_txt(Lista* l)
{
    FILE* arquivo;
    Lista* p = l;
    char linha[1000];
    char nome[100];
    int encontrado = 0;

    arquivo = fopen("Arquivo_de_Mikael.txt", "r+");
    if (arquivo == NULL) {
        printf("HOUVE UM ERRO AO ABRIR O ARQUIVO");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "Nome: ", 6) == 0) {
            sscanf(linha, "Nome: %[^\n]", nome);
            if (strcmp(nome, p->info->nome) == 0) {
                encontrado = 1;
                break;
            }
        }
    }

    if (encontrado) {
        fseek(arquivo, -strlen(linha), SEEK_CUR);

        fprintf(arquivo, "Nome: %s\nData de entrada: %d/%d/%d\nFim do contrato: %d/%d/%d\nRG: %s\nCPF: %s\nApartamento: %d\n",
                p->info->nome, p->info->data_de_entrada.dia, p->info->data_de_entrada.mes, p->info->data_de_entrada.ano,
                p->info->duracao_do_contrato.dia_contrato, p->info->duracao_do_contrato.mes_contrato, p->info->duracao_do_contrato.ano_contrato,
                p->info->documentos.RG, p->info->documentos.CPF, p->info->apartamento);

        printf("As informa��es foram editadas com sucesso!\n");
    } else {
        printf("Inquilino n�o encontrado no arquivo.\n");
    }

    fclose(arquivo);
}*/ 
