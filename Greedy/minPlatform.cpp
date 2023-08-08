#include <bits/stdc++.h>
using namespace std;

// TC - O(2nlogn) + O(2n)  SC-O(1)

int findPlatform(vector<double> &arr, vector<double> &dep, int n){  // sort both arrival and departure
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int plat_needed = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i]<=dep[j]) {
            plat_needed++;
            i++;
        }
        else if (arr[i]> dep[j]) {
            plat_needed--;
            j++;
        }
        if (plat_needed > result)
            result = plat_needed;
    }
    return result;
}
int main(){
   vector<double> arr = {10,11,12.5};
    vector<double> dep = {10.5,11.5,12.5 };
    cout<<findPlatform(arr, dep, 1);
    return 0;
}
