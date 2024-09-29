class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n=word.size(),ans=0;
        unordered_map<char,int>mp={{'a',1},{'e',2},{'i',4},{'o',8},{'u',16}};
        int lim=31;
        for(int i=0;i<n;++i) 
        {
            int v=0,c=0;
            for(int j=i;j<n;++j) 
            {
                char ch=word[j];
                if(mp.find(ch)!=mp.end())
                    v|=mp[ch];
                else
                    ++c;
                if(c>k)
                    break;
                if(v==lim && c==k)
                    ++ans;
            }
        }
        return ans;
    }
};