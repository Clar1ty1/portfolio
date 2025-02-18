#include <iostream>
#define MAX 5

using namespace std;

class ArrayStack{
    private: 
        int top = -1;
        int space[MAX];

    public:
        bool push(int data){
            if (stackFull()) 
                return false;
            else{
                top++;
                space[top] = data;
                return true;
            }
        }

        bool pop(){
            if( emptyStack() )
                return false;
            else {
                top--;
                return true;
            }
        }

        int getTop(){
            return space[top];
        }
        bool stackFull(){
            if ( top == MAX-1 )
                return true;
            else
                return false;

        }

        bool emptyStack(){
            if ( top == -1 )
                return true;
            else 
                return false;
        }
};