/*
  Leetcode.com
  Problem No : 705
  Problem : Design HashSet
  Author : cpp.rakesh@gmail.com
  Date: 19/04/2021
*/

#include <bits/stdc++.h>

class MyHashSet {
public:
    MyHashSet() {
        table = std::vector<int>(bucket, -1);
        status = std::vector<bool>(bucket, false);
    }

    void add(int key) {
        if (!contains(key)) {
            const int h1 = hash1(key);
            if (!status[h1]) {
                table[h1] = key;
                status[h1] = true;
            } else {
                const int offset = hash2(key);
                int i = (h1 + offset) % bucket;
                while (status[i])
                    i = (i + offset) % bucket;
                table[i] = key;
                status[i] = true;
            }
            ++size;
            if (percentage() >= 0.75)
                rehash();
        }
    }

    void remove(int key) {
        if (contains(key)) {
            const int h1 = hash1(key);
            if (table[h1] == key) {
                table[h1] = 0;
                status[h1] = false;
            } else {
                const int offset = hash2(key);
                int i = (h1 + offset) % bucket;
                while (1) {
                    if (table[i] == key) {
                        table[i] = -1;
                        status[i] = false;
                        break;
                    }
                    i = (i + offset) % bucket;
                }
            }
            --size;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        bool exist = false;
        const int h1 = hash1(key);
        if (table[h1] == key) {
            exist = true;
        } else {
            if (status[h1]) {
                const int offset = hash2(key);
                int i = (h1 + offset) % bucket;
                while (1) {
                    if (!status[i])
                        break;
                    if (table[i] == key) {
                        exist = true;
                        break;
                    }
                    i = (i + offset) % bucket;
                }
            }
        }
        return exist;
    }

private:
    int bucket = 100009;
    std::vector<int> table;
    std::vector<bool> status;
    int size = 0, pi = 0;

    const std::vector<int> primes = {503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709};

    int hash1(int key) const {
        return key % bucket;
    }

    int hash2(int key) const {
        return primes[pi] - (key % bucket);
    }

    double percentage() const {
        return size / static_cast<double>(bucket);
    }

    void rehash() {
        size = 0; ++pi; bucket = static_cast<int>(table.size()) * 3;
        if (pi >= primes.size())
            --pi;
        std::vector<int> t = table;
        std::vector<bool> s = status;
        table = std::vector<int>(bucket, -1);
        status = std::vector<bool>(bucket, false);
        for (std::size_t i = 0; i < t.size(); ++i)
            if (s[i])
                add(t[i]);
    }
};

int main() {
    MyHashSet h;
    h.add(1);      // set = [1]
    h.add(2);      // set = [1, 2]
    printf("[%d] there == [%d]\n", 1, h.contains(1)); // return True
    printf("[%d] there == [%d]\n", 3, h.contains(3)); // return False, (not found)
    h.add(2);      // set = [1, 2]
    printf("[%d] there == [%d]\n", 2, h.contains(2)); // return True
    h.remove(2);   // set = [1]
    printf("[%d] there == [%d]\n", 2, h.contains(2)); // return False, (already removed)

    return 0;
}
