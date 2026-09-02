class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;
        int smallestEven = INT_MAX;
        for(auto &a: nums1){
            if(a % 2 == 0){
                smallestEven = min(smallestEven, a);
            }else{
                smallestOdd = min(smallestOdd, a);
            }
        }
        if((smallestEven != INT_MAX) && (smallestOdd != INT_MAX) && (smallestOdd > smallestEven)) return false;
        return true;
    }
};

 
// if there exist any even and there is no odd smaller than it and there are odd count in array answer is not possible
