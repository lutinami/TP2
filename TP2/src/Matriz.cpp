/*
 * Matriz.cpp
 *
 *  Created on: May 25, 2024
 *      Author: lu
 */

#include "Matriz.h"

Matriz::Matriz() {
	int i,j;
	n = 2;
	m = 2;
	for(i=0; i<n; i++){
		for(j=0; i<m; j++){
			matriz[i][j] = 0;
		}
	}
}

Matriz::Matriz(int n, int m) {
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
	int i, j;
	for(i=0; i<mat.n; i++){
		for(j=0; j<mat.m; j++){
			os << mat.m;
		}
		os << "\n";
	}
	return os;
}

Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}

