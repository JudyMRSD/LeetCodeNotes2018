#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string a = "hi";


    int n = 10;
    vector<string> res(n);
    for (int i = 1; i<=n; i++){
        if (i%3 == 0){
            res[i-1] = "Fizz";
        }
        else if (i%5 == 0){
            res[i-1] = "Buzz";
        }
        else{
            res[i-1] = to_string(i);
        }
    }
    for (int i = 0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }


    return 0;
}