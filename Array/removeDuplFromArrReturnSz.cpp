#include<bits/stdc++.h>
using namespace std;
/// set use kre extra space lge

/// best approach
int removeDuplicates(vector<int>& nums) {

        // index=0 is sorted
        int index = 1;

        for(int j = 1; j<nums.size(); j++){
            if(nums[j] != nums[j-1]){
                nums[index] = nums[j];
                index++;
            }

        }
        return index;
    }

