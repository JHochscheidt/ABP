#include "funcoes_abp.h"


// retorna um nodo NULL, a raiz da arvore
ARVORE* criaArvore(){
	ARVORE* abp = (ARVORE*) malloc(sizeof (ARVORE) );
	abp->root = NULL;
	abp->h = 0;
	
	return abp;
	
}

