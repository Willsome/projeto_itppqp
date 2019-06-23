#ifndef _FUN_GRAYSCALE_H_
#define _FUN_GRAYSCALE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../structs/typedefs.h"

void deixaImagemEmGrayscale(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
FILE* criaArquivoImagemGrayscale(char nome_imagem[50]);
void aplicaPixeisEmCinzaNoArquivoImagemGrayscale(FILE *arquivo_imagem_grayscale, Cabecalho cabecalho, Imagem imagem);
void mensagemErroCriacaoImagemGrayscale();
void mensagemSucessoCriacaoImagemGrayscale();

#endif