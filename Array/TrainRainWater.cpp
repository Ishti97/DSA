#include<bits/stdc++.h>
using namespace std;
///Brute-force -- O(n)  SC-O(2n) -- extra space
int trap(vector<int>& height) {
    int n = height.size();

    // store maximum heights to the left and right of each element
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    left[0] = height[0];  // leftmost ele as the maximum height on its left
    right[n-1] = height[n-1];  // rightmost ele as the maximum height on its right

    // Traverse from left to right to find the maximum height to the left of each element
    for (int i = 1; i < n; i++)
        left[i] = max(left[i-1], height[i]);

    // Traverse from right to left to find the maximum height to the right of each element
    for (int i = n-2; i >= 0; i--)
        right[i] = max(right[i+1], height[i]);

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += min(left[i], right[i]) - height[i];  // difference between the min of left and right heights and the current height

    return sum;
}
///Two pointer -- O(n)  SC-O(1)
 int trap(vector<int>& height) {
        int n = height.size(), l = 0, r = n-1, ans = 0;
        int leftmax = height[l], rightmax = height[r];

        while (l < r) {
            if (leftmax <= rightmax) {
                l++;
                leftmax = max(leftmax, height[l]);
                ans += leftmax - height[l];
            }
            else {
                r--;
                rightmax = max(rightmax, height[r]);
                ans += rightmax - height[r];
            }
        }

        return ans;
    }
