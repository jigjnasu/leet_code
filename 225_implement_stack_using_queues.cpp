/*
  Leetcode.com
  Problem No: 225
  Problem: Implement Stack using Queues
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 28/05/2021
 */

#include <bits/stdc++.h>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for (std::size_t i = 0; i < q.size() - 1; ++i) {
            q.push(q.front()); q.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = q.front(); q.pop();
        return t;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    std::queue<int> q;
};

int main() {
    MyStack ms;
    ms.push(1);
    ms.push(2);
    printf("top   == [%d]\n", ms.top());
    printf("pop   == [%d]\n", ms.pop());
    printf("empty == [%d]\n", ms.empty());

    return 0;
}
