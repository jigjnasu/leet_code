/*
  Solution for Assign Cookies from Leet Code
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 25th, Nov 2016
 */

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
    
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        std::size_t i = 0;
        std::size_t j = 0;
        int max = 0;
        while (i < g.size() && j < s.size()) {
            if (s[i] >= g[j]) {
                ++max;
                ++i;
            }
            ++j;
        }
        
        return max;
    }
};


int main() {
    int G[] = {250,490,328,149,495,325,314,360,333,418,430,458};
    int S[] = {376,71,228,110,215,410,363,135,508,268,494,288,24,362,20,5,247,118,152,393,458,354,201,188,425,167,220,114,148,43,403,385,51};

    std::vector<int> g(G, G + sizeof(G) / sizeof(G[0]));
    std::vector<int> s(S, S + sizeof(S) / sizeof(S[0]));

    Solution sol;
    printf("[%d]\n", sol.findContentChildren(g, s));
    
    return 0;
}
