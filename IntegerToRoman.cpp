#include<bits/stdc++.h>
using namespace std;

string RomanToInteger(int n){
    string ans = "";
    map<int,string> mp;
    mp[1] = "I";   mp[4] = "IV";   mp[5] = "V";   mp[9] = "IX";
    mp[10]= "X";   mp[40]= "XL";   mp[50]= "L";   mp[90]= "XC";
    mp[100]="C";   mp[400]="CD";   mp[500]="D";   mp[900]="CM";
    mp[1000]="M";
    int c1 = n/1000;
    n = n%1000;
    for(int i=0; i<c1; i++){
        ans = ans + mp[1000];
    }
    int c2 = n/900;
    n = n%900;
    for(int i=0; i<c2; i++){
        ans = ans + mp[900];
    }
    int c3 =n/500;
    n = n%500;
    for(int i=0; i<c3; i++){
        ans = ans + mp[500];
    }
    int c4 = n/400;
    n = n%400;
    for(int i=0; i<c4; i++){
        ans = ans + mp[400];
    }
    int c5 = n/100;
    n = n%100;
    for(int i=0; i<c5; i++){
        ans = ans + mp[100];
    }
    int c6 = n/90;
    n = n%90;
    for(int i=0; i<c6; i++){
        ans = ans + mp[90];
    }
    int c7 = n/50;
    n = n%50;
    for(int i=0; i<c7; i++){
        ans = ans + mp[50];
    }
    int c8 = n/40;
    n=n%40;
    for(int i=0; i<c8; i++){
        ans = ans + mp[40];
    }    
    int c9 = n/10;
    n=n%10;
    for(int i=0; i<c9; i++){
        ans = ans + mp[10];
    }   
    int c10 = n/9;
    n = n%9;
    for(int i=0; i<c10; i++){
        ans = ans + mp[9];
    }   
    int c11 = n/5;
    n=n%5;
    for(int i=0; i<c11; i++){
        ans = ans + mp[5];
    }   
    int c12 = n/4;
    n=n%4;
    for(int i=0; i<c12; i++){
        ans = ans + mp[4];
    }   
    int c13 = n/1;
    n = n%1;
    for(int i=0; i<c13; i++){
        ans = ans + mp[1];
    }   
    return ans;
}

int main(){
    int n;  cin>>n;
    string str = RomanToInteger(n);
    cout << str << endl;
    return 0;
}