#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculos.h"
#include "database.h"

int main(){
	setlocale(LC_ALL, "portuguese_Brazil");

	criar_banco();
	
	
	
	
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

	
	float imc = IMC(massa, altura);
	float gordura = PercentG(idade, imc, sexo);
	float PesoIM = PesoIdeal(altura, sexo);
	float PesoIF = PesoIdeal(altura, sexo);
	float MassaG = MassaGorda(massa, gordura);
	float MassaM = MassaMagra(massa, MassaG);
	
	if(sexo == 'M' || sexo == 'm' ){
		system("cls");
		printf("----------------------------------------------------------------------------\n");
		printf("Olá %s, você tem %d anos com %.2f KG e %.2f M\n", nome, idade, massa, altura);
		printf("----------------------------------------------------------------------------\n");
		printf("Peso Ideal: %.2f\n", PesoIM);
		printf("----------------------------------------------------------------------------\n");
		printf("IMC: %.1f\n", imc);
		printf("----------------------------------------------------------------------------\n");
		printf("Massa Gorda: %.2f KG\n", MassaG);
		printf("Massa Magra: %.2f KG\n", MassaM);
		printf("----------------------------------------------------------------------------\n");
		printf("Percentual de Gordura: %.2f %%\n", gordura);
		if (gordura > 6 && gordura < 14){
			printf("Você é atleta\n");
		}else if (gordura > 14 && gordura < 18){
			printf("Você está fitness\n");
		}else if (gordura > 18 && gordura<= 24){
			printf("Você está saudável\n");
		}else if (gordura > 25){
			printf("Você está acima do ideal\n");
		}
		printf("----------------------------------------------------------------------------\n");
	}else{
		system("cls");
		printf("----------------------------------\n");
		printf("Feminino\n");
		printf("IMC: %.2f\n", imc);
		printf("Peso Ideal: %.2f\n", PesoIF);
		printf("Percentual de Gordura: %.2f %%\n", gordura);
		if (gordura > 16 && gordura <= 23){
			printf("Você está fitness\n");
		}else if (gordura > 24 && gordura <= 30){
			printf("Você está Normal\n");
		}else if (gordura > 31){
			printf("Acima do ideal\n");
		}
		printf("----------------------------------\n");
	}
	system("pause");
	
	return 0;
}
