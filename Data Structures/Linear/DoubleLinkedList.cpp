#include <iostream>

using namespace std;

class Node {
    public:
        int info;
        Node *prev = nullptr;
        Node *next = nullptr;

        Node( int data ) {
            info = data;
        }
};

class DoubleLinkedList {
    private:
        Node *first = nullptr;

    public:
        void appendAtTheBegginning(int data){
            Node *newNode = new Node(data);
            Node *current = first;
            if( current == nullptr ){
                first = newNode;
            }
            else {
                newNode -> next = first;
                first = newNode;
            }
        }
        void appendAtTheEnd(int data){
            Node *newNode = new Node(data);
            Node *current = first;

            while (current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
            
        }
        void appendBefore(int data, int filter){
            Node *newNode = new Node(data);
            Node *current = first;

            while( current != nullptr ){
                if( current->info == filter ){
                    Node *prev = current->prev;
                    prev->next = newNode;
                    newNode->prev = prev;
                    newNode->next = current;
                    current->prev = newNode;
                    break;
                }
                else {
                    current = current->next;
                }
            }
        }
        void appendAfter(int data, int filter){
            Node *newNode = new Node(data);
            Node *current = first;

            while( current != nullptr ){
                if( current -> info == filter ) {
                    if ( current -> next != nullptr ){
                        Node *next = current -> next;

                        next->prev = newNode;
                        current ->next = newNode;

                        newNode->prev = current;
                        newNode->next = next;
                    }
                    else {
                        current->next = newNode;
                        newNode->prev = current;
                    }
                    break;
                }
                else {
                    current = current->next;
                }
            }
        }

        void deleteNode( int data ){
            Node *current = first;

            while ( current != nullptr ){
                if ( current -> info == data ){
                    if ( current -> prev == nullptr ) {
                        first = current -> next;
                        delete(current);
                    }
                    if ( current -> next != nullptr && current -> prev != nullptr ){
                        Node *prev = current -> prev;
                        Node *next = current -> next;
                        prev->next = next;
                        next->prev = prev;
                        delete(current);
                    }
                    break;
                }
                else 
                    current = current->next;
            }
        }

        void printList(){
            Node *current = first;

            while( current->next != nullptr ){
                cout << current->info << " ";
                current=current->next;
            }
            cout << current->info << " ";
            cout << endl;
        }

};


int main(){
    DoubleLinkedList list;
    for( int i = 0; i < 100; i++ ){
        list.appendAtTheBegginning(i);
    }

    list.appendAfter(10, 101);
    list.appendBefore(101, 102);
    list.appendAtTheBegginning(-100);
    list.appendAtTheEnd(-101);

    list.deleteNode(100);
    list.printList();
    return 0;
}