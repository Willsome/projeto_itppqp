#include "funcoes_gerais.h"

FILE* pegaImagemPeloNome(char nome_imagem[50]) {

	// Pega o nome da imagem e adiciona ANTES DO NOME o caminho relativo da imagem
	// e DEPOIS DO NOME a extensão ".ppm"
	printf(">>> Informe o nome da imagem: ");
	scanf("%s", nome_imagem);

	// Caminho da imagem + extensão
	char path_imagem[] = "imagens/";
	char extensao_ppm[] = ".ppm";

	// Variável com o nome da imagem (caminho + nome + extensão)
	char nome_imagem_ppm[55] = "";
	strcat(nome_imagem_ppm, path_imagem);
	strcat(nome_imagem_ppm, nome_imagem);
	strcat(nome_imagem_ppm, extensao_ppm);

	return fopen(nome_imagem_ppm, "r+");
}

int pegaOpcaoUsuario() {
	mostraMenu();

	int opcao;
	scanf("%d", &opcao);

	return opcao;
}

void mostraMenu() {
	printf("\n");
	printf("1 - Deixar a imagem cinza\n");
	printf("2 - Rotacao da imagem\n");
	printf("3 - Binarizacao usando thresholding\n");
	printf("3 - Blurring\n");
	printf("4 - Executa sharpening\n");
	printf("6 - Ampliar a imagem\n");
	printf("7 - Reduzir a imagem\n");
	printf("8 - Sair\n");
	printf("\n");
}

void preencheStructsCabecalhoImagem(FILE *arquivo_imagem, Cabecalho *cabecalho, Imagem *imagem) {

	// Linha atual da leitura da imagem PPM
	long linha_atual = 0;

	// Dados da linha atual
	char dados[20];

	// Cria struct Pixel que recebera cada tripla de valores RGB e coloca na posição atual
	// do vetor de pixeis que não está preenchido na struct criada anteriormente "imagem"
	Pixel pixel;
	int cor_linha_atual = RED;

	// Variável usada para saber a partir de qual posição existem pixeis não preenchidos
	PosicaoAtualPixel posicao_atual_pixel;
	posicao_atual_pixel.x = 0;
	posicao_atual_pixel.y = 0;

	long cont = 0;

	while(fgets(dados, sizeof(dados), arquivo_imagem) != NULL) {

		linha_atual++; // Começa com 1 depois do "++", ou seja LINHA 1 do arquivo

		if(linha_atual < LINHA_QUE_COMECAM_OS_PIXEIS) {
			preencheCabecalho(linha_atual, dados, cabecalho, imagem);
		} else {
			preencheImagemComRGB(dados, cabecalho, imagem, &posicao_atual_pixel, &pixel, &cor_linha_atual, &cont);
		}
	}

	// Fecha o(a) arquivo/imagem PPM
	fclose(arquivo_imagem);
}

void preencheCabecalho(long linha_atual, char dados[20], Cabecalho *cabecalho, Imagem *imagem) {

	char tamanho_imagem[30];
	char *tamanho_imagem_dados;
	
	// Variável que vai identificar a passagem na hora de dividir o tamanho da imagem em LARGURA(passagem 1) e ALTURA(passagem 2)
	int passadas = 1;

	if (linha_atual == 1) { // Linha 1 do arquivo corresponde ao FORMATO TEXTUAL da imagem
		strcpy(cabecalho->formato_textual, dados);

	} else if(linha_atual == 2) { // Linha 2 do arquivo corresponde ao TAMANHO da imagem

		strcpy(tamanho_imagem, dados);

		// Função strtok() divida a string do tamanho pelo espaço "1280 720"
		tamanho_imagem_dados = strtok(tamanho_imagem, " ");
		while (tamanho_imagem_dados != NULL) {

			if (passadas == 1) { // Pega a LARGURA
				strcpy(cabecalho->tamanho_imagem_largura, tamanho_imagem_dados);
				passadas++;

			} else if (passadas == 2) { // Pega a ALTURA
				strcpy(cabecalho->tamanho_imagem_altura, tamanho_imagem_dados);
			}

			// Atribui à variável o próximo valor depois de encontrar o espaço
			tamanho_imagem_dados = strtok(NULL, " ");
		}

		alocaPixelsDaImagem(imagem, cabecalho);


	} else if(linha_atual == 3) { // Linha 3 do arquivo corresponde ao NÍVEL DE QUALIDADE da imagem
		strcpy(cabecalho->nivel_qualidade_imagem, dados);
	}
}

