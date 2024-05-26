//============================================================================
// Name        : Trabajo Practico 2 - Enunciado C
// Author      : Alongi, Paez, Rico
//============================================================================

#include <iostream>
#include <vector>
#include "Matriz.h"
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
	return 0;
}


/*vector<vector<float>> v(2, vector<float>(2, 0));

for(int i=0; i<a.filas; i++){
	for(int j=0; j<a.columnas; j++)
		cout<<a.matriz[j][i]<<" ";
	cout<<endl;
}*/
