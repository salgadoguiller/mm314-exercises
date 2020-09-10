#include<iostream>
#include <string>

using namespace std;

int main() {
    string parrafo;
    string vocal;
    int posicion = -1;
    int numero_encuentros = 0;

    getline(cin, parrafo);
    getline(cin, vocal);

    while (true) {
        posicion = parrafo.find(vocal, posicion + 1);

        if (posicion == string::npos) {
            break;
        } else {
            numero_encuentros++;
            parrafo.replace(posicion, vocal.length(), vocal + string(numero_encuentros, '*'));
        }
    }

    cout << parrafo << endl;
}

