/*
 * Matriz.h
 *
 *  Created on: May 25, 2024
 *      Author: lu
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include<iostream>
#include<vector>
using namespace std;

class Matriz {
private:
	int filas, columnas;
	vector<vector<double>> matriz;
public:
	// constructores
	Matriz();
	Matriz(int n, int m);
	Matriz(int n, int m, double a);
	Matriz(const Matriz& M);

	// funciones miembro
	vector<vector<double>> getMatriz(); // devuelve la matriz de un objeto Matriz

	Matriz& ProductoPorEscalar(double esc); // producto escalar
	int numel(); 		// devuelve el numero total del elementos
	double cumsum();	// devuelve la suma de todos los elementos
	double max();		// devuelve el maximo elemento
	double min();			// devuelve el minimo elemento

	// sobrecarga de operadores
	// imprimir una matriz en pantalla
	friend ostream& operator<<(ostream& os, Matriz& mat);
	// suma de matrices
	Matriz operator+(const Matriz& q)const;
	// resta de matrices
	Matriz operator-(const Matriz& q)const;
	// matriz transpuesta
	Matriz operator!()const;
	// producto matricial
	Matriz operator*(const Matriz& q)const;

	// destructores
	virtual ~Matriz();
};

#endif /* MATRIZ_H_ */
