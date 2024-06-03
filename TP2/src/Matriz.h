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


	// Setters ---------------------------------------------------------------------------------
	void setMatriz(vector<vector<double>> mat);
	void setMatrizUnidad(int n, int m, double a);
	void setFilas(int n);						// Cambia la cantidad de
									// filas a n, sin cambiar
									// el resto de variables
	
	void setColumnas(int m);					// Cambia la cantidad de
									// columnas a m, sin cambiar
									// el resto de variables
	
	void setCoordenada(int n, int m, double a); 			// Cambia el valor del
									// elemento en la fila n
									// y columna m a "a".
	
	void setFilaValor(int n, double a);				// Cambia el valor de los
									// elementos de la fila
									// n a "a".
	void setColumnaValor(int m, double a);				// Cambia el valor de los
									// elementos de la columna
									// m a "a".
	void setRango(int n_a, int n_b, int m_c, int m_d, double x);	// Cambia el valor de los
									// elementos entre la fila
									// a y b, y la columna
									// c y d, al valor x
	// -----------------------------------------------------------------------------------------


	// Getters --------------------------------------------------------
	vector<vector<double>> getMatriz(); 	// devuelve la matriz de un
						// objeto Matriz
	int getFilas(); 			// devuelve cantidad de
						// filas
	int getColumnas(); 			// devuelve cantidad de
						// columnas
	// ----------------------------------------------------------------

	// Funciones miembro --------------------------------------------------------------
	Matriz& ProductoPorEscalar(double esc);	// producto escalar de la matriz
	virtual int numel(); 				// devuelve el numero total del elementos
						// de la matriz
	double cumsum();			// devuelve la suma de todos los elementos
						// de la matriz
	double max();				// devuelve el maximo elemento de la matriz
	double min();				// devuelve el minimo elemento de la matriz
	// --------------------------------------------------------------------------------

	// Sobrecarga de operadores --------------------------------------------------
	friend ostream& operator<<(ostream& os, Matriz& mat);	// permite imprimir en
								// pantalla la matriz
								// del objeto
	Matriz operator+(const Matriz& q)const;			// permite la suma de
								// matrices con el
								// operador +
	Matriz operator-(const Matriz& q)const;			// permite la resta de
								// matrices con el
								// operador -
	Matriz operator!()const;				// permite obtener la
								// matriz traspuesta
	Matriz operator*(const Matriz& q)const;			// permite el producto
								// matricial con el
								// operador *
	// ---------------------------------------------------------------------------

	// Destructores --------------------------------------------------------------
	virtual ~Matriz();
	// ---------------------------------------------------------------------------
};

#endif /* MATRIZ_H_ */
