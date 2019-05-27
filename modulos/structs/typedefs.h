#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#include "../constantes/constantes.h"

typedef struct {
	int R;
	int G;
	int B;
} Pixel;

typedef struct {
	Pixel *pixeis;
} Imagem;

#endif