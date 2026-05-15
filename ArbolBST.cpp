#include "ArbolBST.h"
#include <iostream>
#include <queue>

ArbolBST::ArbolBST() : raiz(nullptr) {}

ArbolBST::~ArbolBST() {
    // Liberar memoria (recorrido postorder implícito)
    while (raiz) {
        eliminarEstudiante(raiz->estudiante.getCedula());
    }
}

// ---------- INSERCIÓN (recursiva) ----------
Nodo* ArbolBST::insertarRecursivo(Nodo* nodo, Estudiante est) {
    if (nodo == nullptr) {
        return new Nodo(est);
    }

    if (est.getCedula() < nodo->estudiante.getCedula()) {
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, est);
    } else if (est.getCedula() > nodo->estudiante.getCedula()) {
        nodo->derecho = insertarRecursivo(nodo->derecho, est);
    } else {
        cout << "Error: Ya existe un estudiante con la cédula " << est.getCedula() << endl;
    }
    return nodo;
}

void ArbolBST::insertarEstudiante(Estudiante est) {
    raiz = insertarRecursivo(raiz, est);
}

// ---------- BÚSQUEDA (recursiva) ----------
Nodo* ArbolBST::buscarRecursivo(Nodo* nodo, string cedula) {
    if (nodo == nullptr) return nullptr;

    if (cedula == nodo->estudiante.getCedula()) {
        return nodo;
    } else if (cedula < nodo->estudiante.getCedula()) {
        return buscarRecursivo(nodo->izquierdo, cedula);
    } else {
        return buscarRecursivo(nodo->derecho, cedula);
    }
}

void ArbolBST::buscarEstudiante(string cedula) {
    Nodo* resultado = buscarRecursivo(raiz, cedula);
    if (resultado) {
        cout << "Estudiante encontrado:\n";
        resultado->estudiante.mostrar();
    } else {
        cout << "No existe estudiante con cédula " << cedula << endl;
    }
}

// ---------- ELIMINACIÓN (recursiva con 3 casos) ----------
Nodo* ArbolBST::encontrarMinimo(Nodo* nodo) {
    while (nodo && nodo->izquierdo) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

Nodo* ArbolBST::eliminarRecursivo(Nodo* nodo, string cedula) {
    if (nodo == nullptr) return nullptr;

    if (cedula < nodo->estudiante.getCedula()) {
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, cedula);
    } else if (cedula > nodo->estudiante.getCedula()) {
        nodo->derecho = eliminarRecursivo(nodo->derecho, cedula);
    } else {
        // Caso 1: sin hijos
        if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
            delete nodo;
            return nullptr;
        }
        // Caso 2: un hijo
        else if (nodo->izquierdo == nullptr) {
            Nodo* temp = nodo->derecho;
            delete nodo;
            return temp;
        } else if (nodo->derecho == nullptr) {
            Nodo* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }
        // Caso 3: dos hijos -> reemplazar por el mínimo del subárbol derecho
        else {
            Nodo* temp = encontrarMinimo(nodo->derecho);
            nodo->estudiante = temp->estudiante;
            nodo->derecho = eliminarRecursivo(nodo->derecho, temp->estudiante.getCedula());
        }
    }
    return nodo;
}

void ArbolBST::eliminarEstudiante(string cedula) {
    raiz = eliminarRecursivo(raiz, cedula);
    cout << "Eliminación procesada (si existía)." << endl;
}

// ---------- RECORRIDOS ----------
void ArbolBST::inordenRecursivo(Nodo* nodo) {
    if (nodo) {
        inordenRecursivo(nodo->izquierdo);
        nodo->estudiante.mostrar();
        inordenRecursivo(nodo->derecho);
    }
}

void ArbolBST::recorridoInorden() {
    cout << "\n--- RECORRIDO INORDEN (ordenado por cédula) ---\n";
    inordenRecursivo(raiz);
}

void ArbolBST::preordenRecursivo(Nodo* nodo) {
    if (nodo) {
        nodo->estudiante.mostrar();
        preordenRecursivo(nodo->izquierdo);
        preordenRecursivo(nodo->derecho);
    }
}

void ArbolBST::recorridoPreorden() {
    cout << "\n--- RECORRIDO PREORDEN ---\n";
    preordenRecursivo(raiz);
}

