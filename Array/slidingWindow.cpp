#include<bits/stdc++.h>

using namespace std;

void GetMax(vector < int > nums, int left, int right, vector < int > & ans) {
  int maxi = INT_MIN;
  for (int i = left; i <= right; i++)
    maxi = max(maxi, nums[i]);
  ans.push_back(maxi);
}
vector < int > maxSlidingWindow(vector < int > & nums, int k) {
  int left = 0, right = 0;
  vector < int > ans;
  while (right < k - 1) {
    right++;
  }

    while (right < nums.size()) {
      GetMax(nums, left, right, ans);
      left++;
      right++;
    }
  return ans;
}
int main() {
  int k = 3;
  vector < int > arr {4,0,-1,3,5,3,6,8};
  vector < int > ans = maxSlidingWindow(arr, k);

  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << "  ";
  return 0;
}
