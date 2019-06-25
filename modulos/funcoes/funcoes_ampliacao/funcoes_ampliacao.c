#include "funcoes_ampliacao.h"

void ampliaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_ampliada = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_AMPLIADA, SUFIXO_IMAGEM_AMPLIADA);
	
	Cabecalho cabecalho_novo = criaCabecalhoComDimensoesAmpliadas(cabecalho);
	adicionaCabecalhoNovoNaImagem(arquivo_imagem_ampliada, cabecalho_novo);

	ampliaPixels(arquivo_imagem_ampliada, imagem, cabecalho);
}

Cabecalho criaCabecalhoComDimensoesAmpliadas(Cabecalho cabecalho) {

	Cabecalho cabecalho_novo;

	// Formato textual
	strcpy(cabecalho_novo.formato_textual, cabecalho.formato_textual);

	// Tamanho da imagem
	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	int tamanho_largura_nova = tamanho_largura_original * 2;
	int tamanho_altura_nova = tamanho_altura_original * 2;

	char tamanho_largura_nova_string[10];
	char tamanho_altura_nova_string[10];

	itoa(tamanho_largura_nova, tamanho_largura_nova_string, 10);
	itoa(tamanho_altura_nova, tamanho_altura_nova_string, 10);

	strcpy(cabecalho_novo.tamanho_imagem_largura, tamanho_largura_nova_string);
	strcpy(cabecalho_novo.tamanho_imagem_altura, tamanho_altura_nova_string);
	
	// Qualidade da imagem
	strcpy(cabecalho_novo.nivel_qualidade_imagem, cabecalho.nivel_qualidade_imagem);

	return cabecalho_novo;
}

void ampliaPixels(FILE *arquivo_imagem_ampliada, Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);
	
	for (int i = 0; i < tamanho_altura_original; i++) {

		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < tamanho_largura_original; j++) {
				
				for (int l = 0; l < 2; l++) {
					fprintf(arquivo_imagem_ampliada, "%d\n", imagem.pixels[i][j].R);
					fprintf(arquivo_imagem_ampliada, "%d\n", imagem.pixels[i][j].G);
					fprintf(arquivo_imagem_ampliada, "%d\n", imagem.pixels[i][j].B);
				}
			}
		}
	}

	fclose(arquivo_imagem_ampliada);
	mensagemSucessoCriacaoImagemAmpliada();
}

void mensagemSucessoCriacaoImagemAmpliada() {
	printf("|\n");
	printf("+-----------------------------------+\n");
	printf("|   Imagem ampliada com sucesso !   |\n");
	printf("+-----------------------------------+\n");
}

void mensagemErroCriacaoImagemAmpliada() {
	printf("|\n");
	printf("+-----------------------------------+\n");
	printf("|   Erro ao criar imagem ampliada   |\n");
	printf("+-----------------------------------+\n");
	exit(1);
}