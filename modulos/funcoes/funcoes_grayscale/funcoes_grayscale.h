#ifndef _FUN_GRAYSCALE_H_
#define _FUN_GRAYSCALE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../structs/typedefs.h"

void deixaImagemEmGrayscale(FILE *arquivo_imagem, char nome_imagem[50]);
void pegaCabecalho(long linha_atual, char dados[20], FILE *arquivo_imagem_grayscale);
void preenchePixelComRGB(Imagem *imagem, long *pixel_posicao_atual, Pixel *pixel, int *cor_linha_atual, char dados[20]);
void aplicaPixeisEmCinzaNaImagemNova(Imagem *imagem, long pixel_posicao_atual, FILE *arquivo_imagem_grayscale);

#endif