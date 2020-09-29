#include <iostream>
using namespace std;

void define_size();
void add_values();
void adding_matrices();
void subtract_matrices();
void multiplier_matrices();
void transpose_matrix();
void show_matrix_silla();

int menu;
const int a = 10;
const int b = 10;
int matriz1[a][b];
const int c = 10;
const int d = 10;
int matriz2[c][d];
const int k = 10;
const int l = 10;
int matriz3[k][l];
int e, f, g, h;
int aux, m;

const int n = 10;
int silla_filas[n];
int silla_columnas[n];

int main()
{
	do
	{
		cout << "Matriz 1: " << e << "x" << f << " Matriz 2: " << g << "x" << h << endl;
		cout << endl;
	    cout << "1. Ingresar tamanio de las matrices." << endl;
	    cout << "2. Agregar valores." << endl;
	    cout << endl;
	    cout << "3. Sumar matrices." << endl;
	    cout << "4. Restar matrices." << endl;
	    cout << "5. Multiplicar matrices." << endl;
	    cout << "6. Trasponer una matriz." << endl;
	    cout << "7. Mostrar matriz y senialar cuales son los puntos de silla." << endl;
	    cout << endl;
	    cout << "0. Salir." << endl;
	    cout << endl;
	    cout << "Digite una opcion: ";
	    cin >> menu;
	    cout << endl;

	    switch(menu)
	    {
	    	case 1:

	    	define_size();

	    	break;
	    	case 2:

	    	add_values();

	    	break;
	    	case 3:

	    	if((e == g) && (f == h))
	    	{
	    		adding_matrices();
	    	}
	    	else
	    	{
	    		cout << "No se pueden sumar estas dos matrices: sus dimenciones son diferentes." << endl;
	    	}

	    	break;
	    	case 4:

	    	if((e == g) && (f == h))
	    	{
	    		subtract_matrices();
	    	}
	    	else
	    	{
	    		cout << "No se pueden restar estas dos matrices: sus dimenciones son diferentes." << endl;
	    	}

	    	break;
	    	case 5:

	    	if(f==g)
	    	{
	    		multiplier_matrices();
	    	}
	    	else
	    	{
	    		cout << "No se pueden multiplicar las matrices: el numero de columnas de la primera no coinicide con el unumero de filas de la segunda." << endl;
	    	}

	    	break;
	    	case 6:

	    	transpose_matrix();

	    	break;
	    	case 7:

	    	show_matrix_silla();
	    	
	    	break;
	    	case 0:

	    	cout << "El programa se esta cerrando." << endl;

	    	break;
	    	default:
	    	cout << "No ingreso una opcion valida. vuelva a intentar." << endl;
	    }
	}while(menu!=0);

	return 0;
}

void define_size()
{
	cout << "Ingrese el numero de filas para la primera matriz: ";
	cin >> e;
	cout << "Ingrese el numero de columnas de la primera matriz: ";
	cin >> f;
	cout << "Ingrese el numero de filas para la segunda matriz: ";
	cin >> g;
	cout << "Ingrese el numero de columnas para la segunda matriz: ";
	cin >> h;
	cout << endl;
}

void add_values()
{
	for(int i=0; i<e; i++)
	{
		for(int j=0; j<f; j++)
		{
			cout << "Ingrese el valor " << i << "x" << j << endl;
			cin >> matriz1[i][j];
		}
	}
	for(int i=0; i<g; i++)
	{
		for(int j=0; j<h; j++)
		{
			cout << "Ingrese el valor " << i << "x" << j << endl;
			cin >> matriz2[i][j];
		}
	}
}

void adding_matrices()
{
	for (int i=0; i<e ; i++)
	{
		for(int j=0; j<f; j++)
		{
			matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
		}
	}
	for(int i=0; i<e; i++)
	{
		for(int j=0; j<f; j++)
		{
			cout << matriz3[i][j] << " ";
			if(f == j+1)
			{
				cout << endl;
			}
		}
	}

	cout << endl;
}

void subtract_matrices()
{
	for(int i=0; i<e ; i++)
	{
		for(int j=0; j<f ; j++)
		{
			matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
		}
	}
	for(int i=0; i<e ; i++)
	{
		for(int j=0; j<f ; j++)
		{
			cout << matriz3[i][j] << " ";
			if(f == j+1)
			{
				cout << endl;
			}
		}
	}

	cout << endl;
}

void multiplier_matrices()
{
	for(int i=0; i<e ; i++)
	{
		m = 0;

		while(m<h)
		{
			aux = 0;

			for(int j=0; j<e ; j++)
			{
				aux += matriz1[i][j] * matriz2[j][m];
			}

			matriz3[i][m] = aux;

			m++;
		}
	}

	for(int i=0; i<e; i++)
	{
		for(int j=0; j<h ; j++)
		{
			cout << matriz3[i][j] << " ";

			if(h == j+1)
			{
				cout << endl;
			}
		}
	}

	cout << endl;
}

void transpose_matrix()
{
	cout << "Ingrese el numero de matriz a trasponer: ";
	cin >> menu;

	switch(menu)
	{
		case 1:

		for(int i=0; i<e ; i++)
		{
			for(int j=0; j<f ; j++)
			{
				matriz3[j][i] = matriz1[i][j];
			}
		}
		for(int i=0; i<f; i++)
		{
			for(int j=0; j<e ; j++)
			{
				cout << matriz3[i][j] << " ";

				if(e == j+1)
				{
					cout << endl;
				}
			}
		}

		break;
		case 2:

		for(int i=0; i<g ; i++)
		{
			for(int j=0; j<h ; j++)
			{
				matriz3[j][i] = matriz2[i][j];
			}
		}
		for(int i=0; i<h ; i++)
		{
			for(int j=0; j<g ; j++)
			{
				cout << matriz3[i][j] << " ";

				if(g == j+1)
				{
					cout << endl;
				}
			}
		}

		break;
		default:

		cout << "No ingreso una opcion valida. Vuelva a intentar." << endl;
	}
}

void show_matrix_silla()
{
	cout << "Ingrese el numero de la matriz a procesar: " << endl;
	cout << "Matriz 1: " << e << "x" << f << endl;
	cout << "Matriz 2: " << g << "x" << h << endl;
	cout << endl;
	cin >> menu;

	switch(menu)
	{
		case 1:

		for(int i=0; i<e ; i++)
		{
			for(int j=0; j<f ; j++)
			{

				if(silla_filas[i] < matriz1[i][j])
				{
					silla_filas[i] = matriz1[i][j];
				}
			    if(silla_columnas[j] > matriz1[i][j])
			    {
				    silla_columnas[j] = matriz1[i][j];
			    }
		    }
	    }
	    for(int i = 0; i<e ;i++)
	    {
		    for(int j = 0; j<f ; j++)
		    {
			    if(silla_filas[i] == silla_columnas[j])
			    {
			    	cout << "Punto de silla en: " << i << ", " << j << endl;
			    }
			    else
			    {
			    	cout << "No se encontro un punto silla en la matriz." << endl;
			    }
		    }
	    }

		break;
		case 2:

		for(int i=0; i<g ; i++)
		{
			for(int j=0; j<h ; j++)
			{
				if(silla_filas[i] < matriz2[i][j])
				{
					silla_filas[i] = matriz2[i][j];
				}
			    if(silla_columnas[j] > matriz2[i][j])
			    {
				    silla_columnas[j] = matriz2[i][j];
			    }
		    }
	    }
	    for(int i = 0; i<g ;i++)
	    {
		    for(int j = 0; j<h ; j++)
		    {
			    if(silla_filas[i] == silla_columnas[j])
			    {
			    	cout << "Punto de silla en: " << i << ", " << j << endl;
			    }
			    else
			    {
			    	cout << "No se encontro un puto silla en la matriz." << endl;
			    }
		    }
	    }

		break;
		default:

		cout << "No ingreso una opcion valida. Vuelva a intentar." << endl;
	}
	
}