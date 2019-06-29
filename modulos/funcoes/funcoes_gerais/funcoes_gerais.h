#ifndef _FUN_GERAIS_H_
#define _FUN_GERAIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/typedefs.h"
#include "../funcoes_grayscale/funcoes_grayscale.h"
#include "../funcoes_ampliacao/funcoes_ampliacao.h"
#include "../funcoes_reducao/funcoes_reducao.h"
#include "../funcoes_blurring/funcoes_blurring.h"
#include "../funcoes_sharpening/funcoes_sharpening.h"
#include "../funcoes_inversao/funcoes_inversao.h"
#include "../funcoes_inversao_cor/funcoes_inversao_cor.h"
#include "../funcoes_destaca_bw/funcoes_destaca_bw.h"

FILE* pegaImagemPeloNome();

void mostraMenu(int opcoes_do_menu);
int pegaOpcaoUsuario();

void preencheStructsCabecalhoImagem(FILE *arquivo_imagem, Cabecalho *cabecalho, Imagem *imagem);
void preencheCabecalho(long linha_atual, char dados[20], Cabecalho *cabecalho, Imagem *imagem);

void alocaPixelsDaImagem(Imagem *imagem, Cabecalho *cabecalho);
void copiaImagemRGB(Imagem *imagem_tmp, Imagem imagem, Cabecalho cabecalho);
void preencheImagemComRGB(char dados[20], Cabecalho *cabecalho, Imagem *imagem, PosicaoAtualPixel *posicao_atual_pixel, Pixel *pixel, int *cor_linha_atual, long *cont);

FILE* criaArquivoImagem(char nome_imagem[50], char pasta_imagem[50], char sufixo_imagem[50]);

void adicionaCabecalhoNaImagem(FILE *arquivo_imagem, Cabecalho cabecalho);
void adicionaCabecalhoNovoNaImagem(FILE *arquivo_imagem, Cabecalho cabecalho);

void mensagemErroOpcaoInvalida();
void mensagemErroAlocacaoPixel();

#endif