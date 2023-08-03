/// TC-O(n) SC-O(h)
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 bool getPath(TreeNode *root, int target, vector<int> &ans ){
    if(!root) return false;
    ans.push_back(root->val);
    if(root->val == target) return true;

    if(getPath(root->left, target, ans) || getPath(root->right, target, ans)) return true;

    ans.pop_back();
    return false;
 }

 vector<int> solve(TreeNode *root, int target){
    vector<int> ans;
    if(!root) return ans;
    getPath(root, target, ans);
    return ans;
 }
