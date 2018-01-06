#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;
bool isAnagram(string s, string t) {
        if (s.size()!= t.size()){
            return false;
        }
        unordered_map<char, int>m;
        for (int i = 0; i<s.size(); i++){
            if (m.find(s[i])==m.end()){

                m.insert(make_pair(s[i],0));
            }
            else{
                m[s[i]]+=1;
            }

        }

        for (int i = 0; i<t.size(); i++){
            if(m.find(t[i])==m.end()){
                return false;
            }
            else{
                m[t[i]]--;
            }
        }
        return true;
    }


int main() {
    std::cout << isAnagram("cat", "atc") << std::endl;
    return 0;
}