class Solution {
public:
    vector<vector<int>> tree;

    // left, right, max_value

    int buildTree(vector<int> &fruits, int x, int y, int node){
        if(x == y){
            tree[node] = {fruits[x], fruits[x], fruits[x]};
            return fruits[x];
        }
        int mid = (x + y) / 2;

        int left = buildTree(fruits, x, mid, 2 * node + 1);
        int right = buildTree(fruits, mid + 1, y, 2 * node + 2);
        tree[node] = {left, right, max(left, right)};
        return tree[node][2];
    }

    int checkAndUpdate(int &check, int x, int y, int node){
        if(x == y){
            tree[node] = {0,0,0};
            return 0;
        }
        int mid = (x + y) / 2;

        int left = tree[node][0];
        int right = tree[node][1];
        if(check <= left){
            left = checkAndUpdate(check, x, mid, 2 * node + 1);
        }else{
            right = checkAndUpdate(check, mid + 1, y, 2 * node + 2);
        }
        tree[node] = {left, right, max(left, right)};
        return tree[node][2];
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        //segment tree
        int n = baskets.size();
        tree.resize(4 * n, vector<int>(3, 0));
        buildTree(baskets, 0, n-1, 0);
        int ans = 0;
        for(auto &a : fruits){
            if(tree[0][2] >= a){
                checkAndUpdate(a, 0, n-1, 0);
            }else{
                ans++;
            }
        }
        return ans;
    }
};
