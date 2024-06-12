#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

bool wordPattern(string pattern, string s) {
    map<char, string> mp;
    set<string> usedWords;
    stringstream ss(s);
    string word;
    int i = 0;

    while (ss >> word) {
        if (i >= pattern.size()) return false;

        char c = pattern[i];

        if (mp.find(c) != mp.end()) {
            if (mp[c] != word) {
                return false;
            }
        } else {
            if (usedWords.find(word) != usedWords.end()) {
                return false;
            }
            mp[c] = word;
            usedWords.insert(word);
        }
        i++;
    }

    return i == pattern.size();
}

int main() {
    string pattern, s;
    cin >> pattern;
    cin.ignore();  // To ignore the newline character after reading pattern
    getline(cin, s);
    
    if (wordPattern(pattern, s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
