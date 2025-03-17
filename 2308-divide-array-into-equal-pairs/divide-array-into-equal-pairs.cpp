class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        int sz = n / 2;
        int oc = 0;
        vector<int> mp(501,0);
        for(auto &a : nums){
            if(mp[a] % 2 == 0){
                oc++;
            }else{
                oc--;
            }
            mp[a]++;
        }
        return oc == 0;
    }
};