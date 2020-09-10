#include <iostream>

using namespace std;

int main()
{
    int numero;
    int suma_numero;
    int suma = 0;

    cout << "Ingrese un numero dentro del intervalo [5, 30]:" << endl;
    cin >> numero;

    if (5 <= numero && numero <= 30) {

        if (numero % 2 == 0) {
            suma_numero = numero;
        } else {
            suma_numero = numero + 1;
        }

        for (int i = 0; i < numero; i++) {
          suma = suma + suma_numero;
          suma_numero+=2;
        }

        cout << suma;
    } else {
        cout << "ERROR";
    }


    return 0;
}
