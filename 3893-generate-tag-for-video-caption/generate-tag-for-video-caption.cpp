class Solution {
public:
    string generateTag(string caption) {
        int n = caption.size();
        string s = "#";
        int a = 'a';
        bool cap = false;
        int cnt = 0;
        int i = 0;
        while(i < n && caption[i] == ' '){
            i++;
        }
        for(; i < n; i++){
            if(caption[i] >= 'a' && caption[i] <= 'z'){
                if(cap){
                    s += caption[i] - 32;
                    cap = false;
                }else{
                    s += caption[i];
                } 
                cnt++;
            }else if(caption[i] >= 'A' && caption[i] <= 'Z'){
                if(cap){
                    s += caption[i];
                    cap = false;
                }else{
                    s += caption[i] + 32;
                }
                cnt++;
            }else if(caption[i] == ' '){
                cap = true;
            }
            if(cnt == 99) break;
        }
        return s;
    }
};