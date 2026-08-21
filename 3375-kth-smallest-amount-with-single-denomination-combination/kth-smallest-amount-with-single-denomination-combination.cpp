class Solution {
public:
    long long getLcm(int a, int b){
        return (1LL * a * b) / gcd(a, b);
    }

    void checkAddsRemovals(vector<int> &check, vector<long long> &adds, vector<long long> &removals, long long lcm, int select, int curr){
        if(curr == check.size()){
            if(select > 0){
                if(select % 2 == 0){
                    removals.push_back(lcm);
                }else{
                    adds.push_back(lcm);
                }
            }
            return;
        }
        checkAddsRemovals(check, adds, removals, getLcm(check[curr], lcm), select + 1, curr + 1);
        checkAddsRemovals(check, adds, removals, lcm, select, curr + 1);
    }

    long long getAns(vector<long long> &check, vector<long long> &removals, int &k){
        long long st = 0;
        long long en = LONG_MAX;
        long long ans = 0;
        while(st <= en){
            long long mid = (en - st) / 2 + st;
            
            // cal total
            long long curr = 0;
            for(auto &a : check){
                curr += (mid / a);
            }
            for(auto &a : removals){
                curr -= (mid / a);
            }
            
            if(curr >= k){
                en = mid - 1;
                ans = mid;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        vector<int> check;
        sort(coins.begin(), coins.end());
        check.push_back(coins[0]);
        for(auto &a : coins){
            bool select = true;
            for(auto &b : check){
                if(a % b == 0){
                    select = false;
                    break;
                }
            }
            if(select) check.push_back(a);
        }
        int n = check.size();
        vector<long long> removals;
        vector<long long> adds;

        // we want to remove lcm of 2 numbers but have to add lcm of 3 numbers then add for 4 then remove 5
        // because lets say 2 3 5 -> if we remove multiples of lcm of 2 combined of them -> 6, 10, 15 now look at number 30 its being removed 3 times we have to add 30 one time or lcm of (2, 3, 5) so its balanced

        // create recursion loop where you select and not select element if size of selected % 2 == 0 then add lcm to removals, else adds
        checkAddsRemovals(check, adds, removals, 1, 0, 0);
        return getAns(adds, removals, k);
    }
};

// 6 15 16 20 22