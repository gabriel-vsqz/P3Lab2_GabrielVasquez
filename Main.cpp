#include <iostream>

using namespace std;

int opcion;
bool runtime = true;

int menu() {
	cout << "\n0. Salir del Programa \nEjercicio 1. Algoritmo de Euclides \nEjercicio 2. Ordenamiento de Areglos \nEjercicio 3. Constante de Kaprekar \n Ingrese la opción que desea: ";
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

int main() {
	while(runtime) {
		opcion = menu();
		switch (opcion) {
			case 0:
				runtime = false;
				break;
			case 1:
				int a, b, mcd;
				cout << "\nEjercicio 1\nIngrese número a: ";
				cin >> a;
				cout << "Ingrese número b: ";
				cin >> b;
				mcd = Euclides(a,b);
				cout << "mcd("<< a << "," << b << ") = " << mcd << endl;
				break;
			case 2:
				//Ordenamiento();
				break;
			case 3:
				//Kaprekar();
				break;
			default:
				cout << "Ha ingresado una opción que no está en el menú" << endl;
		}
	}
	cout << "Ha salido del programa" << endl;
}
