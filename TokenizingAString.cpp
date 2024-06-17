#include<bits/stdc++.h>
using namespace std;

/*  Tokenizing string implies splitting of string with respect to some delimeter(s)  */

int main(){
    string s = "Geeks-For-Geeks";
    string tokens;
    stringstream k(s);
    while(getline(k,tokens,'-')){
        cout << tokens << endl;             // That is basically splitting with respect to some symbol or variables :)
    }
    return 0;
}