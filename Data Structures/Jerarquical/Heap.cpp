#include <iostream>

using namespace std;

class MaxHeap{

    int* arr;

    int maxSize;

    int heapSize;

    public:

        MaxHeap(int maxSize);

        void MaxHeapify(int);

        int parent(int i) { return (i-1)/2; }

        int lChild(int i) { return 2*i + 1; }

        int rChild(int i) { return 2*i + 2; }

        int removeMax();

        void increaseKey(int i, int newVal);

        int getMax() { return arr[0]; }

        int curSize() { return heapSize; }

        void deleteKey(int i);

        void insertKey(int k);

};

MaxHeap::MaxHeap(int totSize){
    heapSize = 0;
    maxSize = totSize;
    arr = new int[totSize];
}

void MaxHeap::insertKey(int x){
    if ( heapSize == maxSize) return;

    heapSize++;
    int i = heapSize - 1;
    arr[i] = x;

    // The max heap property is checked and if violation occurs, it is restored.
    while ( i != 0 && arr[parent(i)] < arr[i] ){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }

}

void MaxHeap::increaseKey(int i, int newVal){
    arr[i] = newVal;

    while( i != 0 && arr[parent(i)] < arr[i] ){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::removeMax(){
    if ( heapSize <= 0 ) return INT_MIN;

    if ( heapSize == 1 ){
        heapSize--;
        return arr[0];
    }

    // Storing the maximum element to remove it
    int root = arr[0];
    arr[0] = arr[heapSize-1];
    heapSize--;

    // To restore the property of the max heap
    MaxHeapify(0);

    return root;
}

void MaxHeap::deleteKey(int i){
    // It increases the value of the key to infinity and then removes the maximum value
    increaseKey(i, INT_MIN);
    removeMax();
}

// To heapify the subtree this method is called recursively
void MaxHeap::MaxHeapify(int i){
    int l = lChild(i);
    int r = rChild(i);
    int largest = i;

    if ( l < heapSize && arr[l] > arr[i] ) largest = l;
    if ( r < heapSize && arr[r] > arr[largest] ) largest = r;

    if ( largest != i ){
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}

int main(){
    MaxHeap h(15);

    int k, i, n = 6, arr[10];

    h.insertKey(3);
    h.insertKey(10);
    h.insertKey(12);
    h.insertKey(8);
    h.insertKey(2);
    h.insertKey(14);

    // Print the current size of the heap
    cout << "Current size of heap is " << h.curSize() << endl;

    // Printing the root element which is actually the maximum element
    cout << "The current maximum element is " << h.getMax() << endl;

    // Deleting key at index 2
    h.deleteKey(2);

    // Printing the size of theheap after deletion
    cout << "The current size of the heap is " << h.curSize() << endl;

    h.insertKey(15);
    h.insertKey(5);

    cout << "The current size of the heap is " << h.curSize() << endl;
    cout << "The current maximum element is " << h.getMax() << endl;

    return 0;
}