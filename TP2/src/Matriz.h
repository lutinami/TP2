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
	Matriz(const Matriz& M);

	// funciones miembro
	vector<vector<double>> getMatriz();

	// sobrecarga de operadores
	friend ostream& operator<<(ostream& os, Matriz& mat);
	Matriz operator+(Matriz& q);
	Matriz operator-(const Matriz& q)const;
	Matriz operator!()const;
	Matriz operator*(const Matriz& q)const;

	// destructores
	virtual ~Matriz();
};

#endif /* MATRIZ_H_ */
