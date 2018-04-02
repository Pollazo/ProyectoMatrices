#ifndef MATRIZ_H
#define MATRIZ_H

#include <string>

struct numero
{
	int valor;
	numero * derecha = 0;
	numero * abajo = 0;
};

class Matriz
{
public:
	Matriz();
	void setMatriz();
	void imprimirMatriz();
	Matriz * sumaMatrices(Matriz *);
	Matriz * restaMatrices(Matriz *);
	Matriz * multipMatrices(Matriz *);
	int ReglaSarrus();
	int determinante();
	void guardarMatriz(Matriz *);
	
	numero * primero;
	int filas;
	int columnas;
	std::string nombreArchivo;
};




#endif // !MATRIZ_H

