#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int opcion, a, b, c, d, resultado;
bool runtime = true;

int menu() {
	cout << "\n0. Salir del Programa \n1. Algoritmo de Euclides \n2. Ordenamiento de Areglos \n3. Constante de Kaprekar \nIngrese la opción que desea: ";
	cin >> opcion;
	return (opcion);
}

int Euclides(int x, int y) {
	if (x % y == 0) {
		return y;
	} else {
		return Euclides(y, x % y);
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
	int posicion, menor = 200;
	for (int i = 0; i < n; i++) {
		for(int j = posicion; j < n; j++) {
			if (arreglo[j] < menor) {
				menor = arreglo[j];
				posicion = j;
			}
		}
	}
}

void sacar_numeros(int num) {
	a = num % 10;
        b = (num%100)/10;
        c = ((num%1000)/100);
        d = ((num%10000)/1000);
}

bool Verificar_Numero(int num) {
	sacar_numeros(num);
	if ( (a!=b) and (b!=c) and (c!=d) and (a!=d) and (a!=c) and (b!=d) ) {
		return true;
	} else {
		return false;
	}
}

void Imprimir_Serie(int* arreglo, int n) {
	for (int i = 0; i < n; i++) {
                cout << arreglo[i];
        }
}

void Kaprekar(int numero) {
	int auxiliar1, auxiliar2, n1, n2;
	int serie1[] = {d,c,b,a};
	int serie2[] = {d,c,b,a};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (serie1[j] > serie1[j+1]){
				auxiliar1 = serie1[j];
				serie1[j] = serie1[j+1];
				serie1[j+1] = auxiliar1;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                        if (serie2[j] < serie2[j+1]){
                                auxiliar2 = serie2[j];
                                serie2[j] = serie2[j+1];
                                serie2[j+1] = auxiliar2;
                        }
                }
        }
	Imprimir_Serie(serie2,4);
	cout << " - ";
	Imprimir_Serie(serie1,4);
	cout << " = ";
	
	n1 = (serie1[0]*1000) + (serie1[1]*100) + (serie1[2]*10) + (serie1[3]*1);
	n2 = (serie2[0]*1000) + (serie2[1]*100) + (serie2[2]*10) + (serie2[3]*1);

	resultado = n2-n1;
	cout << resultado << endl;

	if(resultado != 6174) {
		sacar_numeros(resultado);
		Kaprekar(resultado);
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
				int x, y, mcd;
				cout << "\nEjercicio 1\nIngrese número a: ";
				cin >> x;
				cout << "Ingrese número b: ";
				cin >> y;
				mcd = Euclides(x,y);
				cout << "mcd("<< x << "," << y << ") = " << mcd << endl;
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
				Ordenamiento(arreglo, n);
			       }break;
			case 3:{
				int numero, resultado;
				bool validacion = false;
				cout << "\nEjercicio 3\n";
				while (validacion == false || numero == 6174 || numero < 999 || numero > 9999) {
					cout << "Ingrese un número de 4 digitos: ";
					cin >> numero;
					validacion = Verificar_Numero(numero);
					if (!validacion) {
						cout << "Los 4 digitos deben ser distintos" << endl;
					} else if (numero == 6174) {
						cout << "No puede ingresar el número 6174" << endl;
					} else if (numero < 999 ||  numero > 9999) {
						cout << "Solo puede ingresar números de 4 dígitos" << endl;
					}
				}
				Kaprekar(numero);
			       }break;
			default:
				cout << "Ha ingresado una opción que no está en el menú" << endl;
		}
	}
	cout << "Ha salido del programa\n\n";
}
