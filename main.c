#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Inquilino.c"
#include "Apartamento.c"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

int main (void)
{
    unsigned char op;
    unsigned int saida = 0;
    
    Lista *CadastroInquilino = lst_cria ();
    Lista2 *CadastroApartamento = list_cria ();
    
	char nome [50];
    int numero_do_apartamento;
    
    do
    {
    	//system ("cls");
    	
    	printf ("\n\n");
    	printf ("\n    +-------------------------------------------------------------------------+");
    	printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf ("\n    +-------------------------------------------------------------------------+");
    	printf ("\n\n");
    	
        printf ("%c -%s\n", OPCAO1, " ADICIONAR INQUILINO ");
        printf ("%c -%s\n", OPCAO2, " EXCLUIR INQUILINO ");
        printf ("%c -%s\n", OPCAO3, " LISTAR INQUILINO ");
        printf ("%c -%s\n", OPCAO4, " BUSCAR INQUILINO ");
        printf ("%c -%s\n", OPCAO5, " EDITAR INQUILINO ");
        printf ("%c -%s\n", OPCAO6, " CONSULTAR APARTAMENTOS DISPONIVEIS  ");
        printf ("%c -%s\n", OPCAO7, " CONSULTAR QUANTITATIVO DE INQUILINOS ");
        printf ("%c -%s\n", OPCAO8, " SAIR ");

        printf ("\nDigite uma opcao: ");
                
		op = getchar ();
        fflush (stdin);
        
        //system ("cls");

        switch (op)
        {
        	
        case OPCAO1:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                       ADICIONAR INQUILINO                               |");
            printf ("\n    +-------------------------------------------------------------------------+");

            CadastroInquilino = lst_insere (CadastroInquilino);
            CadastroApartamento = InsereAp (CadastroApartamento);

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            break;

        case OPCAO2:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                         EXCLUIR INQUILINO                               |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            printf ("Nome do inquilino que deseja excluir: ");
            scanf (" %[^\n]", nome);

            CadastroInquilino = ExcluirInquilino(CadastroInquilino, nome);

            printf ("Numero do apartamento do inquilino que deseja excluir: ");
            scanf ("%d", &numero_do_apartamento);

            CadastroApartamento = ExcluirAp (CadastroApartamento, numero_do_apartamento);

            printf ("\nInquilino excluido com sucesso!\n");
            exclui_txt(CadastroInquilino);

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            break;

        case OPCAO3:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                         LISTAR INQUILINOS                               |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            ListarInquilino (CadastroInquilino);
            printf ("\n");

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                       LISTAR APARTAMENTOS                               |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            ListarAp (CadastroApartamento);
            printf ("\n");

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            break;

        case OPCAO4:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                         BUSCAR INQUILINOS                               |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            CadastroInquilino = fc_buscar (CadastroInquilino);
            CadastroApartamento = l_buscar (CadastroApartamento);

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            break;

        case OPCAO5:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                         EDITAR INQUILINOS                               |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            EditarInq (CadastroInquilino);
            EditarAp (CadastroApartamento);

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            break;

        case OPCAO6:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                      CONSULTAR APARTAMENTO DISPONIVEL                   |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            disponivel (CadastroApartamento);

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            break;

        case OPCAO7:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                   CONSULTAR QUANTIDADE DE INQUILINOS                    |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            quant (CadastroInquilino);

            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            break;

        case OPCAO8:
        	
            printf ("\n    +-------------------------------------------------------------------------+");
            printf ("\n    |                            PROGRAMA ENCERRADO                           |");
            printf ("\n    +-------------------------------------------------------------------------+\n");

            saida = 1;

            printf ("Obrigado.\n");

            break;

        default:
        	
            printf ("Opcao invalida. Tente novamente.\n");
            
            break;
        }

    } while (!saida);

    return (0);
}
