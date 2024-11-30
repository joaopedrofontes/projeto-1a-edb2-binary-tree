#include "livro.h"
#include "print-utils.h"
#include "file-utils.h"

void imprimir_opcoes();

int main() {

    char*filename = "livros.csv";

    Livro* raiz = iniciar_arvore();

    raiz = ler_csv_e_inserir(raiz, filename);

    int escolha = -1;

    while(1) {
        imprimir_opcoes();
        scanf("%d", &escolha);

        if(escolha == 1) {
            adicionar_livro(raiz, filename);
        }
        else if(escolha == 2) {
            imprimir_em_ordem(raiz);
        }
        else if(escolha == 3) {
            char genero[100];
            printf("Digite o gênero a ser buscado: ");
            scanf("%s", genero);

            imprimir_por_genero(raiz, genero);
        }
        else {
            break;
        }
    }


    liberar_arvore(raiz);
    
    return 0;
}

void imprimir_opcoes() {
    printf("Escolha uma das seguintes opções:\n ");
    printf("(0) - Parar o programa\n");
    printf("(1) - Adicionar livro\n");
    printf("(2) - Listar todos os livros\n");
    printf("(3) - Listar todos os livros de um gênero\n");
    printf("Opção escolhida: ");
}