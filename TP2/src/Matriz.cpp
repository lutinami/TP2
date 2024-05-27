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
// sin argumentos:
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
Matriz::Matriz() {
	filas = 4;
	columnas = 4;
	vector<double> v(filas, 0);
	for(int j=0; j<columnas; j++){
		matriz.push_back(v);
	}
}
// con n filas y m columnas:
// 1 1 1 1...1
// 1 1 1 1...1
// 1 1 1 1...1
// . . . ....1
// 1 1 1 1 1 1
Matriz::Matriz(int n, int m) {
	filas = n;
	columnas = m;
	vector<double> v(m, 1);
	for(int i=0; i<n; i++){
		matriz.push_back(v);
	}
}

// con n filas y m columnas, llena de double a:
// a a a a...a
// a a a a...a
// a a a a...a
// . . . ....a
// a a a a a a
Matriz::Matriz(int n, int m, double a) {
	filas = n;
	columnas = m;
	vector<double> v(m, a);
	for(int i=0; i<n; i++){
		matriz.push_back(v);
	}
}
// copia de matrices
Matriz::Matriz(const Matriz &M) {
	filas = M.filas;
	columnas = M.columnas;
	matriz = M.matriz;
}

// FUNCIONES
// devuelve la matriz como un vector de dos dimensiones
vector<vector<double> > Matriz::getMatriz(){
	return this->matriz;
}

// producto de una matriz por un escalar
Matriz& Matriz::ProductoPorEscalar(double esc) {
	// navegando la matriz con iteradores
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			// multiplica cada valor de la matriz por el escalar esc
			*columna = esc*(*columna);
		}
	}
	return(*this);
}
// devuelve la cantidad de elementos de la matriz
int Matriz::numel() {
	// multiplica la cantidad de filas (matriz.size()) por la cantidad de columnas (columnas)
	return(this->matriz.size()*this->columnas);
}

// suma todos los elementos de la matriz
double Matriz::cumsum() {
	double suma_total =0;
	// navegando la matriz con iteradores
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			// acumula todos los valores de cada elemento de la matriz
			suma_total += *columna;
		}
	}
	return suma_total;
}
// obtiene el valor maximo de la matriz
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
// obtiene el valor minimo de la matriz
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

// SOBRECARGA DE OPERADORES
// para imprimir en pantalla
ostream& operator<<(ostream& os, Matriz& mat){
	// navegando la matriz con iteradores
	for(fila = mat.matriz.begin(); fila != mat.matriz.end(); fila++){
		for(columna = fila->begin(); columna != fila->end(); columna++){
			os << *columna << " ";
		}
		os << endl;
	}
	return os;
}
// para sumar matrices (si son de distinto tamaño se toma el tamaño mas grande)
Matriz Matriz::operator +(const Matriz &q) const {
	int suma_filas = (this->filas > q.filas)?this->filas:q.filas;
	int suma_col = (this->columnas > q.columnas)?this->columnas:q.columnas;
	Matriz suma = Matriz(suma_filas, suma_col);
	
	// utiliza la funcion transform  y plus (suma) de la stl algorithm
	for(int i=0; i< filas; i++){
		transform(this->matriz[i].begin(), this->matriz[i].end(), q.matriz[i].begin(), suma.matriz[i].begin(), plus<double>());
	}
	return suma;
}

// para restar matrices (si son de distinto tamaño se toma el tamaño mas grande)
Matriz Matriz::operator -(const Matriz &q) const {
	int resta_filas = (this->filas > q.filas)?this->filas:q.filas;
	int resta_col = (this->columnas > q.columnas)?this->columnas:q.columnas;
	Matriz resta = Matriz(resta_filas, resta_col);

	// utiliza la funcion transform y minus (resta) de la stl algorithm
	for(int i=0; i< filas; i++){
		transform(this->matriz[i].begin(), this->matriz[i].end(),q.matriz[i].begin(), resta.matriz[i].begin(), minus<double>());
	}
	return resta;
}

// traspuesta de la matriz
Matriz Matriz::operator !() const {
	Matriz trans = Matriz(this->columnas, this->filas);
	for(int i=0; i<this->filas; i++){
		for(int j=0; j<this->columnas; j++){
			trans.matriz[j][i] = this->matriz[i][j];
		}
	}
	return trans;
}
// producto matricial (primero verifica que sea posible con las matrices dadas (columnas de matriz A igual a filas de matriz B)
Matriz Matriz::operator *(const Matriz &q) const {
	if(this->columnas != q.filas){
		cout << "No es posible realizar el producto matricial para estas matrices." << endl;
		return q;
	}
	int producto_filas = this->filas;
	int producto_col = q.columnas;
	Matriz producto = Matriz(producto_filas, producto_col);

	// utiliza la funcion transform y multiplies (producto) de la stl algorithm
	for(int i=0; i< filas; i++){
		transform(this->matriz[i].begin(), this->matriz[i].end(),q.matriz[i].begin(), producto.matriz[i].begin(), multiplies<double>());
	}
	return producto;
}

// DESTRUCTORES
Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}
