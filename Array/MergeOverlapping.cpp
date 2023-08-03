#include<bits/stdc++.h>
using namespace std;

/// Best -------- TC --- nlogn + O(n)
vector<vector<int>> mergeOverlapping(vector<vector<int>> &t){
    vector<vector<int>> ans;
    int n = t.size();

    sort(t.begin(), t.end());                                /// nlogn

    for(int i=0; i<n; i++){                                  /// O(n)
        if(ans.empty() || t[i][0] > ans.back()[1])
            ans.push_back(t[i]);
        else
            ans.back()[1] = max(ans.back()[1], t[i][1]);
    }
    return ans;
}

int main(){
    vector<vector<int>> t = {
        {1,3},{2,4},{2,6},{8,10}
    };
   vector<vector<int>> ans =  mergeOverlapping(t);

    for(int i=0;i<ans.size();i++){
        for(auto it: ans[i])
            cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
