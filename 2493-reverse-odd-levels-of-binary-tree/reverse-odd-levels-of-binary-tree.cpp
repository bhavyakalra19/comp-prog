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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> check;
        int i = 0;
        int j = 1;
        int level = 0;
        check.push_back(root);
        while(i < j){
            int a = j;
            if(level % 2){
                for(int idx = 0; idx < (j - i)/2; idx++){
                    int temp = check[idx + i]->val;
                    check[idx + i]->val = check[j-1-idx]->val;
                    check[j - 1 - idx]->val = temp;
                }
            }
            while(i < a){
                if(check[i]->left){
                    check.push_back(check[i]->left);
                    j++;
                }
                if(check[i]->right){
                    check.push_back(check[i]->right);
                    j++;
                }
                i++;
            }
            level++;
        }
        return root;
    }
};
