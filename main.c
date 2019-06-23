#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulos/constantes/constantes.h"
#include "modulos/structs/typedefs.h"
#include "modulos/funcoes/funcoes_gerais/funcoes_gerais.h"
#include "modulos/funcoes/funcoes_grayscale/funcoes_grayscale.h"

int main() {

	// Variável com o nome da imagem
	char nome_imagem[50];

	// Variável que armazenará o arquivo da imagem
	FILE *arquivo_imagem = pegaImagemPeloNome(nome_imagem);

	// Variável que armazenará o cabeçalho da imagem PPM
	Cabecalho cabecalho;

	// Variável que armazenará a imagem PPM
	Imagem imagem;

	if (arquivo_imagem == NULL){
		printf("|\n");
		printf("+-------------------------------------+\n");
		printf("|   A imagem informada nao existe !   |\n");
		printf("+-------------------------------------+\n");
		return 1;

	} else {

		int opcao = 0;

		do {

			// Através do arquivo da imagem, cria uma struct Imagem com as informações do arquivo
			preencheStructsCabecalhoImagem(arquivo_imagem, &cabecalho, &imagem);

			// Pega a opção do usuário e coloca na variáve "opcao"
			pegaOpcaoUsuario(&opcao);

			switch(opcao) {

				case 1:
					deixaImagemEmGrayscale(nome_imagem, imagem, cabecalho);
					break;

				case 2:

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
