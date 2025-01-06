class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> check(n+1,0);
        for(auto s : shifts){
            if(s[2] == 1){
                check[s[0]]++;
                check[s[1] + 1]--;
            }else{
                check[s[0]]--;
                check[s[1] + 1]++;
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum + check[i]) % 26;
            int a = ((s[i] - 'a' + sum) + 26) % 26;
            s[i] = a + 'a';
        }
        return s;
    }
};
