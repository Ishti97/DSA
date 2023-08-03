 #include<bits/stdc++.h>
using namespace std;

/// only recursion
int countPaths(int i, int j, int row, int col){

    if(i==(row-1) && j==(col-1)) return 1;

    if(i>=row || j>=col) return 0;

    else return countPaths(i+1, j) + countPaths(i,j+1);
}

/// recursion theke dp
/// only change to make recursion -> dp  is...
/// when return ans, store it in dp , when new recursion called, check similar stage vis/not
int countPaths(int i, int j, int row, int col, vector<vector<int>> & dp){
    if(i==(row-1) && j==(col-1)) return 1;

    if(i>=row || j>=col) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    else return dp[i][j] =  countPaths(i+1, j) + countPaths(i,j+1);
}

/// using combination
int uniquePaths(int row, int col) {

    int N = row + col - 2;      ///atmost right e (col-1) jbo + bottom (row-1) jbo; so (row-1 + col-1)
    int r = col - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (N − r + i) / i;

    return (int) res;
}

int main(){

    return 0;
}
