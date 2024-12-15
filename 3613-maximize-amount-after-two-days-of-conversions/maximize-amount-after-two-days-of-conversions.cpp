class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string,int> mp;
        int n = 1;
        mp[initialCurrency] = 0;
        for(auto p : pairs1){
            if(mp.find(p[0]) == mp.end()){
                mp[p[0]] = n;
                n++;
            }
            if(mp.find(p[1]) == mp.end()){
                mp[p[1]] = n;
                n++;
            }
        }
        for(auto p : pairs2){
            if(mp.find(p[0]) == mp.end()){
                mp[p[0]] = n;
                n++;
            }
            if(mp.find(p[1]) == mp.end()){
                mp[p[1]] = n;
                n++;
            }
        }
        vector<vector<pair<int,double>>> g1(n);
        for(int i = 0; i < pairs1.size(); i++){
            int s1 = mp[pairs1[i][0]];
            int s2 = mp[pairs1[i][1]];
            g1[s1].push_back({s2,rates1[i]});
            g1[s2].push_back({s1, (double) 1 / rates1[i]});
        }
        vector<vector<pair<int,double>>> g2(n);
        for(int i = 0; i < pairs2.size(); i++){
            int s1 = mp[pairs2[i][0]];
            int s2 = mp[pairs2[i][1]];
            g2[s1].push_back({s2,rates2[i]});
            g2[s2].push_back({s1, (double) 1 / rates2[i]});
        }

        for(int i = 0; i < n; i++){
            cout << i << "-> ";
            for(auto g : g1[i]){
                cout << g.first << " " << g.second << "; ";
            }
            cout << endl;
        }  

        vector<double> dist1(n,-1);
        // dist1[0] = INT_MAX;
        queue<pair<int,double>> q;
        q.push({0,1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int u = it.first;
            double w = it.second;
            // cout << u << "-> ";
            for(auto a : g1[u]){
                // cout << a.first << " " << a.second << "; ";
                if(a.second * w > dist1[a.first]){
                    dist1[a.first] = w * a.second;
                    q.push({a.first,dist1[a.first]});
                }
            }
            // cout << endl;
        }
        // for(int i = 0; i < n; i++){
        //     cout << dist1[i] << " ";
        // }
        double ans = 1;
        for(int i = 1; i < n; i++){
            vector<double> dist2(n,-1);
            dist2[i] = 1;
            q.push({i,1});
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int u = it.first;
                double w = it.second;
                for(auto a : g2[u]){
                    if(a.second * w > dist2[a.first]){
                        dist2[a.first] = w * a.second;
                        q.push({a.first,dist2[a.first]});
                    }
                }
            }
            if(dist2[0] != -1 && dist1[i] != -1){
                ans = max(ans, dist1[i] * dist2[0]);
            }
        }
        return ans;
    }
};