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
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        ans += to_string(root->val) + " ";
        while(!q.empty()){
            root = q.front();
            q.pop();
            if(root->left){
                q.push(root->left);
                ans += to_string(root->left->val) + " ";
            }else{
                ans += "# ";
            }
            if(root->right){
                q.push(root->right);
                ans += to_string(root->right->val) + " ";
            }else{
                ans += "# ";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q;
        int n = data.size();
        if(n <= 1) return NULL;
        int i = 0;
        int sum = 0;
        int mul = 1;
        if(data[i] == '-'){
            mul = -1;
            i++;
        }
        while(i < n && data[i] != ' '){
            sum *= 10;
            sum += data[i] - '0';
            i++;
        }
        TreeNode *temp = new TreeNode(mul * sum);
        i++;
        TreeNode *head = temp;
        q.push(temp);
        while(i < n && !q.empty()){
            temp = q.front();
            q.pop();
            if(data[i] == '#'){
                i += 2;
            }else{
                int sum = 0;
                int mul = 1;
                if(data[i] == '-'){
                    mul = -1;
                    i++;
                }
                while(i < n && data[i] != ' '){
                    sum *= 10;
                    sum += data[i] - '0';
                    i++;
                }
                TreeNode *t = new TreeNode(mul * sum);
                temp->left = t;
                q.push(t);
                i++;
            }

            if(data[i] == '#'){
                i += 2;
            }else{
                int sum = 0;
                int mul = 1;
                if(data[i] == '-'){
                    mul = -1;
                    i++;
                }
                while(i < n && data[i] != ' '){
                    sum *= 10;
                    sum += data[i] - '0';
                    i++;
                }
                TreeNode *t = new TreeNode(mul * sum);
                temp->right = t;
                q.push(t);
                i++;
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));