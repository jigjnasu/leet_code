/*
  LeetCode.com
  Problem No: 1038
  Problem: Binary Search Tree to Greater Sum Tree
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 16/06/2021
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

void bfs(TreeNode* root) {
    printf("--------------------------------------\n");
    if (root) {
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                root = q.front(); q.pop();
                printf("%d ", root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            printf("\n");
        }
    }
    printf("--------------------------------------\n");
}

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root->right) bstToGst(root->right);
        sum = root->val = sum + root->val;
        if (root->left) bstToGst(root->left);
        return root;
    }
private:
    int sum = 0;
};

inline void test_1() {
    TreeNode* root = nullptr;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 150);
    root = insert(root, 25);
    root = insert(root, 125);
    root = insert(root, 75);
    root = insert(root, 175);
    bfs(root);

    Solution s;
    root = s.bstToGst(root);
    bfs(root);
}

inline void test_2() {
    TreeNode* root = nullptr;
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 0);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 8);
    bfs(root);
    Solution s;
    root = s.bstToGst(root);
    bfs(root);
}

int main() {
    //test_1();
    test_2();

    return 0;
}
