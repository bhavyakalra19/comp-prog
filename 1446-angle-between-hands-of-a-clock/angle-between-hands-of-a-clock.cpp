class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mins = minutes * 60;
        double hr = hour * 300 + ((double)minutes * 5);
        double x = 0;
        if(hr >= mins){
            x = (hr - mins )/ 10;
        }else{
            x = (mins - hr)/10;
        }
        return min(x, 360 - x);
    }
};
// 15 mins -> 15 * 60 = 900 seconds


// 3 * 300 = 900 seconds + ( 1/4 mins * 5 * 60 ) = 300 / 4 = 75


// 975 - 900 
// 75
// /3600 = 7.5
