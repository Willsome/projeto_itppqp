#include "funcoes_reducao.h"

void reduzImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_reduzida = criaArquivoImagem(nome_imagem, PASTA_IMAGEM_REDUZIDA, SUFIXO_IMAGEM_REDUZIDA);
	
	Cabecalho cabecalho_novo = criaCabecalhoComDimensoesReduzidas(cabecalho);
	adicionaCabecalhoNovoNaImagem(arquivo_imagem_reduzida, cabecalho_novo);

	reduzPixels(arquivo_imagem_reduzida, imagem, cabecalho);
}

Cabecalho criaCabecalhoComDimensoesReduzidas(Cabecalho cabecalho) {

	Cabecalho cabecalho_novo;

	// Formato textual
	strcpy(cabecalho_novo.formato_textual, cabecalho.formato_textual);

	// Tamanho da imagem
	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	int tamanho_largura_nova = tamanho_largura_original / 2;
	int tamanho_altura_nova;
	if (tamanho_altura_original % 2 != 0) {
		tamanho_altura_nova = (tamanho_altura_original / 2) + 1;
	} else {
		tamanho_altura_nova = tamanho_altura_original / 2;
	}

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

void reduzPixels(FILE *arquivo_imagem_reduzida, Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	Pixel pixel_media;
	
	for (int i = 0; i < tamanho_altura_original; i+=2) {
			for (int j = 0; j < tamanho_largura_original; j+=2) {
				
				if (i+1 < tamanho_altura_original) {
					if (j+1 < tamanho_largura_original) {
						
						pixel_media.R = (imagem.pixels[i][j].R + imagem.pixels[i+1][j].R + imagem.pixels[i][j+1].R + imagem.pixels[i+1][j+1].R) / 4;
						pixel_media.G = (imagem.pixels[i][j].G + imagem.pixels[i+1][j].G + imagem.pixels[i][j+1].G + imagem.pixels[i+1][j+1].G) / 4;
						pixel_media.B = (imagem.pixels[i][j].B + imagem.pixels[i+1][j].B + imagem.pixels[i][j+1].B + imagem.pixels[i+1][j+1].B) / 4;

						fprintf(arquivo_imagem_reduzida, "%d\n", pixel_media.R);
						fprintf(arquivo_imagem_reduzida, "%d\n", pixel_media.G);
						fprintf(arquivo_imagem_reduzida, "%d\n", pixel_media.B);
					
					}
				
				} else if (i+1 == tamanho_altura_original) {
					if (j+1 < tamanho_largura_original) {
						
						pixel_media.R = (imagem.pixels[i][j].R + imagem.pixels[i][j+1].R) / 2;
						pixel_media.G = (imagem.pixels[i][j].G + imagem.pixels[i][j+1].G) / 2;
						pixel_media.B = (imagem.pixels[i][j].B + imagem.pixels[i][j+1].B) / 2;

						fprintf(arquivo_imagem_reduzida, "%d\n", pixel_media.R);
						fprintf(arquivo_imagem_reduzida, "%d\n", pixel_media.G);
						fprintf(arquivo_imagem_reduzida, "%d\n", pixel_media.B);
					}
				}

			}
	}

	fclose(arquivo_imagem_reduzida);
	mensagemSucessoCriacaoImagemReduzida();
}

void mensagemSucessoCriacaoImagemReduzida() {
	printf("|\n");
	printf("+-----------------------------------+\n");
	printf("|   Imagem reduzida com sucesso !   |\n");
	printf("+-----------------------------------+\n");
}

void mensagemErroCriacaoImagemReduzida() {
	printf("|\n");
	printf("+-----------------------------------+\n");
	printf("|   Erro ao criar imagem reduzida   |\n");
	printf("+-----------------------------------+\n");
	exit(1);
}