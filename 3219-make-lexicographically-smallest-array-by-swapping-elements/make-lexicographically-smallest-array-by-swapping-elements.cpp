class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {  
        int n = nums.size();
        vector<int> ans(n);
        vector<pair<int,int>> check;
        for(int i = 0; i < n; i++){
            check.push_back({nums[i], i});
        }
        sort(check.begin(), check.end());
        int j = 0;
        while(j < n){
            int i = j;
            vector<int> index;
            index.push_back(check[j].second);
            j++;
            while(j < n && check[j].first - check[j-1].first <= limit){
                index.push_back(check[j].second);
                j++;
            }
            sort(index.begin(), index.end());
            for(auto &a : index){
                ans[a] = check[i].first;
                i++;
            }
        }
        return ans;
    }
};

// first sort the numbers and get their combination
// then after sorting get their actual index and sort them to their new relative sorted indices
// then go for next combinations


// 1 2 4

// store their actual indices and then sort the indices as well
// then store the smaller value to smaller indices