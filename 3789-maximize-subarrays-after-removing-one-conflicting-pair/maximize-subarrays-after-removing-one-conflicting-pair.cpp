class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> pre(n + 1);
        vector<int> post(n + 2, 0);
        vector<long long> count(n + 1, 0);
        post[n+1] = 1e9;
        int j = 0;
        for(auto &a : conflictingPairs){
            if(a[0] > a[1]){
                swap(a[0], a[1]);
            }
            pre[a[0]].push_back(a[1]);
            post[a[1]]++;
        } 
        int top1 = 0;
        int top2 = 0;
        long long ans = 0;
        bool op = true;
        long long mx = 0;
        for(int i = 1; i <= n; i++){
            if(op){
                int j = i+1;
                int cnt = 0;
                while(j <= n + 1 && cnt < 2){
                    if(post[j] > 0){
                        if(cnt == 0){
                            top1 = j;
                            top2 = j;
                        }else{
                            top2 = j;
                        }
                        cnt += post[j];
                    }
                    j++;
                }
                op = false;
            }
            ans += top1 - i;
            if(top1 != n+1){
                count[top1] += top2 - top1;
                mx = max(mx, count[top1]);
            }
            //increase curr
            for(auto &a : pre[i]){
                post[a]--;
                if(((a == top1 || a == top2) && post[a] == 0) || (top2 == a && post[a] == 1)){
                    op = true;
                }
            }
        }
        return ans + mx;
    }
};
