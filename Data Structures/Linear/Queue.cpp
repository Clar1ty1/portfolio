#include <iostream>
#include "LinkedList.cpp"


class Queue{
    private: 
        List storage;
    public: 
        void enqueue(int data){
            storage.appendAtTheEnd(data);
        }
        bool dequeue(){
            return storage.deleteFirst();
        }

        int getFrente(){
            return storage.getFirst();
        }

        bool emptyStorage(){
            return storage.empty();
        }
};


int main() {

    return 0;
}