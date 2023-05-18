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

// Função para inserir um novo inquilino no início da lista
Lista *lst_insere (Lista* list)
{
	
	//A função lst_insere recebe um ponteiro para uma lista como parâmetro.
	//Ela chama a função coleta_de_dados() para obter um novo elemento do tipo Inquilino.
	//Em seguida, aloca memória para um novo elemento da lista (novo) utilizando malloc.
	//O ponteiro info do novo elemento é atribuído ao dado coletado.
	//O ponteiro prox do novo elemento é atribuído ao ponteiro para a lista passado como parâmetro (list).
	//Por fim, a função retorna o ponteiro para o novo elemento.
	
	Inquilino *Dado = coleta_de_dados ();
	Lista *novo = (Lista*) malloc (sizeof (Lista));
	novo -> info = Dado;
	novo -> prox = list;
	
	return novo;
}


// Função para verificar se a lista está vazia
int lst_vazia (Lista *l)
{
	return (l == NULL);
}

// Função para excluir um inquilino da lista pelo nome
Lista *ExcluirInquilino(Lista *l, char *nome)
{
	//A função ExcluirInquilino recebe um ponteiro para uma lista (l) e um ponteiro para uma string (nome) como parâmetros.
	//Ela declara e inicializa dois ponteiros auxiliares, ant e inq, ambos do tipo Lista.
	//Um laço while é utilizado para percorrer a lista (inq) até encontrar o inquilino com o nome desejado ou até o final da lista.
	//Dentro do laço, o ponteiro ant é atualizado para apontar para o inquilino atual (inq), e inq é atualizado para apontar para o próximo inquilino da lista (inq->prox).
	//Após sair do laço, é verificado se o ponteiro inq não é nulo, ou seja, se o inquilino foi encontrado.
	//Se o inquilino foi encontrado, é verificado se o ponteiro ant é nulo. Se for, significa que o inquilino a ser excluído é o primeiro da lista. Nesse caso, o ponteiro l é atualizado para apontar para o próximo elemento (inq->prox).
	//Se o ponteiro ant não for nulo, significa que o inquilino a ser excluído não é o primeiro da lista. Nesse caso, o ponteiro prox do inquilino anterior (ant->prox) é atualizado para apontar para o próximo elemento após o inquilino atual (inq->prox).
	//Em seguida, a função free é utilizada para liberar a memória alocada para o inquilino excluído.
	//Por fim, é exibida uma mensagem de sucesso ou falha, dependendo se o inquilino foi encontrado.
	//A função retorna o ponteiro para a lista atualizado (l).
    
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
        printf("\nInquilino excluído com sucesso!\n");
    }
    else
    {
        printf("\nInquilino não encontrado.\n");
    }

    return l;
}

void ListarInquilino (Lista *l)
{
	
	//A função ListarInquilino recebe um ponteiro para uma estrutura de dados chamada Lista como parâmetro. 
	//Essa função é responsável por percorrer a lista de inquilinos e imprimir informações sobre cada um deles.
	//A linha Lista *inq; declara um ponteiro chamado inq que será usado para percorrer a lista de inquilinos.
	//Em seguida, temos um loop for que começa com inq apontando para o mesmo local que o ponteiro l (que é a lista passada como parâmetro) e continua enquanto inq não for NULL. A cada iteração do loop, o ponteiro inq avança para o próximo elemento da lista usando inq = inq -> prox.
	//Dentro do loop, a função printf é usada para imprimir as informações do inquilino, como nome, data de entrada, fim do contrato, RG, CPF e número do apartamento. Essas informações são acessadas através de ponteiros e estruturas aninhadas.

	Lista *inq;
	
	for (inq = l; inq != NULL; inq = inq -> prox)
	{
		printf("\nNome: %s\nData de entrada: %d/%d/%d\nFim do contrato: %d/%d/%d\nRG: %sCPF: %s\nNumero do apartamento: %d\n ", inq->info->nome, inq->info->data_de_entrada.dia, inq->info->data_de_entrada.mes, inq->info->data_de_entrada.ano, inq->info->duracao_do_contrato.dia_contrato, inq->info->duracao_do_contrato.mes_contrato, inq->info->duracao_do_contrato.ano_contrato, inq->info->documentos.RG, inq->info->documentos.CPF, inq->info->apartamento);
	}
}

// Função para buscar um inquilino pelo nome
Lista *fc_buscar (Lista *l)
{
	//A função fc_buscar é responsável por buscar um inquilino pelo nome na lista. 
	//Ela também recebe um ponteiro para a estrutura Lista como parâmetro e retorna um ponteiro para o elemento encontrado ou NULL se não for encontrado.
	//A variável nome é declarada como um array de caracteres com tamanho 50 para armazenar o nome fornecido pelo usuário.
	//A função printf é usada para exibir uma mensagem solicitando o nome do inquilino a ser buscado. Em seguida, a função scanf é usada para ler o nome digitado pelo usuário e armazená-lo na variável nome.
	//O ponteiro p é declarado e é usado em um loop for para percorrer a lista de inquilinos, assim como no exemplo anteri//or. Se o nome do inquilino atual (p->info->nome) for igual ao nome procurado, uma mensagem informando que o inquilino foi encontrado é exibida e o ponteiro p é retornado.
	//Se nenhum inquilino com o nome especificado for encontrado, uma mensagem informando isso é exibida e NULL é retornado.

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
	//A função EditarInq é responsável por editar as informações de um inquilino na lista. Ela recebe um ponteiro para a estrutura Lista como parâmetro.
	//A variável num é declarada para armazenar o número do apartamento que será usado para encontrar o inquilino a ser editado.
	//A função printf é usada para exibir uma mensagem solicitando o número do apartamento a ser editado. Em seguida, a função scanf é usada para ler o número digitado pelo usuário e armazená-lo na variável num.
	//O ponteiro p é declarado e é usado em um loop for para percorrer a lista de inquilinos, assim como nos exemplos anteriores. Se o número do apartamento do inquilino atual (p->info->apartamento) for igual ao número fornecido, o inquilino é encontrado e suas informações são editadas.
	//Dentro do bloco condicional, várias mensagens usando printf são usadas para solicitar ao usuário as novas informações do inquilino. As informações são lidas usando a função scanf e armazenadas nos campos correspondentes da estrutura do inquilino (p->info->...).
	//Após a edição das informações, a função system("cls") é usada para limpar a tela.
	//Ao final da função, há uma linha em branco (printf("\n")) para melhorar a legibilidade da saída.
	
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
	
	//Início de um loop for que percorre a lista l, iniciando com o ponteiro p apontando para o mesmo elemento que o ponteiro l.
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

        printf("As informações foram editadas com sucesso!\n");
    } else {
        printf("Inquilino não encontrado no arquivo.\n");
    }

    fclose(arquivo);
}*/ 
