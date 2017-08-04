#include "biblioteca.h"

int menu() {
    int cont = 's';
    int opcao;

    while(cont == 's') {
        puts("\t\t Sistema de Cadastro de Livros\n\n");
        
        puts("1 ===> Adicionar Livro \n");
        puts("2 ===> Listar Livros \n");	
        puts("3 ===> Remover Livros \n");
        puts("4 ===> Buscar Livro \n");
        puts("5 ===> Atualizar Livro \n");	        
  
        puts("\n\n");
        puts("Escolha: ");

        opcao = getchar();

        switch (opcao) {
        case '1':
            adiciona_livro(obten_livro(1));
            break;
        case '2':
            lista_livros();
            break;
        case '3':
            int id = obtem_id_livro("\t\t Apagar Registro de Livro\n");
            remove_livro(id);
            break;
        case '4':
            int id = obtem_id_livro("\t\t Buscar Registro de Livro\n");
            busca_livro(id);
            break;
        case '5':
            int id = obtem_id_livro("\t\t Atualizar Registro de Livro\n");
            livro_t livro = obtem_livro(0);
            atualiza_livro(id, livro);
            break;
        }

        puts("Quer continuar? (s/[n]) ");
        cont = getchar();
    }
}

void imprime_titulo_tabela() {
    puts(" -------------------------------------------------------------\n");
  	puts("|	ID\tTítulo\tAutor\tAssunto\t|\n");
  	puts(" -------------------------------------------------------------\n");  
}

void imprime_rodape_tabela() {
    puts("|	                                            	            |\n");
  	puts(" -------------------------------------------------------------\n");
}

/* Imprime um livro recebendo uma struct livro por parâmetro */
void imprime_livro(livro_t livro) {
    printf("| %d\t%s\t%s\t%s\t|", livro.id, livro.titulo, livro.autor, livro.assunto);
}

/* Imprime a tabela, sendo apenas um livro */
void imprime_tabela(livro_t livro) {
    imprime_titulo_tabela();
    imprime_livro(livro);
    imprime_rodape_tabela();
}

/* Imprime a tabela atraves de um array de livros */
void imprime_tabela(livro_t *livros) {
    imprime_titulo_tabela();

    for (int i = 0; i < NELEMS(livros); ++i) {
        imprime_livro(livro[i]);
    }
    
    imprime_rodape_tabela();
}

/* Pede ao usuario o id do livro via console */
int obtem_id_livro(char *titulo) {
    puts(titulo);
    puts("\n");

    return obtem_id_livro();
}

int obtem_id_livro() {
    puts("Entre o ID do Livro: ");
    scanf("%d", &id);

    return id;
}

/* obtem informacoes do livro via console */
livro_t obtem_livro(int novo) {
    livro_t livro;

    if (novo) {
        livro.id = obtem_id_livro();
    }

    puts("Entre o título do livro: ");
    scanf("%s", &livro.titulo);

    puts("Entre o autor do livro: ");
    scanf("%s", &livro.autor);

    puts("Entre o assunto do livro: ");
    scanf("%s", &livro.assunto);

    return livro;
}

/* Adiciona um livro à base de dados */
void adiciona_livro(livro_t livro) {
    adiciona_livro_s(livro);
}

void lista_livros() {
    imprime_tabela(lista_livros_s());
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

    puts("\nLivro atualizado!\n");
    imprime_tabela(livro);
}