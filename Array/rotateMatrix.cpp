#include <bits/stdc++.h>
using namespace std;
/// Brute-force TC - O(n^2) SC - O(n^2)  ----> ans[j][n-1]- i = matrix[i][j]

void rotatematrix(vector<vector<int>> &mt){
    int n = mt.size();

    for(int i=0; i<n-1; i++) {        /// transpose; diagonal same thkbe; n-1 mane half side of diagonal
        for(int j=i+1; j<n; j++)             /// n/2 * n/2
            swap(mt[i][j], mt[j][i]);
    }

    // Traverse each row of arr[][]
    for (int i = 0; i < n; i++) {            /// n * n/2
        int start = 0, end = n - 1;

        while (start < end) {
            swap(mt[i][start], mt[i][end]);
            start++; end--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<mt[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> mt = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    rotatematrix(mt);
    return 0;
}
