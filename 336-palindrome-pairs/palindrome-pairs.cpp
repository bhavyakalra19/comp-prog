class Solution {
public:
    unordered_map<string, bool> check;
    bool isPalindrome(string s){
        if(check.find(s) != check.end())
            return check[s];
        
        if(s.length() == 0){
            check[s] = true;
            return true;
        }
        int n = s.length();
        for(int i = 0; i <= n/2; i++)
        {
            if(s[i] != s[(n - i) - 1])
            {
                check[s] = false;
                return false;
            }
        }
        check[s] = true;
        return true;    
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string,int> mp;
        vector<int> em;
        int n = words.size();
        for(int i = 0; i < n; i++){
            string str = words[i];
            reverse(str.begin(),str.end());
            mp[str] = i;
        }

        for(int i = 0; i < n; i++){
            if(words[i] == ""){
                continue;
            }
            if(isPalindrome(words[i]) && mp.find("") != mp.end()){
                ans.push_back({i, mp[""]});
            }
        }
        for(int i = 0; i < n; i++){
            string left = "";
            string right = words[i];
            for(int j = 0; j < words[i].size(); j++){
                left.push_back(words[i][j]);
                right.erase(right.begin() + 0);
                if(mp.find(right) != mp.end() && isPalindrome(left) && mp[right] != i){
                    ans.push_back({mp[right], i});
                }
                if(mp.find(left) != mp.end() && isPalindrome(right) && mp[left] != i){
                    ans.push_back({i,mp[left]});
                }
            }
        }
        return ans;
    }
};