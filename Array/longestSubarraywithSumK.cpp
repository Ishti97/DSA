#include<bits/stdc++.h>
using namespace std;

/// brute-force n^2
int func(vector<int> &arr, int k){
    int n = arr.size();
    int longest = 0;
    for(int i=0;i<n;i++){        /// {1,2,3,1,1,1,2,1}
        int sum = 0;
        for(int j=i;j<n;j++){

                sum += arr[j];
                if(sum==k)
                    longest = max(longest, j-i+1);

        }
    }
    return longest;
}
/// Better using hashmap
/// O(n) * logn for ordered map
/// O(n) * 1 for unordered but worst case unordered will be n so n^2
/// SC is n
int func1(vector<int> &a, long long k){
    map<long long, int> preSumMap;  // value->index
    long long sum = 0;
    int maxLen = 0;

    for(int i=0; i<a.size(); i++) {
        sum += a[i];

        if(sum == k)
            maxLen = max(maxLen, i+1);

        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end())
            maxLen = max(maxLen, i - preSumMap[rem]);

        if(preSumMap.find(sum) == preSumMap.end()) // check if neg or 0 in lst, else direct assign
            preSumMap[sum] = i;
    }
    return maxLen;
}

/// Best using 2 pointer
/// O(2n)
/// SC is O(1)
int func2(vector<int> &a, long long k){
    int left = 0, right = 0, maxLen = 0 , n = a.size();
    long long sum = a[0];

    while(right < n) {

        while(left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if(right <n)
            sum += a[right];
    }
    return maxLen;
}

int main(){
    vector<int> arr={1,2,3,1,1,1,2,1};
    cout<<func2(arr,3);
    return 0;
}
