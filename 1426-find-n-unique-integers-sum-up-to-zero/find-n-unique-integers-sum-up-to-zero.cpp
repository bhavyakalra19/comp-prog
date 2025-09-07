class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        bool check = false;
        if(n%2 == 0) check = true;
        int cnt = n/2;
        for(int i = -1 * cnt; i <= cnt; i++){
            if(i == 0 && check) continue;
            ans.push_back(i);
        }
        return ans;
    }
};