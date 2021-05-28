/*
  Leetcode.com
  Problem No: 232
  Problem: Implement Queue using Stacks
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 28/05/2021
 */

#include <bits/stdc++.h>

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        peek();
        const int val = out.top(); out.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        if (out.empty())
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        return out.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() & out.empty();
    }

private:
    std::stack<int> in, out;
};

int main() {
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    printf("peek   == [%d]\n", mq.peek());
    printf("pop    == [%d]\n", mq.pop());
    printf("empty  == [%d]\n", mq.empty());

    return 0;
}
