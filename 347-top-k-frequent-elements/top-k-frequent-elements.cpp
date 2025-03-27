class Solution {
public:
    int partition(vector<int> &nums, int st, int en, unordered_map<int,int> &mp){
        int pivot = en;
        int low = st - 1;
        int i = st;
        while(i < en){
            if(mp[nums[i]] >= mp[nums[pivot]]){
                swap(nums[++low],nums[i]);
            }
            i++;
        }
        swap(nums[++low], nums[pivot]);
        return low;
    }

    void quickSort(vector<int> &nums, int i, int j, unordered_map<int,int> &mp){
        if(i >= j) return;
        int pivotIndex = partition(nums, i, j, mp);
        quickSort(nums, i, pivotIndex - 1, mp);
        quickSort(nums, pivotIndex + 1, j, mp);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        vector<int> check;
        for(int i = 0; i < n; i++){
            mp[nums[i]] += 1;
            if(mp[nums[i]] == 1) ans.push_back(nums[i]);
        }
        quickSort(ans,0, ans.size() - 1, mp);
        for(int i = 0; i < k; i++){
            check.push_back(ans[i]);
        }
        return check;
    }
};