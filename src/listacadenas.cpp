#include "listacadenas.h"



void inicializar(tListaCadenas & l) {
	for (int i = 0; i < MAXCAD -1 ; i++)
		l.datos[i] = "";
	l.tam = 0;
}

int getTamanno(const tListaCadenas & l) {// te deja elegi si usarlo o no 
	
	int tamanno = 0;
	for (int i = 0; i < MAXCAD-1; i++){
		if (l.datos[i] != "")
			tamanno++;
	}
	return tamanno;
}

string getCadena(const tListaCadenas & l, int pos) {
	return l.datos[pos];
}

void insertar(tListaCadenas &lista, const string & s) {// inserta un elemento al final de la lista
	int posInvalida;
	if (!buscar(lista,s, posInvalida)) {
		if (getTamanno(lista) == 0)
			lista.tam = 0;
		lista.datos[lista.tam] = s;
		lista.tam++;
	}
}

bool buscar(const tListaCadenas &l, const string &s, int & pos) {// busca una cadena en la lista
	
	bool encontrado = false;
	int i = 0;
	while (i < l.tam && !encontrado) {
		if (l.datos[i] == s) {
			encontrado = true;
			pos = i;
		}
		else i++;
	}
	
	return encontrado;
}



void eliminar(tListaCadenas & l, int pos) {// elimina el elemento en la posicon pos

	for (int i = pos; i < l.tam; i++)//desplaza desde pos +1 uno hacia atras hata l.cont
		l.datos[i] = l.datos[i + 1];
	l.tam--;//disminuimos el contador

}

ostream & operator << (ostream & salida, const tListaCadenas & l) {
	salida << "[";
	for (int i = 0; i < l.tam; i++){
		salida << l.datos[i]  ;
		if (i != l.tam - 1)
			salida << ", ";
	}
	salida << "]" << endl;
	return salida;
}
