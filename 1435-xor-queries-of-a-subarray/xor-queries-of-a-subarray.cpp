class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> left;
        vector<int> right;
        int t = 0;
        int rt = 0;
        for(int i = 0; i < n; i++){
            left.push_back(t);
            right.push_back(rt);
            t ^= arr[i];
            rt ^= arr[n - i - 1];
        }
        reverse(right.begin(),right.end());
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            ans.push_back(t ^ left[queries[i][0]] ^ right[queries[i][1]]);
        }
        return ans;
    }
};