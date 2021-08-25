class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        stack<int> temp;
        
        while(!min.empty() && min.top()<val){
            temp.push(min.top());
            min.pop();
        }
        min.push(val);
        while(temp.empty()==false){
            min.push(temp.top());
            temp.pop();
        }
        return;
    }
    
    void pop() {
        int num=st.top();
        stack<int> temp;
        while(true){
            if(num==min.top()){
                min.pop();
                st.pop();
                break;
            }
            else{
                temp.push(min.top());
                min.pop();
            }
        }
        while(temp.empty()==false){
            min.push(temp.top());
            temp.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */