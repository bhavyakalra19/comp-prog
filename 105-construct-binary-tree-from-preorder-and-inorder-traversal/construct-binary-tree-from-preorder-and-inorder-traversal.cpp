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
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *head = root;
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        stack<TreeNode*> st;
        st.push(root);
        for(int i = 1; i < n; i++){
            TreeNode *temp = new TreeNode(preorder[i]);
            if(mp[root->val] > mp[preorder[i]]){
                root->left = temp;
            }else{
                while(!st.empty() && mp[st.top()->val] < mp[preorder[i]]){
                    root = st.top();
                    st.pop();
                }
                root->right = temp;
            }
            root = temp;
            st.push(temp);
        }
        return head;
    }
};