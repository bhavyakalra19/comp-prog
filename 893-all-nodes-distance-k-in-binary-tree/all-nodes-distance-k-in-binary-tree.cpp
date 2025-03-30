/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;

    void getAns(TreeNode *root, unordered_map<TreeNode*, TreeNode*> mp, unordered_map<TreeNode*, bool> &vis, int k){
        if(!root || vis.find(root) != vis.end()) return;
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        vis[root] = true;
        getAns(root->left, mp, vis, k-1);
        getAns(root->right, mp, vis, k-1);
        getAns(mp[root], mp, vis, k-1);
    }

    void getParent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &mp){
        if(!root){
            return;
        }
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        getParent(root->left, mp);
        getParent(root->right, mp);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap[root] = NULL;
        unordered_map<TreeNode*, bool> visited;
        getParent(root, parentMap);
        getAns(target, parentMap, visited, k);
        return ans;
    }
};