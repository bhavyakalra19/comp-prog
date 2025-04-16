/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val);
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->left){
                ans += " " + to_string(root->left->val);
                q.push(root->left);
            }else{
                ans += " #";
            }
            if(root->right){
                ans += " " + to_string(root->right->val);
                q.push(root->right);
            }else{
                ans += " #";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        int i = 0;
        int n = data.size();
        int sum = 0;
        int sign = 1;
        if(data[i] == '-'){
            sign = -1;
            i++;
        }
        while(i < n && data[i] != ' '){
            sum *= 10;
            sum += (data[i] - '0');
            i++;
        }
        i++;
        TreeNode *root = new TreeNode(sum * sign);
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *temp;
        while(i < n){
            temp = q.front();
            q.pop();
            if(data[i] == '#'){
                i += 2;
            }else{
                int sum = 0;
                int sign = 1;
                if(data[i] == '-'){
                    sign = -1;
                    i++;
                }
                while(i < n && data[i] != ' '){
                    sum *= 10;
                    sum += (data[i] - '0');
                    i++;
                }
                i++;
                temp->left = new TreeNode(sum * sign);
                q.push(temp->left);
            }

            if(data[i] == '#'){
                i += 2;
            }else{
                int sum = 0;
                int sign = 1;
                if(data[i] == '-'){
                    sign = -1;
                    i++;
                }
                while(i < n && data[i] != ' '){
                    sum *= 10;
                    sum += (data[i] - '0');
                    i++;
                }
                i++;
                temp->right = new TreeNode(sum * sign);
                q.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));