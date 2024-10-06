class Graph{
    public:
        int V;
        vector<vector<int>> arr;

        Graph(int V){
            this->V = V;
            arr.resize(V);
        }

        void addNode(int a, int b){
            arr[a].push_back(b);
        }

        void getSuspecious(int k, vector<bool> &check){
            check[k] = true;
            for(auto a : arr[k]){
                if(!check[a]){
                    getSuspecious(a,check);
                }
            }
        }

        bool getAns(int k, vector<bool> &check){
            for(auto a : arr[k]){
                if(check[a]){
                    return true;
                }
            }
            return false;
        }
};

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> check(n,false);
        vector<int> ans;
        vector<int> other;
        for(int i = 0; i < n; i++){
            other.push_back(i);
        }

        Graph g(n);
        for(auto p : invocations){
            g.addNode(p[0],p[1]);
        }
        g.getSuspecious(k,check);
        for(int i = 0; i < n; i++){
            if(!check[i]){
                if(g.getAns(i,check)){
                    return other;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};