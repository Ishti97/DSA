#include<bits/stdc++.h>
using namespace std;

/// Best approach  nlogn + O(n * m)
/// SC - reduced
vector<vector<int>> triplet1(vector<int> &num) {
    int n = num.size();
    vector<vector<int>> ans;
    sort(num.begin(), num.end());

    for (int i=0;i<n;i++) {
        if(i>0 && num[i] == num[i-1]) continue;

        int j = i + 1;
        int k = n - 1;

        while(j<k) {
            int sum = num[i] + num[j] + num[k];

            if(sum < 0)
                j++;
            else if(sum > 0)
                k--;
            else {
                vector<int> temp = {num[i], num[j], num[k]};
                ans.push_back(temp);
                j++; k--;
                while(j<k && num[j] == num[j-1]) j++;
                while(j <k && num[k] == num[k+1]) k--;
            }
    }

    }
    return ans;
}

/// Better app O(n^2) + logm
/// SC - O(n) + (num. uniq. ele)*2

vector<vector<int>> triplet(vector<int> &num) {
    int n= num.size();
    set<vector<int>> st;

    for(int i=0;i<n;i++) {

        set<int> hashset;
        for(int j=i+1;j<n;j++) {
            int third = - (num[i] + num[j]);

            if(hashset.find(third) != hashset.end()){
                vector<int> tmp = {num[i], num[j], third};
                sort(tmp.begin(), tmp.end());
                st.insert(tmp);
            }
            hashset.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){
    vector<int> arr ={-1,0,1,2,-1,-4};
    vector<vector<int>> ans = triplet1(arr);

    for(int i=0;i<ans.size();i++){
        for(auto it : ans[i]){
            cout<<it<<" ";
        }cout<<endl;
    }
}
