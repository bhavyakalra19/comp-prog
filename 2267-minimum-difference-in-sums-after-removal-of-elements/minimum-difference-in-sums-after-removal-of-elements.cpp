class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> min_arr(n, 0);
        vector<long long> max_arr(n, 0);
        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> mq;
        int a = n/3;
        int b = 2 * a;
        long long sum = 0;
        for(int i = 0; i < n/3; i++){
            sum += nums[i];
            pq.push(nums[i]);
        }
        min_arr[a - 1] = sum; 
        for(int i = n/3; i < b; i++){
            if(nums[i] < pq.top()){
                sum -= pq.top();
                pq.pop();
                sum += nums[i];
                pq.push(nums[i]);
            }
            min_arr[i] = sum;
        }
        sum = 0;
        for(int i = n-1; i >= b; i--){
            sum += nums[i];
            mq.push(nums[i]);
        }
        max_arr[b] = sum;
        for(int i = ((2 * n)/ 3) - 1; i >= n/3; i--){
            if(nums[i] > mq.top()){
                sum -= mq.top();
                mq.pop();
                sum += nums[i];
                mq.push(nums[i]);
            }
            max_arr[i] = sum;
        }
        long long mn = LONG_MAX;
        for(int i = a-1; i < b; i++){
            mn = min(mn, min_arr[i] - max_arr[i+1]);
        }
        return mn;
    }
};
