#ifndef ARBOLBST_H
#define ARBOLBST_H

#include "Estudiante.h"

struct Nodo {
    Estudiante estudiante;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(Estudiante est) : estudiante(est), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolBST {
private:
    Nodo* raiz;

    // Funciones recursivas privadas
    Nodo* insertarRecursivo(Nodo* nodo, Estudiante est);
    Nodo* buscarRecursivo(Nodo* nodo, string cedula);
    Nodo* eliminarRecursivo(Nodo* nodo, string cedula);
    Nodo* encontrarMinimo(Nodo* nodo);

    void inordenRecursivo(Nodo* nodo);
    void preordenRecursivo(Nodo* nodo);
    void postordenRecursivo(Nodo* nodo);

    int contarNodosRecursivo(Nodo* nodo);
    int calcularAlturaRecursivo(Nodo* nodo);

    void buscarNotaMayorRecursivo(Nodo* nodo, Estudiante*& mayor);
    void buscarNotaMenorRecursivo(Nodo* nodo, Estudiante*& menor);
    void mostrarAprobadosRecursivo(Nodo* nodo);
    void mostrarReprobadosRecursivo(Nodo* nodo);

public:
    ArbolBST();
    ~ArbolBST();

    void insertarEstudiante(Estudiante est);
    void buscarEstudiante(string cedula);
    void eliminarEstudiante(string cedula);

    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();
    void recorridoPorNiveles(); // BFS con cola

    int contarNodos();
    int calcularAltura();

    void buscarNotaMayor();
    void buscarNotaMenor();
    void mostrarAprobados();
    void mostrarReprobados();
};

#endif