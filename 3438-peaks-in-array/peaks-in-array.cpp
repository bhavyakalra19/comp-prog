class Solution {
public:
    int n;
    vector<int> tree;

    int createTree(int curr, int st, int en, vector<int> &nums){
        if(st == en){
            if(st != 0 && st != n-1 && nums[st] > nums[st-1] && nums[st] > nums[st+1]){
                return tree[curr] = 1;
            }
            return tree[curr] = 0;
        }

        int mid = (st + en) / 2;
        int a = createTree(curr * 2 + 1, st, mid, nums);
        int b = createTree(curr * 2 + 2, mid + 1, en, nums);
        return tree[curr] = a + b;
    }

    int updateTree(int curr, int st, int en, vector<int> &nums, int idx){
        if(st == en){
            if(st != 0 && st != n-1 && nums[st] > nums[st-1] && nums[st] > nums[st+1]){
                return tree[curr] = 1;
            }
            return tree[curr] = 0;
        }
        int mid = (st + en) / 2;
        int a = tree[curr * 2 + 1];
        int b = tree[curr * 2 + 2];
        if(idx >= st && idx <= mid){
            a = updateTree(curr * 2 + 1, st, mid, nums, idx);
        }
        if(idx >= mid + 1){
            b = updateTree(curr * 2 + 2, mid + 1, en, nums, idx);
        }
        return tree[curr] = a + b;
    }
    
    int getAns(int curr, int st, int en, int left, int right){
        if(left > en || right < st){
            return 0;
        }
        if(left <= st && right >= en){
            return tree[curr];
        }
        int mid = (st + en) / 2;
        int a = getAns(curr * 2 + 1, st, mid, left, right);
        int b = getAns(curr * 2 + 2, mid + 1, en, left, right);
        return a + b;
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        tree.resize(4 * n);
        createTree(0, 0, n-1, nums);
        vector<int> ans;
        for(auto &a : queries){
            if(a[0] == 1){
                ans.push_back(getAns(0, 0, n-1, a[1] + 1, a[2] - 1));
            }else{
                int idx = a[1];
                if(nums[idx] != a[2]){
                    nums[idx] = a[2];
                    updateTree(0, 0, n-1, nums, idx);
                    if(idx - 1 > 0) updateTree(0, 0, n-1, nums, idx-1);
                    if(idx + 1 < n-1) updateTree(0, 0, n-1, nums, idx+1);
                }
            }
        }
        return ans;
    }
};

// 3 1 4 4 5

// 4 1 4 2 1 5