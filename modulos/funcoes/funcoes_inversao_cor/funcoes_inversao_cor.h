#ifndef _FUN_COR_INVERTIDA_H_
#define _FUN_COR_INVERTIDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../constantes/constantes.h"
#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void inverteCorImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void aplicaPixeisComCorInvertida(FILE *arquivo_imagem_cor_invertida, Cabecalho cabecalho, Imagem imagem);

void mensagemSucessoCriacaoImagemCorInvertida();
void mensagemErroCriacaoImagemCorInvertida();

#endif