/*
  Leetcode.com
  Problem No : 1669
  Problem : Merge In Between Linked Lists
  Author : cpp.rakesh@gmail.com
  Date: 30/04/2021
*/

#include <bits/stdc++.h>

struct ListNode {
    ListNode() {}
    ListNode(int v) : val(v) {}

    int val = 0;
    ListNode* next = nullptr;
};

class Solution {
public:
    void push_back(ListNode* list, int val) {
        ListNode* node = list;
        while (node->next != nullptr)
            node = node->next;
        node->next = new ListNode(val);
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* n1 = list1;
        for (int i = 0; i < a - 1; ++i)
            n1 = n1->next;
        for (int i = 0; i < b - a + 1; ++i) {
            ListNode* temp = n1->next;
            n1->next = n1->next->next;
            delete temp;
        }
        ListNode* n2 = list2;
        while (n2->next != nullptr)
            n2 = n2->next;
        n2->next = n1->next;
        n1->next = list2;
        return list1;
    }

    void traverse(ListNode* list) const {
        printf("-----------------------------------------------------\n");
        ListNode* node = list;
        while (node) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n-----------------------------------------------------\n");
    }
};

int main() {
    Solution s;
    ListNode* list1 = new ListNode(0);
    for (int i = 1; i <= 10; ++i)
        s.push_back(list1, i);
    s.traverse(list1);

    ListNode* list2 = new ListNode(100);
    for (int i = 101; i <= 110; ++i)
        s.push_back(list2, i);
    s.traverse(list2);

    list1 = s.mergeInBetween(list1, 3, 7, list2);
    s.traverse(list1);

    return 0;
}
