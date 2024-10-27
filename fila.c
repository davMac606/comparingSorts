#include <stdlib.h>
#include "fila.h"

boolean nova_fila (Fila* f, unsigned int capacidade)
{
    if (capacidade<=0) {
        return false;
    }
    f->capacidade=capacidade;

    f->vetor=(ElementoDeFila*)malloc(capacidade*sizeof(ElementoDeFila));

    f->qtd_atual=0;

    return true;
}

boolean guarde_fila (Fila* f, ElementoDeFila e)
{
    if (f->qtd_atual==f->capacidade) {
        return false;
    }
    
    f->vetor[f->qtd_atual]=e;
    f->qtd_atual++;
    return true;
}

boolean recupere_fila (Fila f, ElementoDeFila* e)
{
    if (f.qtd_atual==0) {
        return false;
    }
    
    *e=f.vetor[0];
        return true;
}

boolean remova_de_fila (Fila* f)
{
    if ((*f).qtd_atual==0) {
        return false;
    }

    f->qtd_atual--;
    f->vetor[f->qtd_atual]=NULL;

    return true;
}

boolean fila_cheia (Fila f)
{
    
    return f.qtd_atual==f.capacidade; //retorna resultado da condicional
}

boolean fila_vazia (Fila f)
{
    return f.qtd_atual==0; //retorna resultado da condicional
}

boolean free_fila (Fila* f)
{
    if (f->vetor==NULL) {
        return false;
    }
    for (int i=0; i<f->capacidade; i++) {
        free(f->vetor[i]);
    }
    free(f->vetor);
    f->vetor=NULL;

    return true;
}
