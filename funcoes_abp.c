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
	printf("Informe o valor:\n");
	scanf("%d", &valor);
	return valor;
}

NODO* buscar(int key, NODO* root){
	NODO *aux = root;
	if(!root) return NULL;
	else{
		if(key > aux->key)
			buscar(key, aux->dir);
		else if(key < aux->key)
			buscar(key, aux->esq);
	}
	return aux;
}

NODO* criaNodo(int key){
	NODO *new = (NODO*) malloc(sizeof(NODO));
	new->dir = NULL;
	new->esq = NULL;
	new->fat_b = 0;
	new->key = key;
	return new;
}

NODO* inserir(int key, NODO* root, ARVORE* tree){
	NODO *new = criaNodo(key);; 
	
	// 1. Se ainda não há raiz. Novo nodo será a raiz
	if(!tree->root){
		tree->h = 0;
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
	calcula_fator(root);
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
			
	// se aux possui sub-árvore a direita e a esquerda
	
	return aux;

}

void imprimir(NODO* root){
	if(root){
		printf("<");
		imprimir(root->esq);
		printf("[%d fat %d]", root->key, root->fat_b);
		imprimir(root->dir);
		printf(">");
	}
}

int fator(int key, ARVORE* tree){
	NODO *aux = buscar(key, tree->root);
	if(!aux){
		printf("Não existe este valor na árvore");
		return 0;
	}
	return aux->fat_b;
}

void calcula_fator(NODO* root){
	if(!root) return;
	
	if(!root->esq && !root->dir)
		root->fat_b = 0;
	else if(root->esq && !root->dir)
		root->fat_b = 1 + root->esq->fat_b;
	else if(!root->esq && root->dir)
		root->fat_b = -1 - root->dir->fat_b;
	else root->fat_b = root->esq->fat_b - root->dir->fat_b;	
}

int is_AVL(NODO* root){
	
	if(!root) return 0;// uma arvore vazia é uma arvore balanceada, e por extensão, uma AVL 
	
	if(root->fat_b < 2 || root->fat_b > -2) // arvore balanceada
		return root->fat_b; // 1 se for balanceada, 0 se for totalmente balanceada
	else if(root->fat_b > 1 || root->fat_b < -1)
		return root->fat_b; 
	else{ 
		if(root->esq)
			is_AVL(root->esq);
		if(root->dir)	
			is_AVL(root->dir);
	}
	return 1;	
}

int is_balanceada(NODO* root){
	if(!root) return 1; 

	if(root->fat_b)//em uma arvore completamente balanceada o fator de balanceamento de todo e qualquer nodo é 0
		return 0;
	else{ 
		if(root->esq)
			is_balanceada(root->esq);
		if(root->dir)	
			is_balanceada(root->dir);
	}
	return 1;

}

int altura(NODO* root){
	if((altura(root->dir) - altura(root->esq)) < 2 && (altura(root->dir) - altura(root->esq)) > -2)
		return (altura(root->dir) - altura(root->esq));
	
	printf("não é balanceada");
	return (altura(root->dir) - altura(root->esq));	
}




