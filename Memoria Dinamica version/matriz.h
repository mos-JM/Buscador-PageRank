#ifndef matriz_h
#define matriz_h
#include <iostream>
#include <iomanip>

using namespace std;

//constantes y tipos def
const int MAX_TAM = 10;
const double C = 0.85;

typedef struct {
	double matriz[MAX_TAM][MAX_TAM];
	int rows, col;
} tMatriz;


typedef struct {
	int tam;
	double vector[MAX_TAM];

} tVector;

//cabecera metodos

tMatriz matrizConstante(double x, int n, tMatriz & L); // crea matriz n.n con valores iniciales x
tVector operator*(const tMatriz & m, const tVector & v); //multiplica una matriz por un vector
tMatriz operator*(double x, const tMatriz & m); // mul cada elemento de m por x
tMatriz operator+(const tMatriz & m1, const tMatriz & m2); //suma 2 matrices
//tVector operator/(const tVector & v, const tVector & m);
tMatriz desdeEnlacesAMatriz(const tMatriz & L); // devuelve M obtenida de L intro seccion 4
tVector normaliza(const tVector & v); //devuelve un vector proporcional a v, con la primera componente igual a 1.0
tVector vectorPropio(const tMatriz & M); // M matriz que sus col suman 1 , devuelve un vector v con la primera componente =1 tq M.v ~ v
void inicializarVector(tVector & v, int x); // inicializa el vector a unos
double calculo(tVector &w, tVector & w1);
void imprimir(tVector const & v);

#endif // !matriz_h

