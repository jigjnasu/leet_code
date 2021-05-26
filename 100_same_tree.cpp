/*
  LeetCode.com
  Problem No: 98
  Problem: Validate Binary Search Tree
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 26/05/2021
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
    printf("-------------------------------------------------------\n");
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
    printf("-------------------------------------------------------\n");
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};

void test_1() {
    TreeNode* p = nullptr;
    p = insert(p, 100);
    p = insert(p, 50);
    p = insert(p, 150);
    p = insert(p, 25);
    p = insert(p, 75);
    p = insert(p, 125);
    p = insert(p, 175);
    p = insert(p, 20);
    p = insert(p, 10);
    p = insert(p, 5);
    p = insert(p, 1);
    bfs(p);

    TreeNode* q = nullptr;
    q = insert(q, 100);
    q = insert(q, 50);
    q = insert(q, 150);
    q = insert(q, 25);
    q = insert(q, 75);
    q = insert(q, 175);
    q = insert(q, 20);
    q = insert(q, 10);
    q = insert(q, 5);
    q = insert(q, 1);
    bfs(q);
    Solution s;
    printf("%d\n", s.isSameTree(p, q));
}

int main() {
    test_1();

    return 0;
}
