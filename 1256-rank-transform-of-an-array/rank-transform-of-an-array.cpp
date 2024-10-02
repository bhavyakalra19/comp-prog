class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return arr;
        }
        vector<int> check;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            check.push_back(arr[i]);
        }
        sort(check.begin(), check.end());
        int idx = 1;
        mp[check[0]] = 1;
        for(int i = 1; i < n; i++){
            if(check[i] != check[i-1]){
                idx += 1;
            }
            mp[check[i]] = idx;
        }
        for(int i = 0; i < n; i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};