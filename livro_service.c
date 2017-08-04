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

void adiciona_livro_file_s(livro_t livro, char *arquivo) {
    FILE *f;
    if ((f = fopen(arquivo, "a+")) == NULL){
       puts("Erro ao abrir arquivo!");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fprintf(f, "%d,%s,%s,%s\n", livro.id, livro.titulo, livro.autor, livro.assunto);
   fclose(f);
}

void adiciona_livro_s(livro_t livro) {
   inicializa_base();

   fprintf(fptr, "%d,%s,%s,%s\n", livro.id, livro.titulo, livro.autor, livro.assunto);

   fecha_base();
}

livro_t *lista_livros_s() {
    inicializa_base();

    int currSize = 0;
    int id;
    char titulo[50], autor[50], assunto[50];
    
    while (fscanf(fptr,"%d,%[^,],%[^,],%s\n", &id, titulo, autor, assunto) == 4)
            currSize++;

    printf("%d\n",currSize);
    fecha_base();

    livro_t *livros = malloc(currSize * sizeof(livro_t));
    inicializa_base();
    int i = 0;
    while (fscanf(fptr,"%d,%[^,],%[^,],%s\n", &livros[i].id, 
        livros[i].titulo, livros[i].autor, livros[i].assunto) == 4) {
            
        printf("%d,%s,%s,%s\n", livros[i].id, 
            livros[i].titulo, livros[i].autor, livros[i].assunto);
        i++;
    }

    fecha_base();

    return livros;
}

void remove_livro_s(int id) {
    char *temp = "biblioteca_temp.txt";
    livro_t *livros = lista_livros_s();

    for (int i = 0; i < NELEMS(livros); ++i) {
        if (id == livros[i].id) {
            continue;
        }

        adiciona_livro_file_s(livros[i], temp);
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
    livro_t *livros = lista_livros_s();
    livro_t livro;

    for (int i = 0; i < NELEMS(livros); ++i) {
        if (id == livros[i].id) {
            return livros[i];
        }
    }

    return livro;
}

livro_t atualiza_livro_s(livro_t livro) {
    char *temp = "biblioteca_temp.txt";
    livro_t *livros = lista_livros_s();

    for (int i = 0; i < NELEMS(livros); ++i) {
        if (livro.id == livros[i].id) {
            adiciona_livro_file_s(livro, temp);    
        } else {
            adiciona_livro_file_s(livros[i], temp);
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