void ArbolBST::postordenRecursivo(Nodo* nodo) {
    if (nodo) {
        postordenRecursivo(nodo->izquierdo);
        postordenRecursivo(nodo->derecho);
        nodo->estudiante.mostrar();
    }
}

void ArbolBST::recorridoPostorden() {
    cout << "\n--- RECORRIDO POSTORDEN ---\n";
    postordenRecursivo(raiz);
}

// BFS con cola (NO recursivo)
void ArbolBST::recorridoPorNiveles() {
    if (!raiz) {
        cout << "El árbol está vacío.\n";
        return;
    }
    queue<Nodo*> cola;
    cola.push(raiz);

    cout << "\n--- RECORRIDO POR NIVELES (BFS) ---\n";
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        actual->estudiante.mostrar();

        if (actual->izquierdo) cola.push(actual->izquierdo);
        if (actual->derecho) cola.push(actual->derecho);
    }
}

// ---------- ESTADÍSTICAS ----------
int ArbolBST::contarNodosRecursivo(Nodo* nodo) {
    if (!nodo) return 0;
    return 1 + contarNodosRecursivo(nodo->izquierdo) + contarNodosRecursivo(nodo->derecho);
}

int ArbolBST::contarNodos() {
    return contarNodosRecursivo(raiz);
}

int ArbolBST::calcularAlturaRecursivo(Nodo* nodo) {
    if (!nodo) return -1; // Altura de árbol vacío = -1
    int altIzq = calcularAlturaRecursivo(nodo->izquierdo);
    int altDer = calcularAlturaRecursivo(nodo->derecho);
    return 1 + max(altIzq, altDer);
}

int ArbolBST::calcularAltura() {
    return calcularAlturaRecursivo(raiz);
}

// ---------- NOTAS ----------
void ArbolBST::buscarNotaMayorRecursivo(Nodo* nodo, Estudiante*& mayor) {
    if (!nodo) return;
    if (!mayor || nodo->estudiante.getNotaFinal() > mayor->getNotaFinal()) {
        mayor = &nodo->estudiante;
    }
    buscarNotaMayorRecursivo(nodo->izquierdo, mayor);
    buscarNotaMayorRecursivo(nodo->derecho, mayor);
}

void ArbolBST::buscarNotaMayor() {
    if (!raiz) {
        cout << "Árbol vacío.\n";
        return;
    }
    Estudiante* mayor = nullptr;
    buscarNotaMayorRecursivo(raiz, mayor);
    if (mayor) {
        cout << "Estudiante con MAYOR nota:\n";
        mayor->mostrar();
    }
}

void ArbolBST::buscarNotaMenorRecursivo(Nodo* nodo, Estudiante*& menor) {
    if (!nodo) return;
    if (!menor || nodo->estudiante.getNotaFinal() < menor->getNotaFinal()) {
        menor = &nodo->estudiante;
    }
    buscarNotaMenorRecursivo(nodo->izquierdo, menor);
    buscarNotaMenorRecursivo(nodo->derecho, menor);
}

void ArbolBST::buscarNotaMenor() {
    if (!raiz) {
        cout << "Árbol vacío.\n";
        return;
    }
    Estudiante* menor = nullptr;
    buscarNotaMenorRecursivo(raiz, menor);
    if (menor) {
        cout << "Estudiante con MENOR nota:\n";
        menor->mostrar();
    }
}

void ArbolBST::mostrarAprobadosRecursivo(Nodo* nodo) {
    if (nodo) {
        mostrarAprobadosRecursivo(nodo->izquierdo);
        if (nodo->estudiante.getNotaFinal() >= 7.0) {
            nodo->estudiante.mostrar();
        }
        mostrarAprobadosRecursivo(nodo->derecho);
    }
}

void ArbolBST::mostrarAprobados() {
    cout << "\nESTUDIANTES APROBADOS (nota >= 7):\n";
    mostrarAprobadosRecursivo(raiz);
}

void ArbolBST::mostrarReprobadosRecursivo(Nodo* nodo) {
    if (nodo) {
        mostrarReprobadosRecursivo(nodo->izquierdo);
        if (nodo->estudiante.getNotaFinal() < 7.0) {
            nodo->estudiante.mostrar();
        }
        mostrarReprobadosRecursivo(nodo->derecho);
    }
}

void ArbolBST::mostrarReprobados() {
    cout << "\nESTUDIANTES REPROBADOS (nota < 7):\n";
    mostrarReprobadosRecursivo(raiz);
}