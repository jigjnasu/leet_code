/*
  LeetCode.com
  Problem No: 83
  Problem: Remove Duplicates from Sorted List
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 08/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            while (cur->next && cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete (temp);
            }
            cur = cur->next;
        }
        return head;
    }
};

void test_case_1() {
    SingleLinkedList ls;
    std::vector<int> v = {1, 1, 1, 1, 2, 3, 3, 3, 4};
    ListNode* head = ls.convert_to_list(v);
    ls.traverse(head);

    Solution s;
    head = s.deleteDuplicates(head);
    ls.traverse(head);
}

int main() {
    test_case_1();

    return 0;
}