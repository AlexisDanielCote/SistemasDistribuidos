#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void getwalltime(double* wcTime){
	struct timeval tp;
	gettimeofday(&tp, NULL);
	*wcTime = (tp.tv_sec + tp.tv_usec/1000000.0);
}

int main(int argc, char* argv[]){
	int i, j, k, n = 1000;
	int **matrizA, **matrizB, **matrizC;
	double S1, E1;

	//Inicializando matrices
	matrizA = (int **)malloc(n*sizeof(int*));
	matrizB = (int **)malloc(n*sizeof(int*));
	matrizC = (int **)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		*(matrizA + i) = (int *)malloc(n*sizeof(int));
		*(matrizB + i) = (int *)malloc(n*sizeof(int));
		*(matrizC + i) = (int *)malloc(n*sizeof(int));
	}

	//Llenando matrices
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matrizA[i][j] = rand()%6;
		}
	}

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matrizB[i][j] = rand()%6;
		}
	}

	getwalltime(&S1);

	for(k=0; k<n; ++k){
		for(j=0; j<n; ++j){
			for(i=0; i<n; ++i){
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}

	getwalltime(&E1);

	printf("Tiempo metodo kji 1000x1000: %f s\n", (E1 - S1));
	return 0;
}
