#include <iostream>
#include<bits/stdc++.h>

class MinStack {
public:
    stack<int>st; //creating the stack
    stack<int>minSt; //creating the stack which contain min num
    
    void push(int val) {
        st.push(val);
        if(minSt.empty())  //check of the stack is empty
        {
            minSt.push(val); // push the first element 
        }
        else
        {
            minSt.push(min(minSt.top(),val)); //compare the element with its previous to push it in the min Stack
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};