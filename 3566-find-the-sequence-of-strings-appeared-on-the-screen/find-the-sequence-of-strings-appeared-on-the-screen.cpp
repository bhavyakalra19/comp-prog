class Solution {
public:
    vector<string> stringSequence(string target) {
        string str = "a";
        vector<string> ans;
        for(int i = 0; i < target.size(); i++){
            while(str[i] != target[i]){
                ans.push_back(str);
                int curr = str[i] - 'a';
                cout << curr << endl;
                curr = (curr + 1)%26;
                str[i] = curr + 'a';
            }
            ans.push_back(str);
            str += 'a';
        }
        return ans;
    }
};