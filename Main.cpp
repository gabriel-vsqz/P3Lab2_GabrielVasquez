#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int opcion;
bool runtime = true;

int menu() {
	cout << "\n0. Salir del Programa \n1. Algoritmo de Euclides \n2. Ordenamiento de Areglos \n3. Constante de Kaprekar \nIngrese la opción que desea: ";
	cin >> opcion;
	return (opcion);
}

int Euclides(int a, int b) {
	if (a % b == 0) {
		return b;
	} else {
		return Euclides(b, a % b);
	}
}

int* Llenar_Arreglo(int n) {
	int* temporal = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		temporal[i] = 1 + rand() % (90);
	}
	return temporal;
}

void Imprimir_Arreglo(int* arreglo, int n) {
	for (int i = 0; i < n; i++) {
		cout << "[" << arreglo[i] << "]";
	}
}

int* Ordenamiento(int* arreglo, int n) {
	if (n = 0) {
		return arreglo;
	} else {
		for (int i = 0; i < n; i++) {
			
		}
	}
}

bool Verificar_Numero(int num) {
	int a, b, c, d;
	a = num % 10;
	b = (num%100)/10;
	c = ((num%1000)/100);
	d = ((num%10000)/1000);
	
	if ( (a!=b) and (b!=c) and (c!=d) and (a!=d) and (a!=c) and (b!=d) ) {
		return true;
	} else {
		return false;
	}
}

int main() {
	while(runtime) {
		opcion = menu();
		switch (opcion) {
			case 0:{
				runtime = false;
			       }break;
			case 1:{
				int a, b, mcd;
				cout << "\nEjercicio 1\nIngrese número a: ";
				cin >> a;
				cout << "Ingrese número b: ";
				cin >> b;
				mcd = Euclides(a,b);
				cout << "mcd("<< a << "," << b << ") = " << mcd << endl;
			       }break;
			case 2:{
				int n;
				cout << "\nEjercicio 2\n¿De qué tamaño desea el arreglo? ";
				cin >> n;
				int* arreglo = new int[n];
				arreglo = Llenar_Arreglo(n);
				cout << "Arreglo Generado:\n";
				Imprimir_Arreglo(arreglo, n);
				cout << "\nOrdenamiento:\n";
				//Ordenamiento(arreglo, n);
			       }break;
			case 3:{
				int numero;
				bool validacion = false;
				cout << "\nEjercicio 3\n";
				while (validacion == false) {
					cout << "Ingrese un número de 4 digitos: ";
					cin >> numero;
					validacion = Verificar_Numero(numero);
					if (!validacion)
						cout << "Los 4 digitos deben ser distintos" << endl;
				}
				//Kaprekar();
			       }break;
			default:
				cout << "Ha ingresado una opción que no está en el menú" << endl;
		}
	}
	cout << "Ha salido del programa\n\n";
}
