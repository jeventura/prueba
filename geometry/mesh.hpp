#ifndef MESH_HPP
#define MESH_HPP

#include "../arbol.h"
#include "element.hpp"
#include "condition.hpp"

enum quantity {NUM_NODES, NUM_ELEMENTS, NUM_DIRICHLET, NUM_NEUMANN};

class Mesh {
private:
    int quantities[4];
    Arbol arbolNodos; // Utiliza un objeto de tipo Arbol para almacenar los nodos
    Element** elements;
    Condition** dirichlet_conditions;
    Condition** neumann_conditions;

public:
    Mesh(){}

    ~Mesh(){
        // Libera la memoria de los elementos que no son del árbol
        free(elements);
        free(dirichlet_conditions);
        free(neumann_conditions);
    }

    // Métodos para operaciones en el árbol
    void mostrarPreOrden() {
        arbolNodos.preOrden();
    }

    void mostrarInOrden() {
        arbolNodos.inOrden();
    }

    void mostrarPostOrden() {
        arbolNodos.postOrden();
    }

    void set_quantities(int num_nodes, int num_elements, int num_dirichlet, int num_neumann){
        quantities[NUM_NODES] = num_nodes;
        quantities[NUM_ELEMENTS] = num_elements;
        quantities[NUM_DIRICHLET] = num_dirichlet;
        quantities[NUM_NEUMANN] = num_neumann;
    }
    int get_quantity(quantity position){
        return quantities[position];
    }

    void insert_node(double x, double y){
        // Inserta el nodo en el árbol según su coordenada y
        arbolNodos.insertar(x, y);
    }
    Nodo* get_node(double y){
        // Obtiene el nodo del árbol según su coordenada y
        return arbolNodos.buscar(y);
    }

    void insert_element(Element* element, int position){
        elements[position] = element;
    }
    Element* get_element(int position){
        return elements[position];
    }

    void insert_dirichlet_condition(Condition* dirichlet_condition, int position){
        dirichlet_conditions[position] = dirichlet_condition;
    }
    Condition* get_dirichlet_condition(int position){
        return dirichlet_conditions[position];
    }
    bool does_node_have_dirichlet_condition(int id){
        bool ans = false;
        for(int i = 0; i < quantities[NUM_DIRICHLET]; i++)
            if(dirichlet_conditions[i]->get_node()->get_ID() == id){
                ans = true;
                break;
            }
        return ans;
    }

    void insert_neumann_condition(Condition* neumann_condition, int position){
        neumann_conditions[position] = neumann_condition;
    }
    Condition* get_neumann_condition(int position){
        return neumann_conditions[position];
    }

    void report(){
        cout << "Problem Data\n**********************\n";
        cout << "Number of nodes: " << quantities[NUM_NODES] << "\n";
        cout << "Number of elements: " << quantities[NUM_ELEMENTS] << "\n";
        cout << "Number of dirichlet boundary conditions: " << quantities[NUM_DIRICHLET] << "\n";
        cout << "Number of neumann boundary conditions: " << quantities[NUM_NEUMANN] << "\n\n";
        cout << "List of nodes\n**********************\n";
            arbolNodos.inOrden();
        cout << "\nList of elements\n**********************\n";
        for(int i = 0; i < quantities[NUM_ELEMENTS]; i++){
            cout << "Element: " << elements[i]->get_ID() << ", Node 1= " << elements[i]->get_node1()->get_ID();
            cout << ", Node 2= " << elements[i]->get_node2()->get_ID() << ", Node 3= " << elements[i]->get_node3()->get_ID() << "\n";
        }
        cout << "\nList of Dirichlet boundary conditions\n**********************\n";
        for(int i = 0; i < quantities[NUM_DIRICHLET]; i++)
            cout << "Condition " << i+1 << ": " << dirichlet_conditions[i]->get_node()->get_ID() << ", Value= " << dirichlet_conditions[i]->get_value() << "\n";
        cout << "\nList of Neumann boundary conditions\n**********************\n";
        for(int i = 0; i < quantities[NUM_NEUMANN]; i++)
            cout << "Condition " << i+1 << ": " << neumann_conditions[i]->get_node()->get_ID() << ", Value= " << neumann_conditions[i]->get_value() << "\n";
        cout << "\n";
    }
};

#endif
