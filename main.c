#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIR 7

void mostraMenu();
void pegaOpcaoUsuario(int *opcao);

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

		} while(opcao != SAIR);
	}

	return 0;
}

void pegaOpcaoUsuario(int *opcao) {
	mostraMenu();
	scanf("%d", opcao);
}

void mostraMenu() {
	printf("1 - Binarização usando thresholding\n");
	printf("2 - Blurring\n");
	printf("3 - Executa sharpening\n");
	printf("4 - Rotação da imagem\n");
	printf("5 - Ampliar a imagem\n");
	printf("6 - Reduzir a imagem\n");
	printf("7 - Sair\n");
}
