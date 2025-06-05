#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    int numero;

    /* Pedir un número de año. */
    cout << "Escriba un número de año: ";
    cin >> numero;

    if ( numero%4 == 0 ) {
        cout << "El año " << numero << " es bisiesto." << endl;
    } else {
        cout << "El año " << numero << " NO es bisiesto." << endl;
    }

    system("pause");
    return 0;
}
