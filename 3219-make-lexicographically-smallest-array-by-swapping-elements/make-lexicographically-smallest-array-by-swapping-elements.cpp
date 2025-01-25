class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> gp;
        for(int i = 0; i < n; i++){
            gp.push_back({nums[i],i});
        }
        sort(gp.begin(), gp.end());
        vector<vector<pair<int,int>>> level;
        level.push_back({gp[0]});
        for(int i = 1; i < n; i++){
            if(gp[i].first - level.back().back().first <= limit){
                level.back().push_back(gp[i]);
            }else{
                level.push_back({gp[i]});
            }
        }

        for(auto l : level){
            vector<int> ind;
            for(auto p : l){
                ind.push_back(p.second);
            }
            sort(ind.begin(), ind.end());
            for(int i = 0; i < ind.size(); i++){
                nums[ind[i]] = l[i].first;
            }
        }
        return nums;
    }
};