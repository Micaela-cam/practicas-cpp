#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    srand(time(NULL));

    /* 1) En una ciudad viven un número aleatorio de personas entre (8.000 y 15.000). Suponiendo que las edades de estas
    personas están comprendidas entre 0 y 100 años, cree un array de 101 posiciones para llevar el recuento de cuántas
    personas hay en la ciudad de cada una de las posibles edades. */
    int poblacion = 8000 + rand() % (15000 - 8000 + 1);
    cout << "Población de la ciudad: " << poblacion << " habitantes." << endl;

    int edades[101];
    /* Inicializo a cero todos los elementos del array. */
    for ( int i=0; i<=100; i++ ) {
        edades[i] = 0;
    }

    /* 2) En un bucle, recorra uno a uno los habitantes de la ciudad y asígneles a cada uno una edad aleatoria (entre 0 y
    100, recuerde). La edad que se obtenga en cada vuelta del bucle, servirá para ir incrementando en una unidad el número
    de personas de dicha edad que hay en la ciudad (el recuento, recuerde, se llevará en el array que se generó en el
    paso 1). */
    int edad;
    for ( int i=1; i<=poblacion; i++) {
        edad = 0 + rand() % (100 - 0 + 1);
        edades[edad]++;
    }

    /* 3) ¿Cuál es la edad media de edad de la población? */
    int sumatorio = 0;
    /* Sumamos la cantidad de habitantes que hay de cada edad por dicha edad. */
    for ( int i=0; i<=100; i++) {
        sumatorio = sumatorio + edades[i] * i;
    }
    float edadMedia = (float)sumatorio / (float)poblacion;

    cout << "Edad media de la población: " << edadMedia << endl;

    /* 4) ¿Cuál es la edad máxima de los habitantes de la ciudad? ¿Cuántos habitantes hay de dicha edad? */
    int edadMaxima;
    /* Recorro el array desde el final para ver cuál es el primer elemento que tiene valor distinto de cero. */
    for ( int i=100; i>=0; i-- ) {
        if ( edades[i] > 0 ) {
            edadMaxima = i;
            break;
        }
    }
    cout << "Edad máxima por el método 1: " << edadMaxima << endl;

    /* O bien: */
    edadMaxima = 100;
    while ( edades[edadMaxima] == 0 ) {
        edadMaxima--;
    }
    cout << "Edad máxima por el método 2: " << edadMaxima << endl;

    cout << "Habitantes con la edad máxima: " << edades[edadMaxima] << endl;

    /* 5) ¿Cuál es la edad mínima de los habitantes de la ciudad? ¿Cuántos habitantes hay de dicha edad? */
    int edadMinima = 0;
    while ( edades[edadMinima] == 0 ) {
        edadMinima++;
    }
    cout << "Edad mínima: " << edadMinima << endl;

    cout << "Habitantes con la edad mínima: " << edades[edadMinima] << endl;;

    /* 6) ¿Cuál es el número máximo de habitantes de una misma edad? ¿Cuál/cuáles son dichas edad/edades? */
    /* Recorro el array para ver cuál es el valor más grande de personas con una determinada edad. */
    int masHabitantes = edades[0];
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] > masHabitantes ) {
            masHabitantes = edades[i];
        }
    }

    cout << "La edad representada con más habitantes es: " << masHabitantes << endl;

    /* Y recorro a ver cuál es la edad correspondiente. */
    cout << "Correspondiente a las edades:" << endl;
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] == masHabitantes ) {
            cout << i << endl;
        }
    }

    /* 7) ¿Cuál es el número mínimo de habitantes de una misma edad? ¿Cuál/cuáles son dichas edad/edades? */
    int menosHabitantes = edades[0];
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] < menosHabitantes ) {
            menosHabitantes = edades[i];
        }
    }

    cout << "La edad representada con menos habitantes es: " << menosHabitantes << endl;

    /* Y recorro a ver cuál es la edad correspondiente. */
    cout << "Correspondiente a las edades:" << endl;
    for ( int i=0; i<=100; i++ ) {
        if ( edades[i] == menosHabitantes ) {
            cout << i << endl;
        }
    }

    /* 8) En un posible sufragio, ¿cuántos habitantes habría en el censo electoral? (es decir, cuántos habitantes tienen
    una edad igual o superior a 18 años? */
    int electores = 0;
    for ( int i=18; i<=100; i++) {
        electores += edades[i];
    }

    cout << "Electores: " << electores << endl;

    /* 9) ¿Hay alguna edad que no esté representada por ningún habitante de la ciudad? (por ejemplo, ningún habitante de
    la ciudad tiene 20 años ni 47 años). Indique cuál/cuáles. */
    cout << "No hay ningún habitante de:" << endl;
    /* Primero un recuento de cuántas edades están vacías para poder expresarnos con propiedad. */
    int contador = 0;
    for ( int i=0; i<=100; i++) {
        if ( edades[i] == 0 ) {
            contador++;
        }
    }
    if ( contador == 0 ) {
        cout << "Todas las edades están representadas" << endl;
    } else {
        for ( int i=0; i<=100; i++) {
            if ( edades[i] == 0 ) {
                cout << i << " años" << endl;
            }
        }
    }

    /* 10) ¿De qué color es el caballo blanco de Santiago? */
    cout << "El caballo blanco de Santiago era blanco, pero se tiznó de hollín y ahora es negro." << endl;

    system("pause");
    return 0;
}
