/*
  LeetCode.com
  Problem Number: 237
  Problem : Delete Node in a Linked List
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 07/05/2021
 */

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        *node = *next;
        delete next;
    }
};

int main() {
    SingleLinkedList ls;
    Solution s;
    ListNode* head = nullptr;
    for (int i = 1; i <= 10; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    ListNode* node = head->next->next->next;
    s.deleteNode(node);
    ls.traverse(head);

    return 0;
}
