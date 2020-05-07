#include "indices.h"
#include <algorithm>
#include <cctype>

void creartabla(tIndicePalabras & tabla, const string & archivo, tListaCadenas &totales, tMatriz &L, bool &ok) { // v2 listaCadenas &totales, tMatriz &L
	tListaCadenas visitados;
	tListaCadenas noVisitados;

	string fileNext;
	int j = 0;

	inicializar(visitados);
	inicializar(noVisitados);
	inicializar(totales);
	insertar(noVisitados, archivo);
	insertar(totales, noVisitados.datos[0]);
	L = matrizConstante(0.0, totales.tam, L);
	L.col = 0;
	L.rows = 0;

	while (noVisitados.tam > 0) {
		
		fileNext = noVisitados.datos[0];
		insertar(visitados, noVisitados.datos[0]);
		eliminar(noVisitados, 0); // elimina el primero
		procesar(noVisitados, visitados, tabla, fileNext, totales, L, ok);
		L.rows++;
		L.col++;
	}
	destruir(visitados);
	destruir(noVisitados);
}

void procesar(tListaCadenas & noVisitado, tListaCadenas & visitado, tIndicePalabras & idx, string  archivo, tListaCadenas &totales, tMatriz &L, bool &ok){
	ifstream entrada;
	entrada.open(archivo);
	string linea;
	if (entrada.fail()) {
		cout << "[INCORRECTO]" << endl;
		ok = false;
	}
	else {
		ok = true;
		while (!entrada.eof()) {
			entrada >> linea;
			procesarLinea(linea, visitado, noVisitado, idx, archivo, totales, L);
			
		}
	}
	entrada.close();

}

void procesarLinea(string linea, tListaCadenas & vis, tListaCadenas & noVis, tIndicePalabras &idx, string & archivo, tListaCadenas &totales, tMatriz &L){

	
	string clave = "" ;
	int i = 0;
	string enlase;

	
			int j = 0;
			while (j < linea.length()){
				if (linea[j] == '<'){
					j++;
					while (linea[j] != '>'){
						enlase += linea[j];
						j++;
					}
					//string enlase = linea.substr(i+1, j -1 );
					std::transform(enlase.begin(), enlase.end(), enlase.begin(), std::tolower);
					if (!buscar(totales, enlase, i)) {// i es la pos donde esta el enlase 
						insertar(noVis, enlase);
						insertar(totales, enlase);
						L = matrizConstante(0.0, totales.tam, L);
						L.matriz[totales.tam - 1][L.col] = 1;
					}
					else {
						L.matriz[i][L.col] = 1;

					}
					enlase = "";
					
					
				}
				else {
					if (!ispunct(linea[j])) {
						bool mas;
						for (int i = 0; i < linea.length(); i++) {
							mas = false;
							if (!ispunct(linea[i]))
								clave += linea[i];
							else {
								mas = true;
								if (clave != "") {
									std::transform(clave.begin(), clave.end(), clave.begin(), std::tolower);
									insertar(idx, clave, archivo);
									clave = "";
								}
							}
							j = i + 1;
						}
						if (!mas) {
							std::transform(clave.begin(), clave.end(), clave.begin(), std::tolower);
							insertar(idx, clave, archivo);
						}
					}
				}
				j++;
			}
		
}

void nuevoIndice(tIndicePalabras &newIndice){
	inicializar(newIndice);
}

void imprimirMatriz(tMatriz &L) {
	cout << setw(15) << "Matriz :" << endl;
	for (int i = 0; i < L.rows; i++){
		cout << setw(15);
		for (int j = 0; j < L.rows; j++) {
			cout << L.matriz[i][j] ;
			if (j < L.rows - 1)
				cout << "," ;
			cout << setw(10);
		}
		cout << endl;
	}
}

