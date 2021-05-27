/*
  Leetcode.com
  Problem No: 155
  Problem: Min Stack
  Author: cpp.rakesh@gmail.com
  Date: 27/05/2021
*/

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int v, int m) : val(v), min(m) {}

    int val = 0;
    int min = 0;
    Node* next = nullptr;
};

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        if (head == nullptr)
            head = new Node(val, val);
        else {
            Node* nh = new Node(val, std::min(val, head->min));
            nh->next = head;
            head = nh;
        }
    }

    void pop() {
        head = head->next;
    }

    int top() {
        return head->val;
    }

    int getMin() {
        return head->min;
    }

private:
    Node* head = nullptr;
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    printf("min == [%d]\n", ms.getMin());
    ms.pop();
    printf("top == [%d]\n", ms.top());
    printf("min == [%d]\n", ms.getMin());

    return 0;
}
