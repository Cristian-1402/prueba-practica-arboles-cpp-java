#include "ArbolBST.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>

using namespace std;

string validarCedula() {
    string ced;
    while (true) {
        cout << "Cedula (10 digitos): ";
        cin >> ced;
        if (ced.length() == 10 && all_of(ced.begin(), ced.end(), ::isdigit)) {
            break;
        }
        cout << "Cedula invalida. Debe tener 10 digitos numericos.\n";
    }
    return ced;
}

double validarNota() {
    double nota;
    while (true) {
        cout << "Nota final (0-10): ";
        cin >> nota;
        if (cin.fail() || nota < 0 || nota > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nota invalida. Debe estar entre 0 y 10.\n";
        } else {
            break;
        }
    }
    return nota;
}

int main() {
    ArbolBST arbol;
    int opcion;

    do {
        cout << "\n========================================\n";
        cout << "  SISTEMA ACADEMICO UTA - ARBOL BST\n";
        cout << "========================================\n";
        cout << "1. Insertar estudiante\n";
        cout << "2. Buscar estudiante por cedula\n";
        cout << "3. Eliminar estudiante\n";
        cout << "4. Recorrido Inorden\n";
        cout << "5. Recorrido Preorden\n";
        cout << "6. Recorrido Postorden\n";
        cout << "7. Recorrido por niveles BFS\n";
        cout << "8. Contar estudiantes\n";
        cout << "9. Calcular altura del arbol\n";
        cout << "10. Mostrar estudiante con mayor nota\n";
        cout << "11. Mostrar estudiante con menor nota\n";
        cout << "12. Mostrar estudiantes aprobados\n";
        cout << "13. Mostrar estudiantes reprobados\n";
        cout << "14. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string ced = validarCedula();
                string apellidos, nombres, carrera, nivel;
                double nota;
                cout << "Apellidos: ";
                cin.ignore();
                getline(cin, apellidos);
                cout << "Nombres: ";
                getline(cin, nombres);
                nota = validarNota();
                cout << "Carrera: ";
                cin.ignore(); // Limpiar buffer antes de getline si es necesario
                getline(cin, carrera);
                cout << "Nivel: ";
                getline(cin, nivel);

                Estudiante nuevo(ced, apellidos, nombres, nota, carrera, nivel);
                arbol.insertarEstudiante(nuevo);
                break;
            }
            case 2: {
                string ced = validarCedula();
                arbol.buscarEstudiante(ced);
                break;
            }
            case 3: {
                string ced = validarCedula();
                arbol.eliminarEstudiante(ced);
                break;
            }
            case 4: arbol.recorridoInorden(); break;
            case 5: arbol.recorridoPreorden(); break;
            case 6: arbol.recorridoPostorden(); break;
            case 7: arbol.recorridoPorNiveles(); break;
            case 8:
                cout << "Total estudiantes: " << arbol.contarNodos() << endl;
                break;
            case 9:
                cout << "Altura del arbol: " << arbol.calcularAltura() << endl;
                break;
            case 10: arbol.buscarNotaMayor(); break;
            case 11: arbol.buscarNotaMenor(); break;
            case 12: arbol.mostrarAprobados(); break;
            case 13: arbol.mostrarReprobados(); break;
            case 14:
                cout << "Saliendo del sistema. Hasta luego!\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 14);

    return 0;
}