class Solution {
public:
    unordered_map<int,int> count;
    int mod = 1e9+1;


    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        vector<int> dx = {1,4,16,64,256, 1024,4096,16384,65536,262144,1048576,4194304,16777216,67108864,268435456, mod+1};
        for(auto &q : queries){
            unordered_map<int,long long> mp;
            int i = 0;
            int a = q[0];
            int b = q[1];
            int mn = INT_MAX;
            int mx = INT_MIN;
            int c;
            while(a >= dx[i+1]){
                i++;
            }
            mn = i+1;
            while(i < 17){
                if(b < dx[i+1]){
                    mp[i+1] = b+1 - max(dx[i], a);
                    break;
                }else{
                    mp[i+1] = dx[i+1] - max(dx[i], a);
                }
                i++;
            }
            mx = i+1;
            c = mx;
            while(c >= mn){
                if(mp[c] % 2 == 0){
                    if(c == mn){
                        ans += c * (mp[c] / 2);
                        break;
                    }else{
                        ans += c * ((mp[c] - 2) / 2);
                        mp[c-1] += 2;
                        ans += 1;
                    }
                }else{
                    if(c == mn){
                        if(mp[c] > 3){
                            ans += c * ((mp[c] - 3) / 2);
                        }
                        ans += c + (c+1)/2;
                        break;
                    }else{
                        if(mp[c] > 1){
                            ans += c * (mp[c] / 2);
                        }
                        if(c-2 >= mn){
                            ans += 1;
                            mp[c-2]++;
                        }else{
                            ans += c;
                            if(mp[c-1] % 2 == 0){
                                if(mp[c-1] > 2){
                                    ans += (c-1) * ((mp[c-1] - 2) / 2);
                                }
                                ans += (c-1) - c/2;
                            }else{
                                if(mp[c-1] > 1){
                                    ans += (c-1) * ((mp[c-1] - 1) / 2);
                                }
                            }
                            break;
                        }
                    }
                }
                mp[c] = 0;
                c--;
            }
        }
        return ans;
    }
};