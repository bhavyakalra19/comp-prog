class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> check(1, -1);
        int sz = 1;
   
        double c = (double) a / (double) b;
        long long ans = 0;
        int total_even = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 != 0){
                check.push_back(i);
                sz++;
            }else{
                total_even++;
            }
            int j = sz - 1;
            double cnt;
            while(j > 0){
                cnt = sz - j;
                int st = check[j];
                int en = check[j-1] + 1;
                j--;

                // cout << st << " " << en << " " << total_even << " " << endl;

                double curr_one_count = i - st + 1 - cnt;
                if(curr_one_count / cnt > c){
                    continue;
                }else if(total_even / cnt <= c){
                    ans += st + 1;
                    break;
                }
                int max_permissible_ones = floor((double)(a * cnt) / b) - curr_one_count;
                int mid = max(en, st - max_permissible_ones);
                if(mid <= st){
                    ans += st - mid + 1;
                }
            }
        }
        return ans;
    }
};

// one_count <= floor(c * cnt)