
class Solution {
public:
    vector<int> tree;

    // void build_tree(){
        // No need to build segment tree as all values are initially zeroes
    // }

    void update(int curr, int node, int low, int high){
        if(low == high){
            tree[node] += 1;
            return;
        }
        tree[node] += 1;
        int mid = (low + high) / 2;
        if(curr <= mid && curr >= low){
            update(curr, 2 * node + 1, low, mid);
        }else{
            update(curr, 2 * node + 2, mid + 1, high);
        }
    }

    int query(int node, int left, int right, int l, int r){
        if(r < left || l > right){
            return 0;
        }

        if(l <= left && right <= r) return tree[node]; // it means curr division is truly in our params
    
        int mid = (left + right) / 2;
        return query(2 * node + 1, left, mid, l, r) + query(2 * node + 2, mid + 1, right, l, r);
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        //prefix sum and calculate sum
        int n = nums.size();
        long long curr = n;
        // vector<long long> check(2 * n + 1, 0);
        int tree_size = 4 * (2 * n + 1);
        tree.resize(tree_size + 2, 0);
        // target -> +1, others -> -1
        //find all prefix sum encounters lesser than curr as there will be more target values there -> very obvious 
        long long ans = 0;
        // check[n] = 1;
        long long ps = 0;
        int low = 0;
        int high = 2 * n;
        update(curr, 0, low, high);
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                
                //sum is either increaseing by one or decreasing by one so store the previous lowest sum in ps
                // ps += check[curr];
                curr += 1;
            }else{
                curr -= 1;
                //but now curr is decreased we need to remove that added sum up there as curr is lowered why add same upper value
                // this is becasue we are storing all values sum which have ps < curr, if curr decreases we remove from prefix sum totol as now we want one more lowrer value
                // ps -= check[curr];
            }
            // check[curr]++;
            ps = query(0, low, high, 0, curr-1);
            update(curr, 0, low, high);
            ans += ps;
        }
        return ans;
    }
};
// n n-1, n, n+1 , n

// 0 -1, -2, -3 -2 -3


//we can use segment tree here but value is either decreasing by one or increasing by one this is the best method we can do to calcutlate total sum of ps on the go