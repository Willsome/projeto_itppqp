#include "funcoes_grayscale.h"

void deixaImagemEmGrayscale(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_grayscale = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_GRAYSCALE, SUFIXO_IMAGEM_GRAYSCALE);

	adicionaCabecalhoNaImagem(arquivo_imagem_grayscale, cabecalho);

	aplicaPixeisEmCinzaNoArquivoImagemGrayscale(arquivo_imagem_grayscale, cabecalho, imagem);
}

void aplicaPixeisEmCinzaNoArquivoImagemGrayscale(FILE *arquivo_imagem_grayscale, Cabecalho cabecalho, Imagem imagem) {

	// Variável que armazenará a média tirada dos valores RGB para saber qual escala de cinza
	// será aplicada
	int media_grayscale;

	int largura_imagem = atoi(cabecalho.tamanho_imagem_largura);
	int altura_imagem = atoi(cabecalho.tamanho_imagem_altura);

	for (int i = 0; i < altura_imagem; i++) {
		
		for (int j = 0; j < largura_imagem; j++) {
			
			// Tira a média do pixel atual e aplica o valor para a tripla RGB ficar
			// na tonalidade de cinza adequada
			media_grayscale = (imagem.pixels[i][j].R + imagem.pixels[i][j].G + imagem.pixels[i][j].B) / 3;

			// Escreve no(a) novo(a) arquivo/foto os valores em escala de cinza
			for (int k = 0; k < 3; k++) { // Repete 3 vezes para gravar como o R, G e no B
				fprintf(arquivo_imagem_grayscale, "%d\n", media_grayscale);
			}
		}
	}

	// Fecha o(a) arquivo/imagem grayscale PPM
	fclose(arquivo_imagem_grayscale);
	mensagemSucessoCriacaoImagemGrayscale();
}

void mensagemSucessoCriacaoImagemGrayscale() {
	printf("|\n");
	printf("+---------------------------------------------+\n");
	printf("|   Imagem em grayscale salva com sucesso !   |\n");
	printf("+---------------------------------------------+\n");
}

void mensagemErroCriacaoImagemGrayscale() {
	printf("|\n");
	printf("+------------------------------------+\n");
	printf("|   Erro ao criar imagem grayscale   |\n");
	printf("+------------------------------------+\n");
	exit(1);
}