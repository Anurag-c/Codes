class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>s1;
    stack<int>s2;
    
    MyQueue() 
    {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) 
    {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop_peek(bool option)
    {
        while(!s1.empty())
        {
            int x = s1.top();
            s1.pop();
            s2.push(x);
        }
        
        int ans = s2.top();
        if(option == 1) s2.pop();
        
        while(!s2.empty())
        {
            int x = s2.top();
            s2.pop();
            s1.push(x);
        }
        
        return ans;
    }
    
    int pop() 
    {
        return pop_peek(1);
    }
    
    /** Get the front element. */
    int peek() 
    {
        return pop_peek(0);
    }
    
    /** Returns whether the queue is empty. */
    bool empty() 
    {
        return s1.empty();   
    }
};