#include "funcoes_abp.h"


// retorna um nodo NULL, a raiz da arvore
ARVORE* criaArvore(){
	ARVORE* abp = (ARVORE*) malloc(sizeof (ARVORE) );
	abp->root = NULL;
	abp->h = -1;
	return abp;
}

int valor(){
	int valor;
	printf("Informe o valor a ser inserido na árvore:\n");
	scanf("%d", &valor);
	return valor;
}

NODO* buscar(int key, NODO* root){
	if(!root) return NULL;
	else{
		if(key > root->key)
			buscar(key, root->dir);
		else if(key < root->key)
			buscar(key, root->esq);
	}
	return root;
}

NODO* criaNodo(){
	NODO *new = (NODO*) malloc(sizeof(NODO));
	new->dir = NULL;
	new->esq = NULL;
	return new;
}

NODO* inserir(int key, NODO* root, ARVORE* tree){
	
	NODO *new = criaNodo();
	new->key = key;
	if(!new) return NULL;
	// 1. Se ainda não há raiz. Novo nodo será a raiz
	if(!tree->root){
		tree->root = new; 
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


// inacabada
NODO* remover(int key, NODO* root){
	NODO *aux;
	aux = buscar(key, root);
	// se aux não possui sub-árvores
	if(!aux->dir && !aux->esq)
		free(aux);
	// se aux possui somente uma sub-arvore 
	else if(aux->dir)
		
		
	// se aux possui sub-árvore a direita e a esquerda
	
	return aux;

}

void imprimir(NODO* root){
	if(root){
		printf("<");
		imprimir(root->esq);
		printf("%d", root->key);
		imprimir(root->dir);
		printf(">");
	}
}



