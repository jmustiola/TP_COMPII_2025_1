#include "Objetivos.h"
#include <iostream>
using namespace std;

enum {
    OBJETIVO_CINCO = 1,
    OBJETIVO_SEIS,
    OBJETIVO_SIETE,
    SALIR = 0,
};

void printMenu();

int main() 
{
    int opcion;
    do {
        printMenu();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion) {
            case OBJETIVO_CINCO:
                // objetivoCinco(); // Implementar esta función
                break;
            case OBJETIVO_SEIS:
                cout << "Ejecutando Objetivo 6..." << endl;
                cout << "==========================" << endl;
                cout << "Desea crear una lista para la prueba o usar la lista por defecto? (0: Crear, 1: Usar por defecto): ";
                bool useDefault;
                cin >> useDefault;
                objetivoSeis(useDefault);
                break;
            case OBJETIVO_SIETE:
                // objetivoSiete(); // Implementar esta función
                break;
            case SALIR:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 0); 
    return 0;
}

void printMenu() 
{
    cout << "Seleccione un objetivo:" << endl;
    cout << OBJETIVO_CINCO << ". Objetivo 5" << endl;
    cout << OBJETIVO_SEIS << ". Objetivo 6" << endl;
    cout << OBJETIVO_SIETE << ". Objetivo 7" << endl;
    cout << SALIR << ". Salir" << endl;
}