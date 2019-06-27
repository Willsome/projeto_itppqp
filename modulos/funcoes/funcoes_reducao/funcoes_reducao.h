#ifndef _FUN_REDUCAO_H_
#define _FUN_REDUCAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void reduzImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
Cabecalho criaCabecalhoComDimensoesReduzidas(Cabecalho cabecalho);
void reduzPixels(FILE *arquivo_imagem_reduzida, Imagem imagem, Cabecalho cabecalho);

void mensagemSucessoCriacaoImagemReduzida();
void mensagemErroCriacaoImagemReduzida();

#endif