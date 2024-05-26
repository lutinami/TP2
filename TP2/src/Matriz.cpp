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
#include <numeric>
using namespace std;

// ITERADORES
vector<vector<double>>::iterator fila;
vector<double>::iterator columna;

// CONSTRUCTORES
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

Matriz::Matriz(int n, int m, double a) {
	filas = n;
	columnas = m;
	vector<double> v(m, a);
	for(int i=0; i<n; i++){
		matriz.push_back(v);
	}
}

Matriz::Matriz(const Matriz &M) {
	filas = M.filas;
	columnas = M.columnas;
	matriz = M.matriz;
}

// FUNCIONES

vector<vector<double> > Matriz::getMatriz(){
	return this->matriz;
}

Matriz& Matriz::ProductoPorEscalar(double esc) {
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			*columna = esc*(*columna);
		}
	}
	return(*this);
}

int Matriz::numel() {
	return(this->matriz.size()*this->columnas);
}

double Matriz::cumsum() {
	double suma_total =0;
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			suma_total += *columna;
		}
	}
	return suma_total;
}

double Matriz::max() {
	double max = this->matriz[0][0];
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			if (*columna > max){
				max = *columna;
			}
		}
	}
	return max;
}

double Matriz::min() {
	double min = this->matriz[0][0];
		for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){
			for(columna = fila->begin(); columna != fila->end(); columna++){
				if (*columna < min){
					min = *columna;				}
			}
		}
	return min;
}

// SOBRECARGAR DE OPERADORES

ostream& operator<<(ostream& os, Matriz& mat){
	for(fila = mat.matriz.begin(); fila != mat.matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			os << *columna << " ";
		}
		os << endl;
	}
	return os;
}

Matriz Matriz::operator +(const Matriz &q) const {
	int suma_filas = (this->filas > q.filas)?this->filas:q.filas;
	int suma_col = (this->columnas > q.columnas)?this->columnas:q.columnas;
	Matriz suma = Matriz(suma_filas, suma_col);

	for(int i=0; i< filas; i++){
		transform(this->matriz[i].begin(), this->matriz[i].end(), q.matriz[i].begin(), suma.matriz[i].begin(), plus<double>());
	}
	return suma;
}

Matriz Matriz::operator -(const Matriz &q) const {
	int resta_filas = (this->filas > q.filas)?this->filas:q.filas;
	int resta_col = (this->columnas > q.columnas)?this->columnas:q.columnas;
	Matriz resta = Matriz(resta_filas, resta_col);

	for(int i=0; i< filas; i++){
		transform(this->matriz[i].begin(), this->matriz[i].end(),q.matriz[i].begin(), resta.matriz[i].begin(), minus<double>());
	}
	return resta;
}

Matriz Matriz::operator !() const {
	Matriz trans = Matriz(this->columnas, this->filas);
	for(int i=0; i<this->filas; i++){
		for(int j=0; j<this->columnas; j++){
			trans.matriz[j][i] = this->matriz[i][j];
		}
	}
	return trans;
}

Matriz Matriz::operator *(const Matriz &q) const {
	if(this->columnas != q.filas){
		cout << "No es posible realizar el producto matricial para estas matrices." << endl;
		return q;
	}
	int producto_filas = this->filas;
	int producto_col = q.columnas;
	Matriz producto = Matriz(producto_filas, producto_col);

	for(int i=0; i< filas; i++){
		transform(this->matriz[i].begin(), this->matriz[i].end(),q.matriz[i].begin(), producto.matriz[i].begin(), multiplies<double>());
	}
	return producto;
}

// DESTRUCTORES
Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}
