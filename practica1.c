#include <stdio.h>
#include <sys/time.h>

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
//TODO
}
void test1(){
//TODO
}
void test2(){
//TODO
}


int main(){
    inicializar_semilla();
    test1();
    test2();
    return 0;
}