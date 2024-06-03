/*
 * MatrizCuadrada.cpp
 *
 *  Created on: May 29, 2024
 *      Author: lu
 */

// Bibliotecas ------------
#include "MatrizCuadrada.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
// ------------------------



// Constructores -------------------------------------------------------------------------------------
MatrizCuadrada::MatrizCuadrada() {
	size_n = 4;					// crea una matriz cuadrada 4x4 llena de ceros
	this->setFilas(4);				// usando los setters de la clase Matriz
	this->setColumnas(4);				//
	this->setMatrizUnidad(filas, columnas, 0);	//
}
// ----------------------------------------------------------------------------------------------------
MatrizCuadrada::MatrizCuadrada(int n) {
	size_n = n;					// crea una matriz cuadrada nxn llena de 1
	this->setFilas(n);				// usando los setters de la clase Matriz
	this->setColumnas(n);				//
	this->setMatrizUnidad(n, n, 0);			//
}
// ----------------------------------------------------------------------------------------------------
MatrizCuadrada::MatrizCuadrada(int n, double a) {
	size_n = a;					// crea una matriz cuadrada nxn llena de a
	this->setFilas(n);				// usando los setters de la clase Matriz
	this->setColumnas(n);				//
	this->setMatrizUnidad(n, n, a);			//
}
// ----------------------------------------------------------------------------------------------------
MatrizCuadrada::MatrizCuadrada(vector<vector<double> > mat) {
	matriz = mat;					// crea una matriz cuadrada dado un vector 2d,
	size_n = mat.size();				// llenando la cantidad de filas y columnas
	columnas = size_n;				// con la funcion size() propia de los vectores
	filas = size_n;					//
}
// ----------------------------------------------------------------------------------------------------



// Getters ---------------------------------------------------------------------
int MatrizCuadrada::getSize_n() {
	return (size_n);	// devuelve el valor size_n de la MatrizCuadrada
}
// -----------------------------------------------------------------------------


// Funciones miembro -----------------------------------------------------------------------------------------------------------
MatrizCuadrada& MatrizCuadrada::ProductoPorEscalar(double esc) {
	Matriz auxiliar = Matriz(*this);		// adapta la funcion ProductoPorEscalar() de la
	auxiliar.ProductoPorEscalar(esc);		// clase matriz, transformando sus resultados a
	*this = MatrizCuadrada(auxiliar.getMatriz());	// una matriz cuadrada
	return (*this);					//
}
// ------------------------------------------------------------------------------------------------------------------------------
double MatrizCuadrada::determinante() {
	vector<vector<double>> mat = this->getMatriz();				// Calcula el determinante
	if (size_n>3){								// de una matriz.
		return 0;							// Se limita este calculo
	}									// para matrices de tamaño
	else{									// n=3.
		switch (size_n){						// Con un switch:
		case 0:								// Para n=0, se devuelve 0
			return 0;						// Para n=1, se devuelve el
		case 1:								// unico elemento de la 
			return (mat[0][0]);					// matriz.
		case 2:								// Para n=2, se devuelve el
			return((mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]));	// resultado de la determinante
		case 3:								// de 2x2:
			return((mat[0][0]*mat[1][1]*mat[2][2])			// a11*a22 - a12*a21
					+ (mat[0][1]*mat[1][2]*mat[2][0])	// Para n=3, se devuelve el
					+ (mat[0][2]*mat[1][0]*mat[2][1])	// resultado de la determinante
					- (mat[0][2]*mat[1][1]*mat[2][0])	// de 3x3:
					- (mat[0][0]*mat[1][2]*mat[2][1])	// a11*a22*a33 + a12*a23*a31
					- (mat[0][1]*mat[1][0]*mat[2][2]));	// + a13*a21*a32 - a13*a22*a31
		}								// - a11*a23*a32 - a12*a21*a33
	}									// Para n>3, devuelve 0
	return 0;								//
}
// ------------------------------------------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::cortaFilaColumna(size_t i, size_t j) {
	vector<vector<double>> mat = this->getMatriz();	// elimina la fila i y la columna j de la matriz,
							// actualizando su tamaño.
	if(mat.size() > i){				//
		mat.erase(mat.begin() + i);		//
	}						//
	for(size_t k=0; k < mat.size(); k++){		//
		mat[k].erase(mat[k].begin() + j);	//
	}						//
							//
	MatrizCuadrada cortada = MatrizCuadrada(mat);	//
	return cortada;					//
}
// ------------------------------------------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::adjunta() {
	vector<vector<double>> adjunta = this->getMatriz();				// devuelve la matriz adjunta
	MatrizCuadrada auxiliar = *this;						// de una matriz cuadrada de
	MatrizCuadrada aux_cortada;							// tamaño menor o igual a n=3.
	for(int i=0; i<size_n; i++){							// guardando en un auxiliar la
		for(int j=0; j<size_n; j++){						// matriz, se llena un vector 2d
			aux_cortada = auxiliar.cortaFilaColumna(i, j);			// con cada elemento:
			adjunta[i][j] = pow(-1, (i+j))*(aux_cortada.determinante());	// aij = (-1)^(i+j) * det(aux_cortada)
		}									// siendo aux_cortada la matriz original,
	}										// donde se elimina la fila i y la
	MatrizCuadrada ad = MatrizCuadrada(adjunta);					// columna j.
	return ad;									//
}
// ------------------------------------------------------------------------------------------------------------------------------
int MatrizCuadrada::numel() {
	return (size_n*size_n);	// devuelve la cantidad de elementos en la matriz
}
// ------------------------------------------------------------------------------------------------------------------------------



