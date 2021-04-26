/*
  Leetcode.com
  Problem No : 1670
  Problem : Design front middle back queue
  Author : cpp.rakesh@gmail.com
  Date : 21/04/2021
*/

#include <bits/stdc++.h>

struct Node {
    Node* next = nullptr;
    Node* prev = nullptr;
    int val = 0;
};

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
        head = new Node;
        tail = new Node;
    }

    ~FrontMiddleBackQueue() {
        Node* node = head->next;
        while (node) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
        delete head;
        delete tail;
    }

    void pushFront(int val) {
        Node* node = new Node;
        node->val = val;
        if (head->next == nullptr && tail->next == nullptr) {
            head->next = tail->next = node;
        } else {
            node->next = head->next;
            node->next->prev = node;
            head->next = node;
        }
        ++size;
    }

    void pushMiddle(int val) {
        Node* node = new Node;
        node->val = val;
        if (head->next == nullptr && tail->next == nullptr) {
            head->next = tail->next = node;
            ++size;
        } else {
            const int index = size >> 1;
            if (index == 0) {
                pushFront(val);
            } else {
                int i = 0;
                Node* iter = head->next;
                while (i < index) {
                    iter = iter->next;
                    ++i;
                }
                iter->prev->next = node;
                node->prev = iter->prev;
                node->next = iter;
                node->next->prev = node;
                ++size;
            }
        }
    }

    void pushBack(int val) {
        Node* node = new Node;
        node->val = val;
        if (head->next == nullptr && tail->next == nullptr) {
            head->next = tail->next = node;
        } else {
            node->prev = tail->next;
            node->prev->next = node;
            tail->next = node;
        }
        ++size;
    }

    int popFront() {
        if (size == 0)
            return -1;
        int res = 0;
        if (size == 1) {
            Node* node = head->next;
            res = node->val;
            delete node;
            head->next = tail->next = nullptr;
        } else {
            Node* node = head->next;
            res = node->val;
            head->next = node->next;
            head->next->prev = nullptr;
            delete node;
        }
        --size;
        return res;
    }

    int popMiddle() {
        if (size == 0)
            return -1;
        int index = size >> 1;
        int res = 0;
        if (size <= 2) {
            res = popFront();
        } else {
            int i = 0;
            Node* node = head->next;
            if (size & 1 == 0)
                --index;
            while (i < index) {
                node = node->next;
                ++i;
            }
            res = node->val;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            --size;
        }
        return res;
    }

    int popBack() {
        if (size == 0)
            return -1;

        int res = 0;
        if (size == 1) {
            Node* node = head->next;
            res = node->val;
            head->next = tail->next = nullptr;
            delete node;
        } else {
            Node* node = tail->next;
            res = node->val;
            tail->next = node->prev;
            tail->next->next = nullptr;
            delete node;
        }
        --size;
        return res;
    }

    void print() {
        printf("-------------------------------------------------------------------------\n");
        Node* node = head->next;
        while (node) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n-------------------------------------------------------------------------\n");
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};

void test_a() {
    FrontMiddleBackQueue fmb;
    fmb.pushFront(1);
    fmb.pushBack(100);
    fmb.pushMiddle(50);
    fmb.pushMiddle(25);
    printf("pop front  == [%d]\n", fmb.popFront());
    fmb.print();
    printf("pop middle == [%d]\n", fmb.popMiddle());
    fmb.print();
}

void test_b() {
    FrontMiddleBackQueue fmb;
    fmb.pushFront(1);
    fmb.pushBack(2);
    fmb.pushMiddle(3);
    fmb.pushMiddle(4);
    printf("pop front  == [%d]\n", fmb.popFront());
    printf("pop middle == [%d]\n", fmb.popMiddle());
    printf("pop middle == [%d]\n", fmb.popMiddle());
    printf("pop back   == [%d]\n", fmb.popBack());
    printf("pop front  == [%d]\n", fmb.popFront());
    printf("pop back   == [%d]\n", fmb.popBack());
    printf("pop middle == [%d]\n", fmb.popMiddle());
}

int main() {
    //test_a();
    test_b();

    return 0;
}
