#ifndef LIVRO_SERVICE_H
#define LIVRO_SERVICE_H

#include <stdio.h>  
#include "livro.h"

#define MAXLINES 256
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

static const char BASE[] = "biblioteca.txt";
/* ponteiro para o descritor do arquivo */
static FILE *fptr;

void inicializa_base();
void fecha_base();

void adiciona_livro_s(livro_t livro);
livro_t *lista_livros_s();
void remove_livro_s(int id);
livro_t busca_livro_s(int id);
livro_t atualiza_livro_s(livro_t livro);



#endif /* LIVRO_SERVICE_H */