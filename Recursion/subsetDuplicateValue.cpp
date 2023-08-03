  #include <bits/stdc++.h>
using namespace std;

 void solve(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);

    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind and nums[i] == nums[i - 1])
            continue;

        ds.push_back(nums[i]);
        solve(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    solve(0, nums, ds, ans);
    return ans;
}
int main(){
    vector<int> arr={1,2,2};
    vector<vector<int>> ans = subsetsWithDup(arr);

    for(int i=0; i<ans.size();i++){
        for(auto it:ans[i]){
            cout<<it<<" ";
        }cout<< endl;
    }
    return 0;
}
