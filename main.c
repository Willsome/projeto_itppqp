#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int opcao = 0;

	char nome_imagem[50];
	FILE *ArquivoImagem;


	printf(">>> Informe o nome da imagem: ");
	scanf("%s", nome_imagem);

	strcat(nome_imagem, ".ppm");

	ArquivoImagem = fopen(nome_imagem, "r+");

	if (ArquivoImagem == NULL){
		printf("Imagem nao carregada");	
		return 1;
	} else {
		do {

		printf("1 - para binarização usando thresholding\n");
		printf("2 - executa blurring\n");
		printf("3 - executa sharpening\n");
		printf("4 - rotação da imagem\n");
		printf("5 - ampliar a imagem\n");
		printf("6 - reduzir a imagem\n");
		printf("7 - sair\n");
		scanf("%d", &opcao);

	} while(opcao != 7);
	}	

	return 0;
}
