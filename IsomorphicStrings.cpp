#include<bits/stdc++.h>
using namespace std;

bool is_isomorphic(string s, string t){
    map<char,char> mp;
    for(int i=0; i<s.size(); i++){
        if(mp[s[i]] == '\0'){
            mp[s[i]] = t[i];
        }else{
            if(mp[s[i]] != t[i]){
                return false;
            }
        }
    }
    map<char,char> mp1;
    for(int i=0; i<t.size(); i++){
        if(mp1[t[i]] == '\0'){
            mp1[t[i]] = s[i];
        }else{
            if(mp1[t[i]] != s[i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int t;  cin>>t;
    while(t--){
        string s,t; cin>>s>>t;
        cout << is_isomorphic(s,t) << endl;
    }
    return 0;
}