class Solution {
public:
    unordered_map<int,vector<int>> mp;

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int i = 0;
        int ans = 0;
        set<int, greater<int>> checkArr;
        while(i < n){
            int a = points[i][0];
            int b = points[i][1];
            mp[a].push_back(b);
            int mn = INT_MAX;
            if(i + 1 < n && points[i][0] == points[i+1][0]){
                mn = points[i+1][1];
                ans++;
            }
            for(auto curr : checkArr){
                if(mp.find(curr) != mp.end() && curr != a){
                    int j = 0;
                    int sz = mp[curr].size();
                    while(j < sz && mp[curr][j] < b){
                        j++;
                    }
                    if(j < sz){
                        if(mp[curr][j] < mn){
                            ans++;
                            mn = mp[curr][j];
                        }
                        mn = min(mn, mp[curr][j]);
                    }
                }
                curr--;
            }
            checkArr.insert(a);
            i++;
        }
        return ans;
    }
};