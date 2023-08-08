#include<bits/stdc++.h>
using namespace std;

func(vector<int> &arr){
    int prev2 = 0, prev = arr[0], n = arr.size();

    for(int i=1;i<n;i++){
        int take = arr[i];
        if(i > 1) take += prev2;

        int notTake = 0 + prev;

        int curr = max(take, notTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

long long int houseRobber(vector<int> &arr, int sz){
    if(sz==1) return arr[0];

    vector<int> tmp1,tmp2;
    for(int i=0;i<sz;i++){
        if(i!=0) tmp1.push_back(arr[i]);
        if(i!=sz-1) tmp2.push_back(arr[i]);
    }
    return max(func(tmp1), func(tmp2));
}

int main(){
    vector<int> arr={10,20,5,15};
    int sz = arr.size();
    cout<<houseRobber(arr, sz);
    return 0;
}
