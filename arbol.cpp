// arbol.cpp
#include "arbol.h"
#include <iostream>

Arbol::Arbol() : raiz(nullptr) {}

Arbol::~Arbol() {
    destruir(raiz);
}

void Arbol::insertar(double x, double y) {
    insertarNodo(raiz, x, y);
}

void Arbol::insertarNodo(Nodo*& nodo, double x, double y) {
    if (nodo == nullptr) {
        nodo = new Nodo(x, y);
    } else if (y <= nodo->y) {
        insertarNodo(nodo->izquierda, x, y);
    } else {
        insertarNodo(nodo->derecha, x, y);
    }
}

void Arbol::destruir(Nodo* nodo) {
    if (nodo) {
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
}

void Arbol::imprimir(Nodo* nodo) {
    if (nodo) {
        imprimir(nodo->izquierda);
        std::cout << "Nodo (" << nodo->y << ")\n";
        imprimir(nodo->derecha);
    }
}

void Arbol::preOrden() {
    preOrden(raiz);
    std::cout << std::endl;
}

void Arbol::inOrden() {
    inOrden(raiz);
    std::cout << std::endl;
}

void Arbol::postOrden() {
    postOrden(raiz);
    std::cout << std::endl;
}

void Arbol::preOrden(Nodo* nodo) {
    if (nodo) {
        std::cout << nodo->y << std::endl;
        preOrden(nodo->izquierda);
        preOrden(nodo->derecha);
    }
}

void Arbol::inOrden(Nodo* nodo) {
    if (nodo) {
        inOrden(nodo->izquierda);
        std::cout << nodo->y << std::endl;
        inOrden(nodo->derecha);
    }
}

void Arbol::postOrden(Nodo* nodo) {
    if (nodo) {
        postOrden(nodo->izquierda);
        postOrden(nodo->derecha);
        std::cout << nodo->y << std::endl;
    }
}

// Implementación de la función buscar
Nodo* Arbol::buscar(double y) {
    return buscar(raiz, y);
}

Nodo* Arbol::buscar(Nodo* nodo, double y) {
    if (nodo == nullptr || nodo->y == y) {
        return nodo;
    }

    if (y < nodo->y) {
        return buscar(nodo->izquierda, y);
    } else {
        return buscar(nodo->derecha, y);
    }
}