// Sobrecarga de operadores ----------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::operator +(const MatrizCuadrada &q) const {
	Matriz auxiliar1 = Matriz(*this);				// transforma el resultado de la suma de objetos
	Matriz auxiliar2 = Matriz(q);					// Matriz en un objeto MatrizCuadrada
	auxiliar1 = auxiliar1 + auxiliar2;				//
	MatrizCuadrada suma = MatrizCuadrada(auxiliar1.getMatriz());	//
	return suma;							//
}
// ------------------------------------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::operator -(const MatrizCuadrada &q) const {
	Matriz auxiliar1 = Matriz(*this);				// transforma el resultado de la resta de objetos
	Matriz auxiliar2 = Matriz(q);					// Matriz en un objeto MatrizCuadrada
	auxiliar1 = auxiliar1 - auxiliar2;				//
	MatrizCuadrada resta = MatrizCuadrada(auxiliar1.getMatriz());	//
	return resta;							//
}
// ------------------------------------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::operator !() const {
	Matriz auxiliar1 = Matriz(*this);				// transforma el resultado de la traspuesta de un
	auxiliar1 = !auxiliar1;						// objeto Matriz en un objeto MatrizCuadrada
	MatrizCuadrada trans = MatrizCuadrada(auxiliar1.getMatriz());	//
	return trans;							//
}
// ------------------------------------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::operator *(const MatrizCuadrada &q) const {
	Matriz auxiliar1 = Matriz(*this);				// transforma el resultado del producto matricial
	Matriz auxiliar2 = Matriz(q);					// entre objetos Matriz en un objeto MatrizCuadrada
	auxiliar1 = auxiliar1*auxiliar2;				//
	MatrizCuadrada prod = MatrizCuadrada(auxiliar1.getMatriz());	//
	return prod;							//
}
// ------------------------------------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::operator ~() const{
	MatrizCuadrada inversa = *this;				// Calcula la inversa de una matriz A, siendo				
	double det_inversa = inversa.determinante();		// A^-1 = ((Adj(A))^T)/det(A)
	inversa = inversa.adjunta();				// Es decir, la inversa de una matriz sera
	inversa = !inversa;					// igual al cocientre entre la traspuesta de 
	inversa = inversa.ProductoPorEscalar(1/det_inversa);	// la adjunta de A y el determinante de A
	return inversa;						//
}
// ------------------------------------------------------------------------------------------------------------------------
MatrizCuadrada MatrizCuadrada::operator /(const MatrizCuadrada &q) const {
	MatrizCuadrada division = *this;	// Calcula el cociente de matrices A y B como el producto matricial
	division = division*(~q);		// entre A y la inversa de B
	return division;			//
}
// ------------------------------------------------------------------------------------------------------------------------



MatrizCuadrada::~MatrizCuadrada() {
	// TODO Auto-generated destructor stub
}
