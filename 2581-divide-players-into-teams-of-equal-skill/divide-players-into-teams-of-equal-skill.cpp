class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if(n == 2){
            return skill[0]*skill[1];
        }
        long long ans = 0;
        sort(skill.begin(), skill.end());
        int check = skill[0] + skill[n-1];
        for(int i = 0; i < n/2; i++){
            if(skill[i] + skill[n-i-1] != check){
                return -1;
            }
            ans += skill[i] * skill[n-i-1];
        }
        return ans;
    }
};