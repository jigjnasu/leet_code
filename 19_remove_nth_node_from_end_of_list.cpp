/*
  Leetcode.com
  Problem No: 19
  Problem: Remove Nth Node From End of List
  Author: cpp.rakesh@gmail.com
  Date: 08/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *node = head;
        while (node) {
            ++length;
            node = node->next;
        }

        if (n == length) {
            ListNode *temp = head;
            head = head->next;
            delete (temp);
        } else {
            node = head;
            int iter = 1;
            while (iter < length - n) {
                ++iter;
                node = node->next;
            }
            ListNode* temp = node->next;
            node->next = node->next->next;
            delete (temp);
        }
        return head;
    }
};

void test_case_1() {
    SingleLinkedList ls;
    ListNode *head = nullptr;
    for (int i = 1; i <= 10; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    Solution s;
    head = s.removeNthFromEnd(head, 4);
    ls.traverse(head);
}

int main() {
    test_case_1();

    return 0;
}