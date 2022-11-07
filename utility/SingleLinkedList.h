/*
    Header file: implementation of Single Linked List
    Author: cpp.rakesh@gmail.com
    Date: 07/11/2022
*/

#ifndef GIT_HUB_LEET_CODE_UTILITY_SINGLE_LINKED_LIST_H_
#define GIT_HUB_LEET_CODE_UTILITY_SINGLE_LINKED_LIST_H_

#include <bits/stdc++.h>

struct ListNode {
    ListNode(int v) : val(v) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}

    int val = 0;
    ListNode* next = nullptr;
};

class SingleLinkedList {
public:
    ListNode* push_front(ListNode* head, int val) {
        if (head == nullptr) {
            head = new ListNode(val);
        } else {
            ListNode* node = new ListNode(val);
            node->next = head;
            head = node;
        }
        return head;
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
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        ListNode* node = head;
        while (node) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    }
};

#endif //GIT_HUB_LEET_CODE_UTILITY_SINGLE_LINKED_LIST_H_