#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define TAM_MAX 1600
//Es posible que el cuadrado del número de nodos

/*Autores:
Luis Bardanca Rey (l.bardanca.rey)
Manuel Santamariña Ruiz de León (manuel.santamarina)
Sergio Goyanes Legazpi (sergio.legazpi)
*/
double microsegundos(){
    struct timeval t;
    if(gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec+t.tv_sec*1000000.0);
}

void inicializar_semilla(){
    srand(time(NULL));
    /* se establece la semilla de una nueva serie de enteros
    pseudo-aleatorios */
}
void aleatorio(int v[], int n){
    int i, m=2*n+1;
    for(i = 0; i < n; i++)
        v[i] = (rand() % m) -n;
    /* se generan números pseudoaleatorios entre -n y +n */
}

void ascendente(int v [], int n) {
    int i;
    for (i=0; i < n; i++)
        v[i] = i;
}
void descendente(int v [], int n) {
    int i;
    for (i=0; i < n; i++)
        v[i] = (n-1)-i;
}

double tiempo(int n, void(*ini)(int *, int), void(*ord)(int *, int)){
    int i, k;
    double tIni, tFin, t, t1, t2;
    int *v = malloc(sizeof(int) * n);
    k = 1000;
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

int esta_ordenado(int v[], int n){
    int i;
    if(n==1)
        return 1;
    if(n<=0)
        return 0;
    for(i=1;i<n;i++){
        if(v[i-1]>v[i])
            return 0;
    }
    return 1;
}

void listar_vector(int v[], int n){
    int i = 0;
    printf("[");
    for(i = 0; i < n-1; i++){
        printf("%4d",v[i]);
    }
    printf("%4d ]",v[n-1]);
    printf("\n");
}


void ord_ins(int v[], int n){
    int i, x, j;
    for(i=1;i<n;i++){
        x=v[i];
        j=i-1;
        while (j>=0 && v[j]>x){
            v[j+1]=v[j];
            --j;
        }
        v[j+1]=x;
    }
}

void intercambiar(int v[], int i, int j){
    int aux;
    aux=v[i];
    v[i]=v[j];
    v[j]=aux;
}


void mediana3(int v[], int i, int j){
    int k;
    k=(i+j)/2;
    if(v[k]>v[j]){
        intercambiar(v, k, j);
    }
    if(v[k]>v[i]){
        intercambiar(v, k, i);
    }
    if(v[i]>v[j]){
        intercambiar(v, i, j);
    }
}

void rapida_aux(int v[], int izq, int der){
    int pivote, i, j;
    if(izq+UMBRAL<=der){
        mediana3(v, izq, der);
        pivote=v[izq];
        i=izq;
        j=der;
        do {
            do {
                ++i;
            }while(v[i]<pivote);
            do {
                --j;
            }while(v[j]>pivote);
            intercambiar(v, i, j);
        }while(j>i);
        intercambiar(v, i, j);
        intercambiar(v, izq, j);
        rapida_aux(v, izq, j-1);
        rapida_aux(v, j+1, der);
    }
}

void ord_rapida(int v [], int n) {
    rapida_aux(v, 0, n-1);
    if (UMBRAL > 1)
        ord_ins(v, n);
}


void test(void(*ord)(int *, int)){
    int a;
    int n=11;
    int v[n];
    printf("Inicialización aleatoria\n");
    aleatorio(v, n);
    listar_vector(v, n);
    a=esta_ordenado(v, n);//0->false // 1->true
    printf("Ordenado? %d\n", a);
    if(a==0) {
        (*ord)(v, n);
        printf("Ordenado:\n");
        listar_vector(v, n);
    }
    printf("Inicialización descendente\n");
    descendente(v, n);
    listar_vector(v, n);
    a=esta_ordenado(v, n);
    printf("Ordenado? %d\n", a);
    if(a==0) {
        (*ord)(v, n);
        printf("Ordenado:\n");
        listar_vector(v, n);
    }
    printf("Inicialización ascendente\n");
    ascendente(v, n);
    listar_vector(v, n);
    a=esta_ordenado(v, n);
    printf("Ordenado? %d\n", a);
    if(a==0) {
        (*ord)(v, n);
        printf("Ordenado:\n");
        listar_vector(v, n);
    }
    printf("\n");
}
void cotas_general(double t, int n, float cotas[]){
    double x,y,z;
    x = t / pow(n,cotas[0]);
    y = t / pow(n,cotas[1]);
    z = t / pow(n,cotas[2]);
    printf("%6d %17.7f %17.7f %17.7f %17.7f\n", n, t, x, y, z);
}
void printCotas(float cotas[]) {
    printf("%5s %16s %15s%0.2f %13s%0.2f %13s%0.2f\n", "n", "t(n)", 
    "t/n^",cotas[0],"t/n^", cotas[1],"t/n^", cotas[2]);
}

void printDescripCotas(float cotas[]) {

    printf("\n\n");
    printf("Cota subestimada: n^%0.2f\n", cotas[0]);
    printf("Cota ajustada: n^%0.2f\n", cotas[1]);
    printf("Cota sobreestimada: n^%0.2f\n",cotas[2]);
    printf("\n\n");
}
void tablas_ord_rap(char *titulo,
    float cotasAsc[], float cotasDesc[], float cotasAle[]){
    int i,j;
    double t;
    printf("\n%s, inicialización ascendente\n",titulo);
	printCotas(cotasAsc);
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, ascendente, ord_rapida);
			cotas_general(t, j,cotasAsc);
		}
		printf("\n");
	}
    printDescripCotas(cotasAsc);    
    printf("\n%s, inicialización descendente\n",titulo);
	printCotas(cotasDesc);
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, descendente, ord_rapida);
			cotas_general(t, j, cotasDesc);
		}
		printf("\n");
	}
    printDescripCotas(cotasDesc);
    printf("\n%s, inicialización ascendente\n",titulo);
	printCotas(cotasAle);
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, aleatorio, ord_rapida);
			cotas_general(t, j,cotasAle);
		}
		printf("\n");
	}
}

