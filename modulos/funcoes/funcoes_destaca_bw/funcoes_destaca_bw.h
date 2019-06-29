#ifndef _FUN_DESTACA_BW_H_
#define _FUN_DESTACA_BW_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../constantes/constantes.h"
#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void destacaBwImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void aplicaPixeisBw(FILE *arquivo_imagem_destacada_bw, Cabecalho cabecalho, Imagem imagem);

void mensagemSucessoCriacaoImagemDestacadaBw();
void mensagemErroCriacaoImagemDestacadaBw();

#endif