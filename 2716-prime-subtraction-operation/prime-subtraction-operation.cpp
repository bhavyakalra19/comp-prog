class Solution {
public:
    bool isPrime(int num){
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> check;
        for(int i = 2; i < 1000; i++){
            if(isPrime(i)){
                check.push_back(i);
            }
        }
        int m = check.size();
        int prev = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            int j = 0;
            int curr = 0;
            if(nums[i] < prev){
                prev = nums[i];
                continue;
            }
            while(j < m && check[j] < nums[i]){
                if((nums[i] - check[j]) < prev){
                    curr = 1;
                    break;
                }
                j++;
            }
            if(curr == 0){
                return false;
            }
            prev = nums[i] - check[j];
        }
        return true;
    }
};