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

		do {
			// Pega a opção do usuário passando o endereço
			// da variável que vai ser armazenada a opção
			// + Nome da variável: opcao
			pegaOpcaoUsuario(&opcao);

			long cont = 0;
			char dados[1000];

			char formato_textual[30];
			char tamanho_imagem[30];
			char nivel_qualidade_imagem[5];

			switch(opcao) {
				case 1:
					
					while(fgets(dados, sizeof(dados), arquivo_imagem) != NULL) {
						//printf("=== %s\n", dados);
						cont++;

						if(cont == 1) {
							strcpy(formato_textual, dados);
						} else if(cont == 2) {
							strcpy(tamanho_imagem, dados);
						} else if(cont == 3) {
							strcpy(nivel_qualidade_imagem, dados);
							break;
						}
					}

					printf("Formato textual: %s\n", formato_textual);
					printf("Tamanho da imagem: %s\n", tamanho_imagem);
					printf("Nivel de qualidade da imagem: %s\n", nivel_qualidade_imagem);

					fclose(arquivo_imagem);
					break;

				default:
					break;
			}

		} while(opcao != SAIR);
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
