/*
  Leetcode.com
  Problem No: 160
  Problem:   Intersection of Two Linked Lists
  Author: cpp.rakesh@gmail.com
  Date: 07/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_map<ListNode*, int> dict;
        while (headA) {
            ++dict[headA];
            headA = headA->next;
        }

        while (headB) {
            if (dict[headB])
                return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};

void test_case_1() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 21; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);
}

int main() {
    test_case_1();

    return 0;
}