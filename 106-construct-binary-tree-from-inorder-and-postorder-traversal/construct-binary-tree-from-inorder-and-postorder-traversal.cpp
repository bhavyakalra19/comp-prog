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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        TreeNode *root = new TreeNode(postorder[n-1]);
        TreeNode *main = root;
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        for(int i = n-2; i >= 0; i--){
            TreeNode *temp = new TreeNode(postorder[i]);
            if(mp[root->val] < mp[temp->val]){
                root->right = temp;
                root = temp;
            }else{
                while(!st.empty() && mp[st.top()->val] > mp[temp->val]){
                    root = st.top();
                    st.pop();
                }
                root->left = temp;
                root = temp;
            }
            st.push(temp);
        }
        return main;
    }
};