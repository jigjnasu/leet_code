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
    printf("%d\n", s.isPalindrome(head));
}

int main() {
    test_case_1();
    
    return 0;
}