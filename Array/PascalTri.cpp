#include <bits/stdc++.h>
using namespace std;

void findValOfPascalTri(int n, int r){     /// 1. TC - O(N) SC = O(1)
    int res = 1;
    for(int i=0; i<r; i++){
        res = res * (n- i);
        res =res / (i +1);
    }
    cout<<res;
}

void findNthRow(int  r){   /// 2. TC - O(N) SC = O(1)
    int ans = 1;
    cout<<ans<<" ";

    for(int i=1; i<r; i++){
        ans = ans * (r - i);
        ans = ans / i;
        cout<< ans<< " ";
    }
}

vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for(int col = 1; col<row; col++){
        ans = ans * (row - col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int N){ /// 3. O(n^2)
    vector<vector<int>> ans;

    for(int i=1; i<=N; i++)
        ans.push_back(generateRow(i));

    return ans;
}

int main(){
    int row = 6, col = 3;
    /// 1.
    // findValOfPascalTri(row-1,col-1); // nCr = n! / r!  -- works like 5/1 * 4/2 * 3/3 !!
    /// 2.
    //findNthRow(row);
    /// 3.
    pascalTriangle(row);

    return 0;
}
