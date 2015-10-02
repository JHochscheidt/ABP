#ifndef _funcoes_abp
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef struct _arvore{
	struct _nodo *root;
	int h;
}TpArvore;

typedef struct _nodo{
	int info;
	int fat_b;
	struct _nodo *pai;
	struct _nodo *esq;
	struct _nodo *dir;
}TpNodo;

/* 1. Função para inserção de nodos em uma ABP que armazene números inteiros. */
TpNodo* inserir(int new, TpNodo* root, TpArvore* tree);

/* 2. Função que recebe como parâmetro a árvore gerada no exercício 1 
 * e um valor e procura o valor em um nó da árvore e retorna o fator do nó. */
int fator(TpArvore* tree, int key);
 
/* 3. Função que recebe como parâmetro a árvore gerada no exercício 1
 * e retorna uma informação dizendo se a árvore é ou não AVL. */
int is_AVL(TpArvore* tree);

/* 4. Função que recebe como parâmetro a árvore gerada no exercício 1
 * e retorna uma informação dizendo se a árvore está ou não completamente balanceada. */
TpNodo *is_balanceada(TpNodo* root);

// Função para criação de árvore
TpArvore* criaArvoreVazia(); // retorna um nodo NULL, a raiz da arvore

// Função para criação de nodo
TpNodo* criaNodo(int key);

// Função que pede o valor a ser inserido na árvore
int valor();

// Função que percorre a arvore procurando por chave
TpNodo* buscar(int key, TpNodo* root);

// Função para remover um nodo da árvore
TpNodo* remover(int key, TpNodo* root);

// Função para imprimir a árvore
void imprimir(TpNodo* root);

// Função que calcula a altura da árvore
int altura(TpNodo* root);

// Função que calcula o fator de balanceamento de um nó 
void calcula_fator(TpNodo* root);

TpNodo *balancearArvore(TpNodo *root);
// rotacoes
TpNodo *rotacaoSimplesDireita(TpNodo *root);
TpNodo *rotacaoSimplesEsquerda(TpNodo *root);
TpNodo *rotacaoDuplaDireita(TpNodo *root);
TpNodo *rotacaoDuplaEsquerda(TpNodo *root);



TpNodo *buscaNodoDesbalanceado(TpNodo *root);


#endif
