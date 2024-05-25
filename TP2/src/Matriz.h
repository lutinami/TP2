/*
 * Matriz.h
 *
 *  Created on: May 25, 2024
 *      Author: lu
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include<iostream>
using namespace std;

class Matriz {
private:
	int n, m;
	double **matriz;
public:
	// constructores
	Matriz();
	Matriz(int n, int m);
	Matriz(const Matriz& M);

	// funciones
	Matriz& operator=(const Matriz& M);
	friend ostream& operator<<(ostream& os, const Matriz& mat);
	// destructores
	virtual ~Matriz();
};

#endif /* MATRIZ_H_ */
