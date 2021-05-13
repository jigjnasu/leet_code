/*
  Leetcode.com
  Problem No : 379
  Problem : Find a Corresponding Node of a Binary Tree in a Clone of That Tree
  Author : cpp.rakesh@gmail.com
  Date: 13/05/2021
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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr)
            return nullptr;
        if (original == target)
            return cloned;
        TreeNode* l = getTargetCopy(original->left, cloned->left, target);
        TreeNode* r = getTargetCopy(original->right, cloned->right, target);
        TreeNode* res = nullptr;
        if (l) res = l;
        if (r) res = r;
        return res;
    }

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

    TreeNode* clone(TreeNode* original, TreeNode* cloned) {
        std::vector<int> elements;
        std::queue<TreeNode*> q;
        q.push(original);
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                original = q.front(); q.pop();
                elements.emplace_back(original->val);
                if (original->left) q.push(original->left);
                if (original->right) q.push(original->right);
            }
        }
        for (int e : elements)
            cloned = insert(cloned, e);
        return cloned;
    }

    void bfs(TreeNode* node) {
        printf("------------------------------------------------------------\n");
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
        printf("------------------------------------------------------------\n");
    }
};

int main() {
    Solution s;
    TreeNode* root = nullptr;
    root = s.insert(root, 100);
    root = s.insert(root, 50);
    root = s.insert(root, 150);
    root = s.insert(root, 40);
    root = s.insert(root, 60);
    root = s.insert(root, 140);
    root = s.insert(root, 160);
    root = s.insert(root, 20);
    root = s.insert(root, 10);
    root = s.insert(root, 5);
    root = s.insert(root, 200);
    root = s.insert(root, 170);
    s.bfs(root);

    TreeNode* cloned = nullptr;
    cloned = s.clone(root, cloned);
    s.bfs(cloned);

    TreeNode* target = root;
    target = target->right->right;
    TreeNode* cloned_target = s.getTargetCopy(root, cloned, target);
    s.bfs(cloned_target);

    return 0;
}
