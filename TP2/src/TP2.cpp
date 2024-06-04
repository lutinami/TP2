//============================================================================
// Name        : Trabajo Practico 2 - Enunciado C
// Author      : Alongi, Paez, Rico
//============================================================================

#include <iostream>
#include <vector>
#include "Matriz.h"
#include "MatrizCuadrada.h"
#include "MatrizIdentidad.h"
using namespace std;

int main() {
	Matriz a, b, c, d, e, f, g;
	a = Matriz();
	b = Matriz(4, 5);
	c = Matriz(b);
	d = b + c;

	e = Matriz(5, 4);
	e = e + e;
	f = d*e;

	cout << "esta es mi matriz:\n" << b << "wowee zowee !!\n";
	b = !(b);
	cout << "La di vuelta ://\n" << b << endl;
	cout << "producto escalar?? en esta economia ?? \n" << b.ProductoPorEscalar(6) << "si!!"<< endl;
	cout << "el tamaño de la matriz b es " << b.numel() << "?? no lo voy a chequear (no se contar)"<< endl;
	cout << "mira, por alguna razon sume todos los elementos y me dio " << b.cumsum() << "\ndato: la funcion se llama cum sum" << endl;
	cout << "maximo de b es " << b.max() << " y el minimo " << b.min() << "?????? son lo mismo !?!?!?!?" << endl;

	b.setColumnaValor(2, 7);
	cout << "nueva columna de b: \n" << b << endl;
	b.setFilaValor(2, 7);
	cout << "nueva fila de b: \n" << b << endl;
	b.setCoordenada(1, 1, 7);
	cout << "nueva coord de b: \n" << b << endl;
	b.setRango(1, 2, 1, 3, 5);
	cout << "nuevo rango de b: \n" << b << endl;

	Matriz x;
	x = Matriz({{3, 4, 5}, {6, 1, 1}, {3, 3, 1}, {2, 1, 1}});
	cout << "matriz definida 1 por 1, de " << x.getFilas() << " filas y "
			<< x.getColumnas() << " columnas: \n" << x << endl;

	MatrizCuadrada testing = MatrizCuadrada(5, 2);
	testing = MatrizCuadrada({{2,2,1}, {8,1,9}, {7,2,9}});
	//testing = MatrizCuadrada({{2, 1}, {4, 4}});
	//Matriz Cuadrada testing2 = MatrizCuadrada({{1,2,3},{0,2,1},{0,0,5}});
	//MatrizCuadrada test3 = testing.adjunta();
	MatrizCuadrada inversa_t = ~testing;
	cout << "la inversa de la matriz: \n"<< testing
			<< "es: \n" << inversa_t << endl;
	MatrizCuadrada division_t = testing/testing;
	cout << "division de matrices: \n" << division_t << endl;
	MatrizIdentidad test2 = MatrizIdentidad(testing);
	cout << "\n\n" << test2 << endl;
	MatrizCuadrada adas = testing*inversa_t;
	cout << "\n\n" << adas << endl;
	cout << "\n" << adas.determinante() << endl;
	MatrizCuadrada xx2 = adas.cortaFilaColumna(1, 1);
	cout << "\n" << xx2 << endl;
	cout << "\n" << xx2.determinante() << endl;
	xx2 = testing.adjunta();
	cout << "\n" << xx2 << endl;
	MatrizCuadrada wowe = MatrizCuadrada({{2,-1,0}, {-1,2,-1}, {0,-1,2}});
	cout << "\n" << wowe << endl;
	MatrizCuadrada wowe_inv = ~wowe;
	cout << "\n" << wowe_inv << endl;
	MatrizCuadrada identidad = wowe*(~wowe);
	cout << "\n" << identidad << endl;
	return 0;
}
