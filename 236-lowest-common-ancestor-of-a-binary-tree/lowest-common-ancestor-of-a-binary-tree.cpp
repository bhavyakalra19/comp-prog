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
    TreeNode *temp;
    bool getAns(TreeNode *root, int p, int q){
        if(!root || temp != NULL) return false;
        bool a = getAns(root->left, p, q);
        bool b = getAns(root->right, p, q);
        if(((root->val == p || root->val == q) && (a == true || b == true)) || (a & b)){
            temp = root;
        }
        return (a | b | root->val == p | root->val == q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        temp = NULL;
        getAns(root, p->val, q->val);
        return temp;
    }
};