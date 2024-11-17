class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> line(n+1,0);
        for(auto q : queries){
            line[q[0]] += 1;
            line[q[1] + 1] -= 1;
        }
        int s = 0;
        for(int i = 0; i < n; i++){
            s += line[i];
            nums[i] -= s;
            if(nums[i] > 0){
                return false;
            }
        }
        return true;
    }
};