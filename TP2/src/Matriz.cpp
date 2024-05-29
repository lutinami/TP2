//============================================================================
// Name        : Trabajo Practico 2 - Enunciado C
// Author      : Alongi, Paez, Rico
//============================================================================

// Bibliotecas ---------//
#include "Matriz.h"	//
#include <vector>	//
#include <iostream>	//
#include <algorithm>	//
#include <string>	//
#include <numeric>	//
using namespace std;	//
//----------------------//


// ITERADORES --------------------------//
vector<vector<double>>::iterator fila;	//
vector<double>::iterator columna;	//
//--------------------------------------//


// CONSTRUCTORES -----------------------------------------------------------------
// -------------------------------------------------------------------------------
Matriz::Matriz() {			// Sin argumentos:
	filas = 4;			// Matriz 0 de 4 filas y 4 columnas
	columnas = 4;			// 0 0 0 0
	vector<double> v(filas, 0);	// 0 0 0 0
	for(int j=0; j<columnas; j++){	// 0 0 0 0
		matriz.push_back(v);	// 0 0 0 0
	}				//
}					//
// -------------------------------------------------------------------------------
Matriz::Matriz(int n, int m) {		// Matriz 1 con n filas y m columnas
	filas = n;			// 1 1 1 1 ... 1
	columnas = m;			// 1 1 1 1 ... 1
	vector<double> v(m, 1);		// 1 1 1 1 ... 1
	for(int i=0; i<n; i++){		// . . . . ... 1
		matriz.push_back(v);	// . . . . ... 1
	}				// . . . . ... 1
}					// 1 1 1 1 ... 1
// -------------------------------------------------------------------------------
Matriz::Matriz(int n, int m, double a) {	// Matriz "a" con n filas y m columnas
	filas = n;				// a a a a ... a
	columnas = m;				// a a a a ... a
	vector<double> v(m, a);			// a a a a ... a
	for(int i=0; i<n; i++){			// . . . . ... a
		matriz.push_back(v);		// . . . . ... a
	}					// . . . . ... a
}						// a a a a ... a
// -------------------------------------------------------------------------------
Matriz::Matriz(vector<vector<double> > matriz) {	// Define al objeto
	this->matriz = matriz;				// en base a una
	this->columnas = matriz.size();			// matriz ingresada
	this->filas = matriz[0].size();			//
}							//
// -------------------------------------------------------------------------------
Matriz::Matriz(const Matriz &M) {	// Copia un objeto Matriz a otro
	filas = M.filas;		// objeto Matriz
	columnas = M.columnas;		//
	matriz = M.matriz;		//
}					//
// -------------------------------------------------------------------------------


// SETTERS -----------------------------------------------------------------------
// -------------------------------------------------------------------------------
void Matriz::setMatriz(int n, int m, double a) {	// Cambia la matriz
	this->matriz.clear();				// del objeto, sin
	vector<double> v(m, a);				// cambiar el resto
	for(int i=0; i<n; i++){				// de variables
		this->matriz.push_back(v);		//
	}						//
}							//
// -------------------------------------------------------------------------------
void Matriz::setFilas(int n) {	// Cambia la cantidad de filas, si
	this->filas = n;	// cambiar el resto de variables
}				//
// -------------------------------------------------------------------------------
void Matriz::setColumnas(int m) {	// Cambia la cantidad de columnas,
	this->columnas = m;		// sin cambiar el resto de
}					// variables
// -------------------------------------------------------------------------------
void Matriz::setCoordenada(int n, int m, double a) {	// Cambia el valor del
	this->matriz[n][m] = a;				// elemento en la fila n
}							// y columna m
// -------------------------------------------------------------------------------
void Matriz::setFilaValor(int n, double a) {	// Cambia el valor de los
	for(int i = 0; i<this->columnas; i++){	// elementos de la fila n
		this->matriz[n][i] = a;		//
	}					//
}						//
// -------------------------------------------------------------------------------
void Matriz::setColumnaValor(int m, double a) {	// Cambia el valor de
	for(int i = 0; i<this->filas; i++){	// los elementos de la
		this->matriz[i][m] = a;		// columna m
	}					//
}						//
// -------------------------------------------------------------------------------
void Matriz::setRango(int n_a, int n_b, int m_c, int m_d, double x) {
	for (int i = n_a; i<=n_b; i++){
		for (int j = m_c; j<=m_d; j++){
			this->matriz[j][i] = x;
		}
	}
}
// -------------------------------------------------------------------------------

// GETTERS -----------------------------------------------------------------------
// -------------------------------------------------------------------------------
vector<vector<double> > Matriz::getMatriz(){	// devuelve la matriz
	return this->matriz;			// del objeto
}						//
// -------------------------------------------------------------------------------
int Matriz::getFilas() {	// devuelve la cantidad de filas del objeto
	return this->filas;	//
}				//
// -------------------------------------------------------------------------------
int Matriz::getColumnas() {	// devuelve la cantidad de columnas
	return this->columnas;	// del objeto
}				//
// -------------------------------------------------------------------------------


// FUNCIONES -----------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------
Matriz& Matriz::ProductoPorEscalar(double esc) {				// Recorriendo la matriz con
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){	// iteradores, multiplica cada
		for(columna = fila->begin(); columna != fila->end(); columna++){// elemento de la matriz por
			*columna = esc*(*columna);				// el double esc.
		}								//
	}									//
	return(*this);								//
}										//
// ---------------------------------------------------------------------------------------------------------
int Matriz::numel() {					// Devuelve el producto entre el tamaño de la matriz (filas)
	return(this->matriz.size()*this->columnas);	// por la cantidad de columnas
}							//
// ---------------------------------------------------------------------------------------------------------
double Matriz::cumsum() {							// Recorriendo la matriz con
	double suma_total =0;							// iteradores, suma cada
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){	// elemento de la matriz a un
		for(columna = fila->begin(); columna != fila->end(); columna++){// acumulador
			suma_total += *columna;					//
		}								//
	}									//
	return suma_total;							//
}										//
// ---------------------------------------------------------------------------------------------------------
double Matriz::max() {								// Recorriendo la matriz
	double max = this->matriz[0][0];					// con iteradores,
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){	// compara cada elemento
		for(columna = fila->begin(); columna != fila->end(); columna++){// para obtener el maximo
			if (*columna > max){					// valor de la matriz
				max = *columna;					//
			}							//
		}								//
	}									//
	return max;								//
}										//
// ---------------------------------------------------------------------------------------------------------
double Matriz::min() {									// Recorriendo la matriz
	double min = this->matriz[0][0];						// con iteradores,
		for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){	// compara cada elemento
			for(columna = fila->begin(); columna != fila->end(); columna++){// para obtener el minimo
				if (*columna < min){					// valor de la matriz
					min = *columna;					//
				}							//
			}								//
		}									//
	return min;									//
}											//
// ---------------------------------------------------------------------------------------------------------


// SOBRECARGA DE OPERADORES ----------------------------------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& os, Matriz& mat){						// Recorriendo la matriz
	for(fila = mat.matriz.begin(); fila != mat.matriz.end(); fila++){		// con iteradores, se
		for(columna = fila->begin(); columna != fila->end(); columna++){	// imprime cada elemento
			os << *columna << " ";						// de la matriz
		}									//
		os << endl;								//
	}										//
	return os;									//
}											//
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator +(const Matriz &q) const {											// Creando una matriz suma
	int suma_filas = (this->filas > q.filas)?this->filas:q.filas;									// de filas y columnas igual
	int suma_col = (this->columnas > q.columnas)?this->columnas:q.columnas;								// a las de la matriz de
	Matriz suma = Matriz(suma_filas, suma_col);											// mayor tamaño.
																	//
	for(int i=0; i< filas; i++){													// Luego, recorriendo la matriz,
		transform(this->matriz[i].begin(), this->matriz[i].end(), q.matriz[i].begin(), suma.matriz[i].begin(), plus<double>());	// se utiliza las funciones
	}																// transform() y plus<> de la
	return suma;															// biblioteca algorithm para
}																	// sumar las matrices.
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator -(const Matriz &q) const {												// Creando una matriz resta
	int resta_filas = (this->filas > q.filas)?this->filas:q.filas;										// de filas y columnas igual
	int resta_col = (this->columnas > q.columnas)?this->columnas:q.columnas;								// a las de la matriz de
	Matriz resta = Matriz(resta_filas, resta_col);												// menor tamaño.
																		//
	for(int i=0; i< filas; i++){														// Luego, recorriendo la
		transform(this->matriz[i].begin(), this->matriz[i].end(),q.matriz[i].begin(), resta.matriz[i].begin(), minus<double>());	// matriz, se utiliza las
	}																	// funciones transform() y
	return resta;																// plus<> de la bilbioteca
}																		// algorithm para restar las
																		// matrices
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator !() const {					// Usando una matriz auxiliar
	Matriz trans = Matriz(this->columnas, this->filas);		// recorre la matriz, y le
	for(int i=0; i<this->filas; i++){				// asigna a cada elemento la
		for(int j=0; j<this->columnas; j++){			// matriz traspuesta original
			trans.matriz[j][i] = this->matriz[i][j];	//
		}							//
	}								//
	return trans;							//
}									//
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator *(const Matriz &q) const {													// Verificando que se
	if(this->columnas != q.filas){															// pueda realizar el
		cout << "No es posible realizar el producto matricial para estas matrices." << endl;							// producto matricial
		return q;																// (si la cantidad de
	}																		// filas de una coincide
	int producto_filas = this->filas;														// con la cantidad de
	int producto_col = q.columnas;															// columnas de otra),
	Matriz producto = Matriz(producto_filas, producto_col);												// se crea una nueva matriz
																			// con estos tamaños.
	for(int i=0; i< filas; i++){															//
		transform(this->matriz[i].begin(), this->matriz[i].end(),q.matriz[i].begin(), producto.matriz[i].begin(), multiplies<double>());	// Luego, se llena esta matriz
	}																		// con el producto matricial
	return producto;																// utilizando las funciones
}																			// transform() y multiplies<>
																			// de la bilbioteca algorithm
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------


// DESTRUCTORES---------------------------
// ---------------------------------------
Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}
