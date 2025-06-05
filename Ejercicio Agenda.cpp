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

/* Un "array din�mico" para guardar todos los contactos. */
vector<contacto> agenda;

/* Funci�n que pinta el men� en pantalla. */
int menu() {

    int opcion;
    do {
        /* Borro la pantalla. */
        system("cls");

        /* Pinto el men�. */
        cout << "0. Salir de la aplicaci�n." << endl;
        cout << "1. A�adir un contacto a la agenda." << endl;
        cout << "2. Modificar un contacto de la agenda." << endl;
        cout << "3. Eliminar un contacto de la agenda." << endl;
        cout << "4. Eliminar todos los contactos de la agenda." << endl;
        cout << "5. Mostrar todos los contactos de la agenda." << endl;
        cout << endl;

        /* Pido la opci�n. */
        cout << "Elija una opci�n (0-5): ";
        cin >> opcion;
        /* Es necesario para que no se quede el enter pendiente para la siguiente lectura. */
        cin.ignore();

        if ( opcion<0 || opcion>5 ) {
            cout << "La opci�n debe estar comprendida entre 0 y 5. Vuelva a intentarlo."  << endl;
            system("pause");
        }
    } while ( opcion<0 || opcion>5 );

    /* Devuelvo la opci�n seleccionada. */
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

    cout << "Introduzca el tel�fono: ";
    getline(cin,agregarTelefono);
    nuevoContacto.telefono = agregarTelefono;

    cout << "Introduzca el correo electr�nico: ";
    getline(cin,agregarCorreo);
    nuevoContacto.correo = agregarCorreo;

    /* Agrego la estructura del contacto al vector. */
    agenda.push_back(nuevoContacto);

    cout << "Contacto agregado con �xito." << endl;
    system("pause");

}

void modificarContacto() {

    /* Podr�a mostrar previamente la lista de contactos o, simplemente, esperar el n�mero de dicho contacto. */

    system("cls");

    /* Variable que almacena el �ndice del contacto a modificar. */
    int idContacto;
    /* Variables para los nuevos valores de los miembros del contacto. */
    string nuevoNombre, nuevoTelefono, nuevoCorreo;

    do {
        cout << "Introduzca el n�mero de contacto a modificar: ";
        cin >> idContacto;
        cin.ignore();
        if ( idContacto<0 || idContacto>=agenda.size() ) {
            cout << "Error. Ese contacto no existe. Int�ntelo de nuevo." << endl;
        }
    } while ( idContacto<0 || idContacto>=agenda.size() );

    cout << "Escriba el nuevo nombre: ";
    getline(cin,nuevoNombre);
    agenda.at(idContacto).nombre = nuevoNombre;

    cout << "Escriba el nuevo tel�fono: ";
    getline(cin,nuevoTelefono);
    agenda.at(idContacto).telefono = nuevoTelefono;

    cout << "Escriba el nuevo correo: ";
    getline(cin,nuevoCorreo);
    agenda.at(idContacto).correo = nuevoCorreo;

    cout << "Contacto modificado con �xito." << endl;
    system("pause");

}

void eliminarContacto() {

    system("cls");

    /* Almacena el �ndice del contacto a eliminar. */
    int idContacto;

    do {
        cout << "Introduzca el n�mero de contacto a eliminar: ";
        cin >> idContacto;
        cin.ignore();
        if ( idContacto<0 || idContacto>=agenda.size() ) {
            cout << "Error. Ese contacto no existe. Int�ntelo de nuevo." << endl;
        }
    } while ( idContacto<0 || idContacto>=agenda.size() );

    /* Borro el contacto. */
    agenda.erase(agenda.begin() + idContacto);

    cout << "Contacto eliminado con �xito." << endl;
    system("pause");

}

void eliminarTodos() {

    system("cls");

    agenda.clear();

    cout << "Contactos eliminados con �xito." << endl;
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
        /* Seg�n la opci�n elegida, llamo a una funci�n u otra. As�, hago m�s legible el c�digo y m�s f�cil de mantener. */
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
