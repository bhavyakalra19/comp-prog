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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        stack<TreeNode*> st;
        int n = preorder.size();
        if(n == 0) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *head = root;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        st.push(root);
        for(int i = 1; i < n; i++){
            if(mp[preorder[i]] > mp[root->val]){
                while(!st.empty() && mp[preorder[i]] > mp[st.top()->val]){
                    root = st.top();
                    st.pop();
                }
                root->right = new TreeNode(preorder[i]);
                root = root->right;
            }else{
                root->left = new TreeNode(preorder[i]);
                root = root->left;
            }
            st.push(root);
        }
        return head;
    }
};