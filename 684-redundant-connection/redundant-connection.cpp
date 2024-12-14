class Solution {
public:
    int find(vector<int> &check, int num){
        if(check[num] == 0 || check[num] == num){
            return check[num];
        }
        return find(check,check[num]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> check;
        for(int i = 0; i <= n; i++){
            check.push_back(i);
        }
        for(int i = 0; i < n; i++){
            int a = find(check,edges[i][0]);
            int b = find(check,edges[i][1]);
            if(a == b){
                return edges[i];
            }else{
                check[a] = b;
            }
        }
        return edges[n-1];
    }   
};