/*
  Leetcode.com
  Problem No : 1290
  Problem : Convert Binary Number in a Linked List to Integer
  Author : cpp.rakesh@gmail.com
  Date: 24/04/2021
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        std::vector<int> v;
        while (head) {
            v.emplace_back(head->val);
            head = head->next;
        }

        int r = 0;
        for (int i = v.size() - 1; i >= 0; --i)
            if (v[i])
                r += 1 << (v.size() - 1 - i);
        return r;
    }
};

int main() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    Solution s;
    head = ls.push_back(head, 1);
    head = ls.push_back(head, 0);
    head = ls.push_back(head, 0);
    head = ls.push_back(head, 0);
    head = ls.push_back(head, 1);
    ls.traverse(head);
    printf("%d\n", s.getDecimalValue(head));

    return 0;
}
