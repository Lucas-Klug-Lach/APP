#include <stdio.h>
#include "calculos.h"

//Variáveis
#define Ano_Atual 2026

//IMC

float IMC(float peso, float altura){

return peso/(altura*altura);
}

//Percentual de gordura

float PercentG(int idade, float imc, char sexo){
	float PercentGor;
	if(sexo == 'M'){
		PercentGor = (1.20 * imc) + (0.23 * idade) - (10.8 * 1) - 5.4;
	}else{
		PercentGor = (1.20 * imc) + (0.23 * idade) - 16.2;
	}
	return PercentGor;	
}

//Peso Ideal

float PesoIdeal(float altura, char sexo){
	float pesoideal;
	if (sexo == 'M' || sexo == 'm'){
	pesoideal = (altura * 100 - 100) * 0.90;
	}else{
		pesoideal = (altura * 100 - 100) * 0.85;
	}
	return pesoideal;
}

float MassaGorda(float peso, float per){
	float Massagorda = peso * (per / 100.0);
	return Massagorda;
}

float MassaMagra (float peso, float MassaG){
	float MassaM = peso - MassaG;
	return MassaM;
}



