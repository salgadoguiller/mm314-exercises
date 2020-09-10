#include<iostream>

/*
    Si necesita otras librerías agréguelas aquí
*/
#include <random>
#include <chrono>

/*
    Defina aca los prototipos de las funciones
*/
int** Genere_arreglo(int);
void Imprime_arreglo(int**, int);
int Menor_diagonal(int**, int);

int main() {
    /*
        En está parte se debe realizar lo que se pide de la función principal
    */
    int tamano = -1;

    while(tamano < 0 || tamano > 10 ) {
        std::cout << "Ingrese el tamano de la matriz cuadrada [0, 10]:" << std::endl;
        std::cin>>tamano;
    };

    int** matriz = Genere_arreglo(tamano);
    Imprime_arreglo(matriz, tamano);

    std::cout << "El numero menor de la diagonal es: " << Menor_diagonal(matriz, tamano) << std::endl;
    return 0;
}

/*
    Realice las definiciones de la función
*/
int** Genere_arreglo(int tamano) {
    std::default_random_engine generador;
    generador.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distr(1,15);

    int** matriz;
    matriz = new int*[tamano];

    for (int x=0; x<tamano; x++) {
        matriz[x] = new int[tamano];

        for (int y=0; y<tamano; y++) {
            matriz[x][y] = distr(generador);
        }
    }

    return matriz;
}

void Imprime_arreglo(int** matriz, int tamano) {
    for (int x=0; x<tamano; x++) {
        for (int y=0; y<tamano; y++) {
            printf("%i\t", matriz[x][y]);
        }
        printf("\n");
    }
}

int Menor_diagonal(int** matriz, int tamano) {
    int menor = 0;
    if(tamano > 0) { menor = matriz[0][0]; }
    for (int x=0; x<tamano; x++) {
        if (matriz[x][x] < menor) {
            menor = matriz[x][x];
        }
    }

    return menor;
}
