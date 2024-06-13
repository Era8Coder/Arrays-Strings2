#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){   
    if(a.empty()){
        return 0;
    }
    if(a.size() == 1){
        return 1;
    }
    int cnt = 1;
    int ans = 1;
    map<int,int> mp;
    for(int i=0; i<a.size(); i++){
        mp[a[i]]++;
    }
    vector<int> v;
    for(auto it : mp){
        v.push_back(it.first);
    }

    for(int i=1; i<v.size(); i++){
        if(v[i] - v[i-1] == 1){
            cnt++;
            ans = max(ans,cnt);
        }else{
            cnt = 1;
        }
    }
    return ans;
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int ans = solve(v);
    cout << ans << endl;
    return 0;
}