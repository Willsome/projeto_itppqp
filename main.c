#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modulos/constantes/constantes.h"
#include "modulos/structs/typedefs.h"
#include "modulos/funcoes/funcoes_gerais/funcoes_gerais.h"
#include "modulos/funcoes/funcoes_grayscale/funcoes_grayscale.h"
#include "modulos/funcoes/funcoes_rotacao/funcoes_rotacao.h"
#include "modulos/funcoes/funcoes_ampliacao/funcoes_ampliacao.h"
#include "modulos/funcoes/funcoes_reducao/funcoes_reducao.h"
#include "modulos/funcoes/funcoes_blurring/funcoes_blurring.h"
#include "modulos/funcoes/funcoes_inversao/funcoes_inversao.h"
#include "modulos/funcoes/funcoes_inversao_cor/funcoes_inversao_cor.h"
#include "modulos/funcoes/funcoes_destaca_bw/funcoes_destaca_bw.h"

void mensagemErroAberturaImagem();

int main() {

	// Variável com o nome da imagem
	char nome_imagem[50];

	// Variável que armazenará o arquivo da imagem
	FILE *arquivo_imagem = pegaImagemPeloNome(nome_imagem);

	if (arquivo_imagem == NULL){
		mensagemErroAberturaImagem();

	} else {

		// Variável que armazenará o cabeçalho da imagem PPM
		Cabecalho cabecalho;

		// Variável que armazenará a imagem PPM
		Imagem imagem;

		// Através do arquivo da imagem, cria uma struct Imagem com as informações do arquivo
		preencheStructsCabecalhoImagem(arquivo_imagem, &cabecalho, &imagem);

		int opcao;
		do {

			// Pega a opção do usuário
			opcao = pegaOpcaoUsuario();

			switch(opcao) {

				case 1:
					deixaImagemEmGrayscale(nome_imagem, imagem, cabecalho);
					break;

				case 2:
					rotacionaImagem(nome_imagem, imagem, cabecalho);
					break;

				case 3:
					ampliaImagem(nome_imagem, imagem, cabecalho);
					break;

				case 4:
					reduzImagem(nome_imagem, imagem, cabecalho);
					break;

				case 5:
					blurarImagem(nome_imagem, imagem, cabecalho);
					break;

				case 6:
					sharpenaImagem(nome_imagem, imagem, cabecalho);
					break;

				case 7:
					inverteImagem(nome_imagem, imagem, cabecalho);
					break;

				case 8:
					inverteCorImagem(nome_imagem, imagem, cabecalho);
					break;

				case 9:
					destacaBwImagem(nome_imagem, imagem, cabecalho);
					break;

				case 666:
					break;

				default:
					mensagemErroOpcaoInvalida();
					break;
			}

		} while(opcao != SAIR);
	}

	return 0;
}

void mensagemErroAberturaImagem() {
	printf("|\n");
	printf("+-------------------------------------+\n");
	printf("|   A imagem informada nao existe !   |\n");
	printf("+-------------------------------------+\n");
	exit(1);
}