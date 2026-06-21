class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, costs[i]);
        }
        vector<int> check(mx + 1, 0);
        for(auto &c : costs){
            check[c]++;
        }
        int i = 1;
        int ans = 0;
        while(i <= mx && coins > 0){
            if(i > coins) break;
            if(check[i] == 0){
                i++;
                continue;
            }
            if((1LL * check[i] * i) <= coins){
                ans += check[i];
                coins -= check[i] * i;
            }else{
                //binary search
                int st = 1;
                int en = check[i];
                int curr = i;
                int val = 1;

                while(st <= en){
                    int mid = (st + en)/2;
                    if(1LL * curr * mid <= coins){
                        val = mid;
                        st = mid + 1;
                    }else{
                        en = mid - 1;
                    }
                }
                ans += val;
                break;
            }
            i++;
        }
        return ans;
    }
};