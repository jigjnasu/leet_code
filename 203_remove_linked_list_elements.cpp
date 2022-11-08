/*
  Leetcode.com
  Problem No: 203
  Problem : Remove Linked List Elements
  Author : cpp.rakesh@gmail.com
  Date: 08/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *new_head = new ListNode(0, head);
        ListNode *prev = new_head, *curr = head;
        while (curr) {
            if (curr->val != val) {
                prev = curr;
                curr = curr->next;
            } else {
                while (curr && curr->val == val) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete (temp);
                }
                if (curr == nullptr) {
                    prev->next = nullptr;
                    return new_head->next;
                } else {
                    prev->next = curr;
                }
            }
        }

        return new_head->next;
    }
};

void test_case_1() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    std::vector<int> v = {3, 3, 3, 1, 1, 1, 2 , 9, 3, 4, 2, 3, 1, 3, 3, 3, 3, 3, 1, 9, 9, 9, 3};
    head = ls.convert_to_list(v);
    ls.traverse(head);

    Solution s;
    head = s.removeElements(head, 3);
    ls.traverse(head);
}

void test_case_2() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    head = ls.convert_to_list(v);
    ls.traverse(head);

    Solution s;
    head = s.removeElements(head, 6);
    ls.traverse(head);
}

int main() {
    //test_case_1();
    test_case_2();

    return 0;
}