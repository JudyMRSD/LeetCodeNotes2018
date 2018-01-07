#include <iostream>
vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i<nums.size(); i++){
            int index = abs(nums[i])-1;
            if(nums[index]>0){
                nums[index]=-nums[index];
            }
        }
        for (int i = 0; i< nums.size(); i++){
            if (nums[i]>0){
                res.push_back(i);
            }
        }


        return res;
}

int main() {

    vector<int> res = findDisappearedNumbers(nums);
    for (int i = 0; i<res.size(), i++){

    }
    return 0;
}