#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    int numero;

    /* Pedir un n�mero de a�o. */
    cout << "Escriba un n�mero de a�o: ";
    cin >> numero;

    if ( numero%4 == 0 ) {
        cout << "El a�o " << numero << " es bisiesto." << endl;
    } else {
        cout << "El a�o " << numero << " NO es bisiesto." << endl;
    }

    system("pause");
    return 0;
}
