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
			"\n##########     MENU     #########\n"
			"#   0. Sair                     #\n"
			"#   1. Inserir nodo             #\n"
			"#   2. Remover nodo             #\n"
			"#   3. Imprimir arvore          #\n"
			"#   4.                          #\n"
			"##########              #########\n"
		);
		scanf("%d", &op);
		switch(op){
			case 1: inserir(valor(), abp->root, abp);
				break;
			case 2: //remover();
				break;
			case 3: imprimir(abp->root);
				break;
		}
	}while(op > 0);	
	
	
return 0;	
}
