#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string frase;
string palabras;

int main()
{
	cout << "Introduce una frase para procesar: ";
	getline(cin, frase);

	ofstream oup_file;
	oup_file.open("frase.txt", ios::out);
	if(oup_file.is_open())
	{
		oup_file << frase;
	}
	oup_file.close();

	ifstream imp_file;
	imp_file.open("frase.txt", ios::in);
	if(imp_file.is_open())
	{
		while(!imp_file.eof())
		{
			imp_file >> palabras;
			cout << palabras << " -> numero de letras: " << palabras.length() << endl;
		}
	}
	imp_file.close();

	cin.get();

	return 0;
}