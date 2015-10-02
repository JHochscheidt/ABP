#include "funcoes_abp.h"

// retorna um nodo NULL, a raiz da arvore
TpArvore* criaArvoreVazia(){
	TpArvore *arv = (TpArvore*) malloc(sizeof (TpArvore));
	if(arv){
		arv->root = NULL;
		arv->h = 0;
		//puts("arvore criada com sucesso");
		return arv;
	}
	return NULL;	
}

// aloca nodo e insere informacao
TpNodo* criaNodo(int key){
	TpNodo *new = (TpNodo*) malloc(sizeof(TpNodo));
	new->dir = NULL;
	new->esq = NULL;
	new->pai = NULL;
	new->fat_b = 0;
	new->info = key;
	return new;
}

// retorna valor da entrada padrao
int valor(){
	int valor;
	printf("Informe o valor:\n");
	scanf("%d", &valor);
	return valor;
}

// insere nodo e retorna-o
TpNodo* inserir(int key, TpNodo* root, TpArvore* tree){
	TpNodo *new = criaNodo(key);
	// 1. primeiro nodo a ser inserido, inicializa a arvore
	if(!tree->root){
		tree->root = new;
	}else{
		// 2. Se há raiz. Compara nodo com a raiz:
		//		a) se nodo for menor que raiz. Chama inserir para sub-arvore a esquerda
		if(key > root->info){
			// se sub-arvore a direita for vazia. Senao insere o novo nodo
			if(!root->dir){ 
				root->dir = new;
				new->pai = root;
			// senao, chama a insercao para a sub-arvore a direita
			}else{
				inserir(key, root->dir, tree);
			}
		}
		//		b) se nodo for maior que raiz. Chama inserir para sub-arvore a direita
		else if(key < root->info){
			// se sub-arvore a esquerda for vazia. senao insere o novo nodo
			if(!root->esq){ 
				root->esq = new;
				new->pai = root;
			// senao, chama a insercao para a sub-arvore a direita
			}else{
				inserir(key, root->esq, tree);
			}
		}
	}
	return new;
}

// inacabada
TpNodo* remover(int key, TpNodo* root){
	TpNodo *aux;
	aux = buscar(key, root);
	// se aux nÃ£o possui sub-Ã¡rvores
	if(!aux->dir && !aux->esq)
		free(aux);
	// se aux possui somente uma sub-arvore 
			
	// se aux possui sub-Ã¡rvore a direita e a esquerda
	
	return aux;

}

void imprimir(TpNodo* root){
	if(root){
		printf("<");
		imprimir(root->esq);
		printf("([%d]-fb[%d])", root->info, root->fat_b);
		imprimir(root->dir);
		printf(">");
	}
}

TpNodo* buscar(int key, TpNodo* root){
	if(!root)
		return NULL;
	buscar(key, root->dir);
	buscar(key, root->esq);
	return root;
}

int fator(TpArvore* tree, int key){
	TpNodo *aux = buscar(key, tree->root);
	if(aux)
		return aux->fat_b;
	return -0 ;
}

int altura(TpNodo* root){
	if(!root) return 0;
	int Hd = 0, He = 0;
	Hd = altura(root->dir);
	He = altura(root->esq);
	if(He > Hd) return 1 + He;
	else return 1 + Hd; 
}

void calcula_fator(TpNodo* root){
	if(!root)
		return; 
	root->fat_b = (altura(root->esq) - altura(root->dir));

	calcula_fator(root->esq);
	calcula_fator(root->dir);
}

/*
 * int calcula_fator(TpNodo *root){
	if(root == NULL) return 0;
	return (altura(root->esq) - altura(root->dir)); // calcula o fat_b do nodo atual
}
* 
void atualiza_fator(TpNodo *root){
     if (root != NULL)
     {
		 root->fat_b=(altura(root->esq)- altura(root->dir));
		 atualiza_fator(root->esq);
		 atualiza_fator(root->dir);
     }
}*/



int is_AVL(TpArvore* tree){
	// se (alturaDir - alturaEsq) < 2 --> Ã© AVL
	if(!tree->root) return TRUE; // significa que arvore esta vazia, logo está balanceada e é uma AVL
	
	if(altura(tree->root->dir) - altura(tree->root->esq) < 2 && altura(tree->root->dir) - altura(tree->root->esq) > -2)return TRUE;
	else return altura(tree->root->dir) - altura(tree->root->esq); 	
	// se (alturaDir - alturaEsq) >= 2 --> nÃ£o Ã© AVL
}

int is_balanceada(TpNodo* root){
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




