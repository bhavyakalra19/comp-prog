class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //no radix sort as numbers range are way larger 
        int n = arr.size();
        if(n == 0) return {};
        vector<pair<int,int>> check;
        for(int i = 0; i < n; i++){
            check.push_back({arr[i], i});
        }
        sort(check.begin(), check.end());
        int curr = check[0].first;
        int rank = 1;
        vector<int> ans(n);
        ans[check[0].second] = 1;
        for(int i = 1; i < n; i++){
            if(check[i].first != curr){
                rank++;
                curr = check[i].first;
            }
            ans[check[i].second] = rank;
        }
        return ans;
    }
};