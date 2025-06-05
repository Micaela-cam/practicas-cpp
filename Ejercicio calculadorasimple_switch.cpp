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
    //3. multiplicación
    //4. división
    //5. potencia
    //seleccionar una de las opciones
    //leer los dos valores con los que realizaremos la operación
    //mostrar el resultado.

    //mostrar las opciones en pantalla
    int opcion;
    cout << "Operaciones aritméticas básicas" << endl;
    cout << "1. suma"<< endl;
    cout << "2. resta" << endl;
    cout << "3. multiplicación" << endl;
    cout << "4. división" << endl;
    cout << "5. potencia" << endl;
    cout << "Seleccione una opción :" << endl;
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
            cout << "Operación de resta" << valor2 - valor1 << endl;
            }else{
            cout << "Operación de resta" << valor1 - valor2 << endl;
            }
            break;
        case 3:
            cout << "Operación de multiplicación:" << valor1 * valor2 <<  endl;
            break;
        case 4:
            if(valor1 < valor2){
            cout << "Operación de division" << valor2 / valor1 << endl;
            }else{
            cout << "Operación de division" << valor1 / valor2 << endl;
            }
            break;
        case 5:
            cout << "Resultado de la potencia" << pow(valor1, valor2) << endl;
            break;
        default:
            cout<< "opción seleccionada no válida" <<endl;

    }
    system("pause");
    return 0;
}
