#include <iostream>

using namespace std;

//Funcion para asignar la secuencia de paginas para el folleto.
void Folio(int *x,int n);

//Funcion para imprimir las paginas separados por comas.
void Imprimir(int *x,int n);

int main()
{
    int n;
    cin >> n;
    int A[n];
    Folio(A,n);
    Imprimir(A,n);
    return 0;
}

void Imprimir(int *x,int n){
    //Cuerpo de la funcion.
    for (int y=0; y<n; y++) {
        cout << x[y];

        if ((y+1) != n) {
            cout << ",";
        }
    }
}

void Folio(int *x, int n){
    //Cuerpo de la funcion.
    int restar = 0;
    int contador = 1;

    for (int y=0; y<n; y++) {
        x[y] = 0;
        if ((y+1)%4 == 0 || (y+1)%4 == 1) {
            x[y] = n - restar;
            restar++;
        } else {
            x[y] = contador;
            contador++;
        }
    }
}
