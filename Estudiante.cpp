#include "Estudiante.h"
#include <iostream>
#include <iomanip>

Estudiante::Estudiante() {
    cedula = "";
    apellidos = "";
    nombres = "";
    notaFinal = 0.0;
    carrera = "";
    nivel = "";
}

Estudiante::Estudiante(string ced, string ape, string nom, double nota, string carr, string niv) {
    cedula = ced;
    apellidos = ape;
    nombres = nom;
    notaFinal = nota;
    carrera = carr;
    nivel = niv;
}

string Estudiante::getCedula() const { return cedula; }
string Estudiante::getApellidos() const { return apellidos; }
string Estudiante::getNombres() const { return nombres; }
double Estudiante::getNotaFinal() const { return notaFinal; }
string Estudiante::getCarrera() const { return carrera; }
string Estudiante::getNivel() const { return nivel; }

void Estudiante::setCedula(string ced) { cedula = ced; }
void Estudiante::setApellidos(string ape) { apellidos = ape; }
void Estudiante::setNombres(string nom) { nombres = nom; }
void Estudiante::setNotaFinal(double nota) { notaFinal = nota; }
void Estudiante::setCarrera(string carr) { carrera = carr; }
void Estudiante::setNivel(string niv) { nivel = niv; }

void Estudiante::mostrar() const {
    cout << "Cédula: " << cedula << " | "
         << "Apellidos: " << apellidos << " | "
         << "Nombres: " << nombres << " | "
         << "Nota: " << fixed << setprecision(2) << notaFinal << " | "
         << "Carrera: " << carrera << " | "
         << "Nivel: " << nivel << endl;
}