 #include <bits/stdc++.h>
using namespace std;

 void subs(vector<int>& nums, int ind, vector<vector<int>>& ans, vector<int> tmp){
        if (ind==nums.size()){
            ans.push_back(tmp);
            return;
            }
        subs(nums,ind+1,ans,tmp);
        tmp.push_back(nums[ind]);
        subs(nums,ind+1,ans,tmp);
    }

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> tmp;
    vector<vector<int>> ans;
    subs(nums, 0, ans, tmp);
    return ans;
}

int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans = subsets(arr);

    for(int i=0; i<ans.size();i++){
        for(auto it:ans[i]){
            cout<<it<<" ";
        }cout<< endl;
    }
    return 0;
}
