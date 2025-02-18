#include <iostream>

using namespace std;


class Node{
    public:
        int FE;
        int data;
        Node* right;
        Node* left;
        Node* previous;
        Node(const int dat, Node* previous = nullptr, Node* leftNode = nullptr, Node* rightNode = nullptr ) : data(dat), previous(previous), left(leftNode), right(rightNode), FE(0) {}

};

class AVLTree {
    private:    
        enum { LEFT, RIGHT };

        Node* root;
        Node* current;

        int height;

    public:

        AVLTree(): root(nullptr) {}
        ~AVLTree() { 
            trim(root); 
        }

        void insert(int);

        void deleteNode(int);

        void search(int);

        bool empty(Node* r) { return r == nullptr; }

        bool leaf(Node* r) { return r->left == nullptr && r->right == nullptr; }

        int nodeNumber();

        int treeHeight();

        int height(int data);

        int currentNodeInfo() { return current->data; }

        void Root() { current = root; }

        void inorder(void (*func)(int&, int), Node *node = nullptr, bool r = true );
        void preorder(void (*func)(int&, int), Node *node = nullptr, bool r = true );
        void postorder(void (*func)(int&, int), Node *node = nullptr, bool r = true );

    private:
        void balance(Node* node, int, bool);

        // Simple left rotation
        void SLR(Node* node);

        // Simple right rotation
        void SRR(Node* node);

        // Double left rotation
        void DLR(Node* node);

        // Double right rotation
        void DRR(Node* node);

        void trim(Node* &);

        void countHelper(Node*);

        void heightHelper(Node*, int);


};

void AVLTree::insert(int data){
    Node *previous = nullptr;

    current = root;

    while( !empty(current) && data != current->data ){
        previous = current;
        if ( data > current->data ) current = current->right;
        else if( data < current->data ) current = current -> left;
    } 

    if( !empty(current) ) return;

    if( empty(previous) ) root = new Node(data);

    else if ( data < previous->data ) {
        previous->left = new Node(data, previous);
        balance(previous, LEFT, true);
    }

    else if( data > previous->data ){
        previous->right = new Node(data, previous);
        balance(previous, RIGHT, true);
    }
}

void AVLTree::balance(Node* node, int branch, bool newNode){
    bool exit = false;

    // FE = right tree height - left tree height

    while( node != nullptr && !exit ){
        if( newNode ){
            if ( branch == LEFT ) node->FE--;
            else node->FE++;
        }
        else{
            if( branch == LEFT ) node->FE++;
            else node->FE--;
        }

        if( node->FE == 0 ) exit = true;

        else if( node -> FE == -2 ) {
            if( node->left->FE == 1 ) DRR(node);
            else SRR(node);
            exit = true;
        }
        else if( node->FE == 2 ){
            if(node->right->FE == -1) DLR(node);
            else SLR(node);
            exit = true;
        }
        if( node->previous != nullptr ){
            if( node->previous->right == node) branch = RIGHT; else branch = LEFT;
            node = node->previous;
        }
    }
}

// Simple right rotation
void AVLTree::SRR(Node* node){
    Node *Previous = node->previous;
    Node *P = node;
    Node *Q = P->left;
    Node *B = Q->right;

    if( Previous != nullptr ){
        if ( Previous->right == P ) Previous->right = Q;
        else Previous->left = Q;
    } 
    else {
        root = Q;
    }

    // Rebuild tree:
    P->left = B;
    Q->right = P;

    // Reconnect parents
    P->previous = Q;
    if( B != nullptr ) B->previous = P;
    Q->previous = Previous;

    // Adjust FE 
    P->FE = 0;
    Q->FE = 0;
}

