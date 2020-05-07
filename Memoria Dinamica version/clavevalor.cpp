#include "clavevalor.h"

void inicializar(tIndicePalabras & idx) {
	
	idx.lista = new tRegistroIndiceClaves[MAX_CLAVES];
	idx.capacidad = MAX_CLAVES;

	for (int i = 0; i < MAX_CLAVES; i++) //inicializo todo a espacios en blanco para despues en gettammaño saber si tamaño
		idx.lista[i].clave = " ";
	idx.tam = 0;


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

int esta(const tIndicePalabras & l, const string & s, int ini, int fin, bool &encontrado) { //Devuelve true si la palabra es una clave en la tabla, y false en caso contrario.
	int pos = -1;
	if (ini <= fin) {
		int mitad = (ini + fin) / 2;
		if (s == l.lista[mitad].clave) {
			pos = mitad;
			encontrado = true;
		}
		else if (s < l.lista[mitad].clave) {
			pos = esta(l, s, ini, mitad-1, encontrado);
		}
		else
			pos = esta(l, s, mitad+1, fin, encontrado);
	}

	if(ini > fin)
		pos = ini;
	return pos;
} 



tListaCadenas buscar(const tIndicePalabras & l, const string & s){
	tListaCadenas listaCadena;
	bool encontrado = false;
	int i = 0;
	while (i < l.tam && !encontrado) {
		if (l.lista[i].clave == s) {
			listaCadena = (getRegistro(l, i)).valor;
			encontrado = true;
		}
		else
			i++;
	}
		
	return listaCadena;
}

void insertar(tIndicePalabras & idx, const string & palabra, const string & nombreArchivo){
	//tListaCadenas listaBuscada;
	int i = 0;
	/*if (idx.tam == MAX_CLAVES) {
		cout << " Lista llena" << endl;
	}
	else {*/
		bool encontrado = false;
		i = esta(idx, palabra, 0, idx.tam - 1, encontrado);
		if (!encontrado) {
			if (idx.tam >= idx.capacidad)
				ampliar(idx);
			// Insertamos en la posicion i
			for (int j = idx.tam; j > i; j--) { // Desplazamos a la derecha
				idx.lista[j] = idx.lista[j - 1];
			}
			
			inicializar((idx.lista[i].valor));
			
			idx.lista[i].clave = palabra;
			insertar(idx.lista[i].valor, nombreArchivo);
			idx.tam++;
		}
		else {
			insertar(idx.lista[i].valor, nombreArchivo);
		}
		
	//}
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

void ampliar(tIndicePalabras & idx){
	tRegistroIndiceClaves * aux = nullptr;

	aux = new tRegistroIndiceClaves[(idx.capacidad * 3) / 2 + 1];
	for (int i = 0; i < idx.tam; i++) {
		aux[i] = idx.lista[i];
	}
	delete[] idx.lista; // 
	idx.lista = aux;
	idx.capacidad = (idx.capacidad * 3) / 2 + 1;
	aux = nullptr;

}

void destruir(tIndicePalabras & idx){
	delete[] idx.lista;
	idx.tam = 0;
}

