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
class FindElements {
public:
    unordered_map<int,bool> mp;
    FindElements(TreeNode* root) {
        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left){
                temp->left->val = 2 * temp->val + 1;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->val = 2 * temp->val + 2;
                q.push(temp->right);
            }
            mp[temp->val] = true;
        }
    }
    
    bool find(int target) {
        return mp.find(target) != mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */