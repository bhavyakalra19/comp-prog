class Solution {
public:
    vector<int> check;

    int find(int a){
        if(a == check[a]) return a;
        return check[a] = find(check[a]);
    }

    void unionFun(int a, int b){
        int f1 = find(a);
        int f2 = find(b);
        if(f1 != f2){
            check[f1] = f2;
        }   
    }

    int interArray(unordered_map<int,bool> &check, vector<int> &num2){
        unordered_set<int> st;
        for(auto &b : num2){
            if(check.find(b) != check.end()) st.insert(b);
        }
        return st.size();
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        for(int i = 0; i < n; i++){
            check.push_back(i);
        }
        for(int i = 0; i < n-1; i++){
            unordered_map<int, bool> check;
            for(auto &a : properties[i]){
                check[a] = true;
            }
            for(int j = i + 1; j < n; j++){
                int a = interArray(check, properties[j]);
                if(a >= k){
                    unionFun(i, j);
                }
            }
        }
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(find(i));
        }
        return st.size();
    }
};