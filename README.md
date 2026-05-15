# Sistema Académico UTA - Árbol Binario de Búsqueda en C++

## Descripción del Proyecto

Este proyecto implementa un sistema de gestión académica para la Universidad Técnica de Ambato (UTA) utilizando un **Árbol Binario de Búsqueda (BST)** como estructura de datos principal. El sistema permite administrar información de estudiantes, incluyendo cédula, apellidos, nombres, nota final, carrera y nivel.

La implementación está desarrollada íntegramente en **C++** siguiendo los principios de programación orientada a objetos, haciendo uso obligatorio de **punteros** para la gestión de memoria y **recursividad** para las operaciones fundamentales del árbol.

## Estructura del Proyecto
```
prueba-practica-arboles-cpp-java/
├── Estudiante.h          # Definición de la clase Estudiante
├── Estudiante.cpp        # Implementación de métodos de Estudiante
├── ArbolBST.h            # Definición de la clase ArbolBST y estructura Nodo
├── ArbolBST.cpp          # Implementación de todas las operaciones del BST
├── main.cpp              # Menú interactivo y punto de entrada del programa
└── README.md             # Documentación del proyecto
```

## Clases y Módulos

### Clase Estudiante
Representa la información personal y académica de un estudiante. Contiene los siguientes atributos privados:
- `cedula` (string): clave de búsqueda principal
- `apellidos` (string)
- `nombres` (string)
- `notaFinal` (double): valor entre 0 y 10
- `carrera` (string)
- `nivel` (string)

Incluye métodos getter, setter y un método `mostrar()` para visualizar todos los datos.

### Clase ArbolBST
Administra el árbol binario de búsqueda mediante una estructura `Nodo` que contiene:
- Un objeto `Estudiante`
- Punteros a los subárboles izquierdo y derecho

## Funcionalidades Implementadas

El sistema ofrece un menú interactivo con las siguientes 14 opciones:

| Opción | Función | Descripción |
|--------|---------|-------------|
| 1 | Insertar estudiante | Inserta un nuevo estudiante en el árbol usando la cédula como clave |
| 2 | Buscar estudiante | Busca y muestra todos los datos de un estudiante por su cédula |
| 3 | Eliminar estudiante | Elimina un nodo del árbol manejando los tres casos de eliminación en BST |
| 4 | Recorrido Inorden | Muestra los estudiantes en orden ascendente por cédula |
| 5 | Recorrido Preorden | Recorrido raíz-izquierda-derecha |
| 6 | Recorrido Postorden | Recorrido izquierda-derecha-raíz |
| 7 | Recorrido por niveles (BFS) | Recorrido por niveles utilizando una cola (std::queue) |
| 8 | Contar estudiantes | Retorna el número total de nodos en el árbol |
| 9 | Calcular altura | Calcula la altura máxima del árbol |
| 10 | Mostrar mayor nota | Encuentra y muestra el estudiante con la nota más alta |
| 11 | Mostrar menor nota | Encuentra y muestra el estudiante con la nota más baja |
| 12 | Mostrar aprobados | Lista todos los estudiantes con nota >= 7 |
| 13 | Mostrar reprobados | Lista todos los estudiantes con nota < 7 |
| 14 | Salir | Termina la ejecución del programa |

## Requisitos Técnicos Cumplidos

- **Gestión de memoria con punteros**: Los nodos del árbol se manejan mediante punteros, y se libera memoria correctamente en la eliminación.
- **Recursividad**: Todas las operaciones principales (inserción, búsqueda, eliminación y recorridos) están implementadas de forma recursiva.
- **Cola para BFS**: El recorrido por niveles utiliza la estructura std::queue de la biblioteca estándar.
- **Validación de datos**: Se valida que la cédula tenga exactamente 10 dígitos numéricos y que la nota final esté en el rango [0, 10].
- **Modularidad**: El código está organizado en archivos .h y .cpp separados por responsabilidad.
- **Comentarios exhaustivos**: El código fuente está completamente comentado, explicando la lógica de punteros y los casos de eliminación.

## Compilación y Ejecución

### Requisitos previos

- Compilador de C++ compatible con C++11 o superior (g++, clang++, MinGW)
- Sistema operativo: Windows, Linux o macOS

### Compilación con g++

Desde la terminal, ubicado en el directorio del proyecto:

```bash
g++ -std=c++11 -o sistema_academico Estudiante.cpp ArbolBST.cpp main.cpp
