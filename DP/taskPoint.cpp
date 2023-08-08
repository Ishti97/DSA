#include<bits/stdc++.h>
using namespace std;

int func(int day, int last_task, vector<vector<int>> &arr, vector<vector<int>> &dp){
    if(day==0){
            int maxi = 0;
            for(int task=0;task<3;task++){
                if(task!=last_task){
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
    }

    if(dp[day][last_task] != -1) return dp[day][last_task];

    int maxi = 0;
    for(int task=0;task<3;task++){
        if(task!=last_task){
            int point = arr[day][task] + func(day-1, task, arr, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last_task] = maxi;
}


int f(vector<vector<int>> &arr, int n, int task_type){
    vector<vector<int>> dp(n, vector<int>(task_type+1,-1));
    return func(n-1, task_type, arr, dp);
}



int main(){

    vector<vector<int>> arr = {
        {2,1,3},
        {2,3,6},
        {4,3,5},
        {7,5,1}
    };
    cout<<f(arr, arr.size(), arr[0].size());

    return 0;
}
