#ifndef clavevalor_h
#define clavevalor_h
#include "listacadenas.h"

#include <string>
#include<iostream>
#include <iomanip>

using namespace std;

const int MAX_CLAVES = 50;

typedef struct {
	string clave;
	tListaCadenas valor;
}tRegistroIndiceClaves;

typedef struct {
	tRegistroIndiceClaves lista[MAX_CLAVES];
	int tam;
}tIndicePalabras;

void inicializar(tIndicePalabras & l);
int getTamanno(const tIndicePalabras & l);//Devuelve el tama�o de la tabla.
tRegistroIndiceClaves getRegistro(const tIndicePalabras & l, int pos);// Devuelve el registro en la posici�n pos.
bool esta(const tIndicePalabras & l, const string & s, int & pos);//Devuelve true si la palabra es una clave en la tabla, y false en caso contrario.
tListaCadenas buscar(const tIndicePalabras & l, const string & s);//dada una clave que est� en la tabla devuelve la lista de cadenas asociada a esa clave.
void insertar(tIndicePalabras & idx, const string &palabra, const string &nombreArchivo); // Si palabra es ya una clave de la tabla, a�ade nombreArchivo a la lista de archivos correspondiente.Si no, crea un registro nuevo con esa informaci�n.
void imprimir(const tIndicePalabras & idx);// Imprime la tabla.
ostream & operator << (ostream & salida, const tIndicePalabras & idx);

#endif // !clavevalor_h
