/// use queue(node, vertical, level), map(key-wise sort)
/// use map<vertical...int, map<multi_level... int, multilevel_have_multiset... multiset<int>>>
/// vertical--> level-->maybe multilevel-->each level multiset ba multi value
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

vector<vector<int>> verticalOrderTraversal(TreeNode* root){
    map<int, map<int, multiset<int>>> nodes;  // set keeps unique val, multiset keeps similar value but sorted
    queue<pair<TreeNode*, pair<int,int>>> todo;
    todo.push({root, {0,0}});

    while(!todo.empty()){
        auto ptr = todo.front();
        todo.pop();
        TreeNode *node = ptr.first;
        int vertical = ptr.second.first;
        int lvl = ptr.second.second;

        nodes[vertical][lvl].insert(node->val);

        if(node->left)
            todo.push({node->left, {vertical-1, lvl+1}});
        if(node->right)
            todo.push({node->right, {vertical+1, lvl+1}});
    }
    vector<vector<int>> verticals;
    for(auto it:nodes){
        vector<int> levels;
        for(auto eachlevel : it.second){
            levels.insert(levels.end(), eachlevel.second.begin(), eachlevel.second.end());
        }
        verticals.push_back(levels);
    }
    return verticals;
}
