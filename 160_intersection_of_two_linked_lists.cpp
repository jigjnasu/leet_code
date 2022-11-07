/*
  Leetcode.com
  Problem No: 160
  Problem:   Intersection of Two Linked Lists
  Author: cpp.rakesh@gmail.com
  Date: 07/11/2022
*/

#include <bits/stdc++.h>
struct ListNode {
    ListNode(int v) : val(v) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}

    int val = 0;
    ListNode* next = nullptr;
};

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

ListNode* push_back(ListNode* head, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
    } else {
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

void test_case_1() {
    ListNode* head = nullptr;
    for (int i = 1; i <= 21; ++i)
        head = push_back(head, i);
    traverse(head);
}

int main() {
    test_case_1();

    return 0;
}