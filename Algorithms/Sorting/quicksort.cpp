#include <iostream>
#include <vector>


using namespace std;

void swap(vector<int>& arr, int i, int j){
    int d = arr[j];
    arr[j] = arr[i];
    arr[i] = d;
}

int partition( vector<int>& arr, int start, int end ) {
    int pivot = arr[start];

    int i = start + 1;

    for( int j = start + 1; j <= end; j++ ){
        if( arr[j] < pivot ){
            swap(arr, i++, j);
        }
    }

    swap(arr, start, i-1);
    return i-1;
}


void quickSort( vector<int>& arr, int start, int end ) {
    if ( start < end ) {
        int posPartition = partition( arr, start, end );
        quickSort( arr, start, posPartition - 1);
        quickSort( arr, posPartition + 1, end );
    }
}

void quickSort(vector<int>& arr){
    quickSort(arr, 0, arr.size() - 1);
}


int main(){
    vector<int> arr = {91,21,13,41,14,51,15,61,17,71,82,28,39,93,1,21,13,41,14,51,15,61,17,71,82,28,39,931,21,13,41,14,51,15,61,17,71,82,28,39,93};

    quickSort(arr); 
    
    for( int i = 0; i < arr.size(); i++ ) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}