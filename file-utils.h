#ifndef FILE_UTILS_H
#define FILE_UTILS_H
#include "livro.h"

Livro* ler_csv_e_inserir(Livro* raiz, char* filename);

void escrever_no_arquivo(char* filename, Livro *livro);

void adicionar_livro(Livro* raiz, char* filename);

#endif