#include <iostream>

class Node{
    public:
    int info;
    Node *next;
    Node( int data ){
        info = data;
        next = nullptr;
    }
};

class List{
    private: 
        Node *first;

    public:
    List(){
        first = nullptr;
    }
    void appendAtTheEnd(int data){
        Node *node = new Node(data);
        Node *current;
        current = first;
        if( first == nullptr ){
            first = node;
        }
        else {
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = node;
           
        }
    }
    void appendAtTheBeggining(int data){
        Node *newNode = new Node(data);
        newNode -> next = first;
        first = newNode;
    }
    void appendBefore(int data){
        Node *newNode = new Node(data);
        Node *current = first;

        while ( current != nullptr ){
            if( current->next->info == data ){
                newNode->next = current->next;
                current->next = newNode;
            }
            else
                current = current->next;
                
        }
    }
    void appendAfter(int data) {
        Node *newNode = new Node(data);
        Node *current = first;

        while ( current != nullptr ){
            if ( current -> info == data ){
                newNode->next = current->next;
                current->next = newNode;
            }
            else{
                current = current->next;
            }
        }
        
    }
    void printList(){
        Node *current = first;

        while( current->next != nullptr ){
            std::cout << current->info << " ";
            current=current->next;
        }
        std::cout << current->info << " ";
        std::cout << std::endl;
    }

    Node* search (int data){
        Node *current = first;
        while( current != nullptr ){
            if( current -> info == data )
                return current;
            else
                current = current->next;
        }   
        return nullptr;
    }

    bool deleteFirst(){
        if( first != nullptr ){
            first = first->next;
        }
        else
            return false;
    }
    int getFirst(){
        return first->info;
    }

    bool empty(){
        if ( first == nullptr ) return true;
    }
};

int main() {

    List list;
    for( int i = 0; i <= 20; i++ ){
        list.appendAtTheBeggining(i);
    }
    list.printList();
    return 0;
}
