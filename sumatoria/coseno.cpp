#include<iostream>
#include <random>
#include <math.h>
#include <iomanip>

/*
Defina aca los prototipos de las funciones
*/
size_t Aleatorio(void);
long double sumatoria(double x , size_t v);
unsigned long long factorial(size_t n);

int main() {
    double x{};
    size_t opc{} , valor{};
    std::cout << "1. Aleatorio" << std::endl
              << "2. Determinista" << std::endl;

   /*
   En esta parte del main usted debe controlar el llamado a las funciones aleatorio  y sumatoria,el resultado de la aproximación usando el comando setprecision(16). además
   controlar la entrada del valor cuando se utiliza Aleatorio o Determinista y el ingreso del valor de x usado en
   la sumatoria y por último debe imprimir la sumatoria de acuerdo a las especificaciones
   */

    while( opc < 1 || opc > 2 ) {
        std::cin>>opc;
    }

    if( opc == 1){
        valor=Aleatorio();
    }else{
        std::cin>>valor;
    }

    std::cin>>x;

    std::cout << std::setprecision(16) << sumatoria(x, valor);

    return 0;
}

size_t Aleatorio(void) {
    /*
    Esta funcion debe generar un número aleatorio entre 5 y 15 inclusive, utilice para ello
    la funcion srand, además agregue las librerías necesarias.
    */
    std::default_random_engine generador;
    std::uniform_int_distribution<size_t> distr(5,15);
    size_t aleatorio = distr(generador);

    return aleatorio;
}

long double sumatoria(double x , size_t v) {
    /*
    Esta funcion retorna el valor de la sumatoria (-1)^i *(x^2*i)/(2*i!)
    con 0 <= i <= v
    */
    long double suma = 0;

    for (size_t i=0; i<v; i++) {
        suma = suma + ((std::pow(-1, i) * std::pow(x,2*i)) / factorial(2*i));
    }

    return suma;
}

unsigned long long factorial(size_t n) {
    /*
    Esta funcion calcula de forma recursiva el factorial del numero n
    y luego retorna ese valor calculado
    */
    if (n > 0) {
        return n * factorial(n-1);
    } else {
        return 1;
    }
}
