#include "listacadenas.h"



void inicializar(tListaCadenas & l) {
	l.datos = new string[MAXCAD];
	l.capacidad = MAXCAD;
	
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
	int pos;
	if (!buscar(lista,s, pos)) {
		if(lista.tam < lista.capacidad)
			lista.datos[pos] = s;
		else {
			ampliar(lista);
			lista.datos[pos] = s;
		}
		lista.tam++;
		/*if (getTamanno(lista) == 0)
			lista.tam = 0;
		lista.datos[lista.tam] = s;
		lista.tam++;*/
	}
}

bool buscar(const tListaCadenas &l, const string &s, int & pos) {// busca una cadena en la lista
	
	bool encontrado = false;
	int i = 0;
	while (i < l.tam && !encontrado) {
		if (l.datos[i] == s) {
			encontrado = true;
			
		}
		else i++;
	}
	pos = i;
	
	return encontrado;
}



void eliminar(tListaCadenas & l, int pos) {// elimina el elemento en la posicon pos

	for (int i = pos + 1; i < l.tam; i++)//desplaza desde pos +1 uno hacia atras hata l.cont
		l.datos[i - 1] = l.datos[i];
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

void ampliar(tListaCadenas & l){
	string * aux = nullptr;

	aux = new string[(l.capacidad * 3) / 2 + 1];
	for (int i = 0; i < l.tam; i++){
		aux[i] = l.datos[i];
	}
	delete[] l.datos; // 
	l.datos = aux;
	l.capacidad = (l.capacidad * 3) / 2 + 1;
	aux = nullptr;

}

void destruir(tListaCadenas & l){
	delete[] l.datos;
	l.tam = 0;
}


