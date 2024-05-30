/*
 * MatrizIdentidad.h
 *
 *  Created on: May 30, 2024
 *      Author: lu
 */

#ifndef SRC_MATRIZIDENTIDAD_H_
#define SRC_MATRIZIDENTIDAD_H_

#include "MatrizCuadrada.h"

class MatrizIdentidad: public MatrizCuadrada {
public:
	MatrizIdentidad();
	MatrizIdentidad(int n);
	MatrizIdentidad(MatrizCuadrada M);
	virtual ~MatrizIdentidad();
};

#endif /* SRC_MATRIZIDENTIDAD_H_ */
