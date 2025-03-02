#include <iostream>


using namespace std;

bool palindrome( char str[], int i, int f ){
    if ( f - i <= 1 ) return true;

    if ( str[i] == str[f] )
        return palindrome( str, i + 1, f - 1);


    else return false;

}
bool palindrome( string str, int i, int f ){
    if ( f - i <= 1 ) return true;

    if ( str[i] == str[f] )
        return palindrome( str, i + 1, f - 1);


    else return false;

}

int main() {

    char str1[10] = "rotomoto";
    char str2[9] = "reconoce";

    string str1_1 = "o";
    string str2_2 = "reconoce";

    if ( palindrome(str1, 0, 9-1) ) 
        cout <<  str1 << " es palindromo " << endl;
    else 
        cout <<  str1 << " no es palindromo " << endl;

    if ( palindrome(str1, 0, 8-1) )
        cout <<  str2 << " es palindromo " << endl;
    else 
        cout <<  str2 << " no es palindromo " << endl;

    if ( palindrome(str1_1, 0, str1_1.length() - 1 ))
        cout <<  str1_1 << " es palindromo " << endl;
    else 
        cout <<  str1_1 << " no es palindromo " << endl;
    return 0;

}


