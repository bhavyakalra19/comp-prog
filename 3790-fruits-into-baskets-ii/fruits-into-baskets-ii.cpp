class Node{
    public:
        int st;
        int en;
        int leftMax;
        int rightMax;
        Node *left;
        Node *right;

    Node(int l, int r){
        st = l;
        en = r;
        leftMax = 0;
        rightMax = 0;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* createTree(vector<int> &baskets, int left, int right){
        if(left == right){
            Node *root = new Node(left, right);
            root->leftMax = baskets[left];
            root->rightMax = baskets[left];
            return root;
        }
        int mid = (left + right)/2;
        Node *root = new Node(left, right);
        root->left = createTree(baskets, left, mid);
        root->right = createTree(baskets, mid + 1, right);
        root->leftMax = max(root->left->leftMax, root->left->rightMax);
        root->rightMax = max(root->right->leftMax, root->right->rightMax);
        return root;
    }
    
    int getAns(Node *&root, int curr){
        if(root->left == root->right){
            int val = root->leftMax;
            root->leftMax = 0;
            root->rightMax = 0;
            return val;
        }
        int a;
        if(root->leftMax >= curr){
            a = getAns(root->left, curr);
            root->leftMax = max(root->left->leftMax, root->left->rightMax);
        }else{
            a = getAns(root->right, curr);
            root->rightMax = max(root->right->leftMax, root->right->rightMax);
        }
        return a;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        Node *root = createTree(baskets, 0, n-1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(fruits[i] > root->leftMax && fruits[i] > root->rightMax){
                ans++;
            }else{
                getAns(root, fruits[i]);
            }
        }
        return ans;
    }
};



