/*
  LeetCode.com
  Problem No: 127
  Problem: Word Ladder
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 30/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graph(numCourses);
        buildGraph(graph, prerequisites);
        std::vector<int> visit(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (cyclic(i, graph, visit))
                return false;
        }
        return true;
    }

private:
    void buildGraph(std::vector<std::vector<int>>& graph, const std::vector<std::vector<int>>& prerequisites) {
        for (auto& p : prerequisites)
            graph[p[1]].emplace_back(p[0]);
    }

    bool cyclic(int node, const std::vector<std::vector<int>>& graph, std::vector<int>& visit) {
        if (visit[node] == 1)
            return true;
        if (visit[node] == 0) {
            visit[node] = 1;
            for (std::size_t i = 0; i < graph[node].size(); ++i)
                if (cyclic(graph[node][i], graph, visit))
                    return true;
        }
        visit[node] = 2;
        return false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> pre = {{1,0},{0,1}};
    printf("%s\n", s.canFinish(2, pre) ? "yes" : "no");

    pre = {{1,0}, {0,1}};
    printf("%s\n", s.canFinish(2, pre) ? "yes" : "no");

    return 0;
}
