#include<bits/stdc++.h>
using namespace std;

/// 1. extra 3rd arr niye abr initial array gulo te replace - TC O(n+m) + O(n+m) --- SC - O(n+m)

/// Optimum - TC - O(min(n,m)) {n or m anyone size is small it will end there}
///                       + O(nlogn)  + O(mlogm) for sort    !      SC - O(1)

vector<int> func(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size(), m = arr2.size();
    /// point to right side of arr1 and left side of arr2 cz they r swappble until left < right value;
    int left = n-1, right = 0;

    while(left>=0 && right<m){
        if(arr1[left]>arr2[right]){
            swap(arr1[left], arr2[right]);
            left--; right++;
        }
        else
            break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    return arr1;
}

int main(){
    vector<int> a1 = {1,3,5,7};
    vector<int> a2 = {0,2,6,8,9};
    vector<int> ans = func(a1,a2);
    for(auto& it:ans)
        cout<<it<<" ";
}


