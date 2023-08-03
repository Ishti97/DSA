#include <bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> &arr, int sz, vector<int> &sumSubset) {
    if(ind == sz) {
        sumSubset.push_back(sum);
        return;
    }

    // pick the element
    func(ind + 1, sum + arr[ind], arr, sz, sumSubset);
    // Do-not pick the element
    func(ind +1, sum, arr, sz, sumSubset);
}

vector<int> subsetSums (vector<int> &arr, int sz) {         /// Formula - next value sum krbo or krbo na
    vector<int> sumSubset;

    func(0,0, arr, sz, sumSubset);
    sort(sumSubset.begin(),  sumSubset.end());
    return sumSubset;
}

int main(){
    vector<int> arr={1,2,3};
    int sz = arr.size();
    vector<int> ans = subsetSums(arr, sz);

    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}
