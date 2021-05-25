/*
  LeetCode.com
  Problem No: 61
  Problem: Rotate List
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 26/05/2021
*/

#include <bits/stdc++.h>

struct ListNode {
    ListNode() {}
    ListNode(int val) : val(val) {}

    int val = 0;
    ListNode* next = nullptr;
};

ListNode* push_back(ListNode* head, int val) {
    if (head == nullptr)
        head = new ListNode(val);
    else {
        ListNode* node = head;
        while (node->next)
            node = node->next;
        node->next = new ListNode(val);
    }
    return head;
}

void traverse(ListNode* head) {
    ListNode* node = head;
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            ++len;
        }
        tail->next = head;

        k %= len;
        if (k) {
            for (int i = 0; i < len - k; ++i)
                tail = tail->next;
        }
        ListNode* new_head = tail->next;
        tail->next = nullptr;
        return new_head;
    }
};

int main() {
    ListNode* head = nullptr;
    for (int i = 1; i <= 10; ++i)
        head = push_back(head, i);
    traverse(head);

    Solution s;
    head = s.rotateRight(head, 3);
    traverse(head);

    return 0;
}
