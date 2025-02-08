class NumberContainers {
public:
    unordered_map<int,set<int>> mp;
    unordered_map<int,int> check;
    
    void change(int index, int number) {
        if(check.find(index) != check.end()){
            int num = check[index];
            mp[num].erase(index);
        }
        check[index] = number;
        mp[number].insert(index);
    }
    
    int find(int number) {
        if(mp.find(number) == mp.end() || mp[number].empty()){
            return -1;
        }
        auto it = mp[number].begin();
        return *it;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */