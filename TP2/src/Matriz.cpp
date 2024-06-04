//============================================================================
// Name        : Trabajo Practico 2 - Enunciado C
// Author      : Alongi, Paez, Rico
//============================================================================

// Bibliotecas ------
#include "Matriz.h"
#include <vector>
#include <iostream>
#include <algorithm>	//transform
#include <cstdlib>
#include <time.h>
using namespace std;
//-------------------



// ITERADORES ------------------------
vector<vector<double>>::iterator fila;
vector<double>::iterator columna;
//------------------------------------



// CONSTRUCTORES ------------------------------------------------------------------------------
Matriz::Matriz() {					// Sin argumentos:
	filas = 4;					// Matriz 0 de 4 filas y 4 columnas
	columnas = 4;					// 0 0 0 0
	vector<double> v(filas, 0);			// 0 0 0 0
	for(int j=0; j<columnas; j++){			// 0 0 0 0
		matriz.push_back(v);			// 0 0 0 0
	}						//
}							//
// -------------------------------------------------------------------------------------------
Matriz::Matriz(int n, int m) {				// Matriz de n filas y m columnas
	srand(time(0));					// donde cada uno de sus elementos
	filas = n;					// es generado aleatoriamente
	columnas = m;					// dentro de un rango de 0 a 100.
	vector<double> v(m, 1);				// 
	for(int i=0; i<n; i++){
		vector<double> v;
		for(int j=0; j<m;j++){
			v.push_back((rand()%101)*1.0);
		}
		matriz.push_back(v);
	}
}
// -------------------------------------------------------------------------------------------
Matriz::Matriz(int n, int m, double a) {		// Matriz "a" con n filas y m columnas
	filas = n;					// a a a a ... a
	columnas = m;					// a a a a ... a
	vector<double> v(m, a);				// a a a a ... a
	for(int i=0; i<n; i++){				// . . . . ... a
		matriz.push_back(v);			// . . . . ... a
	}						// . . . . ... a
}							// a a a a ... a
// -------------------------------------------------------------------------------------------
Matriz::Matriz(vector<vector<double> > matriz) {	// Define al objeto
	this->matriz = matriz;				// en base a una
	this->columnas = matriz.size();			// matriz ingresada
	this->filas = matriz[0].size();			// como vector 2d
}							//
// -------------------------------------------------------------------------------------------
Matriz::Matriz(const Matriz &M) {			// Copia un objeto Matriz a otro
	filas = M.filas;				// objeto Matriz
	columnas = M.columnas;				//
	matriz = M.matriz;				//
}							//
// -------------------------------------------------------------------------------------------



// SETTERS ----------------------------------------------------------------------------------------------
void Matriz::setMatriz(vector<vector<double> > mat) {			// Cambia la matriz del objeto
	this->matriz.clear();						// con un vector 2d
	this->matriz = mat;						//
	this->filas = mat.size();					//
	this->columnas = mat[0].size();					//
}									//
// -------------------------------------------------------------------------------------------------------
void Matriz::setMatrizUnidad(int n, int m, double a) {			// Cambia la matriz del objeto
	this->filas = n;						// con una nueva de n filas y
	this->columnas = m;						// m columnas, y la llena del
	this->matriz.clear();						// valor a
	vector<double> v(m, a);
	for(int i=0; i<n; i++){
		this->matriz.push_back(v);
	}
}
// -------------------------------------------------------------------------------------------------------
void Matriz::setMatrizAleatoria(int n, int m) {		// Cambia la matriz por una matriz de n filas y 
	this->filas = n;				// m columnas donde cada elemento es generado
	this->columnas = m;				// aleatoriamente,
	this->matriz.clear();
	vector<double> v(m, 1);	
	for(int i=0; i<n; i++){
		vector<double> v;
		for(int j=0; j<m;j++){
			v.push_back((rand()%101)*1.0);
		}
		matriz.push_back(v);
	}
}
// -------------------------------------------------------------------------------------------------------



// GETTERS --------------------------------------------------------------------------------
vector<vector<double> > Matriz::getMatriz(){	// devuelve la matriz
	return this->matriz;			// del objeto
}						//
// ----------------------------------------------------------------------------------------
int Matriz::getFilas() {			// devuelve la cantidad de filas del objeto
	return this->filas;			//
}						//
// ----------------------------------------------------------------------------------------
int Matriz::getColumnas() {			// devuelve la cantidad de columnas
	return this->columnas;			// del objeto
}						//
// ----------------------------------------------------------------------------------------



