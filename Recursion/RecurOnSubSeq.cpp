#include<bits/stdc++.h>
using namespace std;

void printF(int ind, vector<int> &ds, vector<int> &arr, int n) {
        if(ind == n) {
                for(auto it: ds)
                    cout << it << " " ;

        if(ds.size() == 0) cout << "{}";

        cout << endl;
        return;
}
    // take or pick the particular Index Into the subsequence
    ds.push_back(arr[ind]);
    printF(ind+1, ds, arr, n);
    ds.pop_back();

    printF(ind+1, ds, arr, n);  // not pick, or not take condition, this elemnt is not added to your subsequenc printf(ind+1, ds, arr, n);
}

int main(){
    vector<int> arr = {3,1,2};
    vector<int> ds;
    printF(0,ds, arr,3);
}
