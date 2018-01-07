//break leaves a loop, continue jumps to the next iteration.
#include <iostream>
using namespace std;
int main() {
    for(int i = 0; i<5; i++){
        cout<<i<<endl;
        if (i==3){
            break;

        }

    }
    cout<<"break out of loop"<<endl;



    for(int i = 0; i<5; i++){
        cout<<i;
        if(i==3){
            cout<<"next iter"<<endl;
            continue;
        }
        cout<<"hi"<<endl;
    }
    cout<<"continue jumps to the next iteration"<<endl;

    return 0;
}