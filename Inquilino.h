#include <stdio.h>
#include <stdlib.h>

typedef struct Inquilino Inquilino;
typedef struct Lista Lista;
Lista *lst_cria (void);
Lista *lst_insere (Lista *list);
Inquilino *coleta_de_dados (void);
int lst_vazia (Lista *l);
Lista *ExcluirInquilino (Lista *l , char *nome);
void ListarInquilino (Lista *l);
Lista *fc_buscar (Lista *l);
void EditarInq (Lista *l);
void quant (Lista *l);
void exclui_txt(Lista* l);
//void editar_txt(Lista* l);
