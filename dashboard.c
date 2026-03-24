#include <stdio.h>
#include "dashboard.h"
#include "calculos.h"

void DashBoard(char sexo, char nome, int idade, float massa, float altura){

	float imc = IMC(massa, altura);
	float gordura = PercentG(idade, imc, sexo);
	float PesoIM = PesoIdeal(altura, sexo);
	float PesoIF = PesoIdeal(altura, sexo);
	float MassaG = MassaGorda(massa, gordura);
	float MassaM = MassaMagra(massa, MassaG);
	
	if(sexo == 'M' || sexo == 'm'){
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
	}


}
