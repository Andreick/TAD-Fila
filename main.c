#include <stdio.h>
#include "fila.h"

void menuFila() {
	printf("\tImplementacao de uma fila dinamica\n\n");

    printf("1) Criar Fila\n");
    printf("2) Sair\n");
}

void menuOperacoes() {
	printf("\tOperacoes da fila\n\n");

    printf("1) Enfileirar\n");
    printf("2) Desenfileirar\n");
    printf("3) Exibir Fila\n");
    printf("4) Excluir Fila\n");
}

int lerOpcao(int maior_opcao) {
	int opcao, qt_input;

	printf("\nSelecione uma opcao: ");
    qt_input = scanf("%d", &opcao);
    while(getchar() != '\n');

    if (qt_input != 1 || opcao < 1 || opcao > maior_opcao) {
    	printf("\n- Opcao invalida, tente novamente!\n\n\n");
    	return 0;
    }

    return opcao;
}

int lerNumero(int *num) {
	int qt_input;

	printf("Digite o numero que deseja inserir: ");
    qt_input = scanf("%d", num);
    while(getchar() != '\n');

    if (qt_input != 1) {
    	printf("\n- Numero invalido, tente novamente!\n\n\n");
    	return 0;
    }

    return 1;
}

int main() {
	Fila *fila;
	int opcao;
	int num;

	do {
		menuFila();
		opcao = lerOpcao(2);

		if (opcao == 1) {

			fila = criarFila();

			if (fila != NULL)
				printf("\n- Fila criada com sucesso!\n\n\n");
			else {
				printf("\n- Sem memoria disponivel para criar a fila!\n\n\n");
				continue;
			}

			do {
				menuOperacoes();
				opcao = lerOpcao(4);

				switch (opcao) {
					case 1:
						if (lerNumero(&num)) {

							if (enfileirar(num, fila))
    							printf("\n- Numero inserido com sucesso!\n\n\n");
    						else
    							printf("\n- Sem memoria disponivel para inserir o numero!\n\n\n");
						}
						break;
					case 2:
						if (desenfileirar(fila))
							printf("\n- Primeiro numero da fila removido com sucesso!\n\n\n");
						else
							printf("\n- A fila esta vazia, nao e possivel desenfileirar!\n\n\n");
						break;
					case 3:
						if (filaVazia(fila))
							printf("\n- A fila esta vazia!\n\n\n");
						else {
							printf("\n");
							exibirFila(fila);
							printf("\n\n\n");
						}
						break;
					case 4:
						excluirFila(&fila);
						printf("\n- Fila excluida com sucesso!\n\n\n");
						break;
				}

			} while (opcao != 4);
		}

	} while(opcao != 2);

	printf("\nPressione a tecla Enter para continuar. . . ");
    getchar();

	return 0;
}
