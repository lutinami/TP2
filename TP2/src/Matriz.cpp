/*
 * Matriz.cpp
 *
 *  Created on: May 25, 2024
 *      Author: lu
 */

#include "Matriz.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

Matriz::Matriz() {
	filas = 4;
	columnas = 4;
	vector<double> v(filas, 0);
	for(int j=0; j<columnas; j++){
		matriz.push_back(v);
	}
}

Matriz::Matriz(int n, int m) {
	filas = n;
	columnas = m;
	vector<double> v(n, 0);
	for(int i=0; i<m; i++){
		matriz.push_back(v);
	}
}

Matriz::Matriz(const Matriz &M) {
	filas = M.filas;
	columnas = M.columnas;
	matriz = M.matriz;
}

ostream& operator<<(ostream& os, const Matriz& mat){
	for(int i=0; i < mat.filas; i++){
			for(int j=0; j<mat.columnas; j++){
				os << mat.matriz[j][i] << " ";
			}
			os << "\n";
		}
	return os;
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}

