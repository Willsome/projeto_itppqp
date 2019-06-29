#include "funcoes_blurring.h"

void blurarImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_blurada = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_BLURADA, SUFIXO_IMAGEM_BLURADA);
	
	adicionaCabecalhoNaImagem(arquivo_imagem_blurada, cabecalho);

	bluraPixels(arquivo_imagem_blurada, imagem, cabecalho);
}

void bluraPixels(FILE *arquivo_imagem_blurada, Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);
	
	Imagem imagem_tmp;
	alocaPixelsDaImagem(&imagem_tmp, &cabecalho);
	copiaImagemRGB(&imagem_tmp, imagem, cabecalho);

	Pixel pixel_media;
	for (int i = 1; i < tamanho_altura_original-2; i++) {
		for (int j = 1; j < tamanho_largura_original-2; j++) {

			pixel_media.R = (
				imagem.pixels[i-1][j-1].R + imagem.pixels[i-1][j].R + imagem.pixels[i-1][j+1].R +
				imagem.pixels[i][j-1].R + imagem.pixels[i][j].R + imagem.pixels[i][j+1].R +
				imagem.pixels[i+1][j-1].R + imagem.pixels[i+1][j].R + imagem.pixels[i+1][j+1].R
			) / 9;

			pixel_media.G = (
				imagem.pixels[i-1][j-1].G + imagem.pixels[i-1][j].G + imagem.pixels[i-1][j+1].G +
				imagem.pixels[i][j-1].G + imagem.pixels[i][j].G + imagem.pixels[i][j+1].G +
				imagem.pixels[i+1][j-1].G + imagem.pixels[i+1][j].G + imagem.pixels[i+1][j+1].G
			) / 9;

			pixel_media.B = (
				imagem.pixels[i-1][j-1].B + imagem.pixels[i-1][j].B + imagem.pixels[i-1][j+1].B +
				imagem.pixels[i][j-1].B + imagem.pixels[i][j].B + imagem.pixels[i][j+1].B +
				imagem.pixels[i+1][j-1].B + imagem.pixels[i+1][j].B + imagem.pixels[i+1][j+1].B
			) / 9;

			imagem_tmp.pixels[i][j].R = pixel_media.R;
			imagem_tmp.pixels[i][j].G = pixel_media.G;
			imagem_tmp.pixels[i][j].B = pixel_media.B;
		}
	}

	for (int i = 0; i < tamanho_altura_original; i++) {
		for (int j = 0; j < tamanho_largura_original; j++) {
			fprintf(arquivo_imagem_blurada, "%d\n", imagem_tmp.pixels[i][j].R);
			fprintf(arquivo_imagem_blurada, "%d\n", imagem_tmp.pixels[i][j].G);
			fprintf(arquivo_imagem_blurada, "%d\n", imagem_tmp.pixels[i][j].B);
		}
	}

	fclose(arquivo_imagem_blurada);
	mensagemSucessoCriacaoImagemBlurada();
}

void mensagemSucessoCriacaoImagemBlurada() {
	printf("|\n");
	printf("+----------------------------------+\n");
	printf("|   Imagem blurada com sucesso !   |\n");
	printf("+----------------------------------+\n");
}

void mensagemErroCriacaoImagemBlurada() {
	printf("|\n");
	printf("+----------------------------------+\n");
	printf("|   Erro ao criar imagem blurada   |\n");
	printf("+----------------------------------+\n");
	exit(1);
}