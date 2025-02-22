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
    TreeNode* recoverFromPreorder(string s) {
        int n = s.size();
        stack<TreeNode*> st;
        int prev = 0;
        int a = 0;
        int i = 0;
        while(i < n && s[i] != '-'){
            a *= 10;
            a += (int)(s[i] - '0');
            i++;
        }
        TreeNode *root = new TreeNode(a);
        st.push(root);
        int cnt;
        while(!st.empty() && i < n){
            TreeNode *top = st.top();
            cnt = 0;
            while(s[i] == '-'){
                cnt++;
                i++;
            }
            a = 0;
            while(i < n && s[i] != '-'){
                a *= 10;
                a += (int)(s[i] - '0');
                i++;
            }
            TreeNode *temp = new TreeNode(a);
            if(cnt > prev){
                top->left = temp;
            }else{
                int a = prev - cnt + 1;
                while(a > 0){
                    st.pop();
                    a -= 1;
                }
                TreeNode *top = st.top();
                top->right = temp;
            }
            st.push(temp);
            prev = cnt;
        }
        return root;
    }
};