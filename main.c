#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
/*Autores:
Luis Bardanca Rey (l.bardanca.rey)
Manuel Santamariña Ruiz de León (manuel.santamarina)
Sergio Goyanes Legazpi (sergio.legazpi)
*/

//funciones dadas
double microsegundos()
{
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void inicializar_semilla()
{
    srand(time(NULL));
    /* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
}
void aleatorio(int v[], int n)
{
    int i, m = 2 * n + 1;
    for (i = 0; i < n; i++)
        v[i] = (rand() % m) - n;
    /* se generan números pseudoaleatorios entre -n y +n */
}

int sumaSubMax1(int v[], int n)
{
    int sumaMax = 0, estaSuma, i, j;
    for (i = 0; i < n; i++)
    {
        estaSuma = 0;
        for (j = i; j < n; j++)
        {
            estaSuma = estaSuma + v[j];
            if (estaSuma > sumaMax)
            {
                sumaMax = estaSuma;
            }
        }
    }
    return sumaMax;
}

int sumaSubMax2(int v[], int n)
{
    int estaSuma = 0, sumaMax = 0, j;
    for (j = 0; j < n; j++)
    {
        estaSuma = estaSuma + v[j];
        if (estaSuma > sumaMax)
        {
            sumaMax = estaSuma;
        }
        else
        {
            if (estaSuma < 0)
            {
                estaSuma = 0;
            }
        }
    }
    return sumaMax;
}

void tiempos(int v[], int n)
{
    int i;
    double ta, tb, t, t1, t2;
    aleatorio(v, n);
    ta = microsegundos();
    sumaSubMax1(v, n);
    tb = microsegundos();
    t = tb - ta;
    if (t < 500)
    {
        ta = microsegundos();
        for (i = 0; i < 500; i++)
        {
            aleatorio(v, n);
            sumaSubMax1(v, n);
        }
        tb = microsegundos();
        t1 = tb - ta;
        ta = microsegundos();
        for (i = 0; i < 500; i++)
        {
            aleatorio(v, n);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = (t1 - t2) / 500;
        printf("%f", t);
    }
}

void listar_vector(int v[], int n)
{
    int i = 0;
    printf("[");
    for (i = 0; i < n - 1; i++)
    {
        printf("%3d", v[i]);
    }
    printf("%3d ]", v[n - 1]);
}
void test1()
{
    int m[][6] = {
        {-9, 2, -5, -4, 6},
        {4, 0, 9, 2, 5},
        {-2, -1, -9, -7, -1},
        {9, -2, 1, -7, -8},
        {15, -2, -5, -4, 16},
        {7, -5, 6, 7, -7}
        };
    int i = 0;
    printf("%35s%17s", "sumaSubMax1", "sumaSubMax2\n");
    for (i = 0; i < 6; i++)
    {
        listar_vector(m[i], 5);
        printf("\t\t%3d\t\t%3d\n", sumaSubMax1(m[i], 5), sumaSubMax2(m[i], 5));
    }
}
void test2()
{
    int v[9];
    int i;
    printf("%42s%16s\n", "sumaSubMax1", "sumaSubMax2");
    for (i = 0; i < 6; i++)
    {
        aleatorio(v, 9);
        listar_vector(v, 9);
        printf("\t\t%2d\t\t%2d\n", sumaSubMax1(&v[i], 5), sumaSubMax2(&v[i], 5));
    }
}

int main()
{
    int n = 500;
    int v[n];
    /*inicializar_semilla();
    test1();
    test2();*/
    tiempos(v, n);
    return 0;
}