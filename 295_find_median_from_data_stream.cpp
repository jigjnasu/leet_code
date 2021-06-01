/*
  LeetCode.com
  Problem No: 295
  Problem: Find Median from Data Stream
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 01/06/2021
*/

#include <bits/stdc++.h>

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if  (L.empty() || L.top() > num) L.push(num);
        else R.push(num);

        if (L.size() > R.size() + 1) {
            R.push(L.top()); L.pop();
        } else if (R.size() > L.size() + 1) {
            L.push(R.top()); R.pop();
        }
    }

    double findMedian() {
        if (L.size() == R.size())
            return (L.top() + R.top()) / 2.0f;
        else if (L.size() > R.size()) return L.top();
        else return R.top();
    }

private:
    std::priority_queue<int> L;
    std::priority_queue<int, std::vector<int>, std::greater<int>> R;
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    printf("%f\n", mf.findMedian());
    mf.addNum(3);
    printf("%f\n", mf.findMedian());

    return 0;
}
