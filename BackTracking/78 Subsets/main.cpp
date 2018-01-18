#include <iostream>
#include <vector>
using namespace std;

void printSubs(vector<vector<int>>& subs){
    for(int i = 0 ; i < subs.size(); i++){
        cout<<"i= "<<i<<endl;
        if(subs[i].size()==0){
            cout<<"subs[i]=[]"<<endl;
        }
        for(int j = 0 ; j < subs[i].size(); j++){
            cout<<" j= "<<j<<" subs[i][j] "<<subs[i][j] <<"    ";
        }
        cout<<endl;
    }
}

void printSub(vector<int>& sub){
    if(sub.size()==0){
        cout<<"     sub.size()==0"<<endl;
    }

    for(int j = 0 ; j < sub.size(); j++) {
        cout << "     j= " << j << " sub[j] " << sub[j] << "    "<<endl;
    }
}

void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
    //printSub(sub);
    subs.push_back(sub);
    //printSubs(subs);
    for (int i = start; i < nums.size(); i++) {
        //cout<<"ith iteration: "<< i<<endl;
        sub.push_back(nums[i]);
        genSubsets(nums, i + 1, sub, subs);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subs;
    vector<int> sub;
    genSubsets(nums, 0, sub, subs);
    return subs;
}


int main() {
    vector<int> nums = {1,2,3};
    subsets(nums);
    return 0;
}