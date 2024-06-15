#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n == 1) {
        return 1;
    }
    // Create a map to store the slope and corresponding points
    map<pair<int, int>, set<pair<int, int>>> mp;
    // Iterate over all pairs of points
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            // Calculate the greatest common divisor
            int gcd = __gcd(dx, dy);
            // Reduce the slope to its simplest form
            dx /= gcd;
            dy /= gcd;
            // To handle cases where slope should be represented consistently
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            } else if (dx == 0) {
                dy = abs(dy);
            }
            // Use a pair to represent the slope
            pair<int, int> slope = {dx, dy};
            // Insert the points into the map
            mp[slope].insert({points[i][0], points[i][1]});
            mp[slope].insert({points[j][0], points[j][1]});
        }
    }
    int maxi = INT_MIN;
    for (auto it : mp) {
        int m = it.second.size();
        maxi = max(m, maxi);
    }
    return maxi;
}

int main(){
    int n;  cin>>n;
    vector<vector<int>> v(n);
    for(int i=0; i<n; i++){
        int x,y;    cin>>x>>y;
        v[i].push_back(x);
        v[i].push_back(y);
    }
    cout << maxPoints(v) << endl;
    return 0;
}