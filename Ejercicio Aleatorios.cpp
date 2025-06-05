#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    int elementos = 10;
    int minimo = 1;
    int maximo = 100;
    int aleatorio;
    int suma = 0;
    float media;

    /* Creamos el array. */
    int aleatorios[elementos];

    /* Plantamos una semilla para la generación del aleatorio que dependerá del momento concreto del tiempo. */
    srand(time(NULL));

    for ( int i=0; i<elementos; i++ ) {
        aleatorio = minimo + rand() % (maximo - minimo + 1);
        aleatorios[i] = aleatorio;
        suma += aleatorio;
    }

    media = (float)suma / (float)elementos;

    cout << "La suma de todos los aleatorios es: " << suma << endl;
    cout << "La media es: " << media << endl;

    system("pause");
    return 0;
}
