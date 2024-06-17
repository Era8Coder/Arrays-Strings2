#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

string simplifyPath(string path) {
    string ans = "";
    string tokens;
    stringstream k(path);
    stack<string> stk;
    
    while (getline(k, tokens, '/')) {  // Using getline to segregate the file names using "/"
        if (tokens == "." || tokens == "") {
            continue;
        } else if (tokens == "..") {
            if (!stk.empty()) {
                stk.pop();
            }
        } else {
            stk.push(tokens);
        }
    }

    while (!stk.empty()) {
        ans = "/" + stk.top() + ans;
        stk.pop();
    }

    if(ans.empty()){
        return "/";
    }
    return ans;
}

int main() {
    string path = "/home/";
    cout << simplifyPath(path) << endl;
    return 0;
}
