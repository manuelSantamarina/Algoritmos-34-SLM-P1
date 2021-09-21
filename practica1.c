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

int sumaSubMax1(int v[], int n){
   int sumaMax=0, estaSuma=0, i, j;
   for(i=0;i<n;i++){
      estaSuma=0;
      for(j=i;j<n;j++){
         estaSuma=estaSuma+v[j];
         if(estaSuma>sumaMax){
            sumaMax=estaSuma;
         }
      }
   }
    return sumaMax;
}

int sumaSubMax2(int v[], int n){
   int estaSuma=0, sumaMax=0, j;
   for(j=0;j<n;j++){
      estaSuma=estaSuma+v[j];
      if(estaSuma>sumaMax){
        sumaMax=estaSuma;
      }else{
        if(estaSuma<0){
          estaSuma=0;
      }
    } 
  }
   return sumaMax;
}

void listar_vector(int v[], int n){
  int i = 0; 
   printf("[");
    for(i = 0; i < n-1; i++){
        printf("%3d",v[i]);
    }
    printf("%3d ]",v[n-1]);
}
void test1(){
    int m[][6]={{-9, 2, -5, -4, 6},
                {4, 0, 9, 2, 5},
                {-2, -1, -9, -7, -1},
                {9, -2, 1, -7, -8},
                {15, -2, -5, -4, 16},
                {7, -5, 6, 7, -7}};
    int i = 0;
    printf("%35s%17s","sumaSubMax1","sumaSubMax2\n");
    for(i=0;i<6;i++) {
      listar_vector(m[i],5);
      printf("\t\t%3d\t\t%3d\n", sumaSubMax1(m[i],5), sumaSubMax2(m[i],5));
    }
}
void test2(){
  int v[9];
    int i;
    printf("%42s%16s\n","sumaSubMax1","sumaSubMax2");
    for(i=0;i<6;i++) {
        aleatorio(v, 9);
        listar_vector(v,9);
        printf("\t\t%2d\t\t%2d\n", sumaSubMax1(&v[i],5), sumaSubMax2(&v[i],5));
    }
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
void cotas_sumaSubMax1(double t, int n){
	double x, y, z;
	x = t / pow(n, 1.8);
	y = t / pow(n, 2);
	z = t / pow(n, 2.2);
	printf("%6d %17.7f %17.7f %17.7f %17.7f\n", n, t, x, y, z);
}

void cotas_sumaSubMax2(double t, int n){
	double x, y, z;
	x = t / pow(n, 0.8);
	y = t / pow(n, 0.9);
	z = t / pow(n, 1.1);
	printf("%6d %17.7f %17.7f %17.7f %17.7f\n", n, t, x, y, z);
}

void tablas_sumaSubMax(){
	int i, j;
	double t;
	char cota1[] = "n^1.8", cota2[] = "n^2", cota3[] = "n^2.2";
	printf("\nSuma de la subsecuencia máxima, algoritmo 1\n");
	printf("%5s %16s %18s %17s %17s\n", "n", "t(n)", "n^1.8", "n^2", "n^2.2");
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, aleatorio, sumaSubMax1);
			cotas_sumaSubMax1(t, j);
		}
		printf("\n");
	}
	printf("\nSuma de la subsecuencia máxima, algoritmo 2\n");
	printf("%5s %16s %18s %17s %17s\n", "n", "t(n)", cota1, cota2, cota3);
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, aleatorio, sumaSubMax2);
			cotas_sumaSubMax2(t, j);
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