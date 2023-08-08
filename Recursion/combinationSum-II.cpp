  #include <bits/stdc++.h>
using namespace std;

void helper(int ind, vector<int>& arr, int target, vector<int>& temp, vector<vector<int>>& ans)
    {
        if (target==0) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            if (i != ind &&  arr[i] == arr[i-1])
                continue;
            if (arr[i] > target)
                break;

            temp.push_back(arr[i]);
            helper(i+1, arr, target-arr[i], temp, ans);
            temp.pop_back();
        }
    }

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    helper(0, arr, target, temp, ans);
    return ans;
}

int main(){
    vector<int> arr={10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(arr, target);

    for(int i=0; i<ans.size();i++){
        for(auto it:ans[i])
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
