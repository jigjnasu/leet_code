/*
    Header file: unit test cases for single linked list
    Author: cpp.rakesh@gmail.com
    Date: 07/11/2022
*/

#include "SingleLinkedList.h"

void test_case_1() {
    SingleLinkedList sl;
    ListNode* head1 = nullptr;
    for (int i = 1; i <= 20; ++i)
        head1 = sl.push_front(head1, i);
    sl.traverse(head1);

    ListNode* head2 = nullptr;
    for (int i = 1; i <= 20; ++i)
        head2 = sl.push_back(head2, i);
    sl.traverse(head2);
}

int main() {
    test_case_1();

    return 0;
}