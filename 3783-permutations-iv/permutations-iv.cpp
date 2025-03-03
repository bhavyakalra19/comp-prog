class Solution {
public:
    vector<double> dp;

    double getFact(int n, vector<double> &dp){
        if(dp[n] != -1) return dp[n];
        return dp[n] = n * getFact(n-1, dp);
    }

    vector<int> permute(int n, double k) {
        dp.resize(201,-1);
        dp[0] = 1;
        dp[1] = 1;
        unordered_map<int,bool> mp;
        for(int i = 1; i <= n; i++) mp[i] = 1;
        int oc = n/2 + (n % 2 == 1 ? 1 : 0);
        int ec = n/2;
        int fd = -1;
        bool odd = (n % 2 == 1);
        double sum = 0;
        double prev = 0;
        for(int i = 1; i <= n; i++){
            if(fd == -1 && odd && (i % 2 == 0)) continue;
            if(i % 2 == 0){
                sum += (getFact(ec - 1, dp) * getFact(oc, dp));
            }else{
                sum += (getFact(ec, dp) * getFact(oc - 1, dp));
            }
            if(sum >= k){
                fd = i;
                break;
            }
            prev = sum;
        }
        vector<int> ans;
        if(fd == -1) return ans;
        mp[fd] = false;
        k -= prev;
        if(fd % 2 == 0){
            ec--;
        }else{
            oc--;
        }
        ans.push_back(fd);
        for(int j = 1; j < n; j++){
            sum = 0;
            prev = 0;
            if((j % 2 == 1 && fd % 2 == 1) || (j % 2 == 0 && fd % 2 == 0)){
                for(int i = 2; i <= n; i += 2){
                    if(mp[i] == true){
                        sum += (getFact(ec - 1, dp) * getFact(oc, dp));
                        if(sum >= k){
                            mp[i] = false;
                            ans.push_back(i);
                            ec--;
                            break;
                        }
                        prev = sum;
                    }
                }
            }else{
                for(int i = 1; i <= n; i += 2){
                    if(mp[i] == true){
                        sum += (getFact(ec, dp) * getFact(oc - 1, dp));
                        if(sum >= k){
                            mp[i] = false;
                            ans.push_back(i);
                            oc--;
                            break;
                        }
                        prev = sum;
                    }
                }
            }
            k -= prev;
        }
        return ans;
    }
};