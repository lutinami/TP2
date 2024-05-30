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
private:
	int size_n;
public:
	MatrizCuadrada();
	MatrizCuadrada(int n);
	MatrizCuadrada(int n, double a);
	MatrizCuadrada(vector<vector<double>> mat);

	double determinante();
	MatrizCuadrada cortaFilaColumna(size_t i, size_t j);
	MatrizCuadrada adjunta();


	MatrizCuadrada& ProductoPorEscalar(double esc);
	virtual int numel();

	MatrizCuadrada operator+(const MatrizCuadrada& q)const;
	MatrizCuadrada operator-(const MatrizCuadrada& q)const;
	MatrizCuadrada operator!()const;
	MatrizCuadrada operator*(const MatrizCuadrada& q)const;

	MatrizCuadrada operator~()const;
	MatrizCuadrada operator/(const MatrizCuadrada& q)const;

	virtual ~MatrizCuadrada();
};

#endif /* MATRIZCUADRADA_H_ */
