#ifndef _FUN_ROTACAO_H_
#define _FUN_ROTACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../funcoes_gerais/funcoes_gerais.h"
#include "../../structs/typedefs.h"

void rotacionaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
int pegaRotacaoUsuario();
void imprimeOpcoesRotacao();
void rotaciona90(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void rotaciona180(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void rotaciona270(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void gravaRGB(FILE *arquivo_imagem_rotacionada, Imagem imagem, int tamanho_altura_nova, int tamanho_largura_nova);
FILE* criaArquivoImagemRotacionada(char nome_imagem[50], char rotacao[5]);
Cabecalho criaCabecalhoComDimensoesInvertidas(Cabecalho cabecalho);
void adicionaCabecalhoNovoNaImagem(FILE *arquivo_imagem_rotacionada, Cabecalho cabecalho_dimensoes_invertidas);
void mensagemErroCriacaoImagemRotacionada();
void mensagemSucessoRotacaoImagem();

#endif