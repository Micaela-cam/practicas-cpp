#include <iostream>
#include <clocale>
#include<cstdlib>
#include <math.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "spanish");
    //mostrar mediante un switch las operaciones que puede realizar
    //1. suma
    //2. resta
    //3. multiplicaci�n
    //4. divisi�n
    //5. potencia
    //seleccionar una de las opciones
    //leer los dos valores con los que realizaremos la operaci�n
    //mostrar el resultado.

    //mostrar las opciones en pantalla
    int opcion;
    cout << "Operaciones aritm�ticas b�sicas" << endl;
    cout << "1. suma"<< endl;
    cout << "2. resta" << endl;
    cout << "3. multiplicaci�n" << endl;
    cout << "4. divisi�n" << endl;
    cout << "5. potencia" << endl;
    cout << "Seleccione una opci�n :" << endl;
    cin >> opcion;
    //solicitar los valores
    int valor1, valor2;
    cout << "Introduzca un valor:";
    cin >> valor1;
    cout <<" Introduzca otro valor:";
    cin >> valor2;

    //utilizando el switch
    switch(opcion){
        case 1: cout << "Resultado de la suma" << valor1 + valor2 << endl;
                break;
        case 2:
            if(valor1 < valor2){
            cout << "Operaci�n de resta" << valor2 - valor1 << endl;
            }else{
            cout << "Operaci�n de resta" << valor1 - valor2 << endl;
            }
            break;
        case 3:
            cout << "Operaci�n de multiplicaci�n:" << valor1 * valor2 <<  endl;
            break;
        case 4:
            if(valor1 < valor2){
            cout << "Operaci�n de division" << valor2 / valor1 << endl;
            }else{
            cout << "Operaci�n de division" << valor1 / valor2 << endl;
            }
            break;
        case 5:
            cout << "Resultado de la potencia" << pow(valor1, valor2) << endl;
            break;
        default:
            cout<< "opci�n seleccionada no v�lida" <<endl;

    }
    system("pause");
    return 0;
}
