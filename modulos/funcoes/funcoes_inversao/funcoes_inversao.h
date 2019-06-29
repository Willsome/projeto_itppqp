#ifndef _FUN_INVERSAO_H_
#define _FUN_INVERSAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void inverteImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void invertePixels(FILE *arquivo_imagem_invertida, Imagem imagem, Cabecalho cabecalho);

void mensagemSucessoCriacaoImagemInvertida();
void mensagemErroCriacaoImagemInvertida();

#endif