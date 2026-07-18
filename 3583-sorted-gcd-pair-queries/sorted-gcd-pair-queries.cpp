class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> count(mx+1, 0);
        vector<int> check(mx+1, 0);
        for(auto &a : nums){
            check[a]++;
        }
        int n;
        int ans;
        for(int i = 1; i <= mx; i++){
            long long m = 0;
            for(int j = i; j <= mx; j += i){
                if(check[j] > 0){
                    m += check[j];
                }
            }
            count[i] = (m * (m-1)) / 2;
        }
        
        for(int i = mx; i >= 1; i--){
            for(int j = i + i; j <= mx; j += i){
                count[i] -= count[j];
            }
        }
        
        vector<long long> ps(mx+1, 0);
        for(int i = 1; i <= mx; i++){
            ps[i] += ps[i-1] + count[i];
        }
        vector<int> result(queries.size());
        for(int i = 0; i < queries.size(); i++){
            long long q = queries[i] + 1;
            int st = 1;
            int en = mx;
            int ans = 1;

            while(st <= en){
                int mid = (st + en) / 2;
                if(ps[mid] >= q){
                    en = mid - 1;
                    ans = mid;
                }else{
                    st = mid + 1;
                }
            }
            result[i] = ans;
        }
        return result;
    }
};