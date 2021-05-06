/*
  LeetCode.com
  Problem Number: 1315
  Problem: Sum of Nodes with Even-Valued Grandparent
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
        printf("------------------------------------------------\n");
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
        printf("------------------------------------------------\n");
    }

    int sumEvenGrandparent(TreeNode* node, int parent = 1, int grand_parent = 1) {
        if (node) {
            return sumEvenGrandparent(node->left, node->val, parent) +
                sumEvenGrandparent(node->right, node->val, parent) +
                (grand_parent & 1 ? 0 : node->val);
        }
        return 0;
    }

private:
    int grandchild(TreeNode* node) {
        int res = 0;
        if (node->left) {
            if (node->left->left)
                res += node->left->left->val;
            if (node->left->right)
                res += node->left->right->val;
        }
        if (node->right) {
            if (node->right->left)
                res += node->right->left->val;
            if (node->right->right)
                res += node->right->right->val;
        }
        return res;
    }
};

int main() {
    Solution s;
    TreeNode* root = nullptr;
    root = s.insert(root, 100);
    root = s.insert(root, 50);
    root = s.insert(root, 150);
    root = s.insert(root, 30);
    root = s.insert(root, 70);
    root = s.insert(root, 140);
    root = s.insert(root, 200);
    root = s.insert(root, 2);
    root = s.insert(root, 250);
    s.bfs(root);
    printf("sum of even grand parent == [%d]\n", s.sumEvenGrandparent(root));

    return 0;
}