void tablas_tripleinit(char *titulo,
    float cotasAsc[], float cotasDesc[], float cotasAle[], 
    void(*ord)(int *, int)){
    int i,j;
    double t;
    printf("\n%s, inicialización ascendente\n",titulo);
	printCotas(cotasAsc);
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, ascendente, ord);
			cotas_general(t, j,cotasAsc);
		}
		printf("\n");
	}
    printDescripCotas(cotasAsc);
    printf("\n%s, inicialización descendente\n",titulo);
	printCotas(cotasDesc);
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, descendente, ord);
			cotas_general(t, j, cotasDesc);
		}
		printf("\n");
	}
    printDescripCotas(cotasDesc);
    printf("\n%s, inicialización aleatoria\n",titulo);
	printCotas(cotasAle);
	for(i = 0; i < 3; i++){
		for(j = 500; j < 64000; j = j * 2){
			t = tiempo(j, aleatorio, ord);
			cotas_general(t, j,cotasAle);
		}
		printf("\n");
	}
    printDescripCotas(cotasAle);
}
//P4
typedef int ** matriz;
typedef struct {
int x, y, peso;
} arista;

typedef arista tipo_elemento;
typedef struct {
int cabeza, final, tamano;
tipo_elemento vector[TAM_MAX];
} cola;
void crear_cola(cola *);
int cola_vacia(cola);
void insertar(tipo_elemento, cola *);
tipo_elemento quitar_primero(cola *);
tipo_elemento primero(cola);
void mostrar_cola(cola);

void prim(matriz m, int nodos, cola *aristas) {
/* calcular el árbol de recubrimiento mínimo devolviendo
las aristas del arbol en la cola ’aristas’ */
int min, i, j, k=0;
arista a;
int *masProximo = (int *) malloc(nodos*sizeof(int));
int *distanciaMinima = (int *) malloc(nodos*sizeof(int));
crear_cola(aristas);
distanciaMinima[0] = -1;
for(i = 1; i < nodos; i++) {
masProximo[i] = 0;
distanciaMinima[i] = m[i][0];
}
/*
...
*/
free(masProximo);
free(distanciaMinima);
}

matriz crear_matriz(int n) {
    int i;
    matriz aux;
    if ((aux = malloc(n*sizeof(int *))) == NULL)
    return NULL;
    for (i=0; i<n; i++)
    if ((aux[i] = malloc(n*sizeof(int))) == NULL)
    return NULL;
    return aux;
}
void inicializar_matriz(matriz m, int n) {
    /* Crea un grafo completo no dirigido con valores aleatorios entre 1 y n */
    int i, j;
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            m[i][j] = rand() % n + 1;
        for (i=0; i<n; i++)
            for (j=0; j<=i; j++)
                if (i==j)
                    m[i][j] = 0;
                else
                    m[i][j] = m[j][i];
    }

void liberar_matriz(matriz m, int n) {
    int i;
    for (i=0; i<n; i++)
        free(m[i]);
        free(m);
    }
    int main() {
}