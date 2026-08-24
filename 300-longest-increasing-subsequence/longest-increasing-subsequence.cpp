class Solution {
public:
    vector<int> tree;

    int addNum(int curr, int st, int en, int idx, int val){
        if(st == en){
            return tree[curr] = max(tree[curr], val);
        }
        int mid = (st + en) / 2;
        int a = (idx <= mid) ? addNum(curr * 2 + 1, st, mid, idx, val) : tree[curr * 2 + 1];
        int b = (idx > mid) ? addNum(curr * 2 + 2, mid + 1, en, idx, val) : tree[curr * 2 + 2];
        return tree[curr] = max(a, b);
    }

    int getSum(int curr, int st, int en, int idx){
        if(idx >= en){
            return tree[curr];
        }
        if(st > idx) return 0;
        int mid = (st + en) / 2;
        int a = getSum(curr * 2 + 1, st, mid, idx);
        int b = getSum(curr * 2 + 2, mid + 1, en, idx);
        return max(a, b);
    }

    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int mn = 10000;
        int mx = -10000;
        for(auto &a : nums){
            mn = min(mn, a);
            mx = max(mx, a);
        }
        int total = mx - mn + 1;
        tree.resize(total * 4, 0);

        addNum(0, 0, total - 1, nums[0] - mn, 1);
        for(int i = 1; i < n; i++){
            int val = nums[i] - mn;
            int curr_mx = 0;
            if(val != 0) curr_mx = max(curr_mx, getSum(0, 0, total - 1, val - 1));
            ans = max(ans, curr_mx + 1);
            addNum(0, 0, total - 1, val, curr_mx + 1);
        }
        return ans;
    }
};

// we can create segment tree or fenwick tree for logn getting 