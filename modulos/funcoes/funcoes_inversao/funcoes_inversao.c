#include "funcoes_inversao.h"

void inverteImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_invertida = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_INVERTIDA, SUFIXO_IMAGEM_INVERTIDA);
	
	adicionaCabecalhoNaImagem(arquivo_imagem_invertida, cabecalho);

	invertePixels(arquivo_imagem_invertida, imagem, cabecalho);
}

void invertePixels(FILE *arquivo_imagem_invertida, Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);
	
	Pixel pixel_media;
	
	for (int i = 0; i < tamanho_altura_original; i++) {
		for (int j = 0; j < tamanho_largura_original; j++) {
			
			fprintf(arquivo_imagem_invertida, "%d\n", imagem.pixels[i][(tamanho_largura_original-1)-j].R);
			fprintf(arquivo_imagem_invertida, "%d\n", imagem.pixels[i][(tamanho_largura_original-1)-j].G);
			fprintf(arquivo_imagem_invertida, "%d\n", imagem.pixels[i][(tamanho_largura_original-1)-j].B);
		}
	}

	fclose(arquivo_imagem_invertida);
	mensagemSucessoCriacaoImagemInvertida();
}

void mensagemSucessoCriacaoImagemInvertida() {
	printf("|\n");
	printf("+------------------------------------+\n");
	printf("|   Imagem invertida com sucesso !   |\n");
	printf("+------------------------------------+\n");
}

void mensagemErroCriacaoImagemInvertida() {
	printf("|\n");
	printf("+------------------------------------+\n");
	printf("|   Erro ao criar imagem invertida   |\n");
	printf("+------------------------------------+\n");
	exit(1);
}