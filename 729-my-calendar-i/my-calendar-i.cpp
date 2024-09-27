class Node{
    public:
        int s;
        int t;
        Node *left;
        Node *right;

        Node(int s, int t){
            this->s = s;
            this->t = t;
            left = NULL;
            right = NULL;
        }
};


class MyCalendar {
public:
    Node *root;

    bool dfs(int s, int e, Node* &curr){
        if(!curr){
            curr = new Node(s,e);
            return 1;
        }
        if(curr && e <= curr->s){
            return dfs(s,e,curr->left);
        }else if(curr && s >= curr->t){
            return dfs(s,e,curr->right);
        }
        return 0;
    }
    
    bool book(int start, int end) {
        return dfs(start, end, root);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */