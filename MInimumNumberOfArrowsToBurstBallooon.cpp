#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> p1, vector<int> p2) {
        // Calculate the merged interval if there is an overlap
        if (p1[1] >= p2[0]) {
            return {max(p1[0], p2[0]), min(p1[1], p2[1])};
        }
        return {-1, -1};
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort intervals based on the starting point
        sort(points.begin(), points.end());
        
        vector<vector<int>> ans;
        vector<int> negp = {-1, -1};

        for (int i = 0; i < points.size(); ++i) {
            if (ans.empty()) {
                ans.push_back(points[i]);
            } else {
                vector<int> k = intersection(ans.back(), points[i]);
                if (k != negp) {
                    ans.back() = k;
                } else {
                    ans.push_back(points[i]);
                }
            }
        }
        
        return ans.size();
    }
};

int main(){

    return 0;
}