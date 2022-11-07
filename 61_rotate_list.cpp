/*
  LeetCode.com
  Problem No: 61
  Problem: Rotate List
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 26/05/2021
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

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
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 10; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    Solution s;
    head = s.rotateRight(head, 3);
    ls.traverse(head);

    return 0;
}
