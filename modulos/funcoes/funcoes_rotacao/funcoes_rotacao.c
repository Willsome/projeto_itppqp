#include "funcoes_rotacao.h"

void rotacionaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	Cabecalho cabecalho_dimensoes_invertidas = criaCabecalhoComDimensoesInvertidas(cabecalho);

	FILE *arquivo_imagem_rotacionada = criaArquivoImagemRotacionada(nome_imagem);
	
	int rotacao = pegaRotacaoUsuario();

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	int tamanho_largura_nova = tamanho_largura_original;
	int tamanho_altura_nova = 0;

	switch(rotacao) {

		case 90:

			adicionaCabecalhoNovoNaImagem(arquivo_imagem_rotacionada, cabecalho_dimensoes_invertidas);

			for (int i = 0; i < tamanho_largura_original; i++) {
				for (int j = 0; j < tamanho_altura_original; j++) {

					fprintf(arquivo_imagem_rotacionada, "%d\n", imagem.pixels[tamanho_altura_nova][tamanho_largura_nova-1].R);
					fprintf(arquivo_imagem_rotacionada, "%d\n", imagem.pixels[tamanho_altura_nova][tamanho_largura_nova-1].G);
					fprintf(arquivo_imagem_rotacionada, "%d\n", imagem.pixels[tamanho_altura_nova][tamanho_largura_nova-1].B);

					tamanho_altura_nova++;
				}

				tamanho_altura_nova = 0;
				tamanho_largura_nova--;
			}

			mensagemSucessoRotacaoImagem();
			break;

		default:
			mensagemErroOpcaoInvalida();
			break;
	}

	fclose(arquivo_imagem_rotacionada);
}

Cabecalho criaCabecalhoComDimensoesInvertidas(Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	// Inverte as dimensões da imagem no cabeçalho
	char tamanho_largura_string[10];
	char tamanho_altura_string[10];
	itoa(tamanho_altura_original, tamanho_largura_string, 10);
	itoa(tamanho_largura_original, tamanho_altura_string, 10);

	Cabecalho cabecalho_novo;
	strcpy(cabecalho_novo.formato_textual, cabecalho.formato_textual);
	strcpy(cabecalho_novo.tamanho_imagem_largura, tamanho_largura_string);
	strcpy(cabecalho_novo.tamanho_imagem_altura, tamanho_altura_string);
	strcpy(cabecalho_novo.nivel_qualidade_imagem, cabecalho.nivel_qualidade_imagem);

	return cabecalho_novo;
}

FILE* criaArquivoImagemRotacionada(char nome_imagem[50]) {

	// Caminho da imagem + extensão
	char path_imagem[] = "imagens/rotacionada/";
	char extensao_ppm[] = "_rotacionada90.ppm";

	// Variável com o nome da imagem (caminho + nome + extensão)
	char nome_imagem_ppm_rotacionada[70] = "";
	strcat(nome_imagem_ppm_rotacionada, path_imagem);
	strcat(nome_imagem_ppm_rotacionada, nome_imagem);
	strcat(nome_imagem_ppm_rotacionada, extensao_ppm);

	FILE *arquivo_imagem_rotacionada = fopen(nome_imagem_ppm_rotacionada, "w+");
	if (arquivo_imagem_rotacionada == NULL) {
		mensagemErroCriacaoImagemRotacionada();
	}

	return arquivo_imagem_rotacionada;
}

int pegaRotacaoUsuario() {

	imprimeOpcoesRotacao();

	int rotacao;
	scanf("%d", &rotacao);

	return rotacao;
}

void imprimeOpcoesRotacao() {
	printf("|\n");
	printf(">>> Informe o angulo de rotacao (90/180/270): ");
}

void adicionaCabecalhoNovoNaImagem(FILE *arquivo_imagem_rotacionada, Cabecalho cabecalho_dimensoes_invertidas) {

	fprintf(arquivo_imagem_rotacionada, "%s", cabecalho_dimensoes_invertidas.formato_textual);

	char tamanho_imagem[12] = "";
	strcat(tamanho_imagem, cabecalho_dimensoes_invertidas.tamanho_imagem_largura);
	strcat(tamanho_imagem, " ");
	strcat(tamanho_imagem, cabecalho_dimensoes_invertidas.tamanho_imagem_altura);
	strcat(tamanho_imagem, "\n");
	fprintf(arquivo_imagem_rotacionada, "%s", tamanho_imagem);
	
	fprintf(arquivo_imagem_rotacionada, "%s", cabecalho_dimensoes_invertidas.nivel_qualidade_imagem);
}

void mensagemErroCriacaoImagemRotacionada() {
	printf("|\n");
	printf("+--------------------------------------+\n");
	printf("|   Erro ao criar imagem rotacionada   |\n");
	printf("+--------------------------------------+\n");
	exit(1);
}

void mensagemSucessoRotacaoImagem() {
	printf("|\n");
	printf("+--------------------------------------------+\n");
	printf("|   A imagem foi rotacionada com sucesso !   |\n");
	printf("+--------------------------------------------+\n");
}