class Solution {
public:

    bool solve1(double num){
        if(abs(num-24)<=1e-6)return true;
        else return false;
    }

    bool solve2(vector<double> two){
        bool ans=false;
        for(int i=0;i<1;i++){
            for(int j=0;j<4;j++){
                double z=0;

                if(j==0){z=two[i]+two[i+1];}
                if(j==1){z=two[i]-two[i+1];}
                if(j==2){z=two[i]*two[i+1];}
                if(j==3){if(two[i+1]==0)continue; z=two[i]/two[i+1];}

                if(i==0)ans=ans||solve1(z);
            }
        }
        return ans;
    }

    bool solve3(vector<double> three){
        bool ans=false;
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                double z=0;

                if(j==0){z=three[i]+three[i+1];}
                if(j==1){z=three[i]-three[i+1];}
                if(j==2){z=three[i]*three[i+1];}
                if(j==3){if(three[i+1]==0)continue; z=three[i]/three[i+1];}

                if(i==0)ans=ans||solve2({z,three[2]});
                if(i==1)ans=ans||solve2({three[0],z});
            }
        }
        return ans;
    }

    bool solve4(vector<double>& four){
        bool ans=false;
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                double z=0;

                if(j==0){z=four[i]+four[i+1];}
                if(j==1){z=four[i]-four[i+1];}
                if(j==2){z=four[i]*four[i+1];}
                if(j==3){if(four[i+1]==0)continue; z=four[i]/four[i+1];}

                if(i==0)ans=ans||solve3({z,four[2],four[3]});
                if(i==1)ans=ans||solve3({four[0],z,four[3]});
                if(i==2)ans=ans||solve3({four[0],four[1],z});
            }
        }
        return ans;
    }
    bool judgePoint24(vector<int>& cards) {
        int n=cards.size();
        sort(cards.begin(),cards.end());
        vector<double> four(4);
        for(int i=0;i<4;i++){
            four[i]=cards[i];
        }
        bool ans=false;

        do{
            ans=ans||solve4(four);
        }while(next_permutation(four.begin(),four.end()));

        return ans;
    }
};