class Node{
    public:
        int mx;
        Node *left;
        Node *right;

    Node(){
        mx = 0;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* createTree(vector<int> &baskets, int left, int right){
        if(left == right){
            Node *root = new Node();
            root->mx = baskets[left];
            return root;
        }
        int mid = (left + right)/2;
        Node *root = new Node();
        root->left = createTree(baskets, left, mid);
        root->right = createTree(baskets, mid + 1, right);
        root->mx = max(root->left->mx, root->right->mx);
        return root;
    }
    
    int getAns(Node *&root, int curr){
        if(root->left == root->right){
            int val = root->mx;
            root->mx = 0;
            return val;
        }
        int a;
        if(root->left->mx >= curr){
            a = getAns(root->left, curr);
        }else{
            a = getAns(root->right, curr);
        }
        root->mx = max(root->left->mx, root->right->mx);
        return a;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        Node *root = createTree(baskets, 0, n-1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(fruits[i] > root->mx){
                ans++;
            }else{
                getAns(root, fruits[i]);
            }
        }
        return ans;
    }
};


