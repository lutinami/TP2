//============================================================================
// Name        : Trabajo Practico 2 - Enunciado C
// Author      : Alongi, Paez, Rico
//============================================================================

#ifndef MATRIZ_H_
#define MATRIZ_H_

// Bibliotecas
#include<iostream>
#include<vector>
using namespace std;

class Matriz {

// Variables protegidas para usar en subclases
protected:
	int filas, columnas;
	vector<vector<double>> matriz;

// Funciones publicas
public:
	// Constructores ---------------------------------------------------------------------------
	Matriz();				// Matriz por defecto
	Matriz(int n, int m);			// Matriz de n filas y m columnas
	Matriz(int n, int m, double a);		// Matriz de valor "a" de n filas y m columnas
	Matriz(vector<vector<double>> matriz);	// Matriz definida por sus elementos
	Matriz(const Matriz& M);		// Matriz copia
	// -----------------------------------------------------------------------------------------


	// Setters -------------------------------------------------------------------------------------------------------------------------
	void setMatriz(vector<vector<double>> mat);			// Cambia el valor de matriz con un vector 2D
	void setMatrizUnidad(int n, int m, double a);			// Cambia el valor de matriz con los nuevos tamanos
	void setMatrizAleatoria(int n, int m);
	// ---------------------------------------------------------------------------------------------------------------------------------


	// Getters -------------------------------------------------------------
	vector<vector<double>> getMatriz(); 	// devuelve la matriz
	int getFilas(); 			// devuelve cantidad de filas
	int getColumnas(); 			// devuelve cantidad de columnas
	// ---------------------------------------------------------------------

	// Funciones miembro --------------------------------------------------------------
	Matriz& ProductoPorEscalar(double esc);	// producto escalar de la matriz
	virtual int numel(); 			// devuelve la cantidad de elementos de la matriz
	double cumsum();			// devuelve la suma de todos los elementos de la matriz
	double max();				// devuelve el maximo elemento de la matriz
	double min();				// devuelve el minimo elemento de la matriz
	// --------------------------------------------------------------------------------

	// Sobrecarga de operadores -------------------------------------------------------------------
	friend ostream& operator<<(ostream& os, Matriz& mat);	// imprime en pantalla la matriz con <<
	Matriz operator+(const Matriz& q)const;			// suma matrices con +
	Matriz operator-(const Matriz& q)const;			// resta matrices con -
	Matriz operator!()const;				// devuelve la matriz traspuesta con !
	Matriz operator*(const Matriz& q)const;			// devuelve el producto matricial con *
	// --------------------------------------------------------------------------------------------

	// Destructores --------------------------------------------------------------
	virtual ~Matriz();
	// ---------------------------------------------------------------------------
};

#endif /* MATRIZ_H_ */
