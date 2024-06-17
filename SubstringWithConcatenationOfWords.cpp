#include<bits/stdc++.h>
using namespace std;

void swap(string &x, string &y){
    string temp = x;
    x = y;
    y = temp;
}

void printvec(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void permutations(vector<vector<string>> &ans, vector<string> v, int l, int r){
    if(l == r){
        ans.push_back(v);
        return;
    }

    for(int i=l; i<=r; i++){    
        swap(v[l], v[i]);
        permutations(ans, v, l+1, r);
        swap(v[l], v[i]);
    }
}

vector<int> findSubstring(string s, vector<string> &words, map<string,int> &mp, int &m){
    vector<int> res;
    for(int i=0; i<s.size(); i++){
        string temp = s.substr(i,m);
        if(mp[temp] != 0){
            res.push_back(i);
        }        
    }
    return res;
}

int main(){
    vector<vector<string>> ans;
    vector<string> v = {"word","good","best","good"};
    int n = v.size() - 1;
    map<string,int> mp;
    permutations(ans, v, 0, n);
    int m = 0;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0; i<ans.size(); i++){
        string s = "";
        for(int j=0; j<ans[i].size(); j++){
            s += ans[i][j];
        }
        if(i == 0){
            m = s.size();
        }
        mp[s]++;
    }
    string s = "wordgoodgoodgoodbestword";
    vector<int> res = findSubstring(s, v, mp, m);
    printvec(res);
    return 0;
}