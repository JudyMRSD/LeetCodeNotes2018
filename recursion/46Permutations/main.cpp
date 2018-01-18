#include <iostream>
#include <vector>
using namespace std;
void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result);

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > result;

    permuteRecursive(num, 0, result);
    return result;
}

void printVect(vector<int> vect){
    cout<<"     ";
    for (int i = 0; i<vect.size(); i++){
        cout<<vect[i];
    }
    cout<<endl;
}

void printBlank(int n){
    for(int i = 0; i<n; i++){
        cout<<"  ";
    }

}

void printResult(vector<vector<int> > &result){
    for (int i = 0; i<result.size(); i++){
        for(int j = 0; j<result[i].size(); j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
// permute num[begin..end]
// invariant: num[0..begin-1] have been fixed/permuted
void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
    printBlank(begin);
    cout<<"recursion begin= " <<begin<<endl;
    printResult(result);
    if (begin >= num.size()) {
        // one permutation instance
        result.push_back(num);
        return;
    }
    for (int i = begin; i < num.size(); i++) {
        swap(num[begin], num[i]);
        //cout<<"swap begin = "<< begin<< " i= "<< i<<endl;
        //printVect(num);
        permuteRecursive(num, begin + 1, result);
        // reset
        //cout<<"reset swap begin = "<< begin<< " i= "<< i<<endl;
        swap(num[begin], num[i]);
    }
}
int main() {
    vector<int> num = {1,2,3};
    vector<vector<int> >  result = permute(num);

    return 0;
}