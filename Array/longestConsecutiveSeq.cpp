#include<bits/stdc++.h>
using namespace std;



int longestSuccessiveElements1(vector<int>&a) {
    int n = a.size();
    int longest = 1;
    if(n== 0) return 0;

    unordered_set<int> st;
    for(int i=0;i<n;i++)                         // O(n)
        st.insert(a[i]);

    for (auto it: st) {                               // O(n) + n = 2n       //iterate 7 items mean all
        if(st.find(it-1) == st.end()) {
            int cnt = 1;
            int x= it;
            while(st.find(x+1) != st.end()) {    // 1,2,3,4 //100,101,102 searching
                x = x + 1;
                cnt = cnt+1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}







/// Better apr TC - O(nlogn) + O(n)
int longestSuccessiveElements (vector<int>&nums){
    if(nums.size() == 0) return 0;
    sort(nums.begin(), nums.end());

    int n = nums.size(), lastSmaller = INT_MIN, cnt = 0, longest = 1;

    for(int i=0;i<n;i++) {
            if(nums[i] - 1 == lastSmaller) {
                cnt += 1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]) {
                    cnt = 1;
                    lastSmaller = nums[i];
            }
            longest = max(longest, cnt);
    }
    return longest;
}

int main(){

    vector<int> arr={5,5,5,8,1,2,4,3};
    cout<<longestSuccessiveElements1(arr);
}
