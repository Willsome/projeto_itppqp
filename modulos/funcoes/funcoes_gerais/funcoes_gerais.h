#ifndef _FUN_GERAIS_H_
#define _FUN_GERAIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../structs/typedefs.h"

FILE* pegaImagemPeloNome();
void mostraMenu();
int pegaOpcaoUsuario();
void preencheStructsCabecalhoImagem(FILE *arquivo_imagem, Cabecalho *cabecalho, Imagem *imagem);
void preencheCabecalho(long linha_atual, char dados[20], Cabecalho *cabecalho, Imagem *imagem);
void alocaPixelsDaImagem(Imagem *imagem, Cabecalho *cabecalho);
void preencheImagemComRGB(char dados[20], Cabecalho *cabecalho, Imagem *imagem, PosicaoAtualPixel *posicao_atual_pixel, Pixel *pixel, int *cor_linha_atual, long *cont);
void adicionaCabecalhoNaImagem(FILE *arquivo_imagem, Cabecalho cabecalho);
void mensagemErroAlocacaoPixel();
void mensagemErroOpcaoInvalida();

#endif