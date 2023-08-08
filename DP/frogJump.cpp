#include<bits/stdc++.h>
using namespace std;

int jump(vector<int> &arr, int ind, vector<int> &dp){          // Memoization (Top- Down)
    if(ind==0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int way1 = jump(arr, ind-1, dp) + abs(arr[ind]-arr[ind-1]);

    int way2;
    if(ind>1) way2 =  jump(arr, ind-2, dp) + abs(arr[ind]- arr[ind-2]);

    return dp[ind] = min(way1, way2);
}

int func(vector<int> &arr, int sz){
    vector<int> dp(sz+1,-1);
    return jump(arr, sz-1, dp);
}

int func1(vector<int> &arr, int sz){                              // Tabulation (Bottom-Up)--No recursion
    vector<int> dp(sz, 0);
    dp[0] = 0;
    for(int i=1;i<sz;i++){
        int way1 = dp[i-1] + abs(arr[i]-arr[i-1]);

        int way2;
        if(i>1) way2 =  dp[i-2] + abs(arr[i]- arr[i-2]);

        dp[i] = min(way1, way2);
    }
     return dp[sz-1];
}

int func2(vector<int> &arr, int sz){              // Tabulation--No recursion--No extra space
   int prev = 0, prev2 = 0;

    for(int i=1;i<sz;i++){
        int way1 = prev + abs(arr[i]-arr[i-1]);

        int way2;
        if(i>1) way2 = prev2 + abs(arr[i]- arr[i-2]);

        int curr = min(way1, way2);
        prev2 = prev;
        prev = curr;
    }
     return prev;
}

int main(){
    vector<int> arr ={10,20,30,10};
    int sz = arr.size();
    cout<<func2(arr, sz);
    return 0;
}
