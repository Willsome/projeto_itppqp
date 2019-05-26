#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIR 8

void mostraMenu();
void pegaOpcaoUsuario(int *opcao);

typedef struct {
	int R;
	int G;
	int B;
} Pixel;

typedef struct {
	Pixel *pixeis;
} Imagem;

int main() {

	char nome_imagem[50];
	FILE *arquivo_imagem;
	int opcao = 0;

	// Pega o nome da imagem é adiciona a extensão ".ppm"
	printf(">>> Informe o nome da imagem: ");
	scanf("%s", nome_imagem);
	strcat(nome_imagem, ".ppm");

	// Faz a leitura da imagem baseada no nome
	arquivo_imagem = fopen(nome_imagem, "r+");
	if (arquivo_imagem == NULL){
		printf("A imagem informada não existe.\n");
		return 1;

	} else {

		long linha_atual = 0;
		char dados[20];

		char formato_textual[30];
		char tamanho_imagem[30];
		char nivel_qualidade_imagem[5];

		Imagem imagem;
		imagem.pixeis = (Pixel*) malloc(1000000 * sizeof(Pixel));
		memset(imagem.pixeis, 0, 10 * sizeof(Pixel));
		long pixel_posicao_atual = 0;
		
		Pixel pixel;
		int cor_linha_atual = 1;

		int grayscale_media;

		FILE *arquivo_imagem_grayscale = fopen("aig.ppm", "w+");

		do {
			// Pega a opção do usuário passando o endereço
			// da variável que vai ser armazenada a opção
			// + Nome da variável: opcao
			pegaOpcaoUsuario(&opcao);

			switch(opcao) {
				case 1:
					
					while(fgets(dados, sizeof(dados), arquivo_imagem) != NULL) {
						//printf("=== %s\n", dados);
						linha_atual++;

						if(linha_atual == 1) {
							strcpy(formato_textual, dados);
							fprintf(arquivo_imagem_grayscale, "%s", dados);
						} else if(linha_atual == 2) {
							strcpy(tamanho_imagem, dados);
							fprintf(arquivo_imagem_grayscale, "%s", dados);
						} else if(linha_atual == 3) {
							strcpy(nivel_qualidade_imagem, dados);
							fprintf(arquivo_imagem_grayscale, "%s", dados);
						} else {

							switch(cor_linha_atual) {
								case 1:
									pixel.R = atoi(dados);
									cor_linha_atual++;
									break;
								case 2:
									pixel.G = atoi(dados);
									cor_linha_atual++;
									break;
								case 3:
									pixel.B = atoi(dados);
									cor_linha_atual = 1;
									// printf("%d\n", pixel_posicao_atual);
									imagem.pixeis[pixel_posicao_atual] = pixel;
									pixel_posicao_atual++;
									break;
							}
						}
					}

					break;

				default:
					printf("%d\n", pixel_posicao_atual);
					for (int i = 0; i < pixel_posicao_atual; ++i) {
						printf("==[%d] RGB(%d, %d, %d)\n",
							i,
							imagem.pixeis[i].R,
							imagem.pixeis[i].G,
							imagem.pixeis[i].B
						);

						grayscale_media = (imagem.pixeis[i].R + imagem.pixeis[i].G + imagem.pixeis[i].B) / 3;
						imagem.pixeis[i].R =grayscale_media;
						imagem.pixeis[i].G = grayscale_media;
						imagem.pixeis[i].B= grayscale_media;

						printf("==[%d] RGB(%d, %d, %d)\n",
							i,
							imagem.pixeis[i].R,
							imagem.pixeis[i].G,
							imagem.pixeis[i].B
						);

						fprintf(arquivo_imagem_grayscale, "%d\n", imagem.pixeis[i].R);
						fprintf(arquivo_imagem_grayscale, "%d\n", imagem.pixeis[i].G);
						fprintf(arquivo_imagem_grayscale, "%d\n", imagem.pixeis[i].B);
					}

					fclose(arquivo_imagem_grayscale);
					break;
			}

		} while(opcao != SAIR);

		free(imagem.pixeis);
	}

	return 0;
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