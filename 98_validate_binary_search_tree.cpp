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
    printf("---------------------------------------------\n");
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
    printf("---------------------------------------------\n");
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
            return true;
        TreeNode* prev = nullptr;
        std::stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if (prev && root->val <= prev->val)
                return false;
            prev = root;
            root = root->right;
        }
        return true;
    }
};

void test_1() {
    TreeNode* root = nullptr;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 150);
    root = insert(root, 25);
    root = insert(root, 75);
    root = insert(root, 125);
    root = insert(root, 175);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 1);
    bfs(root);
    Solution s;
    printf("%d\n", s.isValidBST(root));
}

void test_2() {
    TreeNode* root = new TreeNode(14);
    root->left = new TreeNode(8);
    root->right = new TreeNode(1);
    bfs(root);
    Solution s;
    printf("%d\n", s.isValidBST(root));
}

int main() {
    test_1();
    test_2();

    return 0;
}
