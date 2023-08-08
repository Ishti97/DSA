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

 /// use a queue and a map(key-wise sort)
vector <int> bottomView(Node *root) {
    vector<int> ans;
    if(root == NULL) return ans;

    map<int, int> mpp; // line-val
    queue<pair<Node*, int>> q; // node-line
    q.push({root, 0});

    while(!q.empty()) {
        auto it =  q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        mpp[line] = node->val;

        if(node->left!= NULL)
            q.push({node->left, line-1});

        if(node->right != NULL)
            q.push({node->right, line+ 1});

    }

    for (auto it : mpp)
        ans.push_back(it.second);

    return ans;
}
