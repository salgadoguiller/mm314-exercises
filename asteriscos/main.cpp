#include <iostream>
#include <string>

using namespace std;

void asteriscos(char* cadena, char x);

int main() {
    char vocal;
    string entrada;

    getline(cin, entrada);
    cin >> vocal;

    asteriscos(&entrada[0], vocal);

    return 0;
}

void asteriscos(char* cadena, char vocal){
    string vocales = "aeiouAEIOU";
    int posicion = vocales.find(vocal, 0);
    if (posicion == string::npos) {
        cout << cadena;
        return;
    }

    int contador = 0;
    while(*cadena != '\0'){
    	cout << *cadena;

    	if (*cadena == vocal) {
            contador++;
            cout << string(contador, '*');
        }

        cadena++;
  	}
}
