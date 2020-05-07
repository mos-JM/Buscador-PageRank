/**
*
* Buscar (de información)
* @autor Agustín Jofré Millet
**/

#include <iostream>
#include <string>
#include "indices.h"
#include "matriz.h"


using namespace std;

string pedirArchivo();
string pedirPalabra();
int menu();
bool comprobacionTipo(int tipo);
void valoresSubLista(tListaCadenas & lista, tListaCadenas totales, tVector v);


int main() {
	tIndicePalabras idx = nuevoIndice(); 
	tListaCadenas enlasePalabra, totales;
	tMatriz L;
	string nombreArchivo = pedirArchivo();
	string palabra;
	bool archivoTabla;
	cout << "Cargando..." << endl;
	creartabla(idx, nombreArchivo, totales, L, archivoTabla);

	while (!archivoTabla) {
		nombreArchivo = pedirArchivo();
		cout << "Cargando..." << endl;
		creartabla(idx, nombreArchivo, totales, L, archivoTabla);
	}
	cout << "Creando tablas...[CORRECTO]" << endl;

	tMatriz M =desdeEnlacesAMatriz(L);

	tVector v = vectorPropio(M);
	
	int op = menu();
	
	while (op != 0) {
		switch (op) {
		case 1: 
			cout << idx;
			break;
		case 2:
			imprimirMatriz(L);
			break;
		case 3: 
			imprimirMatriz(M);
			break;
		case 4:
			imprimir(v);
			break;
		case 5:
			palabra = pedirPalabra();
			while (palabra != "fin") {
				enlasePalabra = buscar(idx, palabra); // devulve el listacadenas repecto a esa palabra.
				if (enlasePalabra.tam > 0) {
					cout << "Encontrada en archivos : " << enlasePalabra << endl;
					valoresSubLista(enlasePalabra, totales, v);
				}
				else
					cout << "La palabra que buscas no esta en la lista " << endl;
			
				palabra = pedirPalabra();
			}
			break;
		case 6:
			ofstream archivo;
			archivo.open("Tabla.txt");
			archivo << idx;
			cout << "Archivo creado\n\n";
			archivo.close();

		}
		op = menu();
	}

	
	
	
	system("pause");
	return 0;
}

string pedirArchivo() {
	string archivo;
	cout << "Por favor, introduzca el nombre del fichero raiz a partir del que se creara el indice : ";
	cin >> archivo;
	return archivo;
}

string pedirPalabra() {
	string palabra;
	cout << "Introduzca la palabra que desea buscar (fin para terminar): ";
	cin >> palabra;
	cout << endl;
	return palabra;
}

int menu() {
	int op;
	do {
		cout << "\n";
		cout << setw(35) << "1 . Ver Tabla de indices" << endl;
		cout << setw(43) << "2 . Ver Matriz de adyacencia (L)" << endl;
		cout << setw(36) << "3 . Ver Matriz Google (M)" << endl;
		cout << setw(32) << "4 . Ver vector V (PR)" << endl;
		cout << setw(34) << "5 . Buscar en el indice" << endl;
		cout << setw(30) << "6 . Crear Tabla.txt" << endl;
		cout << setw(25) << "0 . Para salir" << endl;
		cout << setw(23) << "Opcion: ";
		cin >> op;
		cout << "\n";
		comprobacionTipo(op);
	} while (op < 0 || op > 6);

	return op;
}

bool comprobacionTipo(int tipo) {  //comprueba si cin es un entero
	bool ok = true;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		ok = false;
	}
	return ok;
}


void valoresSubLista(tListaCadenas & lista, tListaCadenas totales, tVector v) {
	int i = 0;
	while (i <lista.tam) {
		int j = 0;
		while (j <  totales.tam) {
			if (lista.datos[i] == totales.datos[j]) {
				cout << "PR del archivo " << lista.datos[i] << " Relevancia (" << v.vector[j] << ")" << endl;
			}
			j++;
		}
		i++;
		
	}
	cout << endl;
	
}