void alocaPixelsDaImagem(Imagem *imagem, Cabecalho *cabecalho) {

	// Obs.: A função "atoi()" recebe uma 'string' e converte para 'int'
	int largura_imagem = atoi(cabecalho->tamanho_imagem_largura);
	int altura_imagem = atoi(cabecalho->tamanho_imagem_altura);

	imagem->pixels = (Pixel**) malloc(altura_imagem * sizeof(Pixel*));
	if (imagem->pixels == NULL) {
		mensagemErroAlocacaoPixel();
	}

	for (int i = 0; i < altura_imagem; i++) {
		imagem->pixels[i] = (Pixel*) malloc(largura_imagem * sizeof(Pixel));
		if (imagem->pixels == NULL) {
			mensagemErroAlocacaoPixel();
		}
	}
}

void preencheImagemComRGB(char dados[20], Cabecalho *cabecalho, Imagem *imagem,
	PosicaoAtualPixel *posicao_atual_pixel, Pixel *pixel, int *cor_linha_atual, long *cont) {

	(*cont)++;

	int largura_imagem = atoi(cabecalho->tamanho_imagem_largura);
	int altura_imagem = atoi(cabecalho->tamanho_imagem_altura);

	switch(*cor_linha_atual) {

		case RED:
			pixel->R = atoi(dados);
			(*cor_linha_atual)++;
			break;

		case GREEN:
			pixel->G = atoi(dados);
			(*cor_linha_atual)++;
			break;

		case BLUE:
			pixel->B = atoi(dados);
			
			// Reseta a cor da linha atual para RED
			*cor_linha_atual = RED;

			// Depois de preenchido o struct Pixel, copia ele para a posição atual da
			// matriz de pixels da struct Imagem
			imagem->pixels[posicao_atual_pixel->x][posicao_atual_pixel->y] = *pixel;

			// Incrementa a posição atual do pixel vazio na struct Imagem
			if(posicao_atual_pixel->y < (largura_imagem-1)) {
				posicao_atual_pixel->y += 1;
			} else {
				posicao_atual_pixel->x += 1;
				posicao_atual_pixel->y = 0;
			}

			break;
	}
}

void adicionaCabecalhoNaImagem(FILE *arquivo_imagem, Cabecalho cabecalho) {
	
	fprintf(arquivo_imagem, "%s", cabecalho.formato_textual);

	char tamanho_imagem[12] = "";
	strcat(tamanho_imagem, cabecalho.tamanho_imagem_largura);
	strcat(tamanho_imagem, " ");
	strcat(tamanho_imagem, cabecalho.tamanho_imagem_altura);
	fprintf(arquivo_imagem, "%s", tamanho_imagem);
	
	fprintf(arquivo_imagem, "%s", cabecalho.nivel_qualidade_imagem);
}

void mensagemErroAlocacaoPixel() {
	printf("|\n");
	printf("+-----------------------------------------+\n");
	printf("|   Ocorreu um erro ao alocar os pixels   |\n");
	printf("+-----------------------------------------+\n");
	exit(1);
}

void mensagemErroOpcaoInvalida() {
	printf("|\n");
	printf("+----------------------+\n");
	printf("|   Opcao invalida !   |\n");
	printf("+----------------------+\n");
}