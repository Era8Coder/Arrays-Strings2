// -> Time doesn't Heal Anything it just teaches you how to live with pain :(
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int max_width = 20;
    vector<string> res = {};
    vector<string> line= {};
    int len = 0;
    int i = 0;
    while(i < words.size()){
        //  Completed the Line
        if(len + line.size() + words[i].size() > max_width){            // More than or Equal to MaxWidth - 1 <-:->
            // It's not including space -> Here we have to include space evenly :)
            int extra_space = max_width - len;
            int k = line.size()-1; 
            int denom = max(k,1);
            int spaces = extra_space/denom;
            int remainder = extra_space%denom;

            for(int j=0; j<max(k,1); j++){
                for(int k=0; k<spaces; k++){
                    line[j] += " ";
                }
                if(remainder != 0){
                    line[j] += " ";
                    remainder--;
                }
            }
            string str = "";
            for(int i=0; i<line.size(); i++){
                str = str + line[i] + " ";
            }
            res.push_back(str);
            line = {};
            len  = 0;
        } 

        line.push_back(words[i]);           // -->> Push Back i'th Element of words <<--
        len += words[i].size();
        i++;
    }

    string last_line = "";
    for(int i=0; i<line.size(); i++){
        if(i!=0){
            last_line += " ";
        }
        last_line += line[i];
    }
    int trail_space = max_width - last_line.size();
    for(int i=0; i<trail_space-1; i++){
        last_line += " ";
    }
    res.push_back(last_line);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }
    cout << "World Asks Me Why I Love Her ??" << endl;
    return 0;
}