#include "funcoes_rotacao.h"

void rotacionaImagem(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {
	
	int rotacao = pegaRotacaoUsuario();

	switch(rotacao) {

		case 90:
			rotaciona90(nome_imagem, imagem, cabecalho);
			break;

		case 180:
			rotaciona180(nome_imagem, imagem, cabecalho);
			break;

		case 270:
			rotaciona270(nome_imagem, imagem, cabecalho);
			break;

		default:
			mensagemErroOpcaoInvalida();
			break;
	}
}

void rotaciona90(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	int tamanho_largura_nova = tamanho_largura_original-1;
	int tamanho_altura_nova = 0;

	FILE *arquivo_imagem_rotacionada = criaArquivoImagemRotacionada(nome_imagem, "90");

	Cabecalho cabecalho_dimensoes_invertidas = criaCabecalhoComDimensoesInvertidas(cabecalho);
	adicionaCabecalhoNovoNaImagem(arquivo_imagem_rotacionada, cabecalho_dimensoes_invertidas);

	for (int i = 0; i < tamanho_largura_original; i++) {
		for (int j = 0; j < tamanho_altura_original; j++) {
			gravaRGB(arquivo_imagem_rotacionada, imagem, tamanho_altura_nova, tamanho_largura_nova);
			tamanho_altura_nova++;
		}

		tamanho_altura_nova = 0;
		tamanho_largura_nova--;
	}

	fclose(arquivo_imagem_rotacionada);
	mensagemSucessoRotacaoImagem();
}

void rotaciona180(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	int tamanho_largura_nova = tamanho_largura_original-1;
	int tamanho_altura_nova = tamanho_altura_original-1;

	FILE *arquivo_imagem_rotacionada = criaArquivoImagemRotacionada(nome_imagem, "180");

	adicionaCabecalhoNaImagem(arquivo_imagem_rotacionada, cabecalho);

	for (int i = 0; i < tamanho_altura_original; i++) {
		for (int j = 0; j < tamanho_largura_original; j++) {
			gravaRGB(arquivo_imagem_rotacionada, imagem, tamanho_altura_nova, tamanho_largura_nova);
			tamanho_largura_nova--;
		}

		tamanho_largura_nova = tamanho_largura_original-1;
		tamanho_altura_nova--;
	}

	fclose(arquivo_imagem_rotacionada);
	mensagemSucessoRotacaoImagem();
}

void rotaciona270(char nome_imagem[50], Imagem imagem, Cabecalho cabecalho) {

	int tamanho_largura_original = atoi(cabecalho.tamanho_imagem_largura);
	int tamanho_altura_original = atoi(cabecalho.tamanho_imagem_altura);

	int tamanho_largura_nova = 0;
	int tamanho_altura_nova = tamanho_altura_original-1;

	FILE *arquivo_imagem_rotacionada = criaArquivoImagemRotacionada(nome_imagem, "270");

	Cabecalho cabecalho_dimensoes_invertidas = criaCabecalhoComDimensoesInvertidas(cabecalho);
	adicionaCabecalhoNovoNaImagem(arquivo_imagem_rotacionada, cabecalho_dimensoes_invertidas);

	for (int i = 0; i < tamanho_largura_original; i++) {
		for (int j = 0; j < tamanho_altura_original; j++) {
			gravaRGB(arquivo_imagem_rotacionada, imagem, tamanho_altura_nova, tamanho_largura_nova);
			tamanho_altura_nova--;
		}

		tamanho_altura_nova = tamanho_altura_original-1;
		tamanho_largura_nova++;
	}

	fclose(arquivo_imagem_rotacionada);
	mensagemSucessoRotacaoImagem();
}

void gravaRGB(FILE *arquivo_imagem_rotacionada, Imagem imagem, int tamanho_altura_nova, int tamanho_largura_nova) {
	fprintf(arquivo_imagem_rotacionada, "%d\n", imagem.pixels[tamanho_altura_nova][tamanho_largura_nova].R);
	fprintf(arquivo_imagem_rotacionada, "%d\n", imagem.pixels[tamanho_altura_nova][tamanho_largura_nova].G);
	fprintf(arquivo_imagem_rotacionada, "%d\n", imagem.pixels[tamanho_altura_nova][tamanho_largura_nova].B);
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

FILE* criaArquivoImagemRotacionada(char nome_imagem[50], char rotacao[5]) {

	// Caminho da imagem + extensão
	char path_imagem[] = "imagens/rotacionada/";
	char sufixo_imagem[20] = "_rotacionada";
	strcat(sufixo_imagem, rotacao);
	char extensao_ppm[] = ".ppm";

	// Variável com o nome da imagem (caminho + nome + extensão)
	char nome_imagem_ppm_rotacionada[70] = "";
	strcat(nome_imagem_ppm_rotacionada, path_imagem);
	strcat(nome_imagem_ppm_rotacionada, nome_imagem);
	strcat(nome_imagem_ppm_rotacionada, sufixo_imagem);
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