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
		
	ARVORE *abp = criaArvore();
	
	
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
					inserir(valor(), abp->root, abp);
				break;
			case 2: //remover();
				break;
			case 3: if(buscar(valor(), abp->root)) printf("Valor existe");
					else printf("Valor não existe\n");
				break;
			case 4: imprimir(abp->root);
				break;
			case 5: printf("altura[%d]", altura(abp->root));
				break;
			case 6: printf("Procurando fator de nodo...\n");
					printf("FATOR DO NODO [%d]", fator(valor(), abp));
				break;
			case 7:	printf("É AVL?");
					if(is_AVL(abp->root) == 0) printf("[%d] Totalmente Balanceada\n", is_AVL(abp->root));
					else if(is_AVL(abp->root) == 1) printf("[%d] Balanceada\n", is_AVL(abp->root));
					else printf("[%d] Desbalanceada", is_AVL(abp->root));
				break;
			case 8: printf("está balanceada?\n");
					if(is_balanceada(abp->root) == 0) printf("[%d] Totalmente Balanceada\n", is_balanceada(abp->root));
					else if(is_balanceada(abp->root) == 1) printf("[%d] Balanceada\n", is_balanceada(abp->root));
					else printf("[%d] Desbalanceada", is_balanceada(abp->root));
				break;
		}
	}while(op > 0);	
	
	
return 0;	
}
