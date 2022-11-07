/*
  Leetcode.com
  Problem No: 21
  Problem:  Merge Two Sorted Lists
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

int random(int s, int e) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(s, e);
    return dt(rd);
}

std::vector<int> get_sorted_array(int n) {
    std::vector<int> v(n, 0);
    for (std::size_t i = 0; i < v.size(); ++i)
        v[i] = random(1, 100);
    std::sort(v.begin(), v.end());
    return v;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* node = head;
        ListNode* temp = nullptr;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if (list1)
            node->next = list1;
        if (list2)
            node->next = list2;

        return head->next;
    }
};

void test_case_1() {
    ListNode* head = nullptr;
    for (int i = 1; i <= 20; ++i)
        head = push_back(head, i);
    traverse(head);
}

void test_case_2() {
    std::vector<int> v = get_sorted_array(10);
    ListNode* head1 = nullptr;
    for (int& e : v)
        head1 = push_back(head1, e);
    v = get_sorted_array(25);
    ListNode* head2 = nullptr;
    for (int& e : v)
        head2 = push_back(head2, e);
    traverse(head1);
    traverse(head2);

    Solution s;
    ListNode* head = s.mergeTwoLists(head1, head2);
    traverse(head);
}

int main() {
    //test_case_1();
    test_case_2();

    return 0;
}