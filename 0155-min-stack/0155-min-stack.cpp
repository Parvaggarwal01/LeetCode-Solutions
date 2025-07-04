class MinStack {
public:
    stack<int> s1;
    stack<int> minS1;
    MinStack() {
        
    }
    
    void push(int val) {
        if(minS1.empty()){
            minS1.push(val);
            s1.push(val);
        }else if(minS1.top() >= val){
            minS1.push(val);
            s1.push(val);
        }else {
            s1.push(val);
        }
    }
    
    void pop() {
        if(minS1.top() == s1.top()){
            minS1.pop();
            s1.pop();
        }else{
            s1.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return minS1.top();
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