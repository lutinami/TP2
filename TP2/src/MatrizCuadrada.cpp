/*
 * MatrizCuadrada.cpp
 *
 *  Created on: May 29, 2024
 *      Author: lu
 */

#include "MatrizCuadrada.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

MatrizCuadrada::MatrizCuadrada() {
	size_n = 4;
	this->setFilas(4);
	this->setColumnas(4);
	this->setMatriz(filas, columnas, 0);
}

MatrizCuadrada::MatrizCuadrada(int n) {
	size_n = n;
	this->setFilas(n);
	this->setColumnas(n);
	this->setMatriz(n, n, 0);
}

MatrizCuadrada::MatrizCuadrada(int n, double a) {
	size_n = a;
	this->setFilas(n);
	this->setColumnas(n);
	this->setMatriz(n, n, a);
}

MatrizCuadrada::MatrizCuadrada(vector<vector<double> > mat) {
	matriz = mat;
	size_n = mat.size();
	columnas = size_n;
	filas = size_n;
}

MatrizCuadrada& MatrizCuadrada::ProductoPorEscalar(double esc) {
	Matriz auxiliar = Matriz(*this);
	auxiliar.ProductoPorEscalar(esc);
	*this = MatrizCuadrada(auxiliar.getMatriz());
	return (*this);
}

double MatrizCuadrada::determinante() {
	vector<vector<double>> mat = this->getMatriz();
	if (size_n>3){
		return 0;
	}
	else{
		switch (size_n){
		case 0:
			return 0;
		case 1:
			return (mat[0][0]);
		case 2:
			return((mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]));
		case 3:
			return((mat[0][0]*mat[1][1]*mat[2][2])
					+ (mat[0][1]*mat[1][2]*mat[2][0])
					+ (mat[0][2]*mat[1][0]*mat[2][1])
					- (mat[0][2]*mat[1][1]*mat[2][0])
					- (mat[0][0]*mat[1][2]*mat[2][1])
					- (mat[0][1]*mat[1][0]*mat[2][2]));
		}
	}
	return 0;
}

MatrizCuadrada MatrizCuadrada::cortaFilaColumna(size_t i, size_t j) {
	vector<vector<double>> mat = this->getMatriz();

	if(mat.size() > i){
		mat.erase(mat.begin() + i);
	}
	for(size_t k=0; k < mat.size(); k++){
		mat[k].erase(mat[k].begin() + j);
	}

	MatrizCuadrada cortada = MatrizCuadrada(mat);
	return cortada;
}

MatrizCuadrada MatrizCuadrada::adjunta() {
	vector<vector<double>> adjunta = this->getMatriz();
	MatrizCuadrada auxiliar = *this;
	MatrizCuadrada aux_cortada;
	for(int i=0; i<size_n; i++){
		for(int j=0; j<size_n; j++){
			aux_cortada = auxiliar.cortaFilaColumna(i, j);
			adjunta[i][j] = pow(-1, (i+j))*(aux_cortada.determinante());
		}
	}
	MatrizCuadrada ad = MatrizCuadrada(adjunta);
	return ad;
}

int MatrizCuadrada::numel() {
	return (size_n*size_n);
}

int MatrizCuadrada::getSize_n() {
	return (size_n);
}

MatrizCuadrada MatrizCuadrada::operator +(const MatrizCuadrada &q) const {
	Matriz auxiliar1 = Matriz(*this);
	Matriz auxiliar2 = Matriz(q);
	auxiliar1 = auxiliar1 + auxiliar2;
	MatrizCuadrada suma = MatrizCuadrada(auxiliar1.getMatriz());
	return suma;
}

MatrizCuadrada MatrizCuadrada::operator -(const MatrizCuadrada &q) const {
	Matriz auxiliar1 = Matriz(*this);
	Matriz auxiliar2 = Matriz(q);
	auxiliar1 = auxiliar1 - auxiliar2;
	MatrizCuadrada resta = MatrizCuadrada(auxiliar1.getMatriz());
	return resta;
}

MatrizCuadrada MatrizCuadrada::operator !() const {
	Matriz auxiliar1 = Matriz(*this);
	auxiliar1 = !auxiliar1;
	MatrizCuadrada trans = MatrizCuadrada(auxiliar1.getMatriz());
	return trans;
}

MatrizCuadrada MatrizCuadrada::operator *(const MatrizCuadrada &q) const {
	Matriz auxiliar1 = Matriz(*this);
	Matriz auxiliar2 = Matriz(q);
	auxiliar1 = auxiliar1*auxiliar2;
	MatrizCuadrada prod = MatrizCuadrada(auxiliar1.getMatriz());
	return prod;
}

MatrizCuadrada MatrizCuadrada::operator ~() const{
	MatrizCuadrada inversa = *this;
	double det_inversa = inversa.determinante();
	inversa = inversa.adjunta();
	inversa = !inversa;
	inversa = inversa.ProductoPorEscalar(1/det_inversa);
	return inversa;
}

MatrizCuadrada MatrizCuadrada::operator /(const MatrizCuadrada &q) const {
	MatrizCuadrada division = *this;
	division = division*(~q);
	return division;
}

MatrizCuadrada::~MatrizCuadrada() {
	// TODO Auto-generated destructor stub
}
