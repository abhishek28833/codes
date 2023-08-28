class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    int t;
    void push(int x) {
        if(!q2.empty()){
            q2.push(x);
            t = x;
        }
        else{
            q1.push(x);
            t = x;
        }
    }
    
    int pop() {
        if(q1.size()>=1 && q2.size()==0){
            while(q1.size()>1){
                t = q1.front();
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q1.pop();
            return temp;
        }
        else{
            while(q2.size()>1){
                t=q2.front();
                q1.push(q2.front());
                q2.pop();
            }
            int temp = q2.front();
            q2.pop();
            return temp;
        }
        return 0;
    }
    
    int top() {
        return t;
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */