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
	Matriz test = Matriz(3, 4);
	MatrizCuadrada test2 = MatrizCuadrada(4);
	cout << "\n" << test << endl;
	cout << "\n" << test2 << endl;
	return 0;
}
