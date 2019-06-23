#ifndef _FUN_ROTACAO_H_
#define _FUN_ROTACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes_gerais/funcoes_gerais.h"
#include "../../structs/typedefs.h"

void rotacionaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
Cabecalho criaCabecalhoComDimensoesInvertidas(Cabecalho cabecalho);
FILE* criaArquivoImagemRotacionada(char nome_imagem[50]);
int pegaRotacaoUsuario();
void imprimeOpcoesRotacao();
void adicionaCabecalhoNovoNaImagem(FILE *arquivo_imagem_rotacionada, Cabecalho cabecalho_dimensoes_invertidas);
void mensagemErroCriacaoImagemRotacionada();
void mensagemSucessoRotacaoImagem();

#endif