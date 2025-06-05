#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");

    /* A unas elecciones ficticias se presentan dos partidos: el partido A y el partido B.

    En un bucle, vamos a pedir once votos al usuario (que el usuario introduzca A para emitir un voto
    por el partido A o B para emitir un voto por el partido B). Después de cada voto, se incrementará
    el contador de votos totales de cada partido.

    En cada vuelta, se mostrará el recuento parcial de votos de cada partido.

    Al final de la votación, se mostrará qué partido ha ganado las elecciones (no vale decir que los dos).

    Repetir el ejercicio generando 1001 votos aleatorios a un partido u otro. */

    char votoEmitido;
    int contadorA = 0;
    int contadorB = 0;
    int contadorNulos = 0;

    /* Un bucle para pedir los votos. */
    for ( int voto=1; voto<=11; voto++ ) {
        cout << "Emita su voto (A o B): ";
        cin >> votoEmitido;
        if ( votoEmitido == 'A' || votoEmitido == 'a' ) {
            contadorA++;
        } else if ( votoEmitido == 'B' || votoEmitido == 'b' ) {
            contadorB++;
        } else {
            contadorNulos++;
        }
        cout << "Partido A: " << contadorA << endl;
        cout << "Partido B: " << contadorB << endl;
        cout << "Votos nulos: " << contadorNulos << endl;
    }

    /* Indicar cuál es el partido ganador. */
    if ( contadorA > contadorB ) {
        cout << "Felicidades. Ha ganado el partido A." << endl;
    } else if ( contadorB > contadorA ) {
        cout << "Felicidades. Ha ganado el partido B." << endl;
    } else {
        cout << "Ha habido un empate. Hay que repetir las elecciones." << endl;
    }

    /* Repetir el ejercicio generando 1001 votos aleatorios. */
    srand(time(NULL));
    int minimo = 1;
    int maximo = 2;
    int aleatorio;
    int contadorAbis = 0;
    int contadorBbis = 0;

    for ( int voto=1; voto <=1001; voto++ ) {
        aleatorio = minimo + rand() % (maximo - minimo + 1);
        if ( aleatorio == 1) {
            contadorAbis++;
        } else {
            contadorBbis++;
        }
    }

    if ( contadorAbis > contadorBbis ) {
        cout << "Ha ganado el partido A con " << contadorAbis << " votos." << endl;
    } else {
        cout << "Ha ganado el partido B con " << contadorBbis << " votos." << endl;
    }




    system("pause");
    return 0;
}
