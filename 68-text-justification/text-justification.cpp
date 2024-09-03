class Solution {
public:
    string getAns(vector<string> words, int i, int j, int space, int n){
        string ans = "";
        if(i == n - 1){
            for(;j <= i; j++){
                ans += words[j];
                if(space > 0){
                    ans += " ";
                    space -= 1;
                }
            }
            while(space > 0){
                ans += " ";
                space--;
            }
        }else{
            int w = i - j;
            string cs = "";
            if(w > 0){
                int es = space % w;
                for(int a = 0; a < space / w; a++){
                    cs += " ";
                }
                for(;j < i; j++){
                    ans += words[j] + cs;
                    if(es > 0){
                        ans += " ";
                        es -= 1;
                    }
                }
                ans += words[i];
            }else{
                for(int a = 0; a < space; a++){
                    cs += " ";
                }
                ans += words[i] + cs;
            }
        }
        return ans;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int cw;
        for(int i = 0; i < n;){
            cw = 0;
            int j = i;
            while(i < n && cw + words[i].size() <= maxWidth){
                cw += words[i].size();
                cw += 1;
                i++;
            }
            ans.push_back(getAns(words,i-1,j,maxWidth - cw + i - j,n));
        }
        return ans;
    }
};