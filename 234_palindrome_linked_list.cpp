/*
  LeetCode.com
  Problem No: 234
  Problem: Palindrome Linked List
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 07/11/2022
*/

#include "utility/SingleLinkedList.h"
#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        if (fast)
            curr = curr->next;
        
        while (prev && curr) {
            if (prev->val != curr->val)
                return false;
            prev = prev->next;
            curr = curr->next;
        }
        return true;
    }
    
    bool isPalindrome_1(ListNode* head) {
        std::string str;
        while (head) {
            str.push_back(head->val + '0');
            head = head->next;
        }
        int i = 0;
        int j = str.size() - 1;
        while (i < j)
            if (str[i++] != str[j--])
                return false;
        return true;    
    }


};

void test_case_1() {
    SingleLinkedList ls;
    std::vector<int> v = {1, 1, 3, 2, 1, 1};
    ListNode* head = ls.convert_to_list(v);
    ls.traverse(head);

    Solution s;
    printf("%d\n", s.isPalindrome_1(head));
}

void test_case_2() {
    SingleLinkedList ls;
    ListNode* head = nullptr;
    for (int i = 1; i <= 9; ++i)
        head = ls.push_back(head, i);
    ls.traverse(head);

    Solution s;
    head = s.isPalindrome(head);
    ls.traverse(head);
}

int main() {
    //test_case_1();
    test_case_2();
    
    return 0;
}