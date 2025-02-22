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
    bool getAns(TreeNode *root, int &a, int &b){
        if(!root || temp != NULL) return false;
        bool lf = getAns(root->left, a, b);
        bool rt = getAns(root->right, a, b);
        if(lf && rt){
            temp = root;
            return true;
        }
        if(root->val == a || root->val == b){
            if(lf | rt){
                temp = root;
                return true;
            }
            return true;
        }
        return lf | rt;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        temp = NULL;
        getAns(root, p->val, q->val);
        return temp;
    }
};