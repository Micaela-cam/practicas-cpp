#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    /* Tabla de multiplicar del 5. */
    cout << "Tabla del 5" << endl;
    for ( int n=1; n<=10; n++ ) {
        cout << "5 x " << n << " = " << 5*n << endl;
    }

    /* Pedir un número al usuario y usarlo como tabla. */
    int tabla;
    do {
        cout << "Escribe el número de tabla (1-10): ";
        cin >> tabla;
    } while ( tabla<1 || tabla >10);

    cout << "Tabla del " << tabla << endl;
    for ( int n=1; n<=10; n++ ) {
        cout << tabla << " x " << n << " = " << tabla*n << endl;
    }

    /* Todas las tablas del 1 al 10. */
    for ( tabla=1; tabla<=10; tabla++ ) {
        cout << "Tabla del " << tabla << endl;
        for ( int n=1; n<=10; n++ ) {
            cout << tabla << " x " << n << " = " << tabla*n << endl;
        }
    }

    system("pause");
    return 0;
}
