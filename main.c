#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulos/constantes/constantes.h"
#include "modulos/structs/typedefs.h"
#include "modulos/funcoes/funcoes_gerais/funcoes_gerais.h"
#include "modulos/funcoes/funcoes_grayscale/funcoes_grayscale.h"

int main() {

	char nome_imagem[50];

	FILE *arquivo_imagem;
	arquivo_imagem = pegaImagemPeloNome(nome_imagem);

	if (arquivo_imagem == NULL){
		printf("|\n");
		printf("+-------------------------------------+\n");
		printf("|   A imagem informada nao existe !   |\n");
		printf("+-------------------------------------+\n");
		return 1;

	} else {

		int opcao = 0;

		do {
			// Pega a opção do usuário passando o endereço
			// da variável que vai ser armazenada a opção
			// + Nome da variável: opcao
			pegaOpcaoUsuario(&opcao);

			switch(opcao) {
				
				case 1:
					deixaImagemEmGrayscale(arquivo_imagem, nome_imagem);
					break;

				case 8:
					break;

				default:
					printf("|\n");
					printf("+----------------------+\n");
					printf("|   Opcao invalida !   |\n");
					printf("+----------------------+\n");
					break;
			}

		} while(opcao != SAIR);
	}

	return 0;
}