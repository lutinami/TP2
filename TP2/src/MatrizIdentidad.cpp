/*
 * MatrizIdentidad.cpp
 *
 *  Created on: May 30, 2024
 *      Author: lu
 */

#include "MatrizIdentidad.h"

// Constructores ------------------------------------------------------------------
MatrizIdentidad::MatrizIdentidad() {
	MatrizCuadrada ident = MatrizCuadrada();	// Crea la matriz identidad
	ident = ident*(~ident);				// como producto matricial
	this->matriz = ident.getMatriz();		// entre una matriz 4x4
	this->size_n = ident.getSize_n();		// y su inversa
	this->columnas = ident.getColumnas();		//
	this->filas = ident.getFilas();			//
}
// ---------------------------------------------------------------------------------
MatrizIdentidad::MatrizIdentidad(MatrizCuadrada M) {
	M = M*(~M);				// Crea la matriz identidad como
	this->matriz = M.getMatriz();		// producto matricial entre la
	this->size_n = M.getSize_n();		// matriz cuadrada M y su inversa
	this->columnas = M.getColumnas();	//
	this->filas = M.getFilas();		//
}
// ---------------------------------------------------------------------------------
MatrizIdentidad::MatrizIdentidad(int n) {
	MatrizCuadrada ident = MatrizCuadrada(n);	// Crea la matriz identidad
	ident = ident*(~ident);				// como producto matricial
	this->matriz = ident.getMatriz();		// entre una matriz nxn y
	this->size_n = ident.getSize_n();		// su inversa
	this->columnas = ident.getColumnas();		//
	this->filas = ident.getFilas();			//
}
// ---------------------------------------------------------------------------------

// Destructores ------------------------------
MatrizIdentidad::~MatrizIdentidad() {
	// TODO Auto-generated destructor stub
}
// -------------------------------------------
