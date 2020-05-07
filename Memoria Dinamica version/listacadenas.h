#ifndef listacadena_h
#define listacadena_h
#include <iostream>
#include <string>

using namespace std;

const int MAXCAD = 3;

typedef string  *tArrayCadenas ;

typedef struct {
	tArrayCadenas datos; //representa la lista de archivos donde podemos encontrar cada palabra
	int tam, capacidad;
}tListaCadenas;



void inicializar(tListaCadenas & l); // inicializa a espacios todo el array;
int getTamanno(const tListaCadenas & l); // devuelve el tamño de la lista
string getCadena(const tListaCadenas & l, int pos); //devuelve una cadena en la posicion pos
void insertar(tListaCadenas &l, const string & s); // inserta un elemento al final de la lista
bool buscar(const tListaCadenas &l, const string &s, int & pos); // busca una cadena en la lista
void eliminar(tListaCadenas & l, int pos);// elimina el elemento en la posicon pos
ostream & operator << (ostream & salida, const tListaCadenas & l);// hace lo mismo que imprimir
void ampliar(tListaCadenas & l); // amplia de forma dinamica nuestro array
void destruir(tListaCadenas & l); // hacemos delete de la lista y ponemos el tamaño a 0


#endif // !listacadena_hz
