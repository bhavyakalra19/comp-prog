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
    // int check[100001];
    int curr[100001];
    int pos[100001];
    unordered_map<int,vector<int>> mp;
    int dfs(TreeNode* root, int level){
        if(!root){
            return 0;
        }
        curr[root->val] = level;
        int a = dfs(root->left,level+1);
        int b = dfs(root->right,level+1);
        int check = max(a,b);
        if(mp[level].size() < 2){
            mp[level].push_back(check);
            sort(mp[level].begin(),mp[level].end(),greater<int>());
        }else{
            if(check >= mp[level][0]){
                mp[level][1] = mp[level][0];
                mp[level][0] = check;
            }else if(check > mp[level][1]){
                mp[level][1] = check;
            }
        }
        pos[root->val] = check;
        return check + 1;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        dfs(root,0);
        for(auto m : mp){
            cout << m.first << "->" << m.second[0];
            if(m.second.size() > 1){
                cout << " " << m.second[1];
            }
            cout << endl;
        }
        for(auto q : queries){
            if(mp[curr[q]].size() == 1){
                ans.push_back(curr[q] - 1);
            }else{
                if(pos[q] == mp[curr[q]][0]){
                    ans.push_back(curr[q] + mp[curr[q]][1]);
                }else if(pos[q] == mp[curr[q]][1]){
                    ans.push_back(curr[q] + mp[curr[q]][0]);
                }else{
                    ans.push_back(curr[q] + max(mp[curr[q]][0], mp[curr[q]][1]));
                }
            }
        }
        return ans;
    }
};