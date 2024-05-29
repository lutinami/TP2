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
public:
	MatrizCuadrada();
	MatrizCuadrada(int n);
	MatrizCuadrada(int n, double a);
	virtual ~MatrizCuadrada();
};

#endif /* MATRIZCUADRADA_H_ */
