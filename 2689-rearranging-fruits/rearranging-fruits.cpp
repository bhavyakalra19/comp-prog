class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto &a : basket1){
            mp1[a]++;
        }
        for(auto &a : basket2){
            mp2[a]++;
        }
        vector<pair<int,int>> check;
        int cnt = 0;
        for(auto &m : mp1){
            if(m.second != 0){
                if((m.second + mp2[m.first]) % 2 != 0) return -1;
                int a = abs(m.second - mp2[m.first]) / 2;
                mp2[m.first] = 0;
                mp1[m.first] = 0;
                check.push_back({m.first, a});
                cnt += a;
            }
        }
        for(auto &m : mp2){
            if(m.second != 0){
                if((m.second + mp1[m.first]) % 2 != 0) return -1;
                int a = abs(m.second - mp1[m.first]) / 2;
                mp2[m.first] = 0;
                mp1[m.first] = 0;
                check.push_back({m.first, a});
                cnt += a;
            }
        }
        sort(check.begin(), check.end());
        cnt /= 2;
        int i = 0;
        long long ans = 0;
        int mn = 2 * check[0].first;
        while(cnt >= 0){
            if(check[i].second >= cnt){
                ans += min(mn, check[i].first) * 1LL * cnt;
                break;
            }else{
                ans += min(mn, check[i].first) * 1LL * check[i].second;
                cnt -= check[i].second;
            }
            i++;
        }
        return ans;
    }
};
