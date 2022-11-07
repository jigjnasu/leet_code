/*
  Leetcode.com
  Problem No: 141
  Problem:  141. Linked List Cycle
  Author: cpp.rakesh@gmail.com
  Date: 07/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;
        while (f && f->next) {
            f = f->next->next;
            s = s->next;
            if (s == f)
                return true;
        }
        return false;
    }

    bool hasCycle_1(ListNode *head) {
        std::unordered_map<ListNode*, int> dict;
        ListNode* node = head;
        while (node) {
            if (dict[node])
                return true;
            ++dict[node];
            node = node->next;
        }   
        return false;   
    }
};

void test_case_1() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 20; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    Solution s;
    printf("%d\n", s.hasCycle(head));
}

void test_case_2() {
    SingleLinkedList ls;
    ListNode* head = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3;
    n6->next = n7;
    n7->next = nullptr;
    //traverse(head);

    Solution s;
    printf("%d\n", s.hasCycle(head));
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}