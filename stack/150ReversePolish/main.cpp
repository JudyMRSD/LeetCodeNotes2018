#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for(string t : tokens){
            if(t=="+"||t=="-"||t=="*"||t=="/"){
                int b = myStack.top();
                myStack.pop();
                int a = myStack.top();
                myStack.pop();

                if(t=="+"){

                    myStack.push(a+b);
                }
                else if(t=="-"){

                    myStack.push(a-b);
                }
                else if(t=="*"){

                    myStack.push(a*b);
                }
                else if(t=="/"){

                    myStack.push(a/b);
                }
            }

            else{
                myStack.push(atoi(t.c_str()));
            }
        }
        return myStack.top();
    }

int main() {
    vector<string> tokens{"2", "1", "+", "3", "*"};
    int result = evalRPN(tokens);
    cout<<result<<endl;
    return 0;
}