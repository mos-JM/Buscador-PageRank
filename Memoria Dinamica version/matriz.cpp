#include "matriz.h"

tMatriz matrizConstante(double x, int n, tMatriz & L){
	tMatriz mConstante;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (L.matriz[i][j] != 0 && L.matriz[i][j] !=1)
				L.matriz[i][j] = x;
		}
	}
	//L.col = n;
	//L.rows = n;
	
	mConstante = L;
		return mConstante;
}

tVector operator*(const tMatriz & m, const tVector & v){
	tVector result;
	result.tam = m.col;
	inicializarVector(result, 0);
	for (int i = 0; i < m.rows; i++){
		for (int j = 0; j < m.col; j++){
			result.vector[i] += m.matriz[i][j] * v.vector[j];
		}

	}
	return result;
}

tMatriz operator*(double x, const tMatriz & m){
	tMatriz mResult;
	for (int i = 0; i < m.col; i++){
		for (int j = 0; j < m.col; j++){
			mResult.matriz[i][j] = m.matriz[i][j] * x;
		}
	}

	return mResult;
}

tMatriz operator +(const tMatriz & m1, const tMatriz & m2){
	tMatriz mRes;
	
	for (int i = 0; i < MAX_TAM; i++){
		for (int j = 0; j < MAX_TAM; j++){
			mRes.matriz[i][j] = m1.matriz[i][j] + m2.matriz[i][j];

		}
	}
	return mRes;
}

/*double operator/(const tVector & v, const tVector & m){
	double result = 0;
	for (int  i = 0; i < v.tam; i++){
		result += v.vector[i] / m.vector[i];
	}
	return result;
}*/

tMatriz desdeEnlacesAMatriz(const tMatriz & L){
	double N = L.col;
	double num = 1 / N;
	tMatriz Cn = matrizConstante(1 / N, N, Cn);
	tMatriz MPrima = matrizConstante(0.0, N, MPrima);
	tVector noCeros;   // con tamaño N
	int Nj;
	
	for (int  j = 0; j < L.col; j++){
		
		Nj = 0; //num de enlases por pag
		for (int  i = 0; i < L.rows; i++){
			if (L.matriz[i][j] != 0.0) {
				noCeros.vector[Nj] = i;
				Nj++;
			}
		}
		if (Nj != 0) {
			double e = 1.0 / Nj;
			for (int i = 0; i < L.rows; i++){
				if (L.matriz[i][j] == 1.0)
					MPrima.matriz[i][j] = e;
			}
		}
		else { // si es cero
			double e = 1.0 / N;
			for (int i = 0; i < L.rows; i++) {
				MPrima.matriz[i][j] = e;
			}
		}
	}
	Cn.col = N;
	tMatriz r1 = (1 - C) * Cn;
	MPrima.col = N;
	tMatriz r2 = C * MPrima;

	tMatriz MGoogle = r1 + r2;
	MGoogle.col = N;
	MGoogle.rows = N;

	return MGoogle;
}

tVector normaliza(const tVector & v){
	tVector result;
	result.tam = v.tam;
	for (int i = 0; i < v.tam; i++)
		result.vector[i] = v.vector[i] / v.vector[0];

	return result;
}


/*PR2 = M *PR 1
BUCLE DONDE PREGUNTA SI SON MUY PROXIMOS, SINO HAGO 
PR3 = M * PR2
*/
tVector vectorPropio(const tMatriz & M){
	tVector w;
	tVector w1;
	tVector aux;
	w.tam = M.col;
	inicializarVector(w, 1);

	w1 = M * w;

	double total = calculo(w, w1);

	while (total > 0.00001) {
		tVector temp = M * w1;
		total = calculo(w1, temp);
		w1 = temp;
	}

	tVector PR = normaliza(w1);
	
	return PR;
}

void inicializarVector(tVector & v, int x){
	for (int i = 0; i < v.tam; i++){
		v.vector[i] = x;

	}
}

double calculo(tVector & w, tVector & w1){
	double total = 0.0;
	double temp;

	for (int i = 0; i < w.tam; i++){
		temp = w.vector[i] - w1.vector[i];
		if (temp < 0)
			total += (-1)*temp;
		else
			total += temp;

	}
	return total;
}

void imprimir(tVector const & v) {
	cout << setw(15) << "Vector PR:" << endl;
	for (int i = 0; i < v.tam; i++){
		cout << setw(11) << v.vector[i] ;
	}
	cout << endl;


}







