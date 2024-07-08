#include<bits/stdc++.h>
using namespace std;
/*
    Interval defined by Me : 
                        I => [a,b)
*/
bool book(int start, int end, vector<pair<int,int>> &v){
    if(v.size() == 0){
        v.push_back(make_pair(start,end));
        return true;
    }else{
        for(int i=0; i<v.size(); i++){
            if(max(v[i].first,start) <= min(end,v[i].second)){              // If equality also included then the interval is => [a,b]
                return false;
            }
        }
        v.push_back(make_pair(start, end));
        return true;
    }
}

int main(){
    vector<pair<int,int>> v;
    cout << book(1,2,v) << endl;
    cout << book(3,4,v) << endl;
    cout << book(2,3,v) << endl;
    cout << book(5,6,v) << endl;
    return 0;
}