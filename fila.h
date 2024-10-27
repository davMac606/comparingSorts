#ifndef FILA
#define FILA

#include "basics.h"

typedef void* ElementoDeFila;

typedef struct {
    ElementoDeFila* vetor;
    unsigned int capacidade, qtd_atual;
} Fila;

boolean nova_fila (Fila* f, unsigned int capacidade);
boolean guarde_fila (Fila* f, ElementoDeFila e);
boolean recupere_fila (Fila f, ElementoDeFila* e);
boolean remova_de_fila (Fila* f);
boolean fila_cheia (Fila f);
boolean fila_vazia (Fila f);
boolean free_fila (Fila* f);

#endif
