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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        stack<TreeNode*> st;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[preorder[i]] = i;
        }
        TreeNode *root = new TreeNode(postorder[n-1]);
        st.push(root);
        for(int i = n - 2; i >= 0; i--){
            TreeNode *temp = st.top();
            TreeNode *t = new TreeNode(postorder[i]);
            if(mp[postorder[i]] > mp[temp->val]){
                temp->right = t;
            }else{
                while(mp[postorder[i]] < mp[temp->val]){
                    st.pop();
                    temp = st.top();
                }
                temp->left = t;
            }
            st.push(t);
        }
        return root;
    }
};