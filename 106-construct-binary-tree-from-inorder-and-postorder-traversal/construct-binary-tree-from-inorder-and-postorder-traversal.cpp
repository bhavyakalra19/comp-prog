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
        if(n == 0) return NULL;
        TreeNode *root = new TreeNode(postorder[n-1]);
        TreeNode *main = root;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        stack<TreeNode*> st;
        st.push(root);
        for(int i = n-2; i >= 0; i--){
            if(mp[postorder[i]] < mp[st.top()->val]){
                while(!st.empty() && mp[postorder[i]] < mp[st.top()->val]){
                    root = st.top();
                    st.pop();
                }
                root->left = new TreeNode(postorder[i]);
                root = root->left;
            }else{
                root->right = new TreeNode(postorder[i]);
                root = root->right;
            }
            st.push(root);
        }
        return main;
    }
};