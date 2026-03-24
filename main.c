#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculos.h"

int main(){
	setlocale(LC_ALL, "portuguese_Brazil");


	
	
	
	
	char sexo;
	char nome[100];
	int idade;
	float massa;
	float altura;
	
	printf("Qual seu nome? ");
	scanf("%s", &nome);
	
	printf("Olá %s qual o seu sexo?(M/F)? ", nome);
	scanf(" %c", &sexo);
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	
	printf("Você poderia me falar sua massa: ");
	scanf("%f", &massa);

	printf("Você poderia me falar sua altura: ");
	scanf("%f",	&altura);
	
	while ((c = getchar()) != '\n' && c != EOF);
	printf("Qual a sua idade: ");
	scanf("%d", &idade);

	
	DashBoard(sexo, nome, idade, massa, altura);
	
	system("pause");
	
	return 0;
}
