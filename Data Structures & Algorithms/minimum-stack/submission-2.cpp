class MinStack {
    long min;
    std::stack<long> minStack;
public:
    MinStack() {}
    
    void push(int val) {
        if(minStack.empty())
        {
            minStack.push(0);
            min = val;
        }else{
            minStack.push(val - min);
            if(val < min) min = val;
        }
    }
    
    void pop() {
        if(minStack.empty()) return;
        long pop = minStack.top();
        minStack.pop();
        if(pop<0) min = min - pop;
    }
    
    int top() {
        long top = minStack.top();
        return ( top>0 ) ? (top+min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
