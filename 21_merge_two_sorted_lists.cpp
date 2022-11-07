/*
  Leetcode.com
  Problem No: 21
  Problem:  Merge Two Sorted Lists
  Author: cpp.rakesh@gmail.com
  Date: 07/11/2022
*/

#include "utility/common.h"
#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        ListNode* temp = nullptr;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if (list1)
            node->next = list1;
        if (list2)
            node->next = list2;

        return head->next;
    }
};

void test_case_1() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 20; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);
}

void test_case_2() {
    SingleLinkedList ls;
    std::vector<int> v = get_sorted_array(10, 1, 100);
    ListNode* head1 = nullptr;
    for (int& e : v)
        head1 = ls.push_back(head1, e);
    v = get_sorted_array(25, 1, 100);
    ListNode* head2 = nullptr;
    for (int& e : v)
        head2 = ls.push_back(head2, e);
    ls.traverse(head1);
    ls.traverse(head2);

    Solution s;
    ListNode* head = s.mergeTwoLists(head1, head2);
    ls.traverse(head);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}