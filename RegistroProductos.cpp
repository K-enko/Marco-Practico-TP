#include <iostream>
#include <fstream>
using namespace std;

struct tproducto
{
	int idprod;
	double precio;
	int inventario;
};

void load_data();
void save_data();
void show_data();
void show_highest_value();
void delate_data();
void remplace_data();

const int N = 30;
tproducto tproductos[N];
int cont;
int menu;
double hvalue, hvalue_f;
int hvaluef_pos;
int idselec;
int j;

int main()
{
	do
	{
		load_data();

		cout << endl;
		cout << "1. Agregar producto." << endl;
		cout << "2. Ver lista de productos." << endl;
		cout << "3. Ver el valor mas alto en el almacen." << endl;
		cout << "4. Eliminar registro de un porducto." << endl;
		cout << endl;
		cout << "0. Salir." << endl;
		cout << endl;
		cout << "indique su accion: ";
		cin >> menu;
		cin.ignore();

		switch(menu)
		{
			case 1:

			if(cont < N)
			{
				save_data();
			}
			else
			{
				cout << "No se puede ingresar mas productos al almacen. Valor maximo alcanzado: 30." << endl;
			}

			break;
			case 2:

			show_data();

			break;
			case 3:

			show_highest_value();

			break;
			case 4:

			delate_data();

			break;
			case 0:
		
			cout << "El programa se esta cerrando..." << endl;

			break;
			default:

			cout << "No ingreso un valor valido entre las opciones. Vuelva a intentar." << endl;
		}
	}while(menu != 0);

	cin.get();

	return 0;
}

void load_data()
{
	cont = 0;

	ifstream imp_file;
	imp_file.open("Productos.txt", ios::in);
	if(imp_file.is_open())
	{
		while(!imp_file.eof())
		{
			imp_file >> tproductos[cont].idprod;
			imp_file >> tproductos[cont].precio;
			imp_file >> tproductos[cont].inventario;

			if((tproductos[cont].idprod != 0) && (tproductos[cont].precio != 0) && (tproductos[cont].inventario != 0))
			{
				cont++;
			}
		}
	}
	imp_file.close();
}

void save_data()
{
	cout << "Ingrese el id del producto a guardar: ";
	cin >> tproductos[cont].idprod;
	cout << "Ingrese el precio del producto: ";
	cin >> tproductos[cont].precio;
	cout << "Ingrese el inventario disponible: ";
	cin >> tproductos[cont].inventario;

	ofstream oup_file;
	oup_file.open("Productos.txt", ios::app);
	if(oup_file.is_open())
	{
		oup_file << tproductos[cont].idprod << " " << tproductos[cont].precio << " " << tproductos[cont].inventario << endl;
	}
	oup_file.close();

	cont++;
}

void show_data()
{
	for(int i = 0; i < cont; i++)
	{
		cout << "----------------------------------------------" << endl;
		cout << "ID: " << tproductos[i].idprod << " precio: $" << tproductos[i].precio << " Inventario disponible: " << tproductos[i].inventario << endl;
		cout << "----------------------------------------------" << endl;
	}
}

void show_highest_value()
{
	for(int i = 0; i < cont; i++)
	{
		hvalue = tproductos[i].precio * tproductos[i].inventario;

		if(hvalue_f < hvalue)
		{
			hvalue_f = hvalue;

			hvaluef_pos = i;
		}
	}

	cout << "el valor en productos mas altos en el almacen es de:" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "ID: " << tproductos[hvaluef_pos].idprod << " precio: $" << tproductos[hvaluef_pos].precio << " Inventario disponible: " << tproductos[hvaluef_pos].inventario << endl;
	cout << "----------------------------------------------" << endl;
	cout << "con un valor total de: $" << hvalue_f << endl;
	cout << endl;
}

void delate_data()
{
	show_data();

	cout << "Ingrese el id del producto a eliminar: ";
	cin >> idselec;

	while((j < cont)&&(tproductos[j].idprod != idselec))
	{
		j++;
	}
	if(idselec == tproductos[j].idprod)
	{
		for(int i = j; i<cont ; i++)
		{
			tproductos[i].idprod = tproductos[i+1].idprod;
			tproductos[i].precio = tproductos[i+1].idprod;
			tproductos[i].inventario = tproductos[i+1].idprod;
		}
	}

	--cont;

	remplace_data();
}

void remplace_data()
{
	ofstream oup_file;
	oup_file.open("Productos.txt", ios::out);
	if(oup_file.is_open())
	{
		for(int i=0; i<cont; i++)
		{
			oup_file << tproductos[i].idprod << " " << tproductos[i].precio << " " << tproductos[i].inventario << endl;
		}
	}
	oup_file.close();
}