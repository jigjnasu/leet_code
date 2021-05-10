/*
  LeetCode.com
  Problem Number: 237
  Problem : Delete Node in a Linked List
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 07/05/2021
 */

#include <bits/stdc++.h>

struct ListNode {
    ListNode() {}
    ListNode(int v) : val(v) {}

    int val = 0;
    ListNode* next = nullptr;
};

class Solution {
public:
    ~Solution() {
        ListNode* node = head;
        while (node) {
            ListNode* temp = node;
            node = node->next;
            delete temp;
        }
    }

    void push_back(int val) {
        if (head == nullptr)
            head = new ListNode(val);
        else {
            ListNode* node = head;
            while (node->next)
                node = node->next;
            node->next = new ListNode(val);
        }
    }

    void traverse() {
        printf("---------------------------------------------\n");
        ListNode* node = head;
        while (node) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n---------------------------------------------\n");
    }

    ListNode* get(int index) {
        ListNode* node = head;
        for (int i = 0; i < index; ++i)
            node = node->next;
        return node;
    }

    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        *node = *next;
        delete next;
    }

private:
    ListNode* head = nullptr;
};

int main() {
    Solution s;
    for (int i = 1; i <= 10; ++i)
        s.push_back(i);
    s.traverse();

    ListNode* node = s.get(4);
    s.deleteNode(node);
    s.traverse();

    return 0;
}
