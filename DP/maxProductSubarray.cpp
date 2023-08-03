#include<bits/stdc++.h>
using namespace std;
// BF -- O(n^2)
int maxProductSubArray(vector<int>& nums) {
    int sz = nums.size();
    int res=nums[0];

    for(int i=0;i<sz-1;i++){
        int pro=nums[i];
        for(int j = i+1;j<sz;j++){
            res = max(pro, res);
            pro = pro*nums[j];
        }
        res = max(res, pro);
    }
    return res;
}
// 2 pointer -- TC: O(N)
int maxProductSubArray2(vector<int>& nums) {
    int maxLeft = nums[0], maxRight = nums[0];
    int prod = 1;
    bool zeroPresent =  false;

    for(auto i:nums) {
        prod *= i;
        if(i == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxLeft = max(maxLeft,prod);
    }

    prod = 1;

    for(int j=nums.size()-1;j>=0;j--) {
        prod *= nums[j];
        if(nums[j] == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        maxRight = max(maxRight,prod);
    }

    if(zeroPresent)
        return max(max(maxLeft,maxRight),0);
    return max(maxLeft,maxRight);
}

/// Best -- O(n)
int maxProductSubArray3(vector<int>& nums) {
    int prefix=1, suffix=1, ans=INT_MIN, n = nums.size();

    for(int i=0;i<n;i++){
        if(prefix==0) prefix = 1;
        if(suffix ==0 ) suffix = 1;

        prefix *=nums[i];
        suffix *= nums[n-i-1];
        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}

int main() {
    //vector<int> nums = {1,2,-3,0,-4,-5};
    vector<int> nums = {-2,0-1};
    cout<<maxProductSubArray(nums);
    return 0;
}
