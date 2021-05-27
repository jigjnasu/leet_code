/*
  Leetcode.com
  Problem No: 146
  Problem: LRU Cache
  Author: cpp.rakesh@gmail.com
  Date: 27/05/2021
*/

#include <bits/stdc++.h>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = kv_map.find(key);
        if (it == kv_map.end())
            return -1;
        update(key);
        return kv_map[key];
    }

    void put(int key, int value) {
        auto it = kv_map.find(key);
        if (it == kv_map.end()) {
            if (capacity == static_cast<int>(kv_map.size()))
                erase();
            insert(key);
        } else
            update(key);
        kv_map[key] = value;
    }

private:
    std::unordered_map<int, int> kv_map;                      // key's value
    std::unordered_map<int, std::list<int>::iterator> it_map; // key's position in list
    std::list<int> list;                                      // holding the keys
    int capacity = 0;

    void update(int key) {
        list.erase(it_map[key]);
        list.push_front(key);
        it_map[key] = list.begin();
    }

    void insert(int key) {
        list.push_front(key);
        it_map[key] = list.begin();
    }

    void erase() {
        const int k = list.back();
        list.erase(it_map[k]);
        kv_map.erase(k);
        it_map.erase(k);
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    printf("%d\n", cache.get(1));
    cache.put(3, 3);
    printf("%d\n", cache.get(2));
    cache.put(4, 4);
    printf("%d\n", cache.get(1));
    printf("%d\n", cache.get(3));
    printf("%d\n", cache.get(4));

    return 0;
}