// Simplee left rotation
void AVLTree::SLR(Node* node){
    Node* Previous = node->previous;
    Node* P = node;
    Node* Q = P->right;
    Node* B = Q->left;

    if (Previous != nullptr){
        if(Previous->right == P){
            Previous->right = Q;
        }
        else{
            root = Q;
        }
    }

    P->right = B;
    Q->left = P;

    P->previous = Q;
    if( B != nullptr ) B->previous = P;
    Q->previous = Previous;

    P->FE = 0;
    Q->FE = 0;
}

// Double right rotation

void AVLTree::DRR(Node* node){

    Node *Previous = node->previous;
    Node *P = node;
    Node *Q = P->left;
    Node *R = Q->right;
    Node *B = R->left;
    Node *C = R->right;

    if (Previous != nullptr){
        if(Previous->right == node) Previous->right = R;
        else Previous->left = R;
    }
    else{
        root = R;
    }

    Q->right = B;
    P->left = C;
    R->left = Q;
    R->right = P;

    R->previous = Previous;
    P->previous = Q->previous = R;
    if ( B != nullptr )  B->previous = Q;
    if ( C != nullptr ) C->previous = P;

    switch( R->FE ) {
        case -1: Q->FE = 0; P->FE = 1; break;
        case 0: Q->FE = 0; P->FE = 0; break;
        case 1: Q->FE = -1; P->FE = 0; break;
    }

    R->FE = 0;
}

// Double left rotation

void AVLTree::DLR(Node* node){
    Node* Previous = node->previous;
    Node* P = node;
    Node* Q = P->right;
    Node* R = Q->left;
    Node* B = R->left;
    Node* C = R->right;

    if(Previous != nullptr){
        if(Previous->right == node){
            Previous->right = R;
        }
        else{
            Previous->left = R;
        }
    }
    else{
        root = R;
    }

    P->right = B;
    Q->left = C;
    R->left = P;
    R->right = Q;

    R->previous = Previous;
    P->previous = Q->previous = R;
    if( B != nullptr ) B->previous = P;
    if( C != nullptr ) C->previous = Q;

    switch (R->FE){
        case -1: P->FE = 0; Q->FE = 1; break;
        case 0: P->FE = 0; Q->FE = 0; break;
        case 1: P->FE = -1; Q->FE = 0; break;
    }
}


void AVLTree::deleteNode(int data){
    Node *previous = nullptr;
    Node *node;
    int aux;

    current = root;
    // While current is not empty
    while(!empty(current)){
        if(data == current->data){ // If we found the value
            if(leaf(current)){ // If its a leaf we delete it
                if( previous ){ // If has a parent

                    // Delete parent reference to current node
                    if ( previous->right == current ) previous->right = nullptr;
                    else if( previous->left == current ) previous->left == nullptr;
                }
                delete current; // Delete current node
                current = nullptr;

                // Parent node could now be a leaf, so its equilibrium factor is 0, we must now follow the path from the parent if exists
                if( (previous->right == current && previous->FE == 1 ) || (previous->left == current && previous->FE == -1 )  ){
                    previous->FE = 0;
                    current = previous;
                    previous = current->previous;
                }
                if( previous != nullptr ){
                    if( previous->right == current ) balance(previous, RIGHT, false);
                    else balance(previous, LEFT, false);
                }
                return;
            }
            else { // If its not a leaf but the node has the value
                previous = current;

                // Look for the last left node from right branch 
                if( current->right ){
                    node = current->right;
                    while(node->left){
                        previous = node;
                        node = node->left;
                    }
                }
                // Search for the last right node from left branch
                else {
                    node = current->left;
                    while(node->right){
                        previous = node;
                        node = node->right;
                    }
                }

                aux = current->data;
                current->data = node->data;
                node->data = aux;
                current = node;
            }
        }
        else {
            previous = current;
            if( data > current->data) current = current->right;
            else if(data < current->data ) current = current->left;
        }
    }
}

void AVLTree::trim(Node* &node){    
    if( node != nullptr ){
        trim(node->left);
        trim(node->right);
        delete node;
        node = nullptr;
    }
}


int main(){
    return 0;
}