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
	// 1. Se ainda nÃ£o hÃ¡ raiz. Novo nodo serÃ¡ a raiz
	if(!tree->root){
		tree->root = new;
	}else{
		// 2. Se há raiz. Compara nodo com a raiz:
		//		a) se nodo for menor que raiz. Chama inserir para sub-arvore a esquerda
		if(key > root->key){
			// se sub-arvore a direita for vazia. Senao insere o novo nodo
			if(!root->dir){ 
				root->dir = new;
			// senao, chama a insercao para a sub-arvore a direita
			}else{
				inserir(key, root->dir, tree);
			}
			
		}
		//		b) se nodo for maior que raiz. Chama inserir para sub-arvore a direita
		else if(key < root->key){
			// se sub-arvore a esquerda for vazia. senao insere o novo nodo
			if(!root->esq){ 
				root->esq = new;
			// senao, chama a insercao para a sub-arvore a direita
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
	// se aux nÃ£o possui sub-Ã¡rvores
	if(!aux->dir && !aux->esq)
		free(aux);
	// se aux possui somente uma sub-arvore 
			
	// se aux possui sub-Ã¡rvore a direita e a esquerda
	
	return aux;

}

void imprimir(NODO* root){
	if(root){
		printf("<");
		imprimir(root->esq);
		printf("[ %d ]", root->key);
		imprimir(root->dir);
		printf(">");
	}
}

NODO* buscar(int key, NODO* root){
	if(!root)
		return NULL;
	buscar(key, root->dir);
	buscar(key, root->esq);
	return root;
}

int fator(ARVORE* tree, int key){
	NODO *aux = buscar(key, tree->root);
	if(aux)
		return aux->fat_b;
	return -0 ;
}

int altura(NODO* root){
	if(!root) return -1;
	int Hd = 0, He = 0;
	if(root->dir) Hd = 1 + altura(root->dir);
	if(root->esq) He = 1 + altura(root->esq);
	if(Hd > He) return Hd;
	else return He; 
}

void calcula_fator(NODO* root){
	if(!root)
		return; 
	root->fat_b = (altura(root->dir) - altura(root->esq));
}

int is_AVL(ARVORE* tree){
	// se (alturaDir - alturaEsq) < 2 --> Ã© AVL
	if(!tree->root) return TRUE; // significa que arvore esta vazia, logo está balanceada e é uma AVL
	
	if(altura(tree->root->dir) - altura(tree->root->esq) < 2 && altura(tree->root->dir) - altura(tree->root->esq) > -2)return TRUE;
	else return altura(tree->root->dir) - altura(tree->root->esq); 	
	// se (alturaDir - alturaEsq) >= 2 --> nÃ£o Ã© AVL
}

int is_balanceada(NODO* root){
	if(!root) return TRUE; 
	
	else if(root->fat_b < -1 || root->fat_b > 1)
			return FALSE;
	is_balanceada(root->esq);
	is_balanceada(root->dir);
	
	return TRUE;
}


/*
fatbal = altura(sub-arvore direita) - altura(sub-arvore esquerda)

fatbal = -1, quando sub-arvore da esquerda é um nivel mais alto que a direita

fatbal = 0, quando as duas sub-arvores tem a mesma altura

faltbal = 1, quando a sub-arvore da direita é um nivel mais alto que a esquerda

toda folha tem fatbal = 0 

se fatbal tiver sinal igual, rotacao simples
se fatbal tiver sinal diferente, rotacao dupla

se fatbal for positivo (+) rotacao para a esquerda
se fatbal for negativo (-) rotacao para a direita

*/




