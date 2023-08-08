/// Recursion -> Memoization -> Tabulation -> Tabulation without storage
// Tabulation (Bottom-Top)
#include<bits/stdc++.h>
using namespace std;

// Tabulation without storage

int fibo(int n){                               // TC-O(n)  SC-O(1)

     if (n <= 1) {
        return n;
    }
    int prev = 1, prev2 = 0;

    for(int i=2;i<=n;i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// Tabulation with storage

int fibo1(int n){                             // TC-O(n)  SC-O(n)
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Memoization

int fibo2(int n){                              // TC-O(n)  SC-O(n) + O(n) {one for recursive stack}
    vector<int> dp(n+1,-1);

    if(n<=1) return n;

    if(dp[n]!=-1) return dp[n];

   return dp[n] = fibo2(n-1)+fibo2(n-2);
}

int main(){
    cout<<fibo(4);
    cout<<fibo1(4);
    cout<<fibo2(4);
    return 0;
}
