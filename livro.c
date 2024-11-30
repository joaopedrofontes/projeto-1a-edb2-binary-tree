#include "livro.h"

Livro* iniciar_arvore() {
    return NULL;
}

Livro* criar_livro(int livro_id, char* titulo, char* autor, char* genero, int ano, char* editora, int paginas) {
    Livro* novo_livro = (Livro*)malloc(sizeof(Livro));
    novo_livro->livro_id = livro_id;
    novo_livro->ano = ano;
    novo_livro->paginas = paginas;
    novo_livro->titulo = (char*)malloc(strlen(titulo) + 1);
    novo_livro->autor = (char*)malloc(strlen(autor) + 1);
    novo_livro->genero = (char*)malloc(strlen(genero) + 1);
    novo_livro->editora = (char*)malloc(strlen(editora) + 1);
    strcpy(novo_livro->titulo, titulo);
    strcpy(novo_livro->autor, autor);
    strcpy(novo_livro->genero, genero);
    strcpy(novo_livro->editora, editora);
    novo_livro->esquerda = NULL;
    novo_livro->direita = NULL;
    return novo_livro;
}

//insere o livro sem repetir o id 
Livro* inserir_livro(Livro* raiz, Livro* livro) {
    if (raiz == NULL) {
        return livro;
    }

    if (livro->livro_id == raiz->livro_id) {
        printf("Erro: Esse ID já existe (%d).\n", livro->livro_id);
        printf("Escolha um novo ID para %s\n", livro->titulo);
        return raiz; 
    }

    if(livro->livro_id < raiz->livro_id) {
        raiz->esquerda = inserir_livro(raiz->esquerda, livro);
    }

    else if(livro->livro_id > raiz->livro_id) {
        raiz->direita = inserir_livro(raiz->direita, livro);
    }
    
    return raiz;
}


void liberar_arvore(Livro* raiz) {
    if (raiz == NULL) {
        return;
    }

    liberar_arvore(raiz->esquerda);
    liberar_arvore(raiz->direita);

    free(raiz->titulo);
    free(raiz->autor);
    free(raiz->genero);
    free(raiz->editora);
    free(raiz);
}

