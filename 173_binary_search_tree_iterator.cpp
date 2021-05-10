/*
  Leetcode.com
  Problem No : 173
  Problem : Binary Search Tree Iterator
  Author : cpp.rakesh@gmail.com
  Date : 11/05/2021
*/

#include <bits/stdc++.h>

struct TreeNode {
    TreeNode() {}
    TreeNode(int v) : val(v) {}

    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class BST {
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
        printf("----------------------------------------------------------\n");
        std::queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                TreeNode* node = q.front(); q.pop();
                printf("%d ", node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            printf("\n");
        }
        printf("----------------------------------------------------------\n");
    }

    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        printf("%d ", node->val);
        inorder(node->right);
    }
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        int res = 0;
        if (hasNext())
            res = data[iter++];
        return res;
    }

    bool hasNext() {
        return iter < data.size();
    }

private:
    std::vector<int> data;
    std::size_t iter = 0;

    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        data.emplace_back(node->val);
        inorder(node->right);
    }
};

int main() {
    BST bst;
    TreeNode* root = nullptr;
    root = bst.insert(root, 7);
    root = bst.insert(root, 3);
    root = bst.insert(root, 15);
    root = bst.insert(root, 9);
    root = bst.insert(root, 20);
    bst.bfs(root);

    BSTIterator bsi(root);
    printf("%d\n", bsi.next());
    printf("%d\n", bsi.next());
    printf("%s\n", bsi.hasNext() ? "true" : "false");
    printf("%d\n", bsi.next());
    printf("%s\n", bsi.hasNext() ? "true" : "false");
    printf("%d\n", bsi.next());
    printf("%s\n", bsi.hasNext() ? "true" : "false");
    printf("%d\n", bsi.next());
    printf("%s\n", bsi.hasNext() ? "true" : "false");

    return 0;
}
