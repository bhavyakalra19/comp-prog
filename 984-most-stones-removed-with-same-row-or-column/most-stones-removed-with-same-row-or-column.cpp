class Solution {
public:
    vector<int> parent;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(20001);

        for(int i = 0; i < 20001; i++){
            parent[i] = i;
        }

        for(auto s : stones){
            Union(s[0],s[1] + 10001);
        }

        set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(find(stones[i][0]));
        }
        return n - st.size();
    }

    void Union(int x, int y){
        int p1 = find(x);
        int p2 = find(y);
        parent[p1] = p2;
    }

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
};