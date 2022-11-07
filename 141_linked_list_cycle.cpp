/*
  Leetcode.com
  Problem No: 141
  Problem:  141. Linked List Cycle
  Author: cpp.rakesh@gmail.com
  Date: 07/11/2022
*/

#include <bits/stdc++.h>

struct ListNode {
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}

    int val = 0;
    ListNode* next = nullptr;
};

ListNode* push_back(ListNode* head, int v) {
    if (head == nullptr) {
        head = new ListNode(v);
    } else {
        ListNode* node = head;
        while (node->next)
            node = node->next;
        node->next = new ListNode(v);
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
    ListNode* head = nullptr;
    for (int i = 1; i <= 20; ++i)
        head = push_back(head, i);
    traverse(head);

    Solution s;
    printf("%d\n", s.hasCycle(head));
}

void test_case_2() {
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
    //test_case_1();
    test_case_2();

    return 0;
}