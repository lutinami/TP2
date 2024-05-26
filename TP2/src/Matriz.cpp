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
vector<vector<double>>::iterator fila;
vector<double>::iterator columna;

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
	vector<double> v(m, 1);
	for(int i=0; i<n; i++){
		matriz.push_back(v);
	}
}

Matriz::Matriz(const Matriz &M) {
	filas = M.filas;
	columnas = M.columnas;
	matriz = M.matriz;
}

vector<vector<double> > Matriz::getMatriz(){
	return this->matriz;
}

ostream& operator<<(ostream& os, Matriz& mat){
	for(fila = mat.matriz.begin(); fila != mat.matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			os << *columna << " ";
		}
		os << endl;
	}
	return os;
}

Matriz Matriz::operator +( Matriz &q){
	Matriz suma = Matriz(q.filas, q.columnas);
	if(filas != q.filas || columnas != q.columnas){
		cout << "Las matrices deben tener el mismo tamaño para poder sumarlas" << endl;
	}
	for(int i=0; i< filas; i++){
		transform(this->matriz[i].begin(), this->matriz[i].end(), q.matriz[i].begin(), suma.matriz[i].begin(), plus<double>());
	}

	return suma;
}

Matriz Matriz::operator -(const Matriz &q) const {
}

Matriz Matriz::operator !() const {
}

Matriz Matriz::operator *(const Matriz &q) const {
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}
