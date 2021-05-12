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
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (int e : preorder)
            root = insert(root, e);
        return root;
    }

    void bfs(TreeNode* node) {
        printf("--------------------------------------------------\n");
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
        printf("--------------------------------------------------\n");
    }

private:
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
};

int main() {
    Solution s;
    std::vector<int> v1 = {8,5,1,7,10,12};
    s.bfs(s.bstFromPreorder(v1));

    std::vector<int> v2 = {1, 3};
    s.bfs(s.bstFromPreorder(v2));

    return 0;
}
