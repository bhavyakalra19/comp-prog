class Solution {
public:

    long long countProdPos(vector<int> &nums1, vector<int> &nums2, long long mx){
        long long ans = 0;
        for(int i = 0; i < nums1.size(); i++){
            int num = nums1[i];
            int low = 0;
            int hg = nums2.size() - 1;
            int curr = 0;
            while(low <= hg){
                int mid = (low + hg)/2;
                if(1LL * nums2[mid] * num <= mx){
                    low = mid + 1;
                    curr = mid + 1;
                }else{
                    hg = mid - 1;
                }
            }
            ans += curr;
        }
        return ans;
    }

    long long countProdNeg(vector<int> &nums1, vector<int> &nums2, long long mx){
        long long ans = 0;
        for(int i = 0; i < nums1.size(); i++){
            int num = nums1[i];
            int low = 0;
            int hg = nums2.size() - 1;
            int curr = 0;
            while(low <= hg){
                int mid = (low + hg)/2;
                if(1LL * nums2[mid] * num <= mx){
                    hg = mid - 1;
                    curr = nums2.size() - mid;
                }else{
                    low = mid + 1;
                }
            }
            ans += curr;
        }
        return ans;
    }

    long long getAnsNeg(vector<int> &on, vector<int> &op, vector<int> &tn, vector<int> &tp, long long k){
        int n1 = on.size();
        int n2 = op.size();
        int m1 = tn.size();
        int m2 = tp.size();
        long long low = min(((n1 > 0) && (m2 > 0)) ? 1LL * on[0] * tp[m2-1] : LONG_MAX, ((n2 > 0) && (m1 > 0)) ? 1LL * op[n2-1] * tn[0] : LONG_MAX);
        long long high = max(((n1 > 0) && (m2 > 0)) ? 1LL *  on[n1-1] * tp[0] : LONG_MIN, ((n2 > 0) && (m1 > 0)) ? 1LL * op[0] * tn[m1-1] : LONG_MIN);
        reverse(op.begin(), op.end());
        reverse(tp.begin(), tp.end());
        long long ans;
        while(low <= high){
            long long mid = low + ((high - low) / 2);
            if(countProdPos(on, tp, mid) + countProdPos(tn, op, mid) < k){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }

    long long getAnsPos(vector<int> &on, vector<int> &op, vector<int> &tn, vector<int> &tp, long long k){
        int n1 = on.size();
        int n2 = op.size();
        int m1 = tn.size();
        int m2 = tp.size();
        reverse(on.begin(), on.end());
        reverse(tn.begin(), tn.end());
        long long low = min(((n1 > 0) && (m1 > 0)) ? 1LL * on[0] * tn[0] : LONG_MAX, ((n2 > 0) && (m2 > 0)) ? 1LL *  op[0] * tp[0] : LONG_MAX);
        long long high = max(((n1 > 0) && (m1 > 0)) ? 1LL * on[n1 - 1] * tn[m1 - 1] : LONG_MIN, ((n2 > 0) && (m2 > 0)) ? 1LL * op[n2-1] * tp[m2-1] : LONG_MIN);
        long long ans;
        while(low <= high){
            long long mid = low + ((high - low) / 2);
            if(countProdPos(on, tn, mid) + countProdPos(op, tp, mid) < k){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> nums_on;
        vector<int> nums_op;
        vector<int> nums_tn;
        vector<int> nums_tp;
        for(int i = 0; i < nums1.size(); i++){
            if(nums1[i] < 0){
                nums_on.push_back(nums1[i]);
            }else{
                nums_op.push_back(nums1[i]);
            }
        }
        for(int i = 0; i < nums2.size(); i++){
            if(nums2[i] < 0){
                nums_tn.push_back(nums2[i]);
            }else{
                nums_tp.push_back(nums2[i]);
            }
        }
        long long a = ((nums_on.size() * nums_tp.size()) + (nums_op.size() * nums_tn.size()));
        if(k <= a){
            return getAnsNeg(nums_on, nums_op, nums_tn, nums_tp, k);
        }
        return getAnsPos(nums_on, nums_op, nums_tn, nums_tp, k - a);
    }
};
