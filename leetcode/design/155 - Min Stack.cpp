class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        stack.push( x );
        if( mins.empty() || x <= mins.top() )
            mins.push( x ); 
    }
    
    void pop() {
        if( mins.top() == stack.top() )
            mins.pop();
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return mins.top();
    }
    
private:
    std::stack<int> stack;
    std::stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
