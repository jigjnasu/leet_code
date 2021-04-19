/*
  Leetcode.com
  Problem No : 641
  Problem : Design Circular Deque
  Author : cpp.rakesh@gmail.com
  Date: 19/04/2021
*/

#include <bits/stdc++.h>

/*
  front pointer at front or 0th index
  last pointer at last or n - 1th index
 */
class MyCircularDeque1 {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque1(int k) : deque(k, 0), fp(0), lp(k - 1), k(k) {}

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size == k)
            return false;
        deque[fp] = value;
        fp = (fp + 1) % k;
        ++size;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == k)
            return false;
        deque[lp] = value;
        lp = (lp - 1 + k) % k;
        ++size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0)
            return false;
        fp = (fp - 1 + k) % k;
        --size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0)
            return false;
        lp = (lp + 1) % k;
        --size;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (size == 0)
            return -1;
        return deque[(fp - 1 + k) % k];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (size == 0)
            return -1;
        return deque[(lp + 1) % k];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == k;
    }

private:
    std::vector<int> deque;
    int fp = 0, lp = 0, size = 0, k = 0;
};

/*
  front pointer at last or n - 1th index
  last pointer at front or 0th index
 */
class MyCircularDeque2 {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque2(int k) : deque(k, 0), fp(k - 1), lp(0), k(k) {}

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size == k)
            return false;
        deque[fp] = value;
        fp = (fp - 1 + k) % k;
        ++size;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size == k)
            return false;
        deque[lp] = value;
        lp = (lp + 1) % k;
        ++size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size == 0)
            return false;
        fp = (fp + 1) % k;
        --size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size == 0)
            return false;
        lp = (lp - 1 + k) % k;
        --size;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (size == 0)
            return -1;
        return deque[(fp + 1) % k];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (size == 0)
            return -1;
        return deque[(lp - 1 + k) % k];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == k;
    }

private:
    std::vector<int> deque;
    int fp = 0, lp = 0, size = 0, k = 0;
};

void test_a() {
    MyCircularDeque1 deque(3);
    printf("%d\n", deque.insertLast(1));
    printf("%d\n", deque.insertLast(2));
    printf("%d\n", deque.insertFront(3));
    printf("%d\n", deque.insertLast(4));
    printf("%d\n", deque.getRear());
    printf("%d\n", deque.isFull());
    printf("%d\n", deque.deleteLast());
    printf("%d\n", deque.insertFront(4));
    printf("%d\n", deque.getFront());
}

void test_b() {
    MyCircularDeque1 deque(4);
    printf("%d\n", deque.insertFront(9));
    printf("%d\n", deque.deleteLast());
    printf("%d\n", deque.getRear());
    printf("%d\n", deque.getFront());
    printf("%d\n", deque.getFront());
    printf("%d\n", deque.deleteFront());
    printf("%d\n", deque.insertFront(6));
    printf("%d\n", deque.insertLast(5));
    printf("%d\n", deque.insertFront(9));
    printf("%d\n", deque.getFront());
    printf("%d\n", deque.insertFront(6));
}

void test_c() {
    MyCircularDeque1 deque(3);
    printf("%d\n", deque.insertLast(1));
    printf("%d\n", deque.insertLast(2));
    printf("%d\n", deque.insertFront(3));
    printf("%d\n", deque.insertLast(4));
    printf("%d\n", deque.getRear());
    printf("%d\n", deque.isFull());
    printf("%d\n", deque.deleteLast());
    printf("%d\n", deque.insertFront(4));
    printf("%d\n", deque.getFront());
}

void test_d() {
    MyCircularDeque1 deque(4);
    printf("%d\n", deque.insertFront(9));
    printf("%d\n", deque.deleteLast());
    printf("%d\n", deque.getRear());
    printf("%d\n", deque.getFront());
    printf("%d\n", deque.getFront());
    printf("%d\n", deque.deleteFront());
    printf("%d\n", deque.insertFront(6));
    printf("%d\n", deque.insertLast(5));
    printf("%d\n", deque.insertFront(9));
    printf("%d\n", deque.getFront());
    printf("%d\n", deque.insertFront(6));
}

int main() {
    test_a();
    test_b();
    test_c();
    test_d();

    return 0;
}
