#include "funcoes_gerais.h"

FILE* pegaImagemPeloNome(char nome_imagem[50]) {

	char nome_imagem_ppm[55] = "";

	char path_imagem[] = "imagens/";
	char extensao_ppm[] = ".ppm";

	// Pega o nome da imagem e adiciona ANTES DO NOME o caminho relativo da imagem
	// e DEPOIS DO NOME a extensão ".ppm"
	printf(">>> Informe o nome da imagem: ");
	scanf("%s", nome_imagem);

	strcat(nome_imagem_ppm, path_imagem);
	strcat(nome_imagem_ppm, nome_imagem);
	strcat(nome_imagem_ppm, extensao_ppm);

	// Faz a leitura da imagem baseada no nome e retorna para quem chamou a função
	return fopen(nome_imagem_ppm, "r+");
}

void pegaOpcaoUsuario(int *opcao) {
	mostraMenu();
	scanf("%d", opcao);
}

void mostraMenu() {
	printf("\n");
	printf("1 - Deixar a imagem cinza\n");
	printf("2 - Binarizacao usando thresholding\n");
	printf("3 - Blurring\n");
	printf("4 - Executa sharpening\n");
	printf("5 - Rotacao da imagem\n");
	printf("6 - Ampliar a imagem\n");
	printf("7 - Reduzir a imagem\n");
	printf("8 - Sair\n");
	printf("\n");
}