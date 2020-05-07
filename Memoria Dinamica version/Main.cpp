/*
/**
*
* Buscar (de información con memoria dinamica)
* @autor Agustín Jofre Millet
**/


/*fallos de la practica anterior corregidos*/


#include <iostream>
#include <string>
#include "indices.h"
#include "matriz.h"
#include "checkML.h"

using namespace std;

string pedirArchivo();
string pedirPalabra();
int menu();
bool comprobacionTipo(int tipo);
tVector valoresSubLista(tListaCadenas & lista, tListaCadenas &totales, tVector v);
void ordenar(tListaCadenas &lista, tVector &v);
void mostrar(tListaCadenas &lista, tVector &v);


int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	tIndicePalabras idx;
	nuevoIndice(idx); 
	tListaCadenas enlasePalabra, totales;
	tMatriz L;
	string nombreArchivo;
	string palabra;
	bool archivoTabla;
	
	do {
		nombreArchivo = pedirArchivo();
		cout << "Cargando..." << endl;
		creartabla(idx, nombreArchivo, totales, L, archivoTabla);
	} while (!archivoTabla);
	
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
					tVector valores = valoresSubLista(enlasePalabra, totales, v);
					ordenar(enlasePalabra, valores);
					mostrar(enlasePalabra, valores);

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
	
	// destruye lista cadenas
	for (int i = 0; i < idx.tam; i++){
		destruir(idx.lista[i].valor);	
	}
	destruir(totales);

	// destruimos lista clave-valor
	destruir(idx);
	
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


tVector valoresSubLista(tListaCadenas & lista, tListaCadenas &totales, tVector v) {
	tVector subVector;
	subVector.tam = v.tam;
	int i = 0;
	while (i <lista.tam) {
		int j = 0;
		while (j <  totales.tam) {
			if (lista.datos[i] == totales.datos[j]) {
				subVector.vector[i] = v.vector[j];
				//cout << "PR del archivo " << lista.datos[i] << " Relevancia (" << v.vector[j] << ")" << endl;
			}
			j++;
		}
		i++;
		
	}
	cout << endl;
	return subVector;
}


void ordenar(tListaCadenas &lista, tVector &v) {
	for (int i = 1; i < lista.tam; i++){
		int pos = i;
		while (pos > 0 && v.vector[pos - 1] < v.vector[pos]) {
			double tmp;
			tmp = v.vector[pos];
			v.vector[pos] = v.vector[pos - 1];
			v.vector[pos - 1] = tmp;

			string tmpCadenas = lista.datos[pos];
			lista.datos[pos] = lista.datos[pos - 1];
			lista.datos[pos - 1] = tmpCadenas;
			pos--;
		}
	}
}

void mostrar(tListaCadenas & lista, tVector & v){
	cout << "Los valores de esa lista son: " << endl;
	for (int i = 0; i < lista.tam; i++){
		cout << lista.datos[i] << setw(5) << "  (" << v.vector[i] << ")" << endl;
	}
	cout << endl;
}
