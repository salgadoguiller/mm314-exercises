#include <iostream>

using namespace std;

int main()
{
    int suma_pares = 0;
    int suma_impares = 0;
    int numero_impares = 0;
    int i = 1;
    int n;
    int dato;

    cout << "Ingrese la cantidad de datos a ingresar:" << endl;
    cin >> n;

    while (i <= n) {
        cout << "Ingrese el numero " << i << ":" << endl;
        cin >> dato;

        if (dato < -100 || dato > 100) {
            cout << "El numero ingresado debe ser mayor que -100 y menor que 100" << endl;
        } else {
            i++;

            if (dato % 2 == 0) {
                suma_pares = suma_pares + dato;
            } else {
                suma_impares = suma_impares + dato;
                numero_impares = numero_impares + 1;
            }
        }
    }

    cout << "La suma de los numeros pares es: " << suma_pares << endl;
    cout << "El promedio de los numeros inpares es: " << suma_impares/numero_impares << endl;

    return 0;
}
