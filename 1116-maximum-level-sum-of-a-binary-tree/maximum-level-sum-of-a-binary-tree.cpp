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
    unordered_map<int,int> mp;
    void getAns(TreeNode *root, int level){
        if(!root){
            return;
        }
        mp[level] += root->val;
        getAns(root->left,level+1);
        getAns(root->right,level+1);
    }
    
    int maxLevelSum(TreeNode* root) {
        getAns(root,1);
        int ans = INT_MIN;
        int lvl = 1;
        for(auto m : mp){
            if(m.second > ans){
                lvl = m.first;
                ans = m.second;
            }else if (m.second == ans && lvl > m.first){
                lvl = m.first;
            }
        }
        return lvl;
    }
};