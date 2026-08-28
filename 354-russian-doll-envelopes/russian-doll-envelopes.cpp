class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        int curr = 0;
        int n = envelopes.size();
        for(int i = 1; i < n; i++){
            if(envelopes[i][1] > ans[curr]){
                ans.push_back(envelopes[i][1]);
                curr++;
            }else{
                int best = -1;
                int st = 0;
                int en = curr;
                while(st <= en){
                    int mid = (st + en) / 2;
                    if(ans[mid] >= envelopes[i][1]){
                        best = mid;
                        en = mid - 1;
                    }else{
                        st = mid + 1;
                    }
                }
                if(best != -1) ans[best] = envelopes[i][1];
            }
        }
        return curr + 1;
    }
};


// solve by LIS method of binary search