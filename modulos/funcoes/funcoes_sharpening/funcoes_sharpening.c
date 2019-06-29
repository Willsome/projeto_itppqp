#include "funcoes_sharpening.h"

void sharpenaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_sharpenada = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_SHARPENADA, SUFIXO_IMAGEM_SHARPENADA);
	
	adicionaCabecalhoNaImagem(arquivo_imagem_sharpenada, cabecalho);

	sharpenaPixels(arquivo_imagem_sharpenada, imagem, cabecalho);
}

void sharpenaPixels(FILE *arquivo_imagem_sharpenada, Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);
	
	Imagem imagem_tmp;
	alocaPixelsDaImagem(&imagem_tmp, &cabecalho);
	copiaImagemRGB(&imagem_tmp, imagem, cabecalho);

	Pixel pixel_media;
	for (int i = 1; i < tamanho_altura_original-2; i++) {
		for (int j = 1; j < tamanho_largura_original-2; j++) {

			pixel_media.R = 5 * imagem.pixels[i][j].R -
				imagem.pixels[i-1][j].R -
				imagem.pixels[i][j-1].R -
				imagem.pixels[i][j+1].R -
				imagem.pixels[i+1][j].R;

			pixel_media.G = 5 * imagem.pixels[i][j].G -
				imagem.pixels[i-1][j].G -
				imagem.pixels[i][j-1].G -
				imagem.pixels[i][j+1].G -
				imagem.pixels[i+1][j].G;

			pixel_media.B = 5 * imagem.pixels[i][j].B -
				imagem.pixels[i-1][j].B -
				imagem.pixels[i][j-1].B -
				imagem.pixels[i][j+1].B -
				imagem.pixels[i+1][j].B;

			if (pixel_media.R < 0) {
				pixel_media.R = 0;
			}

			if (pixel_media.G < 0) {
				pixel_media.G = 0;
			}

			if (pixel_media.B < 0) {
				pixel_media.B = 0;
			}

			if (pixel_media.R > 255) {
				pixel_media.R = 255;
			}

			if (pixel_media.G > 255) {
				pixel_media.G = 255;
			}

			if (pixel_media.B > 255) {
				pixel_media.B = 255;
			}

			imagem_tmp.pixels[i][j].R = pixel_media.R;
			imagem_tmp.pixels[i][j].G = pixel_media.G;
			imagem_tmp.pixels[i][j].B = pixel_media.B;
		}
	}

	for (int i = 0; i < tamanho_altura_original; i++) {
		for (int j = 0; j < tamanho_largura_original; j++) {
			fprintf(arquivo_imagem_sharpenada, "%d\n", imagem_tmp.pixels[i][j].R);
			fprintf(arquivo_imagem_sharpenada, "%d\n", imagem_tmp.pixels[i][j].G);
			fprintf(arquivo_imagem_sharpenada, "%d\n", imagem_tmp.pixels[i][j].B);
		}
	}

	fclose(arquivo_imagem_sharpenada);
	mensagemSucessoCriacaoImagemSharpenada();
}

void mensagemSucessoCriacaoImagemSharpenada() {
	printf("|\n");
	printf("+-------------------------------------+\n");
	printf("|   Imagem sharpenada com sucesso !   |\n");
	printf("+-------------------------------------+\n");
}

void mensagemErroCriacaoImagemSharpenada() {
	printf("|\n");
	printf("+-------------------------------------+\n");
	printf("|   Erro ao criar imagem sharpenada   |\n");
	printf("+-------------------------------------+\n");
	exit(1);
}