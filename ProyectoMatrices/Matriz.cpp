#include "Matriz.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Matriz::Matriz()
{
	this->primero = 0;
}

void Matriz::setMatriz()
{
	this->primero = new numero;
	numero * filaTmp = this->primero;
	numero * filaArriba = NULL;
	numero * tmpNum = filaTmp;
	cout << "Ingrese el nombre del archivo que desea usar: \n";
	cin >> this->nombreArchivo;

	ifstream archivoMatriz(this->nombreArchivo, ios::in);

	if (!archivoMatriz)
	{
		cout << "Error al tratar de abrir el archivo: " << nombreArchivo << endl;
		return;
	}

	archivoMatriz.seekg(0, ios::beg);

	string valoresTmp;

	while (getline(archivoMatriz, valoresTmp))
	{
		if (this->filas > 0)
		{
			filaArriba = filaTmp;
			filaTmp->abajo = new numero;
			filaTmp = filaTmp->abajo;
			tmpNum = filaTmp;
		}

		stringstream valTmp(valoresTmp);
		while (!valTmp.eof())
		{
			valTmp >> valoresTmp;

			if (stringstream(valoresTmp) >> tmpNum->valor)
			{
				if (filaArriba == NULL)
					this->columnas++;
				if (valTmp.peek() == valTmp.eof() && filaTmp->abajo == NULL)
					break;
				if (filaArriba != NULL)
					filaArriba->abajo = tmpNum;
				if (valTmp.peek() != valTmp.eof())
				{
					tmpNum->derecha = new numero;
					tmpNum = tmpNum->derecha;
				}
				if (filaArriba != NULL && filaArriba->derecha != NULL)
					filaArriba = filaArriba->derecha;
			}
			else
			{
				cout << "Error en el formato del archivo. \n\n";
				return;
			}
			valoresTmp = "";
		}
		this->filas++;
	}
	archivoMatriz.close();
}

void Matriz::imprimirMatriz()
{
	numero * filaTmp = this->primero;
	numero * tmp = this->primero;
	while (tmp != NULL)
	{
		if (tmp->valor < 99999 && tmp->valor > -99999)
			cout << tmp->valor << ' ';
		if (tmp->derecha == NULL && filaTmp->abajo != NULL)
		{
			tmp = filaTmp->abajo;
			filaTmp = filaTmp->abajo;
			cout << endl;
		}
		else if (tmp->derecha == NULL && filaTmp->abajo == NULL)
			break;
		else if (tmp->derecha != NULL)
		{
			tmp = tmp->derecha;
		}
	}
	cout << "\nDimensiones: " << this->filas << "x" << this->columnas << endl;
}

Matriz * Matriz::sumaMatrices(Matriz *B)
{
	if (this->columnas != B->columnas || this->filas != B->filas)
	{
		cout << "No se puede realizar esta operación. \n\n";
		return 0;
	}
	
	Matriz * C = new Matriz;
	C->columnas = this->columnas;
	C->filas = this->filas;
	C->primero = new numero;
	numero * tmpA = this->primero;
	numero * tmpB = B->primero;
	numero * tmpC = C->primero;
	numero * filaTmpA = this->primero;
	numero * filaTmpB = B->primero;
	numero * filaTmpC = C->primero;

	for (int i = 0; i < this->filas; i++)
	{
		for (int i = 0; i < this->columnas; i++)
		{
			tmpC->valor = tmpA->valor + tmpB->valor;
			tmpC->derecha = new numero;
			tmpC = tmpC->derecha;
			tmpA = tmpA->derecha;
			tmpB = tmpB->derecha;
		}

		tmpA = filaTmpA->abajo;
		tmpB = filaTmpB->abajo;
		filaTmpA = tmpA;
		filaTmpB = tmpB;
		filaTmpC->abajo = new numero;
		filaTmpC = filaTmpC->abajo;
		tmpC = filaTmpC;
	}
	cout << "Ingrese el nombre de la matriz resultante: \n";
	cin >> C->nombreArchivo;
	return C;
}

Matriz * Matriz::restaMatrices(Matriz *B)
{
	if (this->columnas != B->columnas || this->filas != B->filas)
	{
		cout << "No se puede realizar esta operación. \n\n";
		return 0;
	}

	Matriz * C = new Matriz;
	C->columnas = this->columnas;
	C->filas = this->filas;
	C->primero = new numero;
	numero * tmpA = this->primero;
	numero * tmpB = B->primero;
	numero * tmpC = C->primero;
	numero * filaTmpA = this->primero;
	numero * filaTmpB = B->primero;
	numero * filaTmpC = C->primero;

	for (int i = 0; i < this->filas; i++)
	{
		for (int i = 0; i < this->columnas; i++)
		{
			tmpC->valor = tmpA->valor - tmpB->valor;
			tmpC->derecha = new numero;
			tmpC = tmpC->derecha;
			tmpA = tmpA->derecha;
			tmpB = tmpB->derecha;
		}

		tmpA = filaTmpA->abajo;
		tmpB = filaTmpB->abajo;
		filaTmpA = tmpA;
		filaTmpB = tmpB;
		filaTmpC->abajo = new numero;
		filaTmpC = filaTmpC->abajo;
		tmpC = filaTmpC;
	}
	cout << "Ingrese el nombre de la matriz resultante: \n";
	cin >> C->nombreArchivo;
	return C;
}

