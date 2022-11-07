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
        std::vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int i = 0;
        int j = v.size() - 1;
        while (i < j)
            if (v[i++] != v[j--])
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
    printf("%d\n", s.isPalindrome(head));
}

int main() {
    test_case_1();

    return 0;
}