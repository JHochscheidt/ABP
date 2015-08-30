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
			case 3:  if(! buscar(valor(), abp->root)) printf("Valor não existe");
					else printf("Valor existe");
				break;
			case 4: imprimir(abp->root);
				break;
			case 5: printf("altura[%d]", altura(abp->root));
				break;
			case 6: printf("FATOR DO NODO [%d]", fator(abp, valor()));
				break;
			case 7:	printf("É AVL?");
					if(is_AVL(abp) == TRUE)  printf("[%d] SIM ", is_AVL(abp));
					else printf("[%d] NÃO", is_AVL(abp));
				break;
			case 8: printf("está balanceada?\n");
					if(is_balanceada(abp->root) == TRUE) printf("Está balanceada");
					else printf("Desbalanceada");
				break;
		}
	}while(op > 0);	
	
	
return 0;	
}
