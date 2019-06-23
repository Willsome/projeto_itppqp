#include "funcoes_grayscale.h"
#include "../funcoes_gerais/funcoes_gerais.h"
#include "../../constantes/constantes.h"

void deixaImagemEmGrayscale(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	FILE *arquivo_imagem_grayscale = criaArquivoImagemGrayscale(nome_imagem);

	adicionaCabecalhoNaImagem(arquivo_imagem_grayscale, cabecalho);

	aplicaPixeisEmCinzaNoArquivoImagemGrayscale(arquivo_imagem_grayscale, cabecalho, imagem);

	mensagemSucessoCriacaoImagemGrayscale();
}

FILE* criaArquivoImagemGrayscale(char nome_imagem[50]) {
	// Caminho da imagem + extensão
	char path_imagem[] = "imagens/grayscale/";
	char extensao_ppm[] = "_grayscale.ppm";

	// Variável com o nome da imagem (caminho + nome + extensão)
	char nome_imagem_ppm_grayscale[70] = "";
	strcat(nome_imagem_ppm_grayscale, path_imagem);
	strcat(nome_imagem_ppm_grayscale, nome_imagem);
	strcat(nome_imagem_ppm_grayscale, extensao_ppm);

	// Nova imagem criada para receber a anterior com a escala de cinza aplicada
	FILE *arquivo_imagem_grayscale = fopen(nome_imagem_ppm_grayscale, "w+");
	if (arquivo_imagem_grayscale == NULL) {
		mensagemErroCriacaoImagemGrayscale();
	}

	return arquivo_imagem_grayscale;
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
}

void mensagemErroCriacaoImagemGrayscale() {
	printf("|\n");
	printf("+------------------------------------+\n");
	printf("|   Erro ao criar imagem grayscale   |\n");
	printf("+------------------------------------+\n");
	exit(1);
}

void mensagemSucessoCriacaoImagemGrayscale() {
	printf("|\n");
	printf("+---------------------------------------------+\n");
	printf("|   Imagem em grayscale salva com sucesso !   |\n");
	printf("+---------------------------------------------+\n");
}