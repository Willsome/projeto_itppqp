#ifndef _FUN_GERAIS_H_
#define _FUN_GERAIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_grayscale/funcoes_grayscale.h"
#include "../funcoes_ampliacao/funcoes_ampliacao.h"

FILE* pegaImagemPeloNome();

void mostraMenu();
int pegaOpcaoUsuario();

void preencheStructsCabecalhoImagem(FILE *arquivo_imagem, Cabecalho *cabecalho, Imagem *imagem);
void preencheCabecalho(long linha_atual, char dados[20], Cabecalho *cabecalho, Imagem *imagem);

void alocaPixelsDaImagem(Imagem *imagem, Cabecalho *cabecalho);
void preencheImagemComRGB(char dados[20], Cabecalho *cabecalho, Imagem *imagem, PosicaoAtualPixel *posicao_atual_pixel, Pixel *pixel, int *cor_linha_atual, long *cont);

FILE* criaArquivoImagem(char nome_imagem[50], char pasta_imagem[50], char sufixo_imagem[50]);

void adicionaCabecalhoNaImagem(FILE *arquivo_imagem, Cabecalho cabecalho);
void adicionaCabecalhoNovoNaImagem(FILE *arquivo_imagem, Cabecalho cabecalho);

void mensagemErroOpcaoInvalida();
void mensagemErroAlocacaoPixel();

#endif