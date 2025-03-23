class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,int> left;
        unordered_map<int,int> right;
        unordered_map<int,int> first;
        vector<int> dist(n, INT_MAX);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(left.find(nums[i]) != left.end()){
                dist[i] = min(i - left[nums[i]], n - i + first[nums[i]]);
            }else{
                first[nums[i]] = i;
            }
            left[nums[i]] = i;
        }
        for(int i = n - 1; i >= 0; i--){
            if(right.find(nums[i]) != right.end()){
                dist[i] = min(dist[i], min(right[nums[i]] - i, n - left[nums[i]] + i));
            }
            right[nums[i]] = i;
        }
        for(auto q : queries){
            ans.push_back(dist[q] == INT_MAX ? -1 : dist[q]);
        }
        return ans;
    }
};