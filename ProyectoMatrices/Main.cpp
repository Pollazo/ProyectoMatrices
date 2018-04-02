#include "Matriz.h"
#include <iostream>

using namespace std;

int main()
{
	int opcion = 0;
	while (opcion != 5)
	{
		opcion = 0;
		cout << "\n\n*** O P E R A C I O N E S  C O N  M A T R I C E S ***\n\n";

		cout << "1 - Suma de Matrices" << endl;
		cout << "2 - Resta de Matrices" << endl;
		cout << "3 - Multiplicacion de Matrices" << endl;
		cout << "4 - Determinantes" << endl;
		cout << "5 - Salir" << endl;

		cout << "\nIngrese la opcion: \n";
		cin >> opcion;

		if (opcion == 1)
		{
			Matriz MatrizA;
			Matriz MatrizB;
			MatrizA.setMatriz();
			MatrizB.setMatriz();
			MatrizA.guardarMatriz(MatrizA.sumaMatrices(&MatrizB));
		}
		if (opcion == 2)
		{
			Matriz MatrizA;
			Matriz MatrizB;
			MatrizA.setMatriz();
			MatrizB.setMatriz();
			MatrizA.guardarMatriz(MatrizA.restaMatrices(&MatrizB));
		}
		if (opcion == 3)
		{
			Matriz MatrizA;
			Matriz MatrizB;
			MatrizA.setMatriz();
			MatrizB.setMatriz();
			MatrizA.guardarMatriz(MatrizA.multipMatrices(&MatrizB));
		}
		if (opcion == 4)
		{
			Matriz MatrizA;
			MatrizA.setMatriz();
			int det = MatrizA.determinante();
			if (MatrizA.determinante() != -1)
				cout << "El determinante de la matriz es: " << det << endl;
		}
	}


	system("pause");

	return 0;
}