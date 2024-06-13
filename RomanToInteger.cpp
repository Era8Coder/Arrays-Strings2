#include<bits/stdc++.h>
using namespace std;

// -->> Simplest Logic to convert Roman to Integer <<--
int roman_to_decimal(string &str){
    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int sum = 0;
    for(int i=0; i<str.size(); i++){
        // -->> If present value is less than the Next Value and Add the resultant to the Sum Variable <<--
        if(mp[str[i]] < mp[str[i+1]]){          // If value of current one is less than the next One
            sum = sum + mp[str[i+1]] - mp[str[i]];
            i++;                // Since we had accounted current "i" in it therefore you can traverse freely from here now
            continue;
        }
        sum = sum + mp[str[i]];
    }
    return sum;
}

int main(){
    string str; cin>>str;
    cout << roman_to_decimal(str) << endl;
    return 0;   
}