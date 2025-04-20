class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[answers[i]]++;
        }
        int ans = 0;
        for(auto &m : mp){
            int k = m.first + 1;
            int v = m.second;
            ans += k * (v / k);
            if(v % k){
                ans += k;
            }
        }
        return ans;
    }
};
