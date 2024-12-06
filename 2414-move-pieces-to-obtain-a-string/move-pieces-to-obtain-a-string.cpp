class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0;
        int j = 0;
        while(i < n && j < n){
            while(i < n && start[i] == '_'){
                i++;
            }
            while(j < n && target[j] == '_'){
                j++;
            }
            if(i < n && j < n){
                if(start[i] == target[j]){
                    if((start[i] == 'L' && j > i) || (start[i] == 'R' && j < i)){
                        return false;
                    }
                }else{
                    return false;
                }
            }else{
                break;
            }
            i++;
            j++;
        }
        while(i < n && start[i] == '_'){
            i++;
        }
        while(j < n && target[j] == '_'){
            j++;
        }
        return i == n && j == n;
    }
};