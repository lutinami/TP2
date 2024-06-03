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
	// Constructores -------------------------------------------------------------------------
	MatrizIdentidad();			// crea una matriz identidad de tamaño 4
	MatrizIdentidad(int n);			// crea una matriz identidad de tamaño n
	MatrizIdentidad(MatrizCuadrada M);	// crea la matriz identidad de una matriz cuadrada
	// ---------------------------------------------------------------------------------------
	
	// Destructores -----------
	virtual ~MatrizIdentidad();
	// ------------------------
};

#endif /* SRC_MATRIZIDENTIDAD_H_ */
