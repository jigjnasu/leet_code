/*
  LeetCode.com
  Problem No: 101
  Problem: Symmetric Tree
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

void bfs(TreeNode* node) {
    printf("----------------------------------------------------\n");
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
    printf("----------------------------------------------------\n");
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return symmetric(root->left, root->right);
    }

    bool isSymmetric_iter(TreeNode* root) {
        if (root == nullptr)
            return true;
        std::queue<TreeNode*> queue;
        queue.push(root->left);
        queue.push(root->right);
        while (!queue.empty()) {
            TreeNode* p = queue.front(); queue.pop();
            TreeNode* q = queue.front(); queue.pop();
            if (p == nullptr && q ==nullptr)
                continue;
            if (p == nullptr || q == nullptr)
                return false;
            if (p->val != q->val)
                return false;
            queue.push(p->left);
            queue.push(q->right);
            queue.push(p->right);
            queue.push(q->left);
        }
        return true;
    }

private:
    bool symmetric(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        return p->val == q->val && symmetric(p->left, q->right) && symmetric(p->right, q->left);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    bfs(root);

    Solution s;
    printf("%d %d\n", s.isSymmetric(root), s.isSymmetric_iter(root));

    return 0;
}
