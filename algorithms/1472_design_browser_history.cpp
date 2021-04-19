/*
  Leetcode.com
  Problem No: 1472
  Problem : Design Browser History
  Author: cpp.rakesh@gmail.com
  Date: 19/04/2021
*/

#include <bits/stdc++.h>

class BrowserHistoryStack {
public:
    BrowserHistoryStack(std::string homepage) {
        history.push(homepage);
    }

    void visit(std::string url) {
        history.push(url);
        future = std::stack<std::string>();
    }

    std::string back(int steps) {
        while (steps-- && history.size() > 1) {
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }

    std::string forward(int steps) {
        while (steps-- && !future.empty()) {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }

private:
    std::stack<std::string> history;
    std::stack<std::string> future;
};

class BrowserHistoryArray {
public:
    BrowserHistoryArray(std::string homepage) {
        history.push_back(homepage);
    }

    void visit(std::string url) {
        ++pos;
        history.resize(pos);
        history.push_back(url);
    }

    std::string back(int steps) {
        pos = std::max(0, pos - steps);
        return history[pos];
    }

    std::string forward(int steps) {
        pos = std::min(pos + steps, static_cast<int>(history.size()) - 1);
        return history[pos];
    }

private:
    std::vector<std::string> history;
    int pos = 0;
};

void test_stack() {
    BrowserHistoryStack hist("leetcode.com");
    hist.visit("google.com");
    hist.visit("facebook.com");
    hist.visit("youtube.com");
    printf("back     --> [%s]\n", hist.back(1).c_str());
    printf("back     --> [%s]\n", hist.back(1).c_str());
    printf("forward  --> [%s]\n", hist.forward(1).c_str());
    hist.visit("linkedin.com");
    printf("forward  --> [%s]\n", hist.forward(2).c_str());
    printf("back     --> [%s]\n", hist.back(2).c_str());
    printf("back     --> [%s]\n", hist.back(7).c_str());
}

void test_array() {
    BrowserHistoryArray hist("leetcode.com");
    hist.visit("google.com");
    hist.visit("facebook.com");
    hist.visit("youtube.com");
    printf("back     --> [%s]\n", hist.back(1).c_str());
    printf("back     --> [%s]\n", hist.back(1).c_str());
    printf("forward  --> [%s]\n", hist.forward(1).c_str());
    hist.visit("linkedin.com");
    printf("forward  --> [%s]\n", hist.forward(2).c_str());
    printf("back     --> [%s]\n", hist.back(2).c_str());
    printf("back     --> [%s]\n", hist.back(7).c_str());
}


int main() {
    test_stack();
    test_array();

    return 0;
}
