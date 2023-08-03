#include <bits/stdc++.h>
using namespace std;
/// 1. Brute Force - O(n^2) Sc - O(1)

/// Best kadane's O(n)
int maxSubArray(vector<int>& nums){
    int sum = 0, maximum = INT_MIN, start, fin;

    for(int i=0; i<nums.size(); i++){
        if(sum==0) start = i;                 // track start to print max length arr

        sum+= nums[i];

        if(sum > maximum){
            maximum = sum;
            start = start;                    // start keeps it pos
            fin = i;                               // finish updates its pos
        }
        if(sum < 0) sum = 0;            // don't carry
    }
    return maximum;
}
int main(){
    vector<int> arr= {-2,-3,4,-1,-2,1,5,-3};
    cout<<"Sum: "<<maxSubArray(arr);
    return 0;
}
