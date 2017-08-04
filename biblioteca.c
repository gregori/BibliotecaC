#include "biblioteca.h"

void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu() {
    int cont = 's';
    int opcao;

    do {
        puts("\t\t Sistema de Cadastro de Livros\n");
        
        puts("1 ===> Adicionar Livro ");
        puts("2 ===> Listar Livros ");	
        puts("3 ===> Remover Livros ");
        puts("4 ===> Buscar Livro ");
        puts("5 ===> Atualizar Livro ");
        puts("S ===> Sair ");	        
  
        fputs("\nEscolha: ", stdout);

        opcao = getchar();
        /* Limpa o 'lixo' da entrada padrao */
        flush_input();

        switch (opcao) {
        case '1':
            adiciona_livro(obtem_livro(1));
            break;
        case '2':
            lista_livros();
            break;
        case '3':
            remove_livro(obtem_id_livro_titulo("\t\t Apagar Registro de Livro"));
            break;
        case '4':
            busca_livro(obtem_id_livro_titulo("\t\t Buscar Registro de Livro"));
            break;
        case '5': 
            atualiza_livro(obtem_id_livro_titulo("\t\t Atualizar Registro de Livro"), 
                obtem_livro(0));
            break;
        case 'S':
            return 0;
        }

        flush_input();
    } while(opcao != 'S');
}

void imprime_titulo_tabela() {
    puts(" -------------------------------------------------------------");
  	puts("|	ID\tTitulo\tAutor\tAssunto\t|");
  	puts(" -------------------------------------------------------------");  
}

void imprime_rodape_tabela() {
    puts("|	                                            	            |");
  	puts(" -------------------------------------------------------------");
}

/* Imprime um livro recebendo uma struct livro por parâmetro */
void imprime_livro(livro_t livro) {
    printf("| %d\t%s\t%s\t%s\t|\n", livro.id, livro.titulo, livro.autor, livro.assunto);
}

/* Imprime a tabela, sendo apenas um livro */
void imprime_tabela(livro_t livro) {
    imprime_titulo_tabela();
    imprime_livro(livro);
    imprime_rodape_tabela();
}

/* Imprime a tabela atraves de um array de livros */
void imprime_tabela_livros(livro_t *livros) {
    imprime_titulo_tabela();

    for (int i = 0; i < NELEMS(livros); ++i) {
        imprime_livro(livros[i]);
    }
    
    imprime_rodape_tabela();
}

/* Pede ao usuario o id do livro via console */
int obtem_id_livro_titulo(char *titulo) {
    puts(titulo);
    puts("");

    return obtem_id_livro();
}

int obtem_id_livro() {
    int id;
    fputs("Entre o ID do Livro: ", stdout);
    scanf("%d", &id);

    return id;
}

/* obtem informacoes do livro via console */
livro_t obtem_livro(int novo) {
    livro_t livro;

    if (novo) {
        livro.id = obtem_id_livro();
    }

    fputs("Entre o titulo do livro: ", stdout);
    scanf("%s", &livro.titulo);

    fputs("Entre o autor do livro: ", stdout);
    scanf("%s", &livro.autor);

    fputs("Entre o assunto do livro: ", stdout);
    scanf("%s", &livro.assunto);

    return livro;
}

/* Adiciona um livro à base de dados */
void adiciona_livro(livro_t livro) {
    adiciona_livro_s(livro);
}

void lista_livros() {
    imprime_tabela_livros(lista_livros_s());
}

void remove_livro(int id) {
    remove_livro_s(id);
}

void busca_livro(int id) {
    livro_t livro = busca_livro_s(id);
    imprime_tabela(livro);
}

void atualiza_livro(int id, livro_t livro) {
    livro_t l = busca_livro_s(id);

    livro.id = l.id;

    atualiza_livro_s(livro);

    puts("\nLivro atualizado!");
    imprime_tabela(livro);
}