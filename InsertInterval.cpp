#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &new_interval) {
    int i = 0;
    while (i < intervals.size() && new_interval[0] > intervals[i][0]) {
        i++;
    }
    intervals.insert(intervals.begin() + i, new_interval);
    return merge(intervals);
}

int main(){
    vector<vector<int>> v = {{1,3},{6,9}};
    vector<int> new_interval = {2,5};
    vector<vector<int>> ans = insert(v, new_interval);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}