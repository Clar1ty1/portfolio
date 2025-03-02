#include <iostream>


using namespace std;

long power( int base, int n ) {
    if ( base == 0 || n == 1 )
    return 1;

    return n * power(base-1, n );
}

int main() {

    cout << power( 2, 4 ) << endl;
    cout << power( 3, 4 ) << endl;
    cout << power( 2, 2 ) << endl;
    cout << power( 3, 2 ) << endl;
    cout << power( 2, 5 ) << endl;
    cout << power( 3, 5 ) << endl;
    return 0;
}