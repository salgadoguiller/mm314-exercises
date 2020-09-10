#include<iostream>

void cuenta_palabras(int);

int main() {
    cuenta_palabras(50);

    return 0;
}

void cuenta_palabras(int tamano) {
    int numero_palabras = 0;
    int tamano_palabra = 0;

    char texto[tamano] = {'\0'};

    std::cin.get(texto, tamano);

    for (int i=0; texto[i] != '\0'; i++)
    {
        if (texto[i] == ' ') {
            if (tamano_palabra > 0) {
                numero_palabras++;
            }

            tamano_palabra = 0;
            continue;
        }

        tamano_palabra++;
    }

    if (tamano_palabra > 0) {
        numero_palabras++;
    }

    std::cout << numero_palabras;
}

