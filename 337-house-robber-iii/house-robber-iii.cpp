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
    unordered_map<TreeNode*,int> tm;
    unordered_map<TreeNode*,int> nm;
    int getAns(TreeNode *root, bool take){
        if(!root) return 0;
        if(take && tm.find(root) != tm.end()) return tm[root];
        if(!take && nm.find(root) != nm.end()) return nm[root];
        int tk = 0;
        if(take){
            tk = root->val + getAns(root->left, false) + getAns(root->right, false);
        }
        int nt = getAns(root->left, true) + getAns(root->right, true);
        if(take){
            return tm[root] = max(tk, nt);
        }
        return nm[root] = max(tk, nt);
    }

    int rob(TreeNode* root) {
        return getAns(root, true);
    }
};