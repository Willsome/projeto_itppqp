#ifndef _FUN_AMPLIACAO_H_
#define _FUN_AMPLIACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void ampliaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
Cabecalho criaCabecalhoComDimensoesAmpliadas(Cabecalho cabecalho);
void ampliaPixels(FILE *arquivo_imagem_ampliada, Imagem imagem, Cabecalho cabecalho);

void mensagemSucessoCriacaoImagemAmpliada();
void mensagemErroCriacaoImagemAmpliada();

#endif