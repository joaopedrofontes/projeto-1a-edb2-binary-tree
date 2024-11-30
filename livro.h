#ifndef LIVRO_H
#define LIVRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
    int livro_id;
    char* titulo;
    char* autor;
    char* genero;
    int ano;
    char* editora;
    int paginas;
    struct Livro* esquerda;
    struct Livro* direita;
} Livro;

Livro* iniciar_arvore();

Livro* criar_livro(int livro_id, char* titulo, char* autor, char* genero, int ano, char* editora, int paginas);

Livro* inserir_livro(Livro* raiz, Livro* livro);

void liberar_arvore(Livro* raiz);

#endif