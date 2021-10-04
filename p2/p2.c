#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
/*Autores: 
Luis Bardanca Rey (l.bardanca.rey)
Manuel Santamariña Ruiz de León (manuel.santamarina)
Sergio Goyanes Legazpi (sergio.legazpi)
*/

//funciones dadas
double microsegundos(){
    struct timeval t;
    if(gettimeofday(&t, NULL) < 0)
      return 0.0;
    return (t.tv_usec+t.tv_sec*1000000.0);
}

void inicializar_semilla(){
    srand(time(NULL));
    /* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
}
void aleatorio(int v[], int n){
    int i, m=2*n+1;
    for(i = 0; i < n; i++)
      v[i] = (rand() % m) -n;
    /* se generan números pseudoaleatorios entre -n y +n */
}

int algoritmo(int v[], int n){
}

void listar_vector(int v[], int n){
  int i = 0; 
   printf("[");
    for(i = 0; i < n-1; i++){
        printf("%3d",v[i]);
    }
    printf("%3d ]",v[n-1]);
}
void test(){

}
double tiempo(int n, void(*ini)(int *, int), int(*ord)(int *, int)){
	int i, k;
	double tIni, tFin, t, t1, t2;
	int *v = malloc(sizeof(int) * n);

	k = 1001;
	(*ini)(v, n);
	tIni = microsegundos();
	(*ord)(v, n);
	tFin = microsegundos();
	t = tFin - tIni;
	if(t < 500){
		printf("#");
		tIni = microsegundos();
		for(i = 0; i < k; i++){
			(*ini)(v, n);
			(*ord)(v, n);
		}
		tFin = microsegundos();
		t1 = tFin - tIni;
		tIni = microsegundos();
		for(i = 0; i < k; i++)
			(*ini)(v, n);
		tFin = microsegundos();
		t2 = tFin - tIni;
		t = (t1 - t2) / k;
	}else{
    printf(" ");
  }
	free(v);
	return t; 
}
void cotas_algoritmo(double t, int n){
	double x, y, z;
	x = t / pow(n, 1.8);
	y = t / pow(n, 2);
	z = t / pow(n, 2.2);
	printf("%6d %17.7f %17.7f %17.7f %17.7f\n", n, t, x, y, z);
}

void tablas_algoritmo(){
	int i, j;
	double t;
	char cota1[] = "n^0.8", cota2[] = "n^0.9", cota3[] = "n^1.1";
	printf("\Algoritmo 1\n");
	printf("%5s %16s %18s %17s %17s\n", "n", "t(n)", "T(n)/n^1.8", "T(n)n^2", "T(n)/n^2.2");
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, aleatorio, algoritmo);
			cotas_algoritmo(t, j);
		}
		printf("\n");
	}
}

int main(){
    inicializar_semilla();
    test1();
    test2();
    tablas_sumaSubMax();
    return 0;
}