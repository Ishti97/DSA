#include<bits/stdc++.h>
using namespace std;

/// 1. Brute force - O(n^2)  SC - O(1)
/// 2. Hashmap - O(2n)  SC - O(n)

/// Best - Simple math - O(2n) SC - O(1)
vector<int> findMissingRepeatingNumbers (vector<int> &a) {
    /// Find ----      S - Sn = x - y             S^2 - S^2n
    long long n = a.size();
    long long Sn = (n * (n+1)) / 2;
    long long S2n = (n* (n+1) * (2*n+1)) / 6;  /// formula for sqr
    long long S = 0, S2 = 0;

    for (int i=0;i<n;i++) {
        S += a[i];
        S2 += (long long) a[i] * (long long) a[i];
    }

    long long val1 = S - Sn;              /// x-y
    long long val2 = S2 - S2n;
    val2 = val2 / val1;                     /// x+y
    long long x = (val1 + val2) / 2;
    long long y= x - val1;
    cout<<x<<" "<<y<<endl;
    return {(int) x, (int) y};
}
int main(){
    vector<int> arr = {1,2,3,4,1,6};
    findMissingRepeatingNumbers(arr);
    return 0;
}
