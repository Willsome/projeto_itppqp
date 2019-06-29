#ifndef _FUN_BLURRING_H_
#define _FUN_BLURRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void blurarImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void bluraPixels(FILE *arquivo_imagem_blurada, Imagem imagem, Cabecalho cabecalho);

void mensagemSucessoCriacaoImagemBlurada();
void mensagemErroCriacaoImagemBlurada();

#endif