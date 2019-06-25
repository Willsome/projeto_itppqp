#ifndef _FUN_ROTACAO_H_
#define _FUN_ROTACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_gerais/funcoes_gerais.h"

void rotacionaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);

void imprimeOpcoesRotacao();
int pegaRotacaoUsuario();

void rotaciona90(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void rotacionaPixels90(FILE *arquivo_imagem_rotacionada, Imagem imagem, Cabecalho cabecalho);

void rotaciona180(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void rotacionaPixels180(FILE *arquivo_imagem_rotacionada, Imagem imagem, Cabecalho cabecalho);

void rotaciona270(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho);
void rotacionaPixels270(FILE *arquivo_imagem_rotacionada, Imagem imagem, Cabecalho cabecalho);

void gravaRGB(FILE *arquivo_imagem_rotacionada, Imagem imagem, int tamanho_altura_nova, int tamanho_largura_nova);

FILE* criaArquivoImagemRotacionada(char nome_imagem[50], char rotacao[5]);
Cabecalho criaCabecalhoComDimensoesInvertidas(Cabecalho cabecalho);

void mensagemSucessoRotacaoImagem();
void mensagemErroCriacaoImagemRotacionada();

#endif