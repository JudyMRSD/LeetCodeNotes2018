#include <iostream>
using namespace std;

// function to reverse any part of string from i to j (just one word or entire string)
void reverseword(string &s, int i, int j){
    while(i<j){
        char t=s[i];
        s[i++]=s[j];
        s[j--]=t;
    }
}

void reverseWords(string &s) {

    int i=0, j=0;
    int l=0;
    int len=s.length();
    int countSpace = 0;
    while(i<len && s[i]==' '){
        countSpace++;
        i++;
    }

    while(i<len){
        //skip ' ' space
        while(s[i]==' '){
            i++;
            j++;
        }
        l=j;
        while(i<len && s[i] != ' ') {j++; i++;}

        reverseword(s,l,j-1);                // reverse word in place
    }
    s.resize(len-countSpace);
    reverseword(s,0,len-1);                  // reverse whole string

}

int main() {
    string input = "   ";
    reverseWords(input);
    cout<<"["<<input<<"]"<<endl;
}