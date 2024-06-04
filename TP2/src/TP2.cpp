//============================================================================
// Name        : Trabajo Practico 2 - Enunciado C
// Author      : Alongi, Paez, Rico
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
#include "MatrizCuadrada.h"
#include "MatrizIdentidad.h"
using namespace std;

bool compara_tam(Matriz& a, Matriz& b){
	return a.numel() < b.numel();
}

int main() {
	Matriz M1,M2,M3,M4,M;
	MatrizCuadrada M5,M6,M7,M8,Minv,Madj,Mdiv;
	MatrizIdentidad M9,M10;
	Matriz Msum,Mproc;
	//Matrices de orden Nxm===========================================================
	M1.setMatrizAleatoria(7, 4);
	M2.setMatrizAleatoria(7, 4);
	M3.setMatrizAleatoria(4, 6);
	M4.setMatrizAleatoria(4, 2);
	//Matrices de duadradas==========================================================
	M5=MatrizCuadrada(2);
	M6=MatrizCuadrada(2);
	M7=MatrizCuadrada(3);
	M8=MatrizCuadrada(3);
	//Matrices identidad
	M9=MatrizIdentidad(2);
	M10=MatrizIdentidad(3);
	//================================================================================
	vector<Matriz>TM({M1,M2,M3,M4,M5,M6,M7,M8,M9,M10});
	cout << "Siendo M1 = \n" << M1 << endl;
	cout << "M1 tiene " << M1.numel() << " elementos" << endl;
	cout << "La suma de todos los elementos de M1 es " << M1.cumsum() << endl;
	cout << "Siendo M2 = \n" << M2 << endl;
	Msum=M1+M2;
	cout<<"la suma entre M1 y M2 es:\n"<< Msum <<endl;
	cout << "Siendo M3 = \n" << M3 << endl;
	M3=!M3;
	cout<<"M3 traspuesta es: \n"<<M3<<endl;
	cout<<"Siendo M4 = \n "<<M4<<endl;
	Mproc=M4*M2;
	cout<<"el producto entre M4*M2 es:\n"<<Mproc<<endl;
	cout << "Siendo M6:\n" << M6 << endl;
	cout<<"EL determinate de la matriz M6 es:\n"<<M6.determinante()<<endl;
	cout<< "\nSiendo M8:\n" << M8 << endl;
	cout<<"EL determinate de la matriz M8 es:\n"<<M8.determinante()<<endl;
	cout << "\nSiendo M7:\n" << M7 << endl;
	Minv=~M7;
	cout<<"su Matriz inversa:\n"<<Minv<<endl;
	Madj=M7.adjunta();
	cout<<"su Matriz Abjunta:\n"<<Madj<<endl;
	Mdiv=M7/M8;
	cout<<"la division entre M7/M8 es:\n"<<Mdiv<<endl;
	cout << "Siendo M9 = \n" << M9 << endl;
	cout<<"el producto de M9 por un escalar es:\n"<<M9.ProductoPorEscalar(5)<<endl;
	cout<<"la Matriz M5:\n"<<M5<<endl;
	cout<<"EL maximo valor de M5 es: "<<M5.max()<<" y su minimo valor es: "<<M5.min()<<endl;
	cout <<"Las matrices se ordenan segun su tamaño de menor a mayor de la siguiente manera" << endl;

	sort(TM.begin(), TM.end(), compara_tam);
	for(int i=0; i<10; i++){
		cout << "Tamaño de la matriz: "<< TM[i].numel() << "\n" << TM[i] << endl;
	}

	return 0;
}
