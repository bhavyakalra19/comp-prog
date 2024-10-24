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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            unordered_map<TreeNode*,int> mp;
            int totalSum = 0;
            qt.push(NULL);
            while(qt.front() != NULL){
                auto it = qt.front();
                qt.pop();
                int localSum = 0;
                if(it->left){
                    qt.push(it->left);
                    localSum += it->left->val;
                }
                if(it->right){
                    qt.push(it->right);
                    localSum += it->right->val;
                }
                totalSum += localSum;
                if(it->left){
                    mp[it->left] = localSum;
                }
                if(it->right){
                    mp[it->right] = localSum;
                }
            }
            qt.pop();
            for(auto m : mp){
                m.first->val = totalSum - mp[m.first];
            }
        }
        root->val = 0;
        return root;
    }
};
