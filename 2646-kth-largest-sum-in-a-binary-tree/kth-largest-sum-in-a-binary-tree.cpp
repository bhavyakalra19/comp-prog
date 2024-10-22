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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            long long count = 0;
            st.push(NULL);
            while(st.front() != NULL){
                TreeNode *tp = st.front();
                st.pop();
                count += (long long)tp->val;
                if(tp->left != NULL){
                    st.push(tp->left);
                }
                if(tp->right != NULL){
                    st.push(tp->right);
                }
            }
            st.pop();
            ans.push_back(count);
        }
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans.size() < k ? -1 : ans[k-1];
    }
};