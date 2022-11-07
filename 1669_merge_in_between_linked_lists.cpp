/*
  Leetcode.com
  Problem No : 1669
  Problem : Merge In Between Linked Lists
  Author : cpp.rakesh@gmail.com
  Date: 30/04/2021
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
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
};

int main() {
    Solution s;
    SingleLinkedList ls;
    ListNode* list1 = new ListNode(0);
    for (int i = 1; i <= 10; ++i)
        list1 = ls.push_back(list1, i);
    ls.traverse(list1);

    ListNode* list2 = new ListNode(100);
    for (int i = 101; i <= 110; ++i)
        list2 = ls.push_back(list2, i);
    ls.traverse(list2);

    list1 = s.mergeInBetween(list1, 3, 7, list2);
    ls.traverse(list1);

    return 0;
}
