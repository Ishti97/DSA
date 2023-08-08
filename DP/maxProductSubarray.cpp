#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {                /// BF -- O(n^2)
    int n = nums.size();
    int res = nums[0];

    for(int i=0; i<n-1; i++){
        int tmp = nums[i];
        for(int j = i+1; j<n; j++){
            res = max(tmp, res);
            tmp *= nums[j];
        }
        res = max(res, tmp);
    }
    return res;
}

int maxProductSubArray2(vector<int>& nums) {            /// 2 pointer -- TC: O(N)
    int maxLeft = nums[0], maxRight = nums[0], n = nums.size();
    bool zeroPresent =  false;

    int res = 1;
    for(auto i:nums) {
        res *= i;
        if(i == 0) {
            zeroPresent = true;
            res = 1;
            continue;
        }
        maxLeft = max(maxLeft,res);
    }

    res = 1;
    for(int j=n-1; j>=0; j--) {
        res *= nums[j];
        if(nums[j] == 0) {
            zeroPresent = true;
            res = 1;
            continue;
        }
        maxRight = max(maxRight, res);
    }

    if(zeroPresent) return max(max(maxLeft,maxRight), 0);
    return max(maxLeft,maxRight);
}


int maxProductSubArray3(vector<int>& nums) {                /// Best -- O(n)
    int prefix=1, suffix=1, ans = INT_MIN, n = nums.size();

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
    vector<int> nums = {1,2,-3,0,-4,-5};
    //vector<int> nums = {-2,0-1};
    cout<<maxProductSubArray(nums);
    return 0;
}
