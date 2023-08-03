#include <bits/stdc++.h>
using namespace std;
/// 1. Brute-force using merge sort Nlogn hbe
/// 2. using hashtable and count total 0,1,2 and rewrite arr O(2n)

/// Best Dutch Flag algo using low, mid, high pointer
void srt(vector<int> &arr){
    int low = 0, mid = 0, high = arr.size()-1;  // entire arr unsorted;  (mid-->high) er majhe unsorted

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++; mid++;
        }
        else if(arr[mid] == 1) mid++;
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr= {0,0,1,2,0,1,1,2,2,1,0};
    srt(arr);
    return 0;
}
