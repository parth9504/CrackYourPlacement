#include <bits/stdc++.h> 
class Stack
{
public:
    deque<int>dq;
    Stack()
    {
    }
    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        dq.push_back(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        //pop the last element inserted if dq not empty
        if (dq.empty()) {
          return -1;
        }
        int val = dq.back();
        dq.pop_back();
        return val;
    }
    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if (dq.empty()) {
          return -1;
        }
        return dq.back();
    }
    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
       return dq.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return dq.size();
    }
};