#include <iostream>
#include <clocale>
#include <cstdlib>
#include <vector>

using namespace std;

/* Estructura con los miembros de un contacto. */
struct contacto {
    string nombre;
    string telefono;
    string correo;
};

/* Un "array dinámico" para guardar todos los contactos. */
vector<contacto> agenda;

/* Función que pinta el menú en pantalla. */
int menu() {

    int opcion;
    do {
        /* Borro la pantalla. */
        system("cls");

        /* Pinto el menú. */
        cout << "0. Salir de la aplicación." << endl;
        cout << "1. Añadir un contacto a la agenda." << endl;
        cout << "2. Modificar un contacto de la agenda." << endl;
        cout << "3. Eliminar un contacto de la agenda." << endl;
        cout << "4. Eliminar todos los contactos de la agenda." << endl;
        cout << "5. Mostrar todos los contactos de la agenda." << endl;
        cout << endl;

        /* Pido la opción. */
        cout << "Elija una opción (0-5): ";
        cin >> opcion;
        /* Es necesario para que no se quede el enter pendiente para la siguiente lectura. */
        cin.ignore();

        if ( opcion<0 || opcion>5 ) {
            cout << "La opción debe estar comprendida entre 0 y 5. Vuelva a intentarlo."  << endl;
            system("pause");
        }
    } while ( opcion<0 || opcion>5 );

    /* Devuelvo la opción seleccionada. */
    return opcion;

}

void agregarContacto() {

    /* Variables para pedir los tres componentes del contacto. */
    string agregarNombre, agregarTelefono, agregarCorreo;
    /* Estructura para almacenar el contacto. */
    contacto nuevoContacto;

    system("cls");

    cout << "Introduzca el nombre: ";
    getline(cin,agregarNombre);
    nuevoContacto.nombre = agregarNombre;

    cout << "Introduzca el teléfono: ";
    getline(cin,agregarTelefono);
    nuevoContacto.telefono = agregarTelefono;

    cout << "Introduzca el correo electrónico: ";
    getline(cin,agregarCorreo);
    nuevoContacto.correo = agregarCorreo;

    /* Agrego la estructura del contacto al vector. */
    agenda.push_back(nuevoContacto);

    cout << "Contacto agregado con éxito." << endl;
    system("pause");

}

void modificarContacto() {

    /* Podría mostrar previamente la lista de contactos o, simplemente, esperar el número de dicho contacto. */

    system("cls");

    /* Variable que almacena el índice del contacto a modificar. */
    int idContacto;
    /* Variables para los nuevos valores de los miembros del contacto. */
    string nuevoNombre, nuevoTelefono, nuevoCorreo;

    do {
        cout << "Introduzca el número de contacto a modificar: ";
        cin >> idContacto;
        cin.ignore();
        if ( idContacto<0 || idContacto>=agenda.size() ) {
            cout << "Error. Ese contacto no existe. Inténtelo de nuevo." << endl;
        }
    } while ( idContacto<0 || idContacto>=agenda.size() );

    cout << "Escriba el nuevo nombre: ";
    getline(cin,nuevoNombre);
    agenda.at(idContacto).nombre = nuevoNombre;

    cout << "Escriba el nuevo teléfono: ";
    getline(cin,nuevoTelefono);
    agenda.at(idContacto).telefono = nuevoTelefono;

    cout << "Escriba el nuevo correo: ";
    getline(cin,nuevoCorreo);
    agenda.at(idContacto).correo = nuevoCorreo;

    cout << "Contacto modificado con éxito." << endl;
    system("pause");

}

void eliminarContacto() {

    system("cls");

    /* Almacena el índice del contacto a eliminar. */
    int idContacto;

    do {
        cout << "Introduzca el número de contacto a eliminar: ";
        cin >> idContacto;
        cin.ignore();
        if ( idContacto<0 || idContacto>=agenda.size() ) {
            cout << "Error. Ese contacto no existe. Inténtelo de nuevo." << endl;
        }
    } while ( idContacto<0 || idContacto>=agenda.size() );

    /* Borro el contacto. */
    agenda.erase(agenda.begin() + idContacto);

    cout << "Contacto eliminado con éxito." << endl;
    system("pause");

}

void eliminarTodos() {

    system("cls");

    agenda.clear();

    cout << "Contactos eliminados con éxito." << endl;
    system("pause");

}

void mostrarAgenda() {

    system("cls");

    /* Variable para ir leyendo los contactos. */
    contacto miContacto;

    /* Compruebo si hay contactos que mostrar. */
    if ( agenda.empty() ) {
        cout << "No hay contactos que mostrar." << endl;
    } else {
        for ( int i=0; i<agenda.size(); i++ ) {
            miContacto = agenda.at(i);
            cout << "Contacto " << i << ": " << miContacto.nombre << " - " << miContacto.telefono << " - " << miContacto.correo << endl;
        }
    }

    system("pause");

}

int main() {

    setlocale(LC_ALL, "spanish");

    int opcion;
    /* Pido opciones hasta que el usuario elija 0. */
    do {
        opcion = menu();
        /* Según la opción elegida, llamo a una función u otra. Así, hago más legible el código y más fácil de mantener. */
        switch ( opcion ) {
        case 1:
            agregarContacto();
            break;
        case 2:
            modificarContacto();
            break;
        case 3:
            eliminarContacto();
            break;
        case 4:
            eliminarTodos();
            break;
        case 5:
            mostrarAgenda();
            break;
        }
    } while ( opcion != 0 );

    system("pause");
    return 0;
}