// FUNCIONES ----------------------------------------------------------------------------------------------------------------------------------------------
Matriz& Matriz::ProductoPorEscalar(double esc) {						// Recorriendo la matriz con
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){			// iteradores, multiplica cada
		for(columna = fila->begin(); columna != fila->end(); columna++){		// elemento de la matriz por
			*columna = esc*(*columna);						// el double esc.
		}
	}
	return(*this);
}
// ---------------------------------------------------------------------------------------------------------------------------------------------------------
int Matriz::numel() {										// Devuelve el producto entre el tamaño de la matriz (filas)
	return(this->matriz.size()*this->columnas);						// por la cantidad de columnas
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------
double Matriz::cumsum() {									// Recorriendo la matriz con
	double suma_total =0;									// iteradores, suma cada
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){			// elemento de la matriz a un
		for(columna = fila->begin(); columna != fila->end(); columna++){		// acumulador
			suma_total += *columna;
		}
	}
	return suma_total;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------------------
double Matriz::max() {										// Recorriendo la matriz
	double max = this->matriz[0][0];							// con iteradores,
	for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){			// compara cada elemento
		for(columna = fila->begin(); columna != fila->end(); columna++){		// para obtener el maximo
			if (*columna > max){							// valor de la matriz
				max = *columna;
			}
		}
	}
	return max;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------------------
double Matriz::min() {										// Recorriendo la matriz
	double min = this->matriz[0][0];							// con iteradores,
		for(fila = this->matriz.begin(); fila != this->matriz.end(); fila++){		// compara cada elemento
			for(columna = fila->begin(); columna != fila->end(); columna++){	// para obtener el minimo
				if (*columna < min){						// valor de la matriz
					min = *columna;
				}
			}
		}
	return min;
}
// ---------------------------------------------------------------------------------------------------------------------------------------------------------



// SOBRECARGA DE OPERADORES ---------------------------------------------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& os, Matriz& mat){														// Recorriendo la matriz
	for(fila = mat.matriz.begin(); fila != mat.matriz.end(); fila++){										// con iteradores, se
		for(columna = fila->begin(); columna != fila->end(); columna++){									// imprime cada elemento
			os << *columna << " ";														// de la matriz
		}
		os << endl;
	}
	return os;
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator +(const Matriz &q) const {													// Se verifica que las matrices
	if(this->filas != q.filas && this->columnas != q.filas){											// tengan igual cantidad de
		cout << "Son de distinto tamaño - no pueden ser sumadas." << endl;									// filas y columnas. 
		return q;																// Se crea una matriz suma
	}																		// auxiliar.
	int suma_filas = this->filas;															// Luego, recorriendo la matriz,
	int suma_col = this->columnas;															// se utilizan las funciones
																			// transform() y plus<> de la
	Matriz suma = Matriz(suma_filas, suma_col);													// biblioteca algorithm para 
																			// sumar las matrices
	for(int i=0; i< filas; i++){															// 
		transform(this->matriz[i].begin(), this->matriz[i].end(), q.matriz[i].begin(), suma.matriz[i].begin(), plus<double>());			// 
	}																		// 
	return suma;																	// 
}																			// 
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator -(const Matriz &q) const {													// Se verifica que las matrices
	if(this->filas != q.filas && this->columnas != q.filas){											// tengan igual cantidad de
		cout << "Son de distinto tamaño - no pueden ser restadas." << endl;									// filas y columnas.				
		return q;																// Se crea una matriz resta
	}																		// auxiliar.
	int resta_filas = this->filas;															// Luego, recorriendo la matriz,
	int resta_col = this->columnas;															// se utilizan las funciones
	Matriz resta = Matriz(resta_filas, resta_col);													// transform() y minus<> de la
																			// biblioteca algorithm para 
	for(int i=0; i< filas; i++){															// restar las matrices
		transform(this->matriz[i].begin(), this->matriz[i].end(),q.matriz[i].begin(), resta.matriz[i].begin(), minus<double>());		// 
	}																		// 
	return resta;																	// 
}																			// 
																			// 
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator !() const {															// Usando una matriz auxiliar
	Matriz trans = Matriz(this->columnas, this->filas);												// recorre la matriz, y le
	for(int i=0; i<this->filas; i++){														// asigna a cada elemento la
		for(int j=0; j<this->columnas; j++){													// matriz traspuesta original
			trans.matriz[j][i] = this->matriz[i][j];											//
		}																	//
	}																		//
	return trans;																	//
}																			//
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Matriz Matriz::operator *(const Matriz &q) const {													// Verificando que se
	if(this->filas != q.columnas){															// pueda realizar el
		cout << "No es posible realizar el producto matricial para estas matrices." << endl;							// producto matricial
		return q;																// (si la cantidad de
	}																		// filas de una coincide
	int producto_filas = this->filas;														// con la cantidad de
	int producto_col = q.columnas;															// columnas de otra),
	Matriz producto = Matriz(producto_filas, producto_col, 0);											// se crea una nueva matriz
	for(int i=0;i<producto_filas;i++){														// auxiliar.
		for(int j=0;j<producto_col;j++){													// Luego, recorriendo la martiz
			for(int k=0;k<producto_col;k++){												// se utiliza un tercer bucle
				producto.matriz[i][j]+=this->matriz[i][k]*q.matriz[k][j];								// para recorrer la fila o 
			}																// columna a multiplicar, 
		}																	// sumando el resultado al
	}																		// elemento de la matriz
	return producto;																// auxiliar correspondiente.
}																			// 
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// DESTRUCTORES---------------------------
Matriz::~Matriz() {
	// TODO Auto-generated destructor stub
}
// ---------------------------------------
