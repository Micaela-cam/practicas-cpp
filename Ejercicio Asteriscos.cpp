#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    int altura;

    /* Pedimos la altura de la escalera. */
    cout << "Introduzca la altura de la escalera: ";
    cin >> altura;

    for ( int f=1; f<=altura; f++ ) {
        for ( int c=1; c<=f; c++ ) {
            cout << "*";
        }
        /* Al final de cada fila, un salto de línea. */
        cout << endl;
    }

    system("pause");
    return 0;
}
