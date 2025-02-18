#include <iostream>

using namespace std;

class NodoArbolBinario{
    public:
        int info;
        NodoArbolBinario *hijoIzquierdo;
        NodoArbolBinario *hijoDerecho;

        NodoArbolBinario(int dato){
            info = dato;
            hijoIzquierdo = nullptr;
            hijoDerecho = nullptr;
        }
};

class BST{
    private:
        NodoArbolBinario *raiz;

        NodoArbolBinario* buscarRecursivo(NodoArbolBinario* p, int dato);

        NodoArbolBinario* insertarRecursivo(NodoArbolBinario* p, int dato);
        
        NodoArbolBinario* eliminarRecursivo(NodoArbolBinario* p, int dato);

        NodoArbolBinario* reemplazar(NodoArbolBinario* q);

        void preordenRecursivo(NodoArbolBinario* p);

        void inordenRecursivo(NodoArbolBinario* p);

        void posordenRecursivo(NodoArbolBinario* p);

        void borrarRecursivo(NodoArbolBinario *p);

    public:
        BST(){
            raiz = nullptr;
        }
        NodoArbolBinario* buscar(int dato){
            return buscarRecursivo(raiz, dato);
        }

        void insertar(int dato){
            raiz = insertarRecursivo(raiz, dato);
        }

        void eliminar(int dato){
            raiz = eliminarRecursivo(raiz, dato);
        }
        void preorden();

        void preorden(NodoArbolBinario* p, void(*func)(int) ){
            func(p->info);
            if(p->hijoIzquierdo) preorden(p->hijoIzquierdo, func);
            if(p->hijoDerecho) preorden(p->hijoDerecho, func);
        }

        void inorden();

        void inorden(NodoArbolBinario* p, void(*func)(int) ){
            if(p->hijoIzquierdo) inorden(p->hijoIzquierdo, func);
            func(p->info);
            if(p->hijoDerecho) inorden(p->hijoDerecho, func);
        }
        
        void posorden();

        void inorden(NodoArbolBinario* p, void(*func)(int) ){
            if(p->hijoIzquierdo) inorden(p->hijoIzquierdo, func);
            if(p->hijoDerecho) inorden(p->hijoDerecho, func);
            func(p->info);
        }

        void borrar();

        int esHoja(NodoArbolBinario* r);

        int numeroNodos(){
            int* contador = 0;

            auxContador(raiz, contador);
            return *contador;
        }

        void auxContador(NodoArbolBinario* nodo, int *c ){
            (*c)++; // Incrementar número de nodos. (Preorden)
            if( nodo->hijoIzquierdo )
                auxContador(nodo->hijoIzquierdo, c);
            if (nodo->hijoDerecho) 
                auxContador(nodo->hijoDerecho, c);
        }

        int alturaArbol(){
            int* altura = 0;

            auxAltura(raiz, 0, altura);
            return *altura;
        }

        void auxAltura(NodoArbolBinario* nodo, int a, int* altura){
            if(nodo->hijoIzquierdo) auxAltura(nodo->hijoIzquierdo, a + 1, altura);
            if(nodo->hijoDerecho) auxAltura(nodo->hijoDerecho, a+1, altura);
            if(esHoja(nodo) && a > *altura ) *altura = a;
        }

        int altura(NodoArbolBinario* a, int dato){
            int altura = 0;
            NodoArbolBinario* actual = a;
            
            while(actual != nullptr){
                if( dato == actual->info ) return altura;
                else{
                    altura++;

                    if( dato < actual->info ) actual = actual->hijoIzquierdo;

                    else if(dato > actual->info) actual = actual->hijoDerecho;
                }
            }
            return -1; // No esta en el árbol
        }


};

int BST::esHoja(NodoArbolBinario* r){
    return !r->hijoDerecho && !r->hijoIzquierdo;
}

NodoArbolBinario* BST::buscarRecursivo(NodoArbolBinario* p, int dato){
    if ( p == nullptr ){
        return nullptr;
    }
    else {
        if ( dato < p->info ){
            return buscarRecursivo(p->hijoIzquierdo, dato);
        }
        else if ( dato < p->info ){
            return buscarRecursivo(p->hijoDerecho, dato);
        }
        else{
            return p;
        }
    }
}

NodoArbolBinario* BST::insertarRecursivo(NodoArbolBinario* p, int dato){
    if( p == nullptr ){
        p = new NodoArbolBinario(dato);
    }
    else if ( dato < p->info ){
        p->hijoIzquierdo = insertarRecursivo(p->hijoIzquierdo, dato);
    }
    else if ( dato > p->info ){
        p->hijoDerecho = insertarRecursivo(p->hijoDerecho, dato);
    }
    else {
        cout << "El elemento está repetido y no se pudo insertar " << endl;
    }
    return p;
}

NodoArbolBinario* BST::eliminarRecursivo(NodoArbolBinario *p, int dato){
    if( p == nullptr ){
        cout << "El dato no fue encontrado" << endl;
    }
    else if ( dato < p->info ){
        p->hijoIzquierdo = eliminarRecursivo(p->hijoIzquierdo, dato);
    } 
    else if ( dato > p->info ){
        p->hijoDerecho = eliminarRecursivo(p->hijoDerecho, dato);
    }
    else {
        NodoArbolBinario *q = p;
        if ( q->hijoIzquierdo == nullptr ){
            p = q->hijoDerecho;
        }
        else if( q->hijoDerecho == nullptr ){
            p = q->hijoIzquierdo;
        }
        else {
            q = reemplazar(q);
        }
        delete( q ); 
    }
    return p;
}

NodoArbolBinario* BST::reemplazar(NodoArbolBinario* actual){

    NodoArbolBinario *a, *p;
    p = actual;
    a = actual->hijoIzquierdo;

    // Encontrar el más nodo más a la derecha del subarbol izquierdo
    while( a->hijoDerecho != nullptr ){
        p = a;
        a = a->hijoDerecho;
    }

    actual->info = a->info;

    if( p == actual )
        p->hijoIzquierdo = a->hijoIzquierdo;
    else 
        p->hijoDerecho = a->hijoIzquierdo;
    return a;

}

void BST::preorden(){
    preordenRecursivo(raiz);
}

void BST::preordenRecursivo(NodoArbolBinario *p){
    if( p != nullptr ){
        cout << p->info << " ";
        preordenRecursivo(p->hijoIzquierdo);
        preordenRecursivo(p->hijoDerecho);
    }
}

void BST::inorden(){
    inordenRecursivo(raiz);
}

void BST::inordenRecursivo(NodoArbolBinario *p){
    if( p != nullptr ){
        inordenRecursivo(p->hijoIzquierdo);
        cout << p->info << " ";
        inordenRecursivo(p->hijoDerecho);
    }
}


void BST::posorden(){
    posordenRecursivo(raiz);
}

void BST::posordenRecursivo(NodoArbolBinario *p){
    if( p != nullptr ){
        posordenRecursivo(p->hijoIzquierdo);
        posordenRecursivo(p->hijoDerecho);
        cout << p->info << " ";
    }
}

void BST::borrarRecursivo(NodoArbolBinario *p){
    if( p != nullptr ){
        borrarRecursivo(p->hijoIzquierdo);
        borrarRecursivo(p->hijoDerecho);
        delete(p);
    }
}

void BST::borrar(){
    borrarRecursivo(raiz);
    raiz = nullptr;
}

int main(){

    BST arbol = BST();

    arbol.insertar(10);
    arbol.insertar(40);
    arbol.insertar(1123);
    arbol.insertar(1);
    arbol.insertar(233);

    arbol.inorden();
    cout << endl;
    arbol.posorden();
    cout << endl;
    arbol.preorden();
    cout << endl;

    cout << "Borrado" << endl;
    arbol.borrar();
    arbol.inorden();

    return 0;
}