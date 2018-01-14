#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
        //convert vector to set
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        //breakable[len]==true if [pos, pos+len] is within the dict
        //s.substr(pos, len)
        vector<bool> breakable(s.size()+1, false);
        //breakable[0], s.substr(pos=0, len=0), substring that include no element
        breakable[0] = true;
        //breakable[len] = true if
        //by index, [0, j-1] is true and [j, len] is true
        //str.substr(0, j) is true,  and str.substr(j, len-j) is true
        //0< j <= len, no j==0, since [from 0, to 0] is breakable[0] already included
        //len <= s.size()
        for(int len = 1; len<=s.length(); len++){
            for(int j=0; j<len ;j++){
                string sub = s.substr(j,len-j);
                if (wordSet.find(sub)!= wordSet.end()){
                    //s.substr(0, len)
                    if (breakable[j]==true){
                        breakable[len] = true;
                        break;
                    }
                }

            }
        }
        return breakable[s.size()];
    }

int main() {
    vector<string> wordDict = {"leet","code"};
    string s = "leetcode";
    bool result = wordBreak(s, wordDict);
    cout << result << endl;
    return 0;
}