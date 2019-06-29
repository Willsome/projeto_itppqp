#include "funcoes_destaca_bw.h"

void destacaBwImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_destacada_bw = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_DESTACADA_BW, SUFIXO_IMAGEM_DESTACADA_BW);

	adicionaCabecalhoNaImagem(arquivo_imagem_destacada_bw, cabecalho);

	aplicaPixeisBw(arquivo_imagem_destacada_bw, cabecalho, imagem);
}

void aplicaPixeisBw(FILE *arquivo_imagem_destacada_bw, Cabecalho cabecalho, Imagem imagem) {

	int media_grayscale;

	int largura_imagem = atoi(cabecalho.tamanho_imagem_largura);
	int altura_imagem = atoi(cabecalho.tamanho_imagem_altura);

	for (int i = 0; i < altura_imagem; i++) {
		for (int j = 0; j < largura_imagem; j++) {
			
			media_grayscale = (imagem.pixels[i][j].R + imagem.pixels[i][j].G + imagem.pixels[i][j].B) / 3;

			if (media_grayscale <= (255/2)) {
				media_grayscale = 0;
			} else {
				media_grayscale = 255;
			}

			for (int k = 0; k < 3; k++) {
				fprintf(arquivo_imagem_destacada_bw, "%d\n", media_grayscale);
			}
		}
	}

	fclose(arquivo_imagem_destacada_bw);
	mensagemSucessoCriacaoImagemDestacadaBw();
}

void mensagemSucessoCriacaoImagemDestacadaBw() {
	printf("|\n");
	printf("+-------------------------------------------------+\n");
	printf("|   Imagem com destaque B/W salva com sucesso !   |\n");
	printf("+-------------------------------------------------+\n");
}

void mensagemErroCriacaoImagemDestacadaBw() {
	printf("|\n");
	printf("+-------------------------------------------+\n");
	printf("|   Erro ao criar imagem com destaque B/W   |\n");
	printf("+-------------------------------------------+\n");
	exit(1);
}