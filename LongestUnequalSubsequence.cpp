#include<bits/stdc++.h>
using namespace std;

vector<string> getLongestSubsequence(vector<string> &words, vector<int>& groups){
    int i = 0;
    int n = words.size();
    vector<string> ans;
    while(i < n){
        ans.push_back(words[i]);
        while(i < n - 1 && groups[i] == groups[i+1]){
            i++;
        }
        i++;
    }
    return ans;
}

int main(){
    vector<string> words = {"e", "a", "b"};
    vector<int> groups = {0, 0, 1};
    vector<string> ans = getLongestSubsequence(words, groups);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}