/*
  LeetCode.com
  Problem No: 543
  Problem: Diameter of Binary Tree
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 02/06/2021
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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(root, d);
        return d;
    }
private:
    int height(TreeNode* node, int& d) {
        if (node == nullptr) return 0;
        int lh = height(node->left, d);
        int rh = height(node->right, d);
        d = std::max(d, lh+rh);
        return std::max(lh, rh) + 1;
    }
};

inline void bfs(TreeNode* node) {
    printf("------------------------------------------------------------\n");
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
    printf("------------------------------------------------------------\n");
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    bfs(root1);

    Solution s;
    printf("%d\n", s.diameterOfBinaryTree(root1));

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    bfs(root2);
    printf("%d\n", s.diameterOfBinaryTree(root2));

    return 0;
}

