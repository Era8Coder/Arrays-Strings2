#include<bits/stdc++.h>
using namespace std;

// It had passed 178/181 and then TIME LIMIT EXCEEDED -->> ((((((((((::::::::::)))))))))) <<--
vector<int> findSubstring(string s, vector<string> &words) {            
        map<string, int> freq, curr;
        for (string it : words) { 
            freq[it]++;
        }

        int len = s.size();
        int n = words.size();
        int wordsize = words[0].size();
        int windowsize = wordsize * n;

        vector<int> ans;
        for (int startpos = 0; startpos < wordsize; startpos++) {           // Trying all the starting positions
            int start = startpos;
            while (start + windowsize <= len) {                         // Edge condition
                curr = freq;            //  Making copy of freq map to edit 
                string curr_word;
                bool matched = true;        // Assuming that match has already happened

                for (int i = 0; i < n; i++) {                     // Find each word
                    curr_word = s.substr(start + i * wordsize, wordsize);            // Extracting current word
                    if (!curr.count(curr_word) || curr[curr_word] == 0) {         // Match words -> That is words don't match
                        matched = false;            // Current word didn't match
                        break;
                    }
                    curr[curr_word]--;              // Remove word after it is found
                }
                if (matched) {
                    ans.push_back(start);
                }
                start += wordsize;              // Sliding window
            }
        }
        return ans;
    }

int main(){

    return 0;
}