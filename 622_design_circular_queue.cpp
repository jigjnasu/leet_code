/*
  Leetcode.com
  Problem No : 622
  Problem : Design circular queue
  Author : cpp.rakesh@gmail.com
  Date : 21/04/2021
*/

#include <bits/stdc++.h>

class MyCiruclarQueue {
public:
    MyCiruclarQueue(int k) : k(k) {
        queue = std::vector<int>(k, 0);
    }

    bool enQueue(int value) {
        if (n == k)
            return false;
        queue[l] = value;
        l = (l + 1) % k; ++n;
        return true;
    }

    bool deQueue(int value) {
        if (n == 0)
            return false;
        f = (f + 1) % k; --n;
        return true;
    }

    int Front() {
        return n == 0 ? -1 : queue[f];
    }

    int Rear() {
        return n == 0 ? -1 : queue[(l - 1 + k) % k];
    }

    bool isEmpty() {
        return n == 0;
    }

    bool isFull() {
        return n == k;
    }

private:
    std::vector<int> queue;
    int f = 0;
    int l = 0;
    int n = 0;
    int k = 0;
};

void test_a() {
    MyCiruclarQueue cq(5);
    for (int i = 1; i <= 10; ++i)
        printf("%d ", cq.enQueue(i));
    printf("\n");
    printf("Front == [%d]\n", cq.Front());
    printf("Rear  == [%d]\n", cq.Rear());
    printf("%d\n", cq.enQueue(7));
    for (int i = 0; i < 10; ++i)
        printf("%d ", cq.deQueue(10));
    printf("%d\n", cq.enQueue(100));
    printf("Front == [%d]\n", cq.Front());
    printf("Rear  == [%d]\n", cq.Rear());
    printf("\n");
}

int main() {
    test_a();

    return 0;
}
