#include "funcoes_inversao_cor.h"

void inverteCorImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_cor_invertida = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_COR_INVERTIDA, SUFIXO_IMAGEM_COR_INVERTIDA);

	adicionaCabecalhoNaImagem(arquivo_imagem_cor_invertida, cabecalho);

	aplicaPixeisComCorInvertida(arquivo_imagem_cor_invertida, cabecalho, imagem);
}

void aplicaPixeisComCorInvertida(FILE *arquivo_imagem_cor_invertida, Cabecalho cabecalho, Imagem imagem) {

	int largura_imagem = atoi(cabecalho.tamanho_imagem_largura);
	int altura_imagem = atoi(cabecalho.tamanho_imagem_altura);

	for (int i = 0; i < altura_imagem; i++) {
		for (int j = 0; j < largura_imagem; j++) {

			fprintf(arquivo_imagem_cor_invertida, "%d\n", 255 - imagem.pixels[i][j].R);
			fprintf(arquivo_imagem_cor_invertida, "%d\n", 255 - imagem.pixels[i][j].G);
			fprintf(arquivo_imagem_cor_invertida, "%d\n", 255 - imagem.pixels[i][j].B);
		}
	}

	fclose(arquivo_imagem_cor_invertida);
	mensagemSucessoCriacaoImagemCorInvertida();
}

void mensagemSucessoCriacaoImagemCorInvertida() {
	printf("|\n");
	printf("+--------------------------------------------------+\n");
	printf("|   Imagem com cor invertida salva com sucesso !   |\n");
	printf("+--------------------------------------------------+\n");
}

void mensagemErroCriacaoImagemCorInvertida() {
	printf("|\n");
	printf("+--------------------------------------------+\n");
	printf("|   Erro ao criar imagem com cor invertida   |\n");
	printf("+--------------------------------------------+\n");
	exit(1);
}