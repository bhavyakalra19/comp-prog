/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    TreeNode* dfs(TreeNode *root, unordered_map<int,bool> &mp){
        if(!root) return NULL;
        if(mp.find(root->val) == mp.end()){
            root->left = dfs(root->left, mp);
            root->right = dfs(root->right, mp);
            return root;
        }
        TreeNode *left = dfs(root->left, mp);
        if(left) ans.push_back(left);
        TreeNode *right = dfs(root->right, mp);
        if(right) ans.push_back(right);
        return NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,bool> mp;
        for(auto a : to_delete) mp[a] = true;
        TreeNode *t = dfs(root, mp);
        if(t) ans.push_back(t);
        return ans;
    }
};