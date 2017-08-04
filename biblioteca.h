#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdio.h>
#include "livro_service.h"


/* Mostra o menu e retorna a opcao do usuario */
int menu();

void flush_input();

void imprime_titulo_tabela();
void imprime_rodape_tabela();

/* Imprime um livro recebendo uma struct livro por parâmetro */
void imprime_livro(livro_t livro);

/* Imprime a tabela, sendo apenas um livro */
void imprime_tabela(livro_t livro);

/* Imprime a tabela atraves de um array de livros */
void imprime_tabela_livros(livro_t *livros);

/* Pede ao usuario o id do livro via console */
int obtem_id_livro_titulo(char *titulo);
int obtem_id_livro();

/* obtem informacoes do livro via console */
livro_t obtem_livro(int novo);

/* Adiciona um livro à base de dados */
void adiciona_livro(livro_t livro);
void lista_livros();
void remove_livro(int id);
void busca_livro(int id);
void atualiza_livro(int id, livro_t livro);

#endif /* BIBLIOTECA_H */