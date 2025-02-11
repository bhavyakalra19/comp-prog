class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        int mx = 0;
        for(auto a : groups){
            mx = max(mx, a);
        }
        vector<int> check(mx+1,-1);
        for(int i = 0; i < elements.size(); i++){
            int a = elements[i];
            int b = elements[i];
            int j = 2;
            if(a <= mx && check[a] != -1) continue;
            while(a <= mx){
                if(check[a] == -1) check[a] = i;
                a = b*j;
                j++;
            }
            if(a == 1) break;
        }
        for(int i = 0; i < n; i++){
            groups[i] = check[groups[i]];
        }
        return groups;
    }
};
