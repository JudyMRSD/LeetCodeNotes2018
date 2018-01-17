#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
        int maxSub = nums[0];
        int minSub = nums[0];
        int res = nums[0];
        for (int i = 1; i< nums.size(); i++){
            int tmp = maxSub;
            //if nums[i] is larger, maxSub=nums[i],
            //effectively setting the maxSub to the maximum value of subarray starting from nums[i]
            //use both maxSub*nums[i], minSub*nums[i], since negative*negative could be positive
            maxSub = max(maxSub*nums[i], max(minSub*nums[i],nums[i]));
            minSub = min(minSub*nums[i], min(tmp*nums[i], nums[i]));
            res = max(maxSub, res);
        }
        return res;
    }
int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout<<maxProduct(nums)<<endl;
    return 0;
}