#include "funcoes_grayscale.h"
#include "../../constantes/constantes.h"

void deixaImagemEmGrayscale(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

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

	adicionaCabecalhoNaImagem(arquivo_imagem_grayscale, cabecalho);

	// Cria imagem PPM nova em escala de cinza
	aplicaPixeisEmCinzaNaImagemNova(arquivo_imagem_grayscale, cabecalho, imagem);

	printf("|\n");
	printf("+---------------------------------------------+\n");
	printf("|   Imagem em grayscale salva com sucesso !   |\n");
	printf("+---------------------------------------------+\n");
}

void adicionaCabecalhoNaImagem(FILE *arquivo_imagem_grayscale, Cabecalho cabecalho) {
	
	fprintf(arquivo_imagem_grayscale, "%s", cabecalho.formato_textual);

	char tamanho_imagem[12] = "";
	strcat(tamanho_imagem, cabecalho.tamanho_imagem_largura);
	strcat(tamanho_imagem, " ");
	strcat(tamanho_imagem, cabecalho.tamanho_imagem_altura);
	fprintf(arquivo_imagem_grayscale, "%s", tamanho_imagem);
	
	fprintf(arquivo_imagem_grayscale, "%s", cabecalho.nivel_qualidade_imagem);
}

void aplicaPixeisEmCinzaNaImagemNova(FILE *arquivo_imagem_grayscale, Cabecalho cabecalho, Imagem imagem) {

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