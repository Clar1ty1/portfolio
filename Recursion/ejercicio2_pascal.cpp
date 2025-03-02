#include <iostream>

using namespace std;


int trianguloPascal(int r, int c){
    if (  c >= r || c == 0 ) {

        return 1;
    }

    return trianguloPascal(r-1,c-1) + trianguloPascal(r-1, c);
}

void triangularesHastaFila(int n){
    for( int i = 0; i <= n; i++ ){
        int valorFila = 0;
        for( int j = 0; j <= i; j++ )
            cout << trianguloPascal(i, j) << " ";
        cout << endl;
    }
}

int main(){
    triangularesHastaFila(9);
    return 0;
}