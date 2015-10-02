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
		new->pai = NULL;
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


// a principio funcionando
TpNodo *is_balanceada(TpNodo* root){
	if(!root) return NULL; 
	
	else if(root->fat_b < -1 || root->fat_b > 1)
			return root;
	else{
		if(root->esq) return is_balanceada(root->esq);
		if(root->dir) return is_balanceada(root->dir);

		return NULL;
	}
}

// funcao que faz balanceamento da arvore
TpNodo *balancearArvore(TpNodo *root){
	
	if(root != NULL) {
		//puts("balanceando arvore\n\n");
			if(root->fat_b == 2){
				if(root->esq->fat_b > 0){ // simples a direita
					root = rotacaoSimplesDireita(root);
				}else{
					root = rotacaoDuplaDireita(root); // dupla a direita
				}
			}else if(root->fat_b == -2){
				if(root->dir->fat_b < 0){ // simples a esquerda
					root = rotacaoSimplesEsquerda(root);
				}else{
					 root =  rotacaoDuplaEsquerda(root);
				}
			}else{
				root->esq = balancearArvore(root->esq);
				root->esq = balancearArvore(root->dir);
			}
	
	}
	//puts("balanceamento feito \n\n");
	return root; // novo raiz
}

// rotacoes
TpNodo *rotacaoSimplesDireita(TpNodo *root){
	//puts("rot. simp. direita\n\n");
	TpNodo *aux = root->esq;
	if(aux->dir){
		root->esq = aux->dir;
		aux->dir->pai = root;
	}
	else root->esq = NULL;
	aux->dir = root;
	root->pai = aux;
	//root->fat_b = 0;
	//root = aux;
	//puts("fim rotacao simples direita");
	return aux;
}

TpNodo *rotacaoSimplesEsquerda(TpNodo *root){
	puts("rot. simp. esquerda\n\n");
	TpNodo *aux = root->dir;
	if(aux->esq){
		root->dir = aux->esq;
		aux->esq->pai = root;
	}
	else root->dir = NULL;
	aux->esq = root;
	root->pai = aux;
	//root->fat_b = 0;
	//root = aux;
	return aux;
}

TpNodo *rotacaoDuplaDireita(TpNodo *root){
	puts("rot. dupla  direita\n\n");
	TpNodo *aux  = root->esq;
	TpNodo *aux2 = aux->dir;

	if(aux2->esq){
		aux->dir = aux2->esq;
		aux2->esq->pai = aux;
	}else aux->dir = NULL;

	if(aux2->dir){
		root->esq = aux2->dir;
		aux2->dir->pai = root;
	}else root->esq = NULL;

	aux2->esq = aux;
	aux->pai = aux2;

	aux2->dir = root;
	root->pai = aux2;
	
	return aux2;
	
}

TpNodo *rotacaoDuplaEsquerda(TpNodo *root){
	puts("rot. dupla  esquerda\n\n");
	TpNodo * aux= root->dir;
     TpNodo * aux2= aux->esq;

      if(aux2->esq){
		root->dir= aux2->esq;
		aux2->esq->pai = root;
	}else root->dir=NULL;

      if(aux2->dir){
		 aux->esq = aux2->dir;
		 aux2->dir->pai = aux;
	}else aux->esq=NULL;

     aux2->esq=root;
     root->pai = aux2;
     
     aux2->dir=aux;
     aux->pai = aux2;
       
       return aux2;
}


// busca nodo desbalanceado

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

int is_AVL(TpArvore* tree){
	// se (alturaDir - alturaEsq) < 2 --> Ã© AVL
	if(!tree->root) return TRUE; // significa que arvore esta vazia, logo está balanceada e é uma AVL
	
	if((altura(tree->root->esq) - altura(tree->root->dir))  < 2 || (altura(tree->root->esq) - altura(tree->root->dir)) > -2) return TRUE;
	else return (altura(tree->root->esq) - altura(tree->root->dir)); 	
	
}


/*
// busca nodo desbalanceado
TpNodo *buscaNodoDesbalanceado(TpNodo *root){
	// se (alturaDir - alturaEsq) < 2 --> é AVL
	if(root) return NULL; // significa que arvore esta vazia, logo esta balanceada e eh uma AVL

	TpNodo *aux = root;

	if(aux->fat_b < -1 || aux->fat_b > 1) return aux;
	else{
		if(aux->esq != NULL)
			return buscaNodoDesbalanceado(aux->esq);
		else if(aux->dir != NULL)
			return buscaNodoDesbalanceado(aux->dir);
	}
	return NULL;
}
*/
