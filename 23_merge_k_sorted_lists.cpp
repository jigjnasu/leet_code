/*
  Leetcode.com
  Problem No: 23
  Problem: Merge k Sorted Lists
  Author: cpp.rakesh@gmail.com
  Date: 23/05/2021
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    ListNode* mergeKLists_merge(std::vector<ListNode*>& lists) {
        ListNode* res = nullptr;
        for (auto& l : lists)
            res = merge(res, l);
        return res;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;
        for (auto& l : lists) {
            if (l) pq.push(l);
        }
        if (pq.empty()) return nullptr;
        ListNode* res = pq.top(); pq.pop();
        if (res->next) pq.push(res->next);
        ListNode* tail = res;
        while (!pq.empty()) {
            tail->next = pq.top(); pq.pop();
            tail = tail->next;
            if (tail->next) pq.push(tail->next);
        }
        return res;
    }

private:
    struct compare {
        bool operator () (const ListNode* a, const ListNode* b) {
            return a-> val > b->val;
        }
    };

    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* res = nullptr;
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        if (a->val < b->val) {
            res = a;
            res->next = merge(a->next, b);
        } else {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }
};

int main() {
    SingleLinkedList ls;
    ListNode* head1 = nullptr;
    for (int i = 1; i <= 20; ++i)
        head1 = ls.push_back(head1, i);
    ListNode* head2 = nullptr;
    for (int i = 2; i <= 20; i += 2)
        head2 = ls.push_back(head2, i);
    ListNode* head3 = nullptr;
    for (int i = 1; i <= 20; i += 2)
        head3 = ls.push_back(head3, i);
    std::vector<ListNode*> lists;
    lists.emplace_back(head1);
    lists.emplace_back(head2);
    lists.emplace_back(head3);
    Solution s;
    /*
    ListNode* node1 = s.mergeKLists_merge(lists);
    traverse(node1);
    */
    ListNode* node2 = s.mergeKLists(lists);
    ls.traverse(node2);

    return 0;
}
