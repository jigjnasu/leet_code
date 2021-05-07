/*
  LeetCode.com
  Problem Number: 104
  Problem : Maximum Depth of Binary Tree
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 07/05/2021
 */

#include <bits/stdc++.h>

struct TreeNode {
    TreeNode() {}
    TreeNode(int v) : val(v) {}
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

    void bfs(TreeNode* node) {
        printf("----------------------------------------------------\n");
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
        printf("----------------------------------------------------\n");
    }

    int maxDepth(TreeNode* root) {
        if (root) {
            return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
        }
        return 0;
    }
};

int main() {
    Solution s;
    TreeNode* root = nullptr;
    root = s.insert(root, 100);
    root = s.insert(root, 50);
    root = s.insert(root, 150);
    root = s.insert(root, 20);
    root = s.insert(root, 60);
    root = s.insert(root, 120);
    root = s.insert(root, 200);
    root = s.insert(root, 10);
    root = s.insert(root, 250);
    root = s.insert(root, 5);
    s.bfs(root);
    printf("maximum depth == [%d]\n", s.maxDepth(root));

    return 0;
}
