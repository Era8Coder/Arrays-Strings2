#include<bits/stdc++.h>
using namespace std;

int jump(vector<int> nums){ // This solution is better than Recursive One -->> Since it's occuring in Linear Time Complexity and Space Complexity :)
    int n = nums.size();
    int total_jumps = 0;
    int destination = n - 1;
    int range = 0;
    int last_jump_idx = 0;
    if(nums.size() == 1){
        return 0;
    }  
    for(int i=0; i<n; i++){
        range = max(range,i + nums[i]);
        if(i == last_jump_idx){         // <<-- It is to check that we had covred the given window or not -->>
            last_jump_idx = range;
            total_jumps++;              // If after covering the window you can reach to the end of the List this means you had completed the journey
            if(range >= destination){      // if we cross the destination then it's nice
                return total_jumps;
            }   
        }
    }
    return total_jumps;
}

int main(){
    int n;  cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << jump(v) << endl;
    return 0;
}