#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <locale.h>

using namespace std;

string ClassificarImc(double imc) {
	if (imc < 16.0) {
		return "Magreza grave";
	}
	else if (imc == 16.0 || imc < 17.0){
		return "Magreza moderada";
	}
	else if (imc == 17.0 || imc < 18.5) {
		return "Magreza leve";
	}
	else if (imc == 18.5 || imc < 25.0) {
		return "IMC normal";
	}
	else if (imc == 25.0 || imc < 30.0) {
		return "Sobrepeso";
	}
	else if (imc == 30.0 || imc < 35.0) {
		return "Obesidade Grau I";
	}
	else if (imc == 35.0 || imc < 40.0) {
		return "Obesidade Grau II";
	}
	else {
		return "Obesidade Grau III";
	}
}

double CalcularImc(double peso, double altura) {
	return peso / (altura * altura);
}

void ProgramaImc(string versao) {
	
	double altura, peso, imc;
	char resp;
	
	system("cls");
	cout << "===========================" << endl;
	cout << "Cálculo do IMC - Versão " << versao << endl;
	cout << "===========================" << endl << endl;
	
	
	cout << "Insira a sua altura em metros: ";
	cin >> altura;
	
	cout << "Insira o seu peso em kg: ";
	cin >> peso;
	
	imc = CalcularImc(peso, altura);
	
	cout << endl << "Seu Índice de Massa Corporal é: " << imc << " kg/m²" << endl;
	cout << "Classificação: " << ClassificarImc(imc) << "." << endl;
	
	cout << "Deseja realizar outro cálculo (s/n)?" << endl;
	cin >> resp;
	
	if(resp == 's') {
		ProgramaImc(versao);
	}
	
	else {
		system("exit");
	}
}


/* Método principal do programa */
int main(int argc, char *argv[]) {
	string versao = "1.0";
	
	/* Locale configurado para Português do Brasil e inserido nas
	 * funções de saída (std::cout) e entrada (std::cin).
	 *
	 * Isto permite o uso de vírgula em números fracionários
	 * ao invés do ponto.
	 */

	setlocale(LC_ALL, "");

	ProgramaImc(versao);

	return 0;
}

