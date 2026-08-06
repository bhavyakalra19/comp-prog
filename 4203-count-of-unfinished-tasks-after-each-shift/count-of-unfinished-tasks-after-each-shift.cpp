class Solution {
public:
    vector<int> countTasks(vector<int>& ps, vector<int>& shifts) {
        int n = ps.size();
        vector<long long> tasks(n, 0);
        tasks[0] = ps[0];
        for(int i = 1; i < n; i++){
            tasks[i] += tasks[i-1] + ps[i];
        }
        // 1 5 9
        int curr_idx = 0;
        long long curr = tasks[0];
        vector<int> result;

        for(auto &a : shifts){
            if(a <= curr){
                curr -= a;
            }else{
                int st = curr_idx + 1;
                int en = n - 1;
                int prev_val = curr_idx;
                int ans = n;
                long long check_val = -1;
                while(st <= en){
                    int mid = (st + en) / 2;
                    long long mid_val = tasks[mid] - tasks[curr_idx] + curr;
                    if(mid_val > a){
                        ans = mid;
                        en = mid - 1;
                        check_val = mid_val;
                    }else{
                        st = mid + 1;
                    }
                }
                if(ans == n){
                    curr = 0;
                    curr_idx = n-1;
                }else{
                    curr_idx = ans;
                    curr = check_val - a;
                }
            }
            
            if(curr == 0){
                result.push_back(n - curr_idx - 1);
                curr_idx++;
                curr_idx %= n;
                if(curr_idx == 0){
                    curr = tasks[0];
                    curr_idx = 0;
                }else{
                    curr = tasks[curr_idx] - tasks[curr_idx - 1]; 
                }
            }else{
                result.push_back(n - curr_idx);
            }
        }
        // for(auto &a : result) cout << a << " ";
        return result;
    }
};
