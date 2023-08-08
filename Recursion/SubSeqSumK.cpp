#include<bits/stdc++.h>
using namespace std;

void prints(int ind, vector<int> &ds, int s, int sum, vector<int> &arr, int n) {
    if(ind == n) {
        if(s == sum) {
            for (auto it: ds)
                cout << it << " ";
            cout<< endl;
        }
        return;
    }

    // pick
    ds.push_back(arr[ind]);
    s += arr[ind];
    prints (ind+1, ds, s, sum, arr, n);
    s-= arr[ind];
    ds.pop_back();

    // not pick
    prints (ind+1, ds, s, sum, arr, n);
}

int main(){
    vector<int> arr = {1,2,1};
    vector<int> ds;
    prints(0,ds,0, 2, arr,3);
}
