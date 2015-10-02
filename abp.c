/*
 * UNIVERSIDADE DA FRONTEIRA SUL - UFFS
 * CIÊNCIA DA COMPUTAÇÃO - 2015.2
 * ESTRUTURA DE DADOS II - 3ª FASE
 * PROFº GUILHERME DAL BIANCO
 * ACADÊMICO JACKSON HENRIQUE HOCHSCHEIDT 
 * E-MAIL: jackson94h@gmail.com   
 * repositório github.com/jacksonhh/ABP
 */
 
#include "funcoes_abp.h"


int main(){
	TpArvore *arv = criaArvoreVazia();
	inserir(5, arv->root, arv);
	calcula_fator(arv->root);
	inserir(6, arv->root, arv);
	calcula_fator(arv->root);
	
	TpNodo *desb;
	TpNodo *pai;
	int op;
	do{
		puts(
			"\n"
			"##########     MENU     #########\n"
			"#   0. Sair                     #\n"
			"#   1. Inserir valor            #\n"
			"#   2. Remover valor            #\n"
			"#   3. Buscar  valor            #\n"
			"#   4. Imprimir arvore          #\n"
			"#   5. Altura   arvore          #\n"
			"#   6. Fator nodo               #\n"
			"#   7. É AVL?                   #\n"
			"#   8. Está Balanceada?         #\n"
			"##########              #########\n"
		);
		scanf("%d", &op);
		switch(op){
			case 1: printf("Inserindo na árvore...");
					inserir(valor(), arv->root, arv);
					calcula_fator(arv->root);
					imprimir(arv->root);
					desb = is_balanceada(arv->root);
					if(desb){
						// desbalanceado
						// fazer balanceamento
						
						pai = desb->pai;
						if(desb->pai == NULL){
							//desb é a raiz
							desb = balancearArvore(desb);
							arv->root = desb;
						}else{
							desb = balancearArvore(desb);
							if(desb->info < pai->info){
							pai->esq = desb;
							desb->pai = pai;
							}else if(desb->info > pai->info){
							pai->dir = desb;
							desb->pai = pai;
							}
						}
					}
					calcula_fator(arv->root);
					//printf("raiz %d\n", arv->root->info);
				break;
			case 2: //remover();
				break;
			case 3:  if(! buscar(valor(), arv->root)) printf("Valor não existe");
					else printf("Valor existe");
				break;
			case 4: imprimir(arv->root);
				break;
			case 5: printf("altura[%d]", altura(arv->root));
				break;
			case 6: printf("FATOR DO NODO [%d]", fator(arv, valor()));
				break;
			case 7:	printf("É AVL?");
					if(is_AVL(arv) == TRUE)  printf("[%d] SIM ", is_AVL(arv));
					else printf("[%d] NÃO", is_AVL(arv));
				break;
			case 8: printf("está balanceada?\n");
					if(is_balanceada(arv->root) == NULL) printf("Está balanceada");
					else printf("Desbalanceada");
				break;
		}
	}while(op > 0);	
	
	
return 0;	
}