Matriz * Matriz::multipMatrices(Matriz *B)
{
	Matriz * MatA = this;
	Matriz * MatB = B;
	Matriz * MatC = new Matriz;
	MatC->primero = new numero;
	if (MatA->columnas == MatB->filas)
	{
	}
	else if (MatA->filas == MatB->columnas)
	{
		MatA = B;
		MatB = this;
	}
	else
	{
		cout << "No se puede realizar esta operación.";
		return 0;
	}

	MatC->filas = MatA->filas;
	MatC->columnas = MatB->columnas;
	numero * tmpNumA = MatA->primero;
	numero * tmpFilaA = MatA->primero;
	numero * tmpNumB = MatB->primero;
	numero * tmpFilaB = MatB->primero;
	numero * tmpNumC = MatC->primero;
	numero * tmpFilaC = MatC->primero;
	tmpNumC->valor = 0;
	int val;

	for (int i = 0; i < MatC->filas; i++)
	{
		for (int j = 0; j < MatC->columnas; j++)
		{
			for (int k = 0; k < MatA->columnas; k++)
			{
				tmpNumC->valor = tmpNumC->valor + ((tmpNumA->valor) * (tmpNumB->valor));
				tmpNumA = tmpNumA->derecha;
				tmpNumB = tmpNumB->abajo;
			}
			tmpNumC = tmpNumC->derecha;
			tmpNumC = new numero;
			tmpNumC->valor = 0;
			tmpNumA = tmpFilaA;
			tmpNumB = tmpFilaB->derecha;
			tmpFilaB = tmpFilaB->derecha;
		}
		tmpNumC = tmpFilaC->abajo;
		tmpNumC = new numero;
		tmpNumC->valor = 0;
		tmpFilaC = tmpFilaC->abajo;
		tmpNumA = tmpFilaA->abajo;
		tmpFilaA = tmpFilaA->abajo;
	}
	cout << "Ingrese el nombre del archivo de la matriz resultante: \n";
	cin >> MatC->nombreArchivo;
	return MatC;
}

int Matriz::ReglaSarrus()
{
	int det;
	numero * num1 = this->primero;
	numero * num2 = this->primero->derecha;
	numero * num3 = this->primero->derecha->derecha;
	numero * num4 = this->primero->abajo;
	numero * num5 = this->primero->abajo->derecha;
	numero * num6 = this->primero->abajo->derecha->derecha;
	numero * num7 = this->primero->abajo->abajo;
	numero * num8 = this->primero->abajo->abajo->derecha;
	numero * num9 = this->primero->abajo->abajo->derecha->derecha;

	det = ((num1->valor) * (num5->valor) * (num9->valor) + (num2->valor)
		* (num6->valor) * (num7->valor) + (num4->valor) * (num8->valor) * (num3->valor))
		- ((num3->valor) * (num5->valor) * (num7->valor) + (num2->valor) * (num4->valor) * (num9->valor) + (num6->valor) * (num8->valor) * (num1->valor));

	return det;
	
}

int Matriz::determinante()
{
	if (this->columnas == 1 && this->filas == 1)
		return this->primero->valor;
	else if (this->columnas == 2 && this->filas == 2)
	{
		int det;
		det = ((this->primero->valor) * (this->primero->abajo->derecha->valor));
		return det;
	}
	else if (this->columnas == 3 && this->filas == 3)
	{
		return this->ReglaSarrus();
	}
	else
	{
		cout << "No se puede realizar esta operación. \n";
		return -1;
	}
}

void Matriz::guardarMatriz(Matriz * nueva)
{
	ofstream archivo(nueva->nombreArchivo, ios::app);

	if (!archivo)
	{
		cout << "Error al intentar abrir el archivo " << nueva->nombreArchivo << "\n\n";
		return;
	}

	numero * tmpNum = nueva->primero;
	numero * tmpFila = nueva->primero;

	for (int i = 0; i < nueva->filas; i++)
	{
		for (int i = 0; i < nueva->columnas; i++)
		{
			archivo << to_string(tmpNum->valor) << ' ';
			tmpNum = tmpNum->derecha;
		}
		tmpNum = tmpFila->abajo;
		tmpFila = tmpFila->abajo;
		archivo << '\n';
	}
	archivo.close();
}