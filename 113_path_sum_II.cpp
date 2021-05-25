/*
  LeetCode.com
  Problem No: 113
  Problem: Path Sum II
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 25/05/2021
*/

#include <bits/stdc++.h>

struct TreeNode {
    TreeNode() {}
    TreeNode(int val) : val(val) {}

    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<std::vector<int>> res;
        std::vector<int> list;
        backtrack(root, targetSum, res, list);
        return res;
    }

private:
    void backtrack(TreeNode* node, int targetSum, std::vector<std::vector<int>>& res, std::vector<int>& list) {
        if (node == nullptr)
            return;
        list.emplace_back(node->val);
        if (node->val == targetSum && node->left == nullptr && node->right == nullptr)
            res.emplace_back(list);
        backtrack(node->left, targetSum - node->val, res, list);
        backtrack(node->right, targetSum - node->val, res, list);
        list.pop_back();
    }
};

void bfs(TreeNode* node) {
    printf("------------------------------------------------------\n");
    if (node) {
        std::queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                node = q.front(); q.pop();
                printf("%d ", node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            printf("\n");
        }
    }
    printf("------------------------------------------------------\n");
}

inline void print_2d(const std::vector<std::vector<int>>& vec) {
    printf("------------------------------------------------------\n");
    for (const auto& v : vec) {
        for (int e : v)
            printf("%d ", e);
        printf("\n");
    }
    printf("------------------------------------------------------\n");
}

int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    bfs(root);
    print_2d(s.pathSum(root, 22));

    return 0;
}
