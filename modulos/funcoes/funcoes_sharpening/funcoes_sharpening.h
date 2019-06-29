#ifndef _FUN_SHARPENING_H_
#define _FUN_SHARPENING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void sharpenaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void sharpenaPixels(FILE *arquivo_imagem_sharpenada, Imagem imagem, Cabecalho cabecalho);

void mensagemSucessoCriacaoImagemSharpenada();
void mensagemErroCriacaoImagemSharpenada();

#endif