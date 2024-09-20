class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> res;
        for(int i = 0; i < exp.size(); i++){
            char ch = exp[i];
            if(ch == '+' || ch == '-' || ch == '*'){
                vector<int> left = diffWaysToCompute(exp.substr(0,i));
                vector<int> right = diffWaysToCompute(exp.substr(i+1));
                for(auto l : left){
                    for(auto r : right){
                        if(ch == '+'){
                            res.push_back(l+r);
                        }else if(ch == '-'){
                            res.push_back(l-r);
                        }else{
                            res.push_back(l*r);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(stoi(exp));
        }
        return res;
    }
};