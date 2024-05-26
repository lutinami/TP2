//============================================================================
// Name        : Trabajo Practico 2 - Enunciado C
// Author      : Alongi, Paez, Rico
//============================================================================

#include <iostream>
#include <vector>
#include "Matriz.h"
using namespace std;

int main() {
	Matriz a, b, c, d;
	a = Matriz();
	b = Matriz(4, 5);
	c = Matriz(b);
	d = b + c;

	cout << "esta es mi matriz:\n" << d << "wowee zowee !!\n";
	return 0;
}


/*vector<vector<float>> v(2, vector<float>(2, 0));

for(int i=0; i<a.filas; i++){
	for(int j=0; j<a.columnas; j++)
		cout<<a.matriz[j][i]<<" ";
	cout<<endl;
}*/
