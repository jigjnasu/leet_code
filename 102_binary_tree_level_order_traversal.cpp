/*
  Leetcode.com
  Problem No: 102
  Problem: Binary Tree Level Order Traversal
  Author: cpp.rakesh@gmail.com
  Date: 24/05/2021
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

    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root) {
            std::queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                std::vector<int> v;
                for (int i = static_cast<int>(q.size()); i > 0; --i) {
                    root = q.front(); q.pop();
                    v.emplace_back(root->val);
                    if (root->left) q.push(root->left);
                    if (root->right) q.push(root->right);
                }
                res.emplace_back(v);
            }
        }
        return res;
    }

    void print(const std::vector<std::vector<int>>& v) {
        printf("--------------------------------------------------------\n");
        for (const auto& r : v) {
            for (int e : r)
                printf("%d ", e);
            printf("\n");
        }
        printf("--------------------------------------------------------\n");
    }
};

int main() {
    Solution s;
    TreeNode* root = nullptr;
    root = s.insert(root, 100);
    root = s.insert(root, 50);
    root = s.insert(root, 25);
    root = s.insert(root, 175);
    root = s.insert(root, 140);
    root = s.insert(root, 155);
    s.print(s.levelOrder(root));

    return 0;
}

