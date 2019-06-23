#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include "../constantes/constantes.h"

typedef struct {
	int R;
	int G;
	int B;
} Pixel;

typedef struct {
	Pixel **pixels;
} Imagem;

typedef struct {
	char formato_textual[30];
	char tamanho_imagem_largura[5];
	char tamanho_imagem_altura[5];
	char nivel_qualidade_imagem[5];
} Cabecalho;

typedef struct {
	long x;
	long y;
} PosicaoAtualPixel;

#endif