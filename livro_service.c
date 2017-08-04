#include "livro_service.h"

void inicializa_base() {
    if ((fptr = fopen(BASE, "a+")) == NULL){
       puts("Erro ao abrir arquivo!");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
}

void fecha_base() {
    fclose(fptr);
}

void adiciona_livro_s(livro_t livro) {
   inicializa_base();

   fprintf(fptr, "%d,%s,%s,%s\n", livro.id, livro.titulo, livro.autor, livro.assunto);

   fecha_base();
}

livro_t *lista_livros_s() {
    inicializa_base();

    livro_t livros[MAXLINES];
    int i = 0;
    while (fscanf(fptr,"%d,%s,%s,%s\n", livros[i].id, 
        livros[i].titulo, livros[i].autor, livros[i].assunto)) {
            i++;
    }

    fecha_base();

    return livros;
}

void remove_livro_s(int id) {
    char *temp = "biblioteca_temp.txt";
    livro_t *livros = lista_livros();

    for (int i = 0; i < NELEMS(livros); ++i) {
        if (id == livros[i].id) {
            continue;
        }

        adiciona_livro(livro[i], tempDb);
    }

    if (!remove(BASE)) {
        puts("Não foi possível remover o livro: não foi possível remover a base.");
        exit(1);
    }

    if (!rename(temp, BASE)) {
        puts("Não foi possível remover o livro: não foi possível renomear a base.");
        exit(1);
    }
}

livro_t busca_livro_s(int id) {
    livro_t *livros = lista_livros();

    for (int i = 0; i < NELEMS(livros); ++i) {
        if (id == livros[i].id) {
            return livros[i];
        }
    }

    return null;
}

livro_t atualiza_livro_s(livro_t livro) {
    char *temp = "biblioteca_temp.txt";
    livro_t *livros = lista_livros();

    for (int i = 0; i < NELEMS(livros); ++i) {
        if (livro.id == livros[i].id) {
            adiciona_livro(livro, tempDb);    
        } else {
            adiciona_livro(livro[i], tempDb);
        }
    }

    if (!remove(BASE)) {
        puts("Não foi possível remover o livro: não foi possível remover a base.");
        exit(1);
    }

    if (!rename(temp, BASE)) {
        puts("Não foi possível remover o livro: não foi possível renomear a base.");
        exit(1);
    }

    return livro;
}
