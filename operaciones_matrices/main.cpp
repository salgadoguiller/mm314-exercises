// Librerias
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

// Prototipos de las funciones
size_t menu();
size_t leer_numero(string);
int** genere_arreglo(int, int);
void imprime_arreglo(int**, int, int);
int** suma(int**, int**, int, int);
int** resta(int**, int**, int, int);
int** multiplicacion(int**, int**, int, int);
int** producto_escalar(int, int**, int, int);
int** opuesta(int**, int, int);
int** transpuesta(int**, int, int);

// Funcion principal
int main() {
    size_t opcion;

    while(opcion != 7) {
        opcion = menu();

        if (opcion > 0 && opcion < 7) {
            size_t filas, columnas;
            filas = leer_numero("Ingrese el numero de filas de la matriz ]0, 10]:");
            columnas = leer_numero("Ingrese el numero de columnas de la matriz ]0, 10]:");

            if  (filas <= 0 || filas > 10 || columnas <= 0 || columnas > 10 ) {
                cout << "Por favor ingrese el numero de filas y columnas en el intervalo establecido" << endl << endl;
                continue;
            }

            cout << "================================================" << endl;

            int** matriz_a = genere_arreglo(filas, columnas);
            cout << "Matriz A:" << endl;
            imprime_arreglo(matriz_a, filas, columnas);

            if (opcion == 1) {
                int** matriz_b = genere_arreglo(filas, columnas);
                cout << "Matriz B:" << endl;
                imprime_arreglo(matriz_b, filas, columnas);

                int** resultado = suma(matriz_a, matriz_b, filas, columnas);

                cout << "Suma:" << endl;
                imprime_arreglo(resultado, filas, columnas);
            }

            if (opcion == 2) {
                int** matriz_b = genere_arreglo(filas, columnas);
                cout << "Matriz B:" << endl;
                imprime_arreglo(matriz_b, filas, columnas);

                int** a_menos_b = resta(matriz_a, matriz_b, filas, columnas);
                cout << "Resta A-B:" << endl;
                imprime_arreglo(a_menos_b, filas, columnas);

                int** b_menos_a = resta(matriz_b, matriz_a, filas, columnas);
                cout << "Resta B-A:" << endl;
                imprime_arreglo(b_menos_a, filas, columnas);
            }

            if (opcion == 3) {
                int filas_b = columnas;
                int columnas_b = filas;

                int** matriz_b = genere_arreglo(filas_b, columnas_b);
                cout << "Matriz B:" << endl;
                imprime_arreglo(matriz_b, filas_b, columnas_b);

                int** a_por_b = multiplicacion(matriz_a, matriz_b, filas, columnas);
                cout << "Multiplicacion A*B:" << endl;
                imprime_arreglo(a_por_b, filas, filas);

                int** b_por_a = multiplicacion(matriz_b, matriz_a, filas_b, columnas_b);
                cout << "Multiplicacion B*A:" << endl;
                imprime_arreglo(b_por_a, filas_b, filas_b);
            }

            if (opcion == 4) {
                size_t escalar;
                escalar = leer_numero("Ingrese escalar para multiplicar la matriz:");

                int** resultado = producto_escalar(escalar, matriz_a, filas, columnas);

                cout << "Producto escalar:" << endl;
                imprime_arreglo(resultado, filas, columnas);
            }

            if (opcion == 5) {
                int** resultado = opuesta(matriz_a, filas, columnas);

                cout << "Opuesta:" << endl;
                imprime_arreglo(resultado, filas, columnas);
            }

            if (opcion == 6) {
                int** resultado = transpuesta(matriz_a, filas, columnas);

                cout << "Transpuesta:" << endl;
                imprime_arreglo(resultado, columnas, filas);
            }

            cout << "================================================" << endl;
        }
    }
    return 0;
}

// Definiciones de las funciones
size_t menu() {
    size_t opcion;

    cout << "Elija una opcion:" << endl;
    cout << "1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicacion" << endl;
    cout << "4. Producto Escalar" << endl;
    cout << "5. Opuesta" << endl;
    cout << "6. Transpuesta" << endl;
    cout << "7. Salir" << endl;

    cin >> opcion;

    return opcion;
}

size_t leer_numero(string mensaje) {
    size_t numero;
    cout << mensaje << endl;
    cin >> numero;
    cout << endl;
    return numero;
}

int** genere_arreglo(int filas, int columnas) {
    default_random_engine generador;
    generador.seed(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distr(1,10);

    int** matriz;
    matriz = new int*[filas];

    for (int x=0; x<filas; x++) {
        matriz[x] = new int[columnas];

        for (int y=0; y<columnas; y++) {
            matriz[x][y] = distr(generador);
        }
    }

    return matriz;
}

void imprime_arreglo(int** matriz, int filas, int columnas) {
    for (int x=0; x<filas; x++) {
        for (int y=0; y<columnas; y++) {
            cout << matriz[x][y] << "\t";
        }
        cout << "\t" << endl;
    }

    cout << "\t" << endl;
}

int** suma(int** matriz_a, int** matriz_b, int filas, int columnas) {
    int** resultado;
    resultado = new int*[filas];

    for (int x=0; x<filas; x++) {
        resultado[x] = new int[columnas];

        for (int y=0; y<columnas; y++) {
            resultado[x][y] = matriz_a[x][y] + matriz_b[x][y];
        }
    }

    return resultado;
}

int** resta(int** matriz_a, int** matriz_b, int filas, int columnas) {
    int** resultado;
    resultado = new int*[filas];

    for (int x=0; x<filas; x++) {
        resultado[x] = new int[columnas];

        for (int y=0; y<columnas; y++) {
            resultado[x][y] = matriz_a[x][y] - matriz_b[x][y];
        }
    }

    return resultado;
}

int** multiplicacion(int** matriz_a, int** matriz_b, int filas, int columnas) {
    int** resultado;
    resultado = new int*[filas];

    for (int x=0; x<filas; x++) {
        resultado[x] = new int[filas];

        for (int y=0; y<filas; y++) {
            int numero = 0;

            for (int z=0; z<columnas; z++) {
                numero += matriz_a[x][z] * matriz_b[z][y];
            }

            resultado[x][y] = numero;
        }
    }

    return resultado;
}

int** producto_escalar(int escalar, int** matriz, int filas, int columnas) {
    int** resultado;
    resultado = new int*[filas];

    for (int x=0; x<filas; x++) {
        resultado[x] = new int[columnas];

        for (int y=0; y<columnas; y++) {
            resultado[x][y] = matriz[x][y] * escalar;
        }
    }

    return resultado;
}

int** opuesta(int** matriz, int filas, int columnas) {
    int** resultado;
    resultado = new int*[filas];

    for (int x=0; x<filas; x++) {
        resultado[x] = new int[columnas];

        for (int y=0; y<columnas; y++) {
            resultado[x][y] = matriz[x][y] * -1;
        }
    }

    return resultado;
}

int** transpuesta(int** matriz, int filas, int columnas) {
    int** resultado;
    resultado = new int*[columnas];

    for (int x=0; x<columnas; x++) {
        resultado[x] = new int[filas];

        for (int y=0; y<filas; y++) {
            resultado[x][y] = matriz[y][x];
        }
    }

    return resultado;
}
