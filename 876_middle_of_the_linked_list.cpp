/*
  LeetCode.com
  Problem No: 876
  Problem: Middle of the Linked List
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 07/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

void test_case_1() {
    ListNode* head = nullptr;
    head = new ListNode(1);
    SingleLinkedList ls;
    ls.traverse(head);

    Solution s;
    printf("middle element == [%d]\n", s.middleNode(head)->val);
}

void test_case_2() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 9; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    Solution s;
    printf("middle element == [%d]\n", s.middleNode(head)->val);
}

void test_case_3() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 10; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    Solution s;
    printf("middle element == [%d]\n", s.middleNode(head)->val);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}