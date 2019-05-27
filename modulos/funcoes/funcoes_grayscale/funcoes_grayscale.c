#include "funcoes_grayscale.h"
#include "../../constantes/constantes.h"

void deixaImagemEmGrayscale(FILE *arquivo_imagem, char nome_imagem[50]) {

	// Cria struct Imagem e aloca seu vetor de pixels por 1M de pixels
	Imagem imagem;
	imagem.pixeis = (Pixel*) malloc(1000000 * sizeof(Pixel));
	// Define o valor inicial de cada struct Pixel como "0"
	memset(imagem.pixeis, 0, 1000000 * sizeof(Pixel));
	// Variável usada para saber a partir de qual posição existem pixeis não preenchidos
	long pixel_posicao_atual = 0;

	// Linha atual da leitura da imagem PPM
	long linha_atual = 0;
	// Dados da linha atual
	char dados[20];

	// Cria o nome da imagem em grayscale, adicionando ao final do
	// nome da imagem original o texto "_grayscale" e a extensão ".ppm"
	char nome_imagem_grayscale[70];
	strcpy(nome_imagem_grayscale, nome_imagem);
	strcat(nome_imagem_grayscale, "_grayscale.ppm");

	// Nova imagem criada para receber a anterior com a escala de cinza aplicada
	FILE *arquivo_imagem_grayscale = fopen(nome_imagem_grayscale, "w+");

	// Cria struct Pixel que recebera cada tripla de valores RGB e colocara na posição atual
	// do vetor de pixeis que não está preenchido na struct criada anteriormente "imagem"
	Pixel pixel;
	int cor_linha_atual = RED;

	while(fgets(dados, sizeof(dados), arquivo_imagem) != NULL) {

		linha_atual++; // Começa com 1 depois do "++", ou seja LINHA 1 do arquivo

		if(linha_atual < LINHA_QUE_COMECAM_OS_PIXEIS) {
			pegaCabecalho(linha_atual, dados, arquivo_imagem_grayscale);
		} else {
			preenchePixelComRGB(&imagem, &pixel_posicao_atual, &pixel, &cor_linha_atual, dados);
		}
	}

	// Cria imagem PPM nova em escala de cinza
	aplicaPixeisEmCinzaNaImagemNova(&imagem, pixel_posicao_atual, arquivo_imagem_grayscale);

	// Libera o espaço alocado pros pixeis da struct Imagem
	free(imagem.pixeis);

	printf("|\n");
	printf("+---------------------------------------------+\n");
	printf("|   Imagem em grayscale salva com sucesso !   |\n");
	printf("+---------------------------------------------+\n");
}

void pegaCabecalho(long linha_atual, char dados[20], FILE *arquivo_imagem_grayscale) {

	// Variáveis que armazenarão o cabeçalho da imagem PPM
	char formato_textual[30];
	char tamanho_imagem[30];
	char nivel_qualidade_imagem[5];

	if (linha_atual == 1) {
		strcpy(formato_textual, dados);
		fprintf(arquivo_imagem_grayscale, "%s", dados);
	} else if(linha_atual == 2) {
		strcpy(tamanho_imagem, dados);
		fprintf(arquivo_imagem_grayscale, "%s", dados);
	} else if(linha_atual == 3) {
		strcpy(nivel_qualidade_imagem, dados);
		fprintf(arquivo_imagem_grayscale, "%s", dados);
	}
}

void preenchePixelComRGB(Imagem *imagem, long *pixel_posicao_atual, Pixel *pixel, int *cor_linha_atual, char dados[20]) {

	// Obs.: A função "atoi()" recebe uma 'string' e converte para 'int'

	switch(*cor_linha_atual) {

		case RED:
			pixel->R = atoi(dados);
			(*cor_linha_atual)++;
			break;

		case GREEN:
			pixel->G = atoi(dados);
			(*cor_linha_atual)++;
			break;

		case BLUE:
			pixel->B = atoi(dados);
			
			// Reseta a cor da linha atual para RED
			*cor_linha_atual = RED;
			// Depois de preenchido o struct Pixel, copia ele para a posição atual do
			// vetor de pixeis da struct Imagem
			imagem->pixeis[*pixel_posicao_atual] = *pixel;
			// Incrementa a posição atual do pixel vazio na struct Imagem
			(*pixel_posicao_atual)++;
			break;
	}
}

void aplicaPixeisEmCinzaNaImagemNova(Imagem *imagem, long pixel_posicao_atual, FILE *arquivo_imagem_grayscale) {

	// Variável que armazenará a média tirada dos valores RGB para saber qual escala de cinza
	// será aplicada
	int grayscale_media;

	for (int i = 0; i < pixel_posicao_atual; i++) {

		// Tira a média do pixel atual e aplica o valor para a tripla RGB ficar
		// na tonalidade de cinza adequada
		grayscale_media = (imagem->pixeis[i].R + imagem->pixeis[i].G + imagem->pixeis[i].B) / 3;
		imagem->pixeis[i].R = grayscale_media;
		imagem->pixeis[i].G = grayscale_media;
		imagem->pixeis[i].B = grayscale_media;

		// Escreve no(a) novo(a) arquivo/foto os valores em escala de cinza
		fprintf(arquivo_imagem_grayscale, "%d\n", imagem->pixeis[i].R);
		fprintf(arquivo_imagem_grayscale, "%d\n", imagem->pixeis[i].G);
		fprintf(arquivo_imagem_grayscale, "%d\n", imagem->pixeis[i].B);
	}

	// Fecha o(a) arquivo/imagem PPM
	fclose(arquivo_imagem_grayscale);
}