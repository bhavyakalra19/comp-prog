class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //prefix sum and calculate sum
        int n = nums.size();
        int curr = n;
        vector<int> check(2 * n + 1, 0);
        // target -> +1, others -> -1
        //find all prefix sum encounters lesser than curr as there will be more target values there -> very obvious 
        int mn = n;
        long long ans = 0;
        check[n] = 1;
        long long ps = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                
                //sum is either increaseing by one or decreasing by one so store the previous lowest sum in ps
                ps += check[curr];

                curr += 1;
            }else{
                curr -= 1;
                //but now curr is decreased we need to remove that added sum up there as curr is lowered why add same upper value
                // this is becasue we are storing all values sum which have ps < curr, if curr decreases we remove from prefix sum totol as now we want one more lowrer value
                ps -= check[curr];
            }
 
            check[curr]++;
            ans +=ps;
        }
        return ans;
    }
};
// n n-1, n, n+1 , n

// 0 -1, -2, -3 -2 -3


//we can use segment tree here but value is either decreasing by one or increasing by one this is the best method we can do to calcutlate total sum of ps on the go