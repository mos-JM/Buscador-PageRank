#ifndef clavevalor_h
#define clavevalor_h
#include "listacadenas.h"

#include <string>
#include<iostream>
#include <iomanip>

using namespace std;

const int MAX_CLAVES = 3;

//typedef tListaCadenas *tListaCadPtr;

typedef struct {
	string clave;
	tListaCadenas valor;
	//tListaCadPtr valor;
}tRegistroIndiceClaves;

typedef tRegistroIndiceClaves *tArrayPtr;

typedef struct {
	tArrayPtr lista;
	int tam, capacidad;
}tIndicePalabras;

void inicializar(tIndicePalabras & idx);
int getTamanno(const tIndicePalabras & l);//Devuelve el tamaño de la tabla.
tRegistroIndiceClaves getRegistro(const tIndicePalabras & l, int pos);// Devuelve el registro en la posición pos.
int esta(const tIndicePalabras & l, const string & s, int ini, int fin, bool &encontrado);//Devuelve true si la palabra es una clave en la tabla, y false en caso contrario.
tListaCadenas buscar(const tIndicePalabras & l, const string & s);//dada una clave que está en la tabla devuelve la lista de cadenas asociada a esa clave.
void insertar(tIndicePalabras & idx, const string &palabra, const string &nombreArchivo); // Si palabra es ya una clave de la tabla, añade nombreArchivo a la lista de archivos correspondiente.Si no, crea un registro nuevo con esa información.
//void imprimir(const tIndicePalabras & idx);// Imprime la tabla.
ostream & operator << (ostream & salida, const tIndicePalabras & idx);
void ampliar(tIndicePalabras & idx); // amplia de forma dinamica nuestro array
void destruir(tIndicePalabras & idx); // hacemos delete de la lista y ponemos el tamaño a 0

#endif // !clavevalor_h
