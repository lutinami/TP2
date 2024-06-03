/*
 * MatrizCuadrada.h
 *
 *  Created on: May 29, 2024
 *      Author: lu
 */

#ifndef MATRIZCUADRADA_H_
#define MATRIZCUADRADA_H_

#include "Matriz.h"

class MatrizCuadrada: public Matriz {
protected:
	int size_n;
public:
	// Constructores ----------------------------------------------------------------------------
	MatrizCuadrada();				// crea una matriz 4x4 de ceros
	MatrizCuadrada(int n);				// toma el tamaño y la rellena con 1
	MatrizCuadrada(int n, double a);		// toma el tamaño y con que numero rellenarla
	MatrizCuadrada(vector<vector<double>> mat);	// toma una vector 2d y crea el objeto
	// ------------------------------------------------------------------------------------------

	// Getters -------------------------------------------------
	int getSize_n();	// devuelve el tamaño n de la matriz
	// ---------------------------------------------------------

	// Funciones Miembro ---------------------------------------------------------------------------------------
	double determinante();					// devuelve la determinante de la matriz (hasta n=3)
	MatrizCuadrada cortaFilaColumna(size_t i, size_t j);	// elimina la fila i y columna j de la matriz	
	MatrizCuadrada adjunta();				// devuelve la matriz adjunta (hasta n=3)
	MatrizCuadrada& ProductoPorEscalar(double esc);		// multiplica los miembros de la matriz por esc
	virtual int numel();					// devuelve la cantidad de miembros de la matriz
	// ---------------------------------------------------------------------------------------------------------

	// Sobrecarga de operadores ------------------------------------------------------------------------
	MatrizCuadrada operator+(const MatrizCuadrada& q)const;	// devuelve la suma de matrices con +
	MatrizCuadrada operator-(const MatrizCuadrada& q)const;	// devuelve la resta de matrices con -
	MatrizCuadrada operator!()const;			// devuelve la traspuesta de la matriz con !
	MatrizCuadrada operator*(const MatrizCuadrada& q)const;	// devuelve el producto matricial con *
	MatrizCuadrada operator~()const;			// devuelve la inversa de la matriz con ~ 
	MatrizCuadrada operator/(const MatrizCuadrada& q)const;	// devuelve el cociente de matrices con /
	// -------------------------------------------------------------------------------------------------

	// Destructores ----------
	virtual ~MatrizCuadrada();
	// -----------------------
};

#endif /* MATRIZCUADRADA_H_ */
