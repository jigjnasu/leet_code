/*
  Leetcode.com
  Problem No: 1008
  Problem: Construct Binary Search Tree from Preorder Traversal
  Author: cpp.rakesh@gmail.com
  Date: 12/05/2021
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
    TreeNode* add(TreeNode* root, int val) {
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
        printf("-----------------------------------------------------------\n");
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
        printf("-----------------------------------------------------------\n");
    }

    void pre_order(TreeNode* node, std::vector<int>& v) {
        if (node == nullptr)
            return;
        v.emplace_back(node->val);
        pre_order(node->left, v);
        pre_order(node->right, v);
    }

    TreeNode* bstFromPreorder(std::vector<int>& preorder, int upper_bound = INT_MAX) {
        if (iter == static_cast<int>(preorder.size()) || preorder[iter] > upper_bound)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[iter++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, upper_bound);
        return root;
    }

private:
    int iter = 0;
};

int main() {
    Solution s;
    TreeNode* root = nullptr;
    root = s.add(root, 100);
    root = s.add(root, 50);
    root = s.add(root, 150);
    root = s.add(root, 20);
    root = s.add(root, 140);
    root = s.add(root, 160);
    root = s.add(root, 10);
    root = s.add(root, 5);
    root = s.add(root, 1);
    root = s.add(root, 155);
    root = s.add(root, 152);
    root = s.add(root, 200);
    root = s.add(root, 250);
    root = s.add(root, 300);
    s.bfs(root);

    std::vector<int> v;
    s.pre_order(root, v);
    printf("-----------------------------------------------------------\n");
    printf("          pre order traversal\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n-----------------------------------------------------------\n");
    TreeNode* root_from_pre_order = s.bstFromPreorder(v);
    s.bfs(root_from_pre_order);

    return 0;
}
