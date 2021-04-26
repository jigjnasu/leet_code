/*
  Leetcode.com
  Problem No : 707
  Problem : Design Linked List
  Author : cpp.rakesh@gmail.com
  Date: 19/04/2021
*/

#include <bits/stdc++.h>

struct Node {
    int val = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node;
        tail = new Node;
    }

    ~MyLinkedList() {
        Node* node = head->next;
        while (node) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
        delete head; delete tail;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= cap)
            return -1;
        int c = 0;
        Node* node = head->next;
        int value = node->val;
        while (c < index) {
            node = node->next;
            value = node->val;
            ++c;
        }
        return value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node;
        node->val = val;
        if (head->next == nullptr && tail->next == nullptr) {
            head->next = tail->next = node;
        } else {
            node->next = head->next;
            node->next->prev = node;
            head->next = node;
        }
        ++cap;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node;
        node->val = val;
        if (head->next == nullptr && tail->next == nullptr) {
            head->next = tail->next = node;
        } else {
            node->prev = tail->next;
            node->prev->next = node;
            tail->next = node;
        }
        ++cap;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index >= 0 && index <= cap) {
            if (index == 0) {
                addAtHead(val);
            } else if (index == cap) {
                addAtTail(val);
            } else {
                Node* node = new Node;
                node->val = val;

                int c = 0;
                Node* iter = head->next;
                while (c < index) {
                    iter = iter->next;
                    ++c;
                }
                node->prev = iter->prev;
                node->prev->next = node;
                iter->prev = node;
                node->next = iter;
                ++cap;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= 0 && index < cap) {
            if (index == 0) {
                if (cap == 1) {
                    Node* node = head->next;
                    delete node;
                    head->next = tail->next = nullptr;
                } else {
                    Node* node = head->next;
                    head->next = node->next;
                    head->next->prev = nullptr;
                    delete node;
                }
            } else {
                if (index == cap - 1) {
                    Node* node = tail->next;
                    tail->next = node->prev;
                    tail->next->next = nullptr;
                    delete node;
                } else {
                    int c = 0;
                    Node* node = head->next;
                    while (c < index) {
                        node = node->next;
                        ++c;
                    }
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    delete node;
                }
            }
            --cap;
        }
    }

    void traverse_from_front() const {
        printf("------------------------------------------------------\n");
        printf("                     from head\n");
        Node* node = head->next;
        while (node) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n------------------------------------------------------\n");
    }

    void traverse_from_back() const {
        printf("------------------------------------------------------\n");
        printf("                     from tail\n");
        Node* node = tail->next;
        while (node) {
            printf("%d ", node->val);
            node = node->prev;
        }
        printf("\n------------------------------------------------------\n");
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int cap = 0;
};

void test_add_ends() {
    MyLinkedList list;
    for (int i = 0; i <= 9; ++i)
        list.addAtHead(i);
    list.traverse_from_front();
    list.traverse_from_back();
}

void test_get() {
    MyLinkedList list;
    for (int i = 0; i <= 9; ++i)
        list.addAtTail(i);

    list.traverse_from_front();
    for (int i = -2; i <= 12; ++i)
        printf("[%d] at [%d]\n", list.get(i), i);
}

void add_at_index() {
    MyLinkedList list;
    list.addAtHead(0);
    list.addAtTail(30);
    for (int i = 1; i <= 29; ++i)
        list.addAtIndex(i, i);
    list.traverse_from_front();
}

void delete_test() {
    MyLinkedList list;
    for (int i = 0; i <= 20; ++i)
        list.addAtTail(i);
    list.traverse_from_front();
    list.deleteAtIndex(0);
    list.deleteAtIndex(19);
    list.deleteAtIndex(8);
    list.traverse_from_front();
}

void test_a() {
    MyLinkedList list;
    list.addAtHead(7);
    list.addAtHead(2);
    list.addAtHead(1);
    list.addAtIndex(3, 0);
    list.deleteAtIndex(2);
    list.addAtHead(6);
    list.addAtTail(4);
    printf("%d\n", list.get(4));
    list.addAtHead(4);
    list.addAtIndex(5, 0);
    list.addAtHead(6);
    list.traverse_from_front();
}

void test_b() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);
    printf("%d\n", list.get(1));
    list.traverse_from_front();
    list.deleteAtIndex(0);
    list.traverse_from_front();
    printf("%d\n", list.get(0));
    printf("%d\n", list.get(1));
    printf("%d\n", list.get(2));
    list.traverse_from_front();
}

int main() {
    test_add_ends();
    test_get();
    add_at_index();
    delete_test();
    test_a();
    test_b();

    return 0;
}
