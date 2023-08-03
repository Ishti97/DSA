/// most right - most left + 1 hocche width
/// now, root i hole child 2i and 2i+1 hbe; now skew type tree hole exponentially bere overflow hoy
/// solution hocche, root value komiye, like i-1 kre diye 2i and 2i+1 krle adjust hoye jbe
/// jokhon child index dibo, tokhon e er age root index thik kre nibo

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

int widthOfBinaryTree(TreeNode *root) {
    if(!root) return 0;
    int ans = 0;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        int mmin = q.front().second; // to make the id starting from zero

        int size = q.size(), first, last;
        for(int i=0; i<size; i++){

            int cur_id = q.front().second- fmmin;
            TreeNode *node = q.front().first;
            q.pop();

            if(i==0) first = cur_id;
            if(i==size-1) last = cur_id;

            if(node->left) q.push({node->left, cur_id*2+1});
            if(node->right) q.push({node->right, cur_id*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}
