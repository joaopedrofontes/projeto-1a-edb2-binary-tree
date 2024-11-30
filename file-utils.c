#include "file-utils.h"

Livro* ler_csv_e_inserir(Livro* raiz, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return raiz;
    }

    char buffer[1024];
    int livro_id;
    char titulo[100];
    char autor[100];
    char genero[100];
    int ano;
    char editora[100];
    int paginas;


    while (fgets(buffer, sizeof(buffer), file)) {
        char* token = strtok(buffer, ",");
        livro_id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(titulo, token);

        token = strtok(NULL, ",");
        strcpy(autor, token);

        token = strtok(NULL, ",");
        strcpy(genero, token);

        token = strtok(NULL, ",");
        ano = atoi(token);

        token = strtok(NULL, ",");
        strcpy(editora, token);

        token = strtok(NULL, ",");
        paginas = atoi(token);

        raiz = inserir_livro(raiz, criar_livro(livro_id, titulo, autor, genero, ano, editora, paginas));
    }
    return raiz;
    fclose(file);
}

void escrever_no_arquivo(char* filename, Livro *livro) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(file, "\n%d,%s,%s,%s,%d,%s,%d", livro->livro_id, livro->titulo, livro->autor, livro->genero, livro->ano, livro->editora, livro->paginas);

    fclose(file);
}

void adicionar_livro(Livro* raiz, char* filename) {
    int livro_id;
    char titulo[100];
    char autor[100];
    char genero[100];
    int ano;
    char editora[100];
    int paginas;

    printf("Digite o ID do livro: ");
    scanf("%d", &livro_id);
    getchar();

    printf("Digite o título do livro: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets(autor, sizeof(autor), stdin);
    autor[strcspn(autor, "\n")] = '\0';

    printf("Digite o gênero do livro: ");
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = '\0';

    printf("Digite o ano do livro: ");
    scanf("%d", &ano);
    getchar();

    printf("Digite a editora do livro: ");
    fgets(editora, sizeof(editora), stdin);
    editora[strcspn(editora, "\n")] = '\0';

    printf("Digite o número de páginas do livro: ");
    scanf("%d", &paginas);

    printf("\nLivro ID: %d\nTítulo: %s\nAutor: %s\nGênero: %s\nAno: %d\nEditora: %s\nPáginas: %d\n", livro_id, titulo, autor, genero, ano, editora, paginas);

    Livro* novo_livro = criar_livro(livro_id, titulo, autor, genero, ano, editora, paginas);
    raiz = inserir_livro(raiz, novo_livro);
    escrever_no_arquivo(filename, novo_livro);
}