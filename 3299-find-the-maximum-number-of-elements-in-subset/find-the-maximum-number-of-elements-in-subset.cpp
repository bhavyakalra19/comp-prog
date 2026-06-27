class Solution {
public:
    //binary search
    int checkBinarySearch(vector<int> &nums, int st, int en, long long check){
        int ans = -1;
        while(st <= en){
            int mid = (st + en)/2;
            if(nums[mid] < check){
                st = mid + 1;
            }else if(nums[mid] == check){
                ans = mid;
                en = mid - 1;
            }else{
                en = mid - 1;
            }
        }
        return ans;
    }

    int maximumLength(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < n && nums[i] == 1){
            i++;
        }
        int mx = (i % 2 == 0 && i > 0) ? i - 1 : i;

        while(i < n){
            int check = nums[i];
            if(st.find(check) != st.end()){
                while(i < n && nums[i] == check){
                    i++;
                }
            }else{
                int j = i;
                int ans = 2;
                while(j + 1 < n && nums[j] == nums[j+1]){
                    st.insert(nums[j]);
                    int mid = checkBinarySearch(nums, j+2, n-1, 1LL * nums[j] * nums[j]);
                    if(mid == -1){
                        break;
                    }
                    ans += 2;
                    j = mid;
                }
                mx = max(mx, ans - 1);
                i++;
            }
        }
        return mx;
    }
};


// 2 2 4 4 16 