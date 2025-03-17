class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        int sz = n / 2;
        int oc = 0;
        unordered_map<int,int> mp;
        for(auto &a : nums){
            if(mp.find(a) == mp.end() || mp[a] % 2 == 0){
                oc++;
            }else{
                oc--;
            }
            mp[a]++;
        }
        return oc == 0;
    }
};