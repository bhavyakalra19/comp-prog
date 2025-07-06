class FindSumPairs {
public:
    int n;
    unordered_map<int,int> mp;
    vector<int> arr1;
    vector<int> arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        sort(arr1.begin(), arr1.end());
        n = nums1.size();
        int m = nums2.size();
        for(int i = 0; i < m; i++){
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp[arr2[index]]--;
        arr2[index] += val;
        mp[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(arr1[i] >= tot) break;
            ans += mp[tot - arr1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */