/*
  Leetcode.com
  Problem No : 1290
  Problem : Convert Binary Number in a Linked List to Integer
  Author : cpp.rakesh@gmail.com
  Date: 24/04/2021
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
};

int main() {
    ListNode* head = nullptr;
    Solution s;
    head = s.push_back(head, 1);
    head = s.push_back(head, 0);
    head = s.push_back(head, 0);
    head = s.push_back(head, 0);
    head = s.push_back(head, 1);
    s.traverse(head);
    printf("%d\n", s.getDecimalValue(head));

    return 0;
}
