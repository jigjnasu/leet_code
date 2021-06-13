/*
  Leetcode.com
  Problem No: 938
  Problem: Range Sum of BST
  Author: cpp.rakesh@gmail.com
  Date: 13/06/2021
*/

#include <bits/stdc++.h>

struct TreeNode {
    TreeNode() {}
    TreeNode(int val) : val(val) {}

    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr)
        root = new TreeNode(val);
    else {
        TreeNode* node = root;
        while (node) {
            if (val < node->val) {
                if (node->left == nullptr) {
                    node->left = new TreeNode(val);
                    break;
                } else
                    node = node->left;
            } else {
                if (node->right == nullptr) {
                    node->right = new TreeNode(val);
                    break;
                } else
                    node = node->right;
            }
        }
    }
    return root;
}

void bfs(TreeNode* node) {
    printf("--------------------------------------------------------\n");
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
    printf("--------------------------------------------------------\n");
}

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;
        if (root->val < low) return rangeSumBST(root->right, low, high);
        if (root->val > high) return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 150);
    root = insert(root, 20);
    root = insert(root, 200);
    bfs(root);

    Solution s;
    printf("sum == [%d]\n", s.rangeSumBST(root, 50, 150));

    return 0;
}
