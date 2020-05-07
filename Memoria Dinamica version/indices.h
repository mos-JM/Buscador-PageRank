#ifndef indices_h
#define indices_h

#include "clavevalor.h"
#include "matriz.h"


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*a partir de archivoinicial rellena la tabla tras haberla inicializado a vacia*/
void creartabla(tIndicePalabras & tabla, const string &archivo, tListaCadenas &totales, tMatriz &L, bool &ok);
void procesar(tListaCadenas &noVisitado, tListaCadenas &visitado, tIndicePalabras &idx, string archivo, tListaCadenas &totales, tMatriz &L, bool &ok);
void procesarLinea(string linea, tListaCadenas &noVis, tListaCadenas &vis, tIndicePalabras &idx, string &archivo, tListaCadenas &totales, tMatriz &L);
void nuevoIndice(tIndicePalabras &newIndice);
void imprimirMatriz(tMatriz &L);


#endif // !indices_h
