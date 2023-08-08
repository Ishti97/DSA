#include<bits/stdc++.h>
using namespace std;

vector<int> duplicateZeros(vector<int>& arr) {
        int i=0, n=arr.size();
        while(i<n)
        {
            if(arr[i]==0)
            {
                arr.insert(arr.begin()+i, 0);
                i += 2;
            }
            else
                i++;
        }
        arr.resize(n);
        return arr;
}

int main(){
    vector<int> arr={1,0,2,3,0,4,5,0};
vector<int> ans = duplicateZeros(arr);
for(auto it:ans)
    cout<<it<<" ";
}
