#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    srand(time(NULL));

    /* 1) En una ciudad viven un n�mero aleatorio de personas entre (8.000 y 15.000). Suponiendo que las edades de estas
    personas est�n comprendidas entre 0 y 100 a�os, cree un array de 101 posiciones para llevar el recuento de cu�ntas
    personas hay en la ciudad de cada una de las posibles edades. */
    int poblacion = 8000 + rand() % (15000 - 8000 + 1);
    cout << "Poblaci�n de la ciudad: " << poblacion << " habitantes." << endl;

    int edades[101];
    /* Inicializo a cero todos los elementos del array. */
    for ( int i=0; i<=100; i++ ) {
        edades[i] = 0;
    }

    /* 2) En un bucle, recorra uno a uno los habitantes de la ciudad y as�gneles a cada uno una edad aleatoria (entre 0 y
    100, recuerde). La edad que se obtenga en cada vuelta del bucle, servir� para ir incrementando en una unidad el n�mero
    de personas de dicha edad que hay en la ciudad (el recuento, recuerde, se llevar� en el array que se gener� en el
    paso 1). */
    int edad;
    for ( int i=1; i<=poblacion; i++) {
        edad = 0 + rand() % (100 - 0 + 1);
        edades[edad]++;
    }

    /* 3) �Cu�l es la edad media de edad de la poblaci�n? */
    int sumatorio = 0;
    /* Sumamos la cantidad de habitantes que hay de cada edad por dicha edad. */
    for ( int i=0; i<=100; i++) {
        sumatorio = sumatorio + edades[i] * i;
    }
    float edadMedia = (float)sumatorio / (float)poblacion;

    cout << "Edad media de la poblaci�n: " << edadMedia << endl;

    /* 4) �Cu�l es la edad m�xima de los habitantes de la ciudad? �Cu�ntos habitantes hay de dicha edad? */
    int edadMaxima;
    /* Recorro el array desde el final para ver cu�l es el primer elemento que tiene valor distinto de cero. */
    for ( int i=100; i>=0; i-- ) {
        if ( edades[i] > 0 ) {
            edadMaxima = i;
            break;
        }
    }
    cout << "Edad m�xima por el m�todo 1: " << edadMaxima << endl;

    /* O bien: */
    edadMaxima = 100;
    while ( edades[edadMaxima] == 0 ) {
        edadMaxima--;
    }
    cout << "Edad m�xima por el m�todo 2: " << edadMaxima << endl;

    cout << "Habitantes con la edad m�xima: " << edades[edadMaxima] << endl;

    /* 5) �Cu�l es la edad m�nima de los habitantes de la ciudad? �Cu�ntos habitantes hay de dicha edad? */
    int edadMinima = 0;
    while ( edades[edadMinima] == 0 ) {
        edadMinima++;
    }
    cout << "Edad m�nima: " << edadMinima << endl;

    cout << "Habitantes con la edad m�nima: " << edades[edadMinima] << endl;;

    /* 6) �Cu�l es el n�mero m�ximo de habitantes de una misma edad? �Cu�l/cu�les son dichas edad/edades? */
    /* Recorro el array para ver cu�l es el valor m�s grande de personas con una determinada edad. */
    int masHabitantes = edades[0];
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] > masHabitantes ) {
            masHabitantes = edades[i];
        }
    }

    cout << "La edad representada con m�s habitantes es: " << masHabitantes << endl;

    /* Y recorro a ver cu�l es la edad correspondiente. */
    cout << "Correspondiente a las edades:" << endl;
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] == masHabitantes ) {
            cout << i << endl;
        }
    }

    /* 7) �Cu�l es el n�mero m�nimo de habitantes de una misma edad? �Cu�l/cu�les son dichas edad/edades? */
    int menosHabitantes = edades[0];
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] < menosHabitantes ) {
            menosHabitantes = edades[i];
        }
    }

    cout << "La edad representada con menos habitantes es: " << menosHabitantes << endl;

    /* Y recorro a ver cu�l es la edad correspondiente. */
    cout << "Correspondiente a las edades:" << endl;
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] == menosHabitantes ) {
            cout << i << endl;
        }
    }

    /* 8) En un posible sufragio, �cu�ntos habitantes habr�a en el censo electoral? (es decir, cu�ntos habitantes tienen
    una edad igual o superior a 18 a�os? */
    int electores = 0;
    for ( int i=18; i<=100; i++) {
        electores += edades[i];
    }

    cout << "Electores: " << electores << endl;

    /* 9) �Hay alguna edad que no est� representada por ning�n habitante de la ciudad? (por ejemplo, ning�n habitante de
    la ciudad tiene 20 a�os ni 47 a�os). Indique cu�l/cu�les. */
    cout << "No hay ning�n habitante de:" << endl;
    /* Primero un recuento de cu�ntas edades est�n vac�as para poder expresarnos con propiedad. */
    int contador = 0;
    for ( int i=0; i<=100; i++) {
        if ( edades[i] == 0 ) {
            contador++;
        }
    }
    if ( contador == 0 ) {
        cout << "Todas las edades est�n representadas" << endl;
    } else {
        for ( int i=0; i<=100; i++) {
            if ( edades[i] == 0 ) {
                cout << i << " a�os" << endl;
            }
        }
    }

    /* 10) �De qu� color es el caballo blanco de Santiago? */
    cout << "El caballo blanco de Santiago era blanco, pero se tizn� de holl�n y ahora es negro." << endl;

    system("pause");
    return 0;
}
