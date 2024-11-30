#include "print-utils.h"

void imprimir_em_ordem(Livro* raiz) {
    if (raiz != NULL) {
        imprimir_em_ordem(raiz->esquerda);
        printf("%d %s \n", raiz->livro_id, raiz->titulo);
        imprimir_em_ordem(raiz->direita);
    }
}

void imprimir_por_genero(Livro* raiz, char* genero) {
    if (raiz == NULL) {
        return; 
    }

    imprimir_por_genero(raiz->esquerda, genero);
 
    if (strcmp(raiz->genero, genero) == 0) {
        printf("Livro encontrado:\n");
        printf("ID: %d\n", raiz->livro_id);
        printf("Título: %s\n", raiz->titulo);
        printf("Autor: %s\n", raiz->autor);
        printf("Ano: %d\n", raiz->ano);
        printf("Editora: %s\n", raiz->editora);
        printf("Páginas: %d\n", raiz->paginas);
        printf("-------------------------\n");
    }

    imprimir_por_genero(raiz->direita, genero);
}