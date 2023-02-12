/*
 * main.c
 * Resposta do exercício 3 do capítulo 8.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(void) {

	int opcao;
	char valor;
	char elemento;
	char pai;

	do {

		printf("\n");
		printf("ÁRVORE CLÁSSICA\n");
		printf("Escolha a opcao\n");
		printf("0. Sair\n");
		printf("1. ROOT\n");
		printf("2. INSERT\n");
		printf("3. SEARCH\n");
		printf("4. UPDATE\n");
		printf("5. DELETE\n");
		printf("6. Exibir Pré-Ordem\n");
		printf("7. Quantidade de Nós\n");
		printf("Digite uma opção:");
		scanf("%d", &opcao);

		switch (opcao) {
		case 0:
			exit(1);
			break;

		case 1:
			printf("Digite um valor para a raiz da árvore:");
			scanf(" %c", &valor);
			criar_raiz(valor);
			break;

		case 2:
			printf("Digite um valor a ser inserido:");
			scanf(" %c", &valor);
			printf("Digite o pai deste valor:");
			scanf(" %c", &pai);
			insert(get_raiz(), pai, valor);
			break;

		case 3:
			printf("Digite um elemento a ser pesquisado:");
			scanf(" %c", &valor);

			No *no_search = NULL;
			no_search = search(get_raiz(), valor);
			if (no_search != NULL) {
				printf("Elemento %c pertence a árvore.", no_search->valor);
			} else {
				printf("Elemento não %c pertence a árvore.", valor);
			}
			break;

		case 4:
			printf("Digite o elemento a ser atualizado:");
			scanf(" %c", &elemento);
			printf("Digite o novo valor:");
			scanf(" %c", &valor);
			update(get_raiz(), elemento, valor);
			break;

		case 5:
			printf("Digite um elemento a ser apagado:");
			scanf(" %c", &valor);

			No *no_delete = NULL;
			no_delete = search(get_raiz(), valor);
			if (no_delete != NULL) {
				delete(no_delete);
			} else {
				printf("Elemento não %c pertence a árvore.", valor);
			}
			break;
		case 6:
			exibir_pre_ordem(get_raiz());
			break;
		case 7:
			printf("A quantidade de nós da árvore é %d .", contar_nos(get_raiz()));
			break;
		default:
			printf("Comando invalido\n\n");
			break;
		}

	} while (opcao);

	return 0;
}
