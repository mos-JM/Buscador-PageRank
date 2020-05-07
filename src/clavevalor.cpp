#include "clavevalor.h"

void inicializar(tIndicePalabras & l) {
	for (int i = 0; i < MAX_CLAVES; i++) //inicializo todo a espacios en blanco para despues en gettammaño saber si tamaño
		l.lista[i].clave = " ";
	l.tam = 0;
}

int getTamanno(const tIndicePalabras & l) {// te deja elegi si usarlo o no 
	
	int tamanno = 0;
	for (int i = 0; i < MAX_CLAVES - 1; i++) {
		if (l.lista[i].clave != " ")
			tamanno++;
	}
	return tamanno;
}

tRegistroIndiceClaves getRegistro(const tIndicePalabras & l, int pos) {// Devuelve el registro en la posición pos.
	tRegistroIndiceClaves h;
	h.valor = l.lista[pos].valor;
	return h;
}

bool esta(const tIndicePalabras & l, const string & s, int &pos) { //Devuelve true si la palabra es una clave en la tabla, y false en caso contrario.
	int ini = 0, fin = l.tam - 1, mitad = 0;
	bool encontrado = false;

	while ((ini <= fin) && !encontrado) {
		pos = (ini + fin) / 2;
		if (s == l.lista[pos].clave)
			encontrado = true;
		else if (s < l.lista[pos].clave)
			fin = pos - 1;
		else
			ini = pos + 1;
	}
	if(ini > fin)
		pos = ini;
	return encontrado;
} 

tListaCadenas buscar(const tIndicePalabras & l, const string & s){
	tListaCadenas listaCadena;
	bool encontrado = false;
	int i = 0;
	while (i < l.tam && !encontrado) {
		if (l.lista[i].clave == s) {
			listaCadena = getRegistro(l, i).valor;
			encontrado = true;
		}
		else
			i++;
	}
		
	return listaCadena;
}

void insertar(tIndicePalabras & idx, const string & palabra, const string & nombreArchivo){
	tListaCadenas listaBuscada;
	int i = 0;
	if (idx.tam == MAX_CLAVES) {
		cout << " Lista llena" << endl;
	}
	else {
		// i es el valor pos  de la función esta
		if (!esta(idx, palabra,i)) {
			

			// Insertamos en la posicion i
			for (int j = idx.tam; j > i; j--) { // Desplazamos a la derecha
				idx.lista[j] = idx.lista[j - 1];
			}
			idx.lista[i].valor.tam = 0;
			idx.lista[i].clave = palabra;
			insertar(idx.lista[i].valor, nombreArchivo);
			idx.tam++;
		}
		else {
			insertar(idx.lista[i].valor, nombreArchivo);
		}
	}
}

/*void imprimir(const tIndicePalabras & idx){
	cout << "Esta tabla de indices tiene un tamaño: " << idx.tam << "\n\n" ;
	cout << setw(16) << "Clave " << " - " << " Indice \n\n";
	for (int i = 0; i < idx.tam; i++) {
		cout << setw(15) << idx.lista[i].clave << "  -  ";
		cout << idx.lista[i].valor ;
	}
	cout << endl;

}*/

ostream & operator << (ostream & salida, const tIndicePalabras & idx) {
	salida << "Esta tabla de indices tiene un tamaño: " << idx.tam << "\n\n";
	salida << setw(16) << "Clave " << " - " << " Indice \n\n";
	for (int i = 0; i < idx.tam; i++) {
		salida << setw(15) << idx.lista[i].clave << "  -  ";
		salida << idx.lista[i].valor;
	}
	salida << endl;
	return salida;
}

