/*
 * Matriz.cpp
 *
 *  Created on: May 25, 2024
 *      Author: lu
 */

#include "Matriz.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Matriz::Matriz() {
	filas = 4;
	columnas = 4;
	vector<double> v(filas, 0);
	for(int i=0; i<columnas; i++){
		matriz.push_back(v);
	}
}

/*Matriz::Matriz(int n, int m) {
	int i,j;
	this->n = n;
	this->m = m;
	for(i=0; i<n; i++){
		for(j=0; i<m; j++){
			this->matriz[i][j] = 0;
		}
	}
}

Matriz::Matriz(const Matriz &M) {
	int i,j;
	m = M.m;
	n = M.n;
	for(i=0; i<n; i++){
		for(j=0; i<m; j++){
			matriz[i][j] = M.matriz[i][j];
		}
	}
}

Matriz& Matriz::operator =(const Matriz &M) {
	return(*this);
}

ostream& operator<<(ostream& os, const Matriz& mat){
	string test = "";
	for(size_t i=0; i<mat.matriz.size(); i++){
		for(size_t j=0; j<mat.matriz[i].size(); j++){
			test += mat.matriz[i][j] ;
		}
	}

	return os;
}*/

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}

