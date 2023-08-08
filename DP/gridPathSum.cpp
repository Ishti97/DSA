#include<bits/stdc++.h>
using namespace std;

int func(vector<vector<int>> &arr, int i, int j){
    if(i==0 && j==0) return arr[i][j];
    if(i<0 || j<0) return 1e9;

    int up = arr[i][j] + func(arr, i-1, j);
    int left = arr[i][j] + func(arr, i, j-1);

    return min(up,left);
}

int help(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp){
     if(i==0 && j==0) return arr[i][j];
     if(i<0 || j<0) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];

    int up = arr[i][j] +help(arr, i-1, j, dp);
    int left = arr[i][j] + help(arr, i, j-1, dp);

    return dp[i][j] = min(up,left);
}

int func2(vector<vector<int>> &arr, int i, int j){
     vector<vector<int>> dp(i, vector<int>(j, -1));
     return help(arr, i-1, j-1, dp);
}

int main(){
    vector<vector<int>> arr={
        {4,3,5},
        {1,2,6},
        {5,8,2},
    };

    // cout<<func(arr,arr.size()-1,arr[0].size()-1);
    cout<<func2(arr,arr.size(),arr[0].size());
    return 0;
}
