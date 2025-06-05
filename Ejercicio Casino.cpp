#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    /* Un casino quiere realizar un estudio sobre la aleatoriedad de alguno de sus juegos: */

    /* 1) Cree un array con 37 posiciones para hacer un recuento de la frecuencia con la que aparecen los distintos
    n�meros de la ruleta (del 0 al 36). */
    int frecuencias[37];

    /* Inicializamos todas las posiciones del array a cero. */
    for ( int i=0; i<=36; i++ ) {
        frecuencias[i] = 0;
    }

    /* 2) Simule la realizaci�n de 500 tiradas de prueba. Con un bucle recorra las 500 tiradas y genere en cada una
    de ellas un valor aleatorio entre 0 y 36. En cada tirada, el n�mero aleatorio obtenido se utilizar� para ir
    incrementando el valor almacenado en el �ndice del mismo n�mero del array del paso anterior. De esta manera, se
    ir� realizando un recuento de las veces que aparece cada n�mero. */

    /* Una variable para el n�mero de tiradas. */
    int numeroTiradas = 10000000;

    /* Planto la semilla del aleatorio. */
    srand(time(NULL));
    int numero;

    for ( int tirada=1; tirada<=numeroTiradas; tirada++ ) {
        /* Generar un aleatorio. */
        numero = rand() % (37);
        /* Incrementamos el contador correspondiente a ese n�mero. */
        frecuencias[numero]++;
    }

    /* S�lo a modo de comprobaci�n. */
    for ( int i=0; i<=36; i++ ) {
        cout << "El " << i << " ha salido " << frecuencias[i] << " veces." << endl;
    }

    /* 3) �Cu�l es el o los n�meros que han aparecido m�s veces? �Cu�les son los que menos? */
    int menosVeces = numeroTiradas, masVeces = 0;
    /* Recorro el array y voy obteniendo los valores de cada elemento. Un valor mayor que masVeces pasar� a ser
    el nuevo masVeces. Un valor menor que menosVeces, pasar� a ser el nuevo menosVeces. */
    for ( int i=0; i<=36; i++ ) {
        if ( frecuencias[i]>masVeces ) {
            masVeces = frecuencias[i];
        }
        if ( frecuencias[i]<menosVeces ) {
            menosVeces = frecuencias[i];
        }
    }

    cout << "La cantidad de veces m�s peque�a que ha salido un n�mero es " << menosVeces << endl;
    cout << "La cantidad de veces m�s grande que ha salido un n�mero es " << masVeces << endl;

    cout << "El n�mero o los n�meros que menos han salido son: " << endl;
    for ( int i=0; i<=36; i++ ) {
        if ( frecuencias[i] == menosVeces ) {
            cout << i <<endl;
        }
    }

    cout << "El n�mero o los n�meros que m�s han salido son: " << endl;
    for ( int i=0; i<=36; i++ ) {
        if ( frecuencias[i] == masVeces ) {
            cout << i <<endl;
        }
    }

    /* 4) �Cu�l es el porcentaje de apariciones de cada n�mero? (por ejemplo, el 0 ha aparecido un 2.5% de las
    tiradas). */
    cout << "Porcentajes:" << endl;
    float porcentaje;
    for ( int i=0; i<=36; i++) {
        porcentaje = ( (float)frecuencias[i] * (float)100 ) / (float)numeroTiradas;
        cout << "N�mero " << i << ": " << porcentaje << "%" << endl;
    }

    /* 5) Calcule la media te�rica (en porcentaje) de las apariciones de cada n�mero. */
    float mediaTeorica = (float)100 / (float)37;
    cout << "Media te�rica: " << mediaTeorica << "%" << endl;

    /* 6) �El n�mero 0 de la ruleta se encuentra por encima o por debajo de dicha media? */
    float porcentajeCero = ( (float)frecuencias[0] * (float)100 ) / (float)numeroTiradas;
    if ( porcentajeCero > mediaTeorica ) {
        cout << "El cero est� por encima de la media." << endl;
    } else if ( porcentajeCero < mediaTeorica ) {
        cout << "El cero est� por debajo de la media." << endl;
    } else {
        cout << "El cero coincide exactamente con la media." << endl;
    }

    /* 7) �Cambian los resultados del punto 6 si se realizan 10.000 tiradas de muestra en lugar de 500? */

    /* 8) Repita el ejercicio anterior para el juego de los dados. En este caso, el juego consiste en arrojar dos
    dados (numerados del 1 al 6) y sumar el valor de ambos. Obs�rvese, que en este caso, se deber� crear un array
    para almacenar los valores posibles de la simulaci�n de tiradas de dos dados (del 2 al 12). Para simiplificar,
    se permite utilizar un array que incluya las posiciones 0 y 1, aunque no sean necesarias. Simule la realizaci�n
    de 500 tiradas de dos dados y repita todos los c�lculos del ejercicio anterior. */

    system("pause");
    return 0;
}
