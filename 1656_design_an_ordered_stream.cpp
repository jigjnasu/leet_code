/*
  Leetcode.com
  Problem No : 1656
  Problem : Design an Ordered Stream
  Author : cpp.rakesh@gmail.com
  Date : 21/04/2021
*/

#include <bits/stdc++.h>

void print(const std::vector<std::string>& v) {
    printf("---------------------------------------\n");
    for (const std::string& s : v)
        printf("%s ", s.c_str());
    printf("\n---------------------------------------\n");
}


class OrderedStream {
public:
    OrderedStream(int n) {
        stream = std::vector<std::string>(n);
    }

    std::vector<std::string> insert(int key, std::string value) {
        stream[key - 1] = value;
        std::vector<std::string> res;
        while (iter < static_cast<int>(stream.size()) && !stream[iter].empty()) {
            res.emplace_back(stream[iter++]);
        }
        return res;
    }

private:
    std::vector<std::string> stream;
    int iter = 0;
};


int main() {
    OrderedStream os(5);
    print(os.insert(3, "ccc"));
    print(os.insert(1, "aaa"));
    print(os.insert(2, "bbb"));
    print(os.insert(5, "eee"));
    print(os.insert(4, "ddd"));

    return 0;
}
