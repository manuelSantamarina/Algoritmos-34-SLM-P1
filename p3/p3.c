#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define UMBRAL 1 //Constante utilizada para el quicksort

/*
 * SANGRADO
 * FALTABA LA T EN LAS CABECERAS
 * EN INTRODUCCION FALTABA  HABLAR DE LO DE LA # (PARA QUE SERVIA)
 * EL * SE PONE EN LOS TIEMPOS, NO EN LA DIVISION
 * LA CONCLUSION ESTABA MAL->REVISAR BIEN LA NUEVA
 */



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

void aux_test(int v[], int n, char ordenacion[]){
    if(strcmp(ordenacion, "insercion")==0){
        printf("Ordenacion por seleccion:\n");
        ord_ins(v, n);
        listar_vector(v, n);
        printf("\n");
    }

}


void test_ins(){
    int a;
    int n=11;
    int v[n];
    printf("Inicialización aleatoria\n");
    aleatorio(v, n);
    listar_vector(v, n);
    a=esta_ordenado(v, n);//0->false // 1->true
    printf("Ordenado? %d\n", a);
    if(a==0)
        aux_test(v, n, "insercion");
    printf("Inicialización descendente\n");
    descendente(v, n);
    listar_vector(v, n);
    a=esta_ordenado(v, n);
    printf("Ordenado? %d\n", a);
    if(a==0)
        aux_test(v, n, "insercion");
    printf("Inicialización ascendente\n");
    ascendente(v, n);
    listar_vector(v, n);
    a=esta_ordenado(v, n);
    printf("Ordenado? %d\n", a);
    if(a==0)
        aux_test(v, n, "insercion");
    printf("\n");
}



int main() {
    test_ins();

    return 0;
}