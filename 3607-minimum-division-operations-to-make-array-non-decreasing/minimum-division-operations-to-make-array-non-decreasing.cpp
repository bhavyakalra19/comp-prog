class Solution {
public:
    bool checkPrime(int num){
        for(int i = 2; i * i <= num; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }

    vector<int> getPrimeNumbers(int num){
        vector<int> ans;
        for(int i = 2; i <= num; i++){
            if(checkPrime(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> check = getPrimeNumbers(1000);
        int curr = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] > nums[i+1]){
                ans++;
                for(int p = 0; check[p]*check[p] <= nums[i]; p++){
                    if(nums[i] % check[p] == 0){
                        nums[i] = check[p];
                        break;
                    }
                }
                if(nums[i] > nums[i+1]){
                    return -1;
                }
            }
        }
        return ans;
    }
};