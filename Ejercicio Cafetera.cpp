#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std;

class Cafetera {

    private:
        int capacidadMaxima; // Expresado en mililitros.
        int cantidadActual; // Idem.
        int cafeMolido; // Cucharadas de café de 0-10.
        int agua; // Tambien en mililitros, de cero a capacidadMaxima.
        float concentracion; // Cucharadas de café entre agua.

    public:
        /* Constructores. */
        Cafetera() {
            capacidadMaxima = 1000;
            cantidadActual = 0;
            cafeMolido = 0;
            agua = 0;
            concentracion = 0.0;
        }

        Cafetera( int capacidadMaxima, int cafeMolido, int agua ) {
            /* Por convención, si la capacidad máxima fuera negativa o cero, la fijamos en 1. */
            if ( capacidadMaxima <= 0 ) {
                this->capacidadMaxima = 1;
            } else {
                this->capacidadMaxima = capacidadMaxima;
            }

            this->cantidadActual = 0;
            setCafeMolido( cafeMolido );
            setAgua( agua );
            concentracion = 0.0;
        }

        /* Accesores. */

        /* Un atributo como la capacidad máxima no varía a lo largo del programa. Es identidad. Por lo tanto,
        creamos un getter pero no un setter, para impedir que pueda modificarse su valor. */
        int getCapacidadMaxima() {
            return capacidadMaxima;
        }

        int getCantidadActual() {
            return cantidadActual;
        }

        void setCantidadActual( int cantidadActual ) {
            if ( cantidadActual > capacidadMaxima ) {
                this->cantidadActual = capacidadMaxima;
            } else if ( cantidadActual < 0 ) {
                this->cantidadActual = 0;
            } else {
                this->cantidadActual = cantidadActual;
            }
        }

        int getCafeMolido() {
            return cafeMolido;
        }

        void setCafeMolido( int cafeMolido ) {
            if ( cafeMolido > 10 ) {
                this->cafeMolido = 10;
            } else if ( cafeMolido < 0 ) {
                this->cafeMolido = 0;
            } else {
                this->cafeMolido = cafeMolido;
            }
        }

        int getAgua() {
            return agua;
        }

        void setAgua( int agua ) {
            if ( agua > capacidadMaxima ) {
                this->agua = capacidadMaxima;
            } else if ( agua < 0 ) {
                this->agua = 0;
            } else {
                this->agua = agua;
            }
        }

        float getConcentracion() {
            return concentracion;
        }

        void setConcentracion() {
            if ( agua == 0 ) {
                concentracion = 0.0;
            } else {
                concentracion = (float)cafeMolido / (float)agua;
            }
        }

        string toString() {
            string resultado = "--------------------------\n";
            resultado += "Capacidad: " + to_string(capacidadMaxima) + "ml\n";
            resultado += "Café preparado: " + to_string(cantidadActual) + "ml\n";
            resultado += "Café molido: " + to_string(cafeMolido) + " cucharadas\n";
            resultado += "Agua: " + to_string(agua) + "ml\n";
            resultado += "Concentracion: " + to_string(concentracion) + "\n";
            resultado += "--------------------------\n";

            return resultado;
        }

        /* Métodos específicos. */

        void vaciarCafetera() {
            cantidadActual = 0;
            cafeMolido = 0;
            agua = 0;
            concentracion = 0.0;
        }

        void prepararCafe() {
            int cafeMolido, agua;

            /* Si hubiera café preparado, vacía la jarra. */
            cantidadActual = 0;

            while ( this->cafeMolido == 0 ) {
                cout << "Introduzca café molido (hasta 10): ";
                cin >> cafeMolido;
                setCafeMolido( cafeMolido );
            }

            while ( this->agua == 0 ) {
                cout << "Introduzca la cantida de agua (hasta "+ to_string(this->capacidadMaxima) + "): ";
                cin >> agua;
                setAgua( agua );
            }

            /* Preparo el café. */
            this->cantidadActual = this->agua;
            /* Calculo la concentración. */
            setConcentracion();
            /* Limpio la cafetera. */
            this->cafeMolido = 0;
            this->agua = 0;
        }

        /* Preparar café sobrecargado. */
        void prepararCafe( int agua, int cafeMolido ) {
            /* Teniendo en cuenta las reglas de negocio. */
            setAgua( agua );
            setCafeMolido( cafeMolido );

            /* Llamo al método prepararCafe por defecto. */
            prepararCafe();
        }

        void servirTaza( int capacidad ) {
            if ( capacidad < 0 ) {
                capacidad = 0;
            }
            if ( capacidad > cantidadActual ) {
                capacidad = cantidadActual;
            }
            cantidadActual -= capacidad;
        }

};

int main() {

    setlocale(LC_ALL, "spanish");

    /* Instancio una cafetera con el constructor por defecto. */
    Cafetera cafetera1;
    cout << cafetera1.toString();

    cafetera1.prepararCafe( 500, 10 );
    cout << cafetera1.toString();

    cafetera1.servirTaza( 200 );
    cafetera1.servirTaza( 150 );
    cout << cafetera1.toString();

    cafetera1.vaciarCafetera();
    cout << cafetera1.toString();

    Cafetera cafetera2( 700, 8, 700 );
    cout << cafetera2.toString();

    cafetera2.prepararCafe();
    cout << cafetera2.toString();

    cafetera2.servirTaza( 250 );
    cout << cafetera2.toString();

    system("pause");
    return 0;
}
