/*
 * MatrizCuadrada.cpp
 *
 *  Created on: May 29, 2024
 *      Author: lu
 */

#include "MatrizCuadrada.h"

MatrizCuadrada::MatrizCuadrada() {
	this->setFilas(4);
	this->setColumnas(4);
	this->setMatriz(filas, columnas, 0);
}

MatrizCuadrada::MatrizCuadrada(int n) {
	this->setFilas(n);
	this->setColumnas(n);
	this->setMatriz(n, n, 0);
}

MatrizCuadrada::MatrizCuadrada(int n, double a) {
	this->setFilas(n);
	this->setColumnas(n);
	this->setMatriz(n, n, a);
}

MatrizCuadrada::~MatrizCuadrada() {
	// TODO Auto-generated destructor stub
}

