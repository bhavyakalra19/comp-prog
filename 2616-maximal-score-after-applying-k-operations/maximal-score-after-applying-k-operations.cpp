class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        while(k > 0){
            auto it = pq.top();
            pq.pop();
            ans += it;
            if(it % 3 != 0){
                pq.push(it/3 + 1);
            }else{
                pq.push(it/3);
            }
            k--;
        }
        return ans;
    }
};