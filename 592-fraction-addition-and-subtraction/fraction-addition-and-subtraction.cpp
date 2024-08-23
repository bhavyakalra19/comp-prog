class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        if(n <= 4){
            return expression;
        }
        unordered_set<int> dis;
        vector<int> num;
        vector<int> den;
        int b = -1;
        int min = false;
        for(int i = 0; i < n; i++){
            char a = expression[i];
            if(a == '+'){
                dis.insert(b);
                den.push_back(b);
            }else if(a == '-'){
                min = true;
                if(b == -1){
                    continue;
                }
                dis.insert(b);
                den.push_back(b);
            }else if(a == '/'){
                if(min == true){
                    num.push_back(-b);
                }else{
                    num.push_back(b);
                }
                min = false;
            }else{
                b = a - '0';
                if(b == 1 && i + 1 < n && expression[i+1] == '0'){
                    b = 10;
                    i++;
                }
            }
        }
        dis.insert(b);
        den.push_back(b);
        long long int prod_den = 1;
        long long int sum = 0;
        for(auto a : dis){
            prod_den *= a;
        }
        for(int i = 0; i < num.size(); i++){
            sum += (prod_den/den[i]) * num[i];
        }
        cout << sum << "/" << prod_den << endl;
        while(sum % 2 == 0 && prod_den % 2 == 0){
            sum /= 2;
            prod_den /= 2;
        }

        while(sum % 3 == 0 && prod_den % 3 == 0){
            sum /= 3;
            prod_den /= 3;
        }

        while(sum % 5 == 0 && prod_den % 5 == 0){
            sum /= 5;
            prod_den /= 5;
        }

        while(sum % 7 == 0 && prod_den % 7 == 0){
            sum /= 7;
            prod_den /= 7;
        }
        return to_string(sum) + '/' + to_string(prod_den);
    }
};