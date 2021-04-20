/*
  Leetcode.com
  Problem No : 1381
  Problem : Design a Stack With Increment Operation
  Author : cpp.rakesh@gmail.com
  Date: 21/04/2021
*/

#include <bits/stdc++.h>

class CustomStack {
public:
    CustomStack(int maxSize) {
        stack = std::vector<int>(maxSize, 0);
    }

    void push(int x) {
        if (top + 1 < static_cast<int>(stack.size()))
            stack[++top] = x;
    }

    int pop() {
        if (top == -1)
            return -1;
        return stack[top--];
    }

    void increment(int k, int val) {
        for (int i = 0; i < std::min(top + 1, k); ++i)
            stack[i] += val;
    }

private:
    std::vector<int> stack;
    int top = -1;
};

void test() {
    CustomStack cs(3);
    cs.push(1);                          // stack becomes [1]
    cs.push(2);                          // stack becomes [1, 2]
    printf("%d\n", cs.pop());            // return 2 --> Return top of the stack 2, stack becomes [1]
    cs.push(2);                          // stack becomes [1, 2]
    cs.push(3);                          // stack becomes [1, 2, 3]
    cs.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
    cs.increment(5, 100);                // stack becomes [101, 102, 103]
    cs.increment(2, 100);                // stack becomes [201, 202, 103]
    printf("%d\n", cs.pop());            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
    printf("%d\n", cs.pop());            // return 202 --> Return top of the stack 102, stack becomes [201]
    printf("%d\n", cs.pop());            // return 201 --> Return top of the stack 101, stack becomes []
    printf("%d\n", cs.pop());            // return -1 --> Stack is empty return -1.
}

int main() {
    test();

    return 0;
}
