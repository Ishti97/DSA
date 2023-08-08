#include <bits/stdc++.h>
using namespace std;

vector<int> func(int ind, int sum, vector<int> &ds, vector<int> &arr, int sz ) {
    if(ind == sz) {
        ds.push_back(sum);
        return {};
    }

    func(ind + 1, sum + arr[ind], ds, arr, sz);    // pick the element

    func(ind +1, sum, ds, arr, sz);   // Do not pick the element

    return ds;
}

int main(){
    vector<int> arr={1,2,3};
    vector<int> ds;

    vector<int> ans = func(0,0, ds, arr, 3);
    sort(ans.begin(),  ans.end());

    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}
