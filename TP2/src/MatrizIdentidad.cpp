/*
 * MatrizIdentidad.cpp
 *
 *  Created on: May 30, 2024
 *      Author: lu
 */

#include "MatrizIdentidad.h"

MatrizIdentidad::MatrizIdentidad() {
	MatrizCuadrada ident = MatrizCuadrada();
	ident = ident*(~ident);
	this->matriz = ident.getMatriz();
	this->size_n = ident.getSize_n();
	this->columnas = ident.getColumnas();
	this->filas = ident.getFilas();
}

MatrizIdentidad::MatrizIdentidad(MatrizCuadrada M) {
	M = M*(~M);
	this->matriz = M.getMatriz();
	this->size_n = M.getSize_n();
	this->columnas = M.getColumnas();
	this->filas = M.getFilas();
}

MatrizIdentidad::MatrizIdentidad(int n) {
	MatrizCuadrada ident = MatrizCuadrada(n);
	ident = ident*(~ident);
	this->matriz = ident.getMatriz();
	this->size_n = ident.getSize_n();
	this->columnas = ident.getColumnas();
	this->filas = ident.getFilas();
}

MatrizIdentidad::~MatrizIdentidad() {
	// TODO Auto-generated destructor stub
}
