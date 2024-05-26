//============================================================================
// Name        : TP2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Matriz.h"
using namespace std;

int main() {
	Matriz a;
	a = Matriz();

	vector<vector<float>> v(2, vector<float>(2, 0));

	for(int i=0; i<a.filas; i++){
		for(int j=0; j<a.columnas; j++)
			cout<<a.matriz[i][j]<<" ";
		cout<<endl;
	}
	//cout << b << endl;
	return 0;
}
