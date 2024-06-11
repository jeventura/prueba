#ifndef ARBOL_H
#define ARBOL_H

struct Nodo {
    double x;
    double y;
    Nodo* izquierda;
    Nodo* derecha;
    
    Nodo(double xCoord, double yCoord) : x(xCoord), y(yCoord), izquierda(nullptr), derecha(nullptr) {}
};

class Arbol {
public:
    Arbol();
    ~Arbol();
    void insertar(double x, double y);
    void imprimir(Nodo* nodo);

    void preOrden();
    void inOrden();
    void postOrden();
    
    // Función para buscar un nodo según su coordenada y
    Nodo* buscar(double y);

private:
    Nodo* raiz;
    void insertarNodo(Nodo*& nodo, double x, double y);
    void destruir(Nodo* nodo);
    void preOrden(Nodo* nodo);
    void inOrden(Nodo* nodo);
    void postOrden(Nodo* nodo);
    
    // Función de búsqueda auxiliar
    Nodo* buscar(Nodo* nodo, double y);
};

#endif
