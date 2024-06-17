#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<string> stk;
    for(int i=0; i<tokens.size(); i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*"){
            string n1 = stk.top();
            stk.pop();
            // cout << n1 << endl;
            string n2 = stk.top();
            stk.pop();
            // cout << n2 << endl;
            int m1 = stoi(n1);
            int m2 = stoi(n2);
            int val;
            if(tokens[i] == "+"){
                val = m1 + m2;
            }else if(tokens[i] == "-"){
                val = m2 - m1;
            }else if(tokens[i] == "/"){
                val = m2/m1;
            }else{
                val = m1*m2;
            }
            string ans = to_string(val);
            stk.push(ans);
        }else{
            stk.push(tokens[i]);
        }
    }

    return stoi(stk.top());
}

int main(){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(tokens) << endl;
    return 0;
}