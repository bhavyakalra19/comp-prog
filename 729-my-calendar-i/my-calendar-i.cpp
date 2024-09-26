class MyCalendar {
public:
    map<int,int> mp;
    // MyCalendar() {
        
    // }
    
    bool book(int start, int end) {
        int k = INT_MAX;
        int s = INT_MAX;
        int nx = INT_MAX;
        for(auto m : mp){
            if(m.first < start){
                s = m.first;
                k = m.second;
            }else if(m.first == start){
                return false;
            }else{
                nx = m.first;
                break;
            }
        }
        if(nx != INT_MAX && end > nx){
            return false;
        }
        if(k != INT_MAX && start < k){
            return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */