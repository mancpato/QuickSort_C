/** QuickSort.c

Algoritmos de ordenamiento con fines análisis empírico comparativo.

Proyecto para la asignatura Computabilidad y Factibilidad
Departamento Académico de Sistemas Computacionales
Universidad Autónoma de Baja California Sur

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY 20

void QuickSort(int A[], int Ini, int Fin);
int SepararMenoresMayores(int A[], int Ini, int Fin);
void MostrarArreglo(int A[], int Tam, int Ini, int Fin);
void MostrarPivote(int A[], int Tam, int Pivote, int Ini, int Fin);
void swap(int A[], int i, int j);

int Llamada=0;

int main()
{
	int i;
	int Tam=MAX_ARRAY;
	int A[MAX_ARRAY];
	void LlenarArreglo(int A[], int Tam);
    time_t t;


    srand((unsigned) time(&t));
	LlenarArreglo(A,Tam);
	printf("    ");
	for ( i=0; i<Tam ; i++ )
		printf(" %2d ", A[i]);
    printf("\n");

	QuickSort(A,0,Tam-1);

	printf("    ");
	for ( i=0; i<Tam ; i++ )
		printf(" %2d ", A[i]);
    printf("\n");

	return 0;
}

void LlenarArreglo(int A[], int Tam)
{
	int i;

	for ( i=0 ; i<Tam ; i++ )
		A[i] = rand()%100;
}

void QuickSort(int A[], int Ini, int Fin)
{
	int Pivote;

	if ( Ini >= Fin )
        return;

	Pivote = SepararMenoresMayores(A,Ini,Fin);
	printf("%2d: ",Llamada++);
	MostrarArreglo(A,MAX_ARRAY,Ini,Fin);

    QuickSort(A, Ini, Pivote-1);
    QuickSort(A, Pivote, Fin);
}

int SepararMenoresMayores(int A[], int Ini, int Fin)
{
    int i, j, Pivote;

    if ( Ini+1 == Fin ) {
        if ( A[Ini]>A[Fin] )
            swap(A,Ini,Fin);
        return Fin;
    }

    if ( A[Fin]<A[Ini] )
        swap(A,Ini,Fin);
    if ( A[Ini+1]<A[Ini] )
        swap(A,Ini,Ini+1);
    if ( A[Fin]<A[Ini+1] )
        swap(A,Ini+1,Fin);

    Pivote = Ini+1;
    i = Ini+2;
    j = Fin;
    while( i<j ) {
        while ( A[i] <= A[Pivote]  && i<Fin  && i<j )
            i++;
        while ( A[j] > A[Pivote] && j>i )
            j--;
        if ( i<j )
            swap(A,i,j);
    }

    return j;
}

void swap(int A[], int i, int j)
{
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
}

void MostrarArreglo(int A[], int Tam, int Ini, int Fin)
{
    for ( int k=0 ; k<Tam ; k++ )
        if ( k<Ini ||  k>Fin )
            printf(" -- ");
        else
            printf(" %2d ", A[k]);
    printf("\n");
}

void MostrarPivote(int A[], int Tam, int Pivote, int Ini, int Fin)
{
    int k;
    for ( k=0 ; k<Tam ; k++ )
        if ( k<Ini ||  k>Fin )
            printf(" -- ");
        else
            printf(" %2d ", A[k]);
    printf("\n");

    for ( k=0 ; k<Tam ; k++ )
        if ( k != Pivote )
            printf(" -- ");
        else
            printf("  ^ ");
    printf("\n");
}

/* Fin de archivo */
