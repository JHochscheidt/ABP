#include "funcoes_abp.h"


// retorna um nodo NULL, a raiz da arvore
ARVORE* criaArvore(){
	ARVORE* abp = (ARVORE*) malloc(sizeof (ARVORE) );
	abp->root = NULL;
	abp->h = -1;
	return abp;
}

NODO* buscar(int key, NODO* root){




	return NULL;
}

NODO* criaNodo(){
	NODO *new = (NODO*) malloc(sizeof(NODO));
	new->dir = NULL;
	new->esq = NULL;
	return new;
}



NODO* inserir(int key, NODO* root){
	
	NODO *new = criaNodo();
	
	if(!new) return NULL;
	// 1. Se ainda não há raiz. Novo nodo será a raiz
	if(!root){
		root = new; 
		new->key = key;
	}else{
		// 2. Se há raiz. Compara nodo com a raiz:
		//		a) se nodo for menor que raiz. Chama inserir para sub-árvore a esquerda
		if(key > root->key){
			// se sub-árvore a direita for vazia. Só insere o novo nodo
			if(!root->dir){ 
				root->dir = new;
			// senão, chama a inserção para a sub-arvore a direita
			}else{
				inserir(key, root->dir, tree);
			}
		}
		//		b) se nodo for maior que raiz. Chama inserir para sub-árvore a direita
		else if(key < root->key){
			// se sub-árvore a esquerda for vazia. Só insere o novo nodo
			if(!root->esq){ 
				root->esq = new;
			// senão, chama a inserção para a sub-arvore a direita
			}else{
				inserir(key, root->esq, tree);
			}
		}
	}
	return new;
}

