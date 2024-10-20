class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> sym;
        stack<int> check;
        for(auto s : expression){
            if(s == '!' || s == '|' || s == '&'){
                sym.push(s);
            }else if(s == '(' || s == 'f' || s == 't'){
                if(s == '('){
                    check.push(-1);
                }else if(s == 'f'){
                    check.push(0);
                }else{
                    check.push(1);
                }
            }else if(s == ')'){
                auto it = sym.top();
                sym.pop();
                if(it == '&'){
                    auto curr = check.top();
                    check.pop();
                    while(check.top() != -1){
                        curr = curr & check.top();
                        check.pop();
                    }
                    check.pop();
                    check.push(curr);
                }else if(it == '|'){
                    auto curr = check.top();
                    check.pop();
                    while(check.top() != -1){
                        curr = curr | check.top();
                        check.pop();
                    }
                    check.pop();
                    check.push(curr);
                }else{
                    auto curr = check.top();
                    check.pop();
                    check.pop();
                    check.push(!curr);
                }
            }
        }
        return check.top();
    }
};