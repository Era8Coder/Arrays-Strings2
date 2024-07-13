#include<bits/stdc++.h>
using namespace std;

/*
                    \/
    -->> Break just breaks the Outer Loop <<--
                    /\
*/

int main(){
    int n = 5;
    for(int i=0; i<n; i++){
        cout << i << " ";
        for(int j=0; j<n; j++){
            break;
            cout << "hey" << endl;
            // break;
        }
    }
    return 0;
}