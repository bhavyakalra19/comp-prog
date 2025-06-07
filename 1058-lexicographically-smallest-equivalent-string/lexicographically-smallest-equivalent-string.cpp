class Solution {
public:
    vector<int> check;

    Solution(){
        check.resize(26);
        for(int i = 0; i < 26; i++){
            check[i] = i;
        }
    }

    int find(int a){
        if(check[a] == a){
            return a;
        }
        return check[a] = find(check[a]);
    }

    void unionFun(int a, int b){
        int p1 = find(a);
        int p2 = find(b);
        if(p1 < p2){
            check[p2] = p1;
        }else{
            check[p1] = p2;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        for(int i = 0; i < n; i++){
            unionFun(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for(auto s : baseStr){
            int a = find(s - 'a');
            char b = a + 'a';
            ans += b;
        }
        return ans;
    }
};
