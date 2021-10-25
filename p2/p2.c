#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdbool.h>
<<<<<<< HEAD
/*Autores: 
Luis Bardanca Rey (l.bardanca.rey)
Manuel Santamariña Ruiz de León (manuel.santamarina)
Sergio Goyanes Legazpi (sergio.legazpi)
*/
=======
>>>>>>> 479573b4b46c09a970dcd7ac1079ccba017af225
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

void ascendente(int v [], int n) {
    int i;
    for (i=0; i < n; i++)
        v[i] = i;
}
void descendente(int v [], int n) {
    int i;
    for (i=0; i < n; i++)
        v[i] = (n-1)-i;
<<<<<<< HEAD
=======
}

void ord_sel(int v[], int n){
    int minj, minx, i, j;
    for(i=0;i<n-1;i++){
        minj=i;
        minx=v[i];
        for(j=i+1;j<n;j++){
            if(v[j]<minx){
                minj=j;
                minx=v[j];
            }
        }
        v[minj]=v[i];
        v[i]=minx;
    }
}

void ord_shell(int v[], int n){
    int incremento, tmp, i, j;
    bool seguir;
    incremento=n-1;//Posicion ultima del vector
    do{
        incremento=incremento/2;//lo dividimos por dos
        for(i=incremento;i<n;i++){
            tmp=v[i];
            j=i;
            seguir=true;
            while(j-incremento>=0 && seguir){
                if(tmp<v[j-incremento]){
                    v[j]=v[j-incremento];
                    j=j-incremento;
                }
                else
                    seguir=false;
            }
            v[j]=tmp;
        }
    }while(incremento!=0);
}

void test(){
    int a;
    int v[10];
    int n=10;

    printf("Inicializacion aleatoria\n");
    aleatorio(v, 10);
    for(int k=0;k<10;k++)
        printf("%d ", v[k]);
    printf("\n");
    printf("Ordenado?\n");
    scanf("%d", &a);
    if(a==0){
        printf("Ordenacion? seleccion/shell\n");
        scanf("%d", &a);
        if(a==0){
            printf("Ordenacion por seleccion:\n");
            ord_sel(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        if(a==1){
            printf("Ordenacion por shell:\n");
            ord_shell(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        printf("Ordenado?\n");
    }

   printf("\n");
    printf("Inicializacion descendente\n");
    descendente(v, 10);
    for(int k=0;k<10;k++)
        printf("%d ", v[k]);
    printf("\n");
    printf("Ordenado?\n");
    scanf("%d", &a);
    if(a==0){
        printf("Ordenacion por seleccion/shell?\n");
        scanf("%d", &a);
        if(a==0){
            printf("Ordenacion por seleccion:\n");
            ord_sel(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        if(a==1){
            printf("Ordenacion por shell:\n");
            ord_shell(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
    }
    printf("Inicializacion ascendente\n");
    ascendente(v, 10);
    for(int k=0;k<10;k++)
        printf("%d ", v[k]);
    printf("\n");
    printf("Ordenado?\n");
    scanf("%d", &a);
    if(a==0){
        printf("Ordenacion por seleccion/shell?\n");
        scanf("%d", &a);
        if(a==0){
            printf("Ordenacion por seleccion:\n");
            ord_sel(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        if(a==1){
            printf("Ordenacion por shell:\n");
            ord_shell(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
    }
>>>>>>> 479573b4b46c09a970dcd7ac1079ccba017af225
}

void ord_sel(int v[], int n){
    int minj, minx, i, j;
    for(i=0;i<n-1;i++){
        minj=i;
        minx=v[i];
        for(j=i+1;j<n;j++){
            if(v[j]<minx){
                minj=j;
                minx=v[j];
            }
        }
        v[minj]=v[i];
        v[i]=minx;
    }
}

void ord_shell(int v[], int n){
    int incremento, tmp, i, j;
    bool seguir;
    incremento=n-1;//Posicion ultima del vector
    do{
        incremento=incremento/2;//lo dividimos por dos
        for(i=incremento;i<n;i++){
            tmp=v[i];
            j=i;
            seguir=true;
            while(j-incremento>=0 && seguir){
                if(tmp<v[j-incremento]){
                    v[j]=v[j-incremento];
                    j=j-incremento;
                }
                else
                    seguir=false;
            }
            v[j]=tmp;
        }
    }while(incremento!=0);
}
void test(){
    int a;
    int v[10];
    int n=10;
    //se inicializa aleatoriamente el vector
    printf("Inicializacion aleatoria\n");
    aleatorio(v, 10);
    for(int k=0;k<10;k++)
        printf("%d ", v[k]);
    printf("\n");
    printf("Ordenado?\n");
    scanf("%d", &a);
    if(a==0){
        printf("Ordenacion? seleccion/shell\n");
        scanf("%d", &a);
        if(a==0){
            printf("Ordenacion por seleccion:\n");
            ord_sel(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        if(a==1){
            printf("Ordenacion por shell:\n");
            ord_shell(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        printf("Ordenado?\n");
    }

<<<<<<< HEAD
   printf("\n");
    printf("Inicializacion descendente\n");
    descendente(v, 10);
    for(int k=0;k<10;k++)
        printf("%d ", v[k]);
    printf("\n");
    printf("Ordenado?\n");
    scanf("%d", &a);
    if(a==0){
        printf("Ordenacion por seleccion/shell?\n");
        scanf("%d", &a);
        if(a==0){
            printf("Ordenacion por seleccion:\n");
            ord_sel(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        if(a==1){
            printf("Ordenacion por shell:\n");
            ord_shell(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
    }
    printf("Inicializacion ascendente\n");
    ascendente(v, 10);
    for(int k=0;k<10;k++)
        printf("%d ", v[k]);
    printf("\n");
    printf("Ordenado?\n");
    scanf("%d", &a);
    if(a==0){
        printf("Ordenacion por seleccion/shell?\n");
        scanf("%d", &a);
        if(a==0){
            printf("Ordenacion por seleccion:\n");
            ord_sel(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
        if(a==1){
            printf("Ordenacion por shell:\n");
            ord_shell(v, 10);
            for(int k=0;k<10;k++)
                printf("%d ", v[k]);
            printf("\n");
        }
    }
=======
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
>>>>>>> 479573b4b46c09a970dcd7ac1079ccba017af225
}


int main(){
    inicializar_semilla();
    int v[5]={2, 1, 3, 1, 4};
    ord_sel(v, 5);
    ord_shell(v,5);
    for(int i=0;i<5;i++){
        printf("%d\t", v[i]);
    }
    printf("\n");
    test();
}
