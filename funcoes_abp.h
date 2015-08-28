#ifndef _funcoes_abp
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct _arvore{
	struct _nodo *root;
	int h;
	
}ARVORE;



typedef struct _nodo{
	int key;
	int fat_b;
	struct _nodo *esq;
	struct _nodo *dir;
}NODO;


// Função para criação de árvore

ARVORE* criaArvore(); // retorna um nodo NULL, a raiz da arvore

// Função para criação de nodo

NODO* criaNodo();

// Função que pede o valor a ser inserido na árvore
int valor();

// Função que percorre a arvore procurando por chave

NODO* buscar(int key, NODO* root);

// Função para remover um nodo da árvore

NODO* remover(int key, NODO* root);

// Função para imprimir a árvore

void imprimir(NODO* root);

// Função que calcula a altura da árvore

int altura(NODO* root);


// 1. Função para inserção de nodos em uma ABP que armazene números inteiros.

NODO* inserir(int new, NODO* root, ARVORE* tree);


/* 2. Função que recebe como parâmetro a árvore gerada no exercício 1 
 * e um valor e procura o valor em um nó da árvore e retorna o fator
 * do nó.
 */
 
int fator(int key, ARVORE* tree);
 
/* 3. Função que recebe como parâmetro a árvore gerada no exercício 1
 * e retorna uma informação dizendo se a árvore é ou não AVL.
 */
 
int eh_AVL(ARVORE* tree);

/* 4. Função que recebe como parâmetro a árvore gerada no exercício 1
 * e retorna uma informação dizendo se a árvore está ou não
 * completamente balanceada.
 */
 
int estah_balanceada(NODO* root);





#endif
