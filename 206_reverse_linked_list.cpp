/*
  LeetCode.com
  Problem No: 206
  Problem: Reverse Linked List
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 07/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

void test_case_1() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 10; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    Solution s;
    head = s.reverseList(head);
    ls.traverse(head);
}

int main() {
    test_case_1();

    return 0;
}