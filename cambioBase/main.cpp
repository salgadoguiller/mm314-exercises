#include <iostream>

void binario(int);
void quinario(int);
void octal(int);

int main() {
	std::cout << "Ingrese un entero positivo: ";

	int n;
	std::cin >> n;

	if (n >= 0) {
		std::cout << "binario : ";
		binario(n);
		std::cout << std::endl;

		std::cout << "quinario: ";
		quinario(n);
		std::cout << std::endl;

		std::cout << "octal   : ";
		octal(n);
		std::cout << std::endl;

	} else {
		std:: cout << "Numero no valido \n";
	}
	return 0;
}

void binario(int n) {
    const int x = n % 2;
    n = n/2;

    if (n > 1) {
        binario(n);
    } else {
        std::cout << n;
    }

    std::cout << x;
}

void quinario(int n) {
    const int x = n % 5;
    n = n/5;

    if (n > 4) {
        quinario(n);
    } else {
        std::cout << n;
    }

    std::cout << x;
}

void octal(int n) {
    const int x = n % 8;
    n = n/8;

    if (n > 7) {
        octal(n);
    } else {
        std::cout << n;
    }

    std::cout << x;
}
