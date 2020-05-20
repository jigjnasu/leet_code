/*
  LeetCode.com
  Problem No: 700
  Problem: Search in a binary tree
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 13/08/2019
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Solution() : m_root(nullptr) {}

    TreeNode* searchBST(TreeNode* root, int val) {
        while (1) {
            if (root == nullptr ||
                root->val == val)
                return root;
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
    }

    void insert(int x) {
        TreeNode* node = new TreeNode(x);
        if (m_root == nullptr) {
            m_root = node;
        } else {
            TreeNode* cur = m_root;

            while (1) {
                if (x < cur->val) {
                    if (cur->left == nullptr) {
                        cur->left = node;
                        break;
                    } else {
                        cur = cur->left;
                    }
                } else if (x > cur->val) {
                    if (cur->right == nullptr) {
                        cur->right = node;
                        break;
                    } else {
                        cur = cur->right;
                    }
                } else {
                    break;
                }
            }
        }
    }

    void level() const {
        printf("--------------------------------------------\n");
        map<int, vector<int>> m;
        m_level(m_root, m, 0);
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (const auto& x : it->second)
                printf("%d ", x);
            printf("\n");
        }
        printf("--------------------------------------------\n");
    }

    TreeNode* root() const {
        return m_root;
    }

private:
    void m_level(TreeNode* node, map<int, vector<int>>& m, int level) const {
        if (node != nullptr) {
            m[level].push_back(node->val);
            m_level(node->left, m, level + 1);
            m_level(node->right, m, level + 1);
        }
    }

    TreeNode* m_root;
};

int main() {
    Solution s;
    s.insert(100);
    s.insert(50);
    s.insert(200);
    s.insert(25);
    s.insert(40);
    s.insert(1);
    s.insert(98);

    s.level();

    TreeNode* node = s.searchBST(s.root(), 50);
    if (node->left != nullptr)
        printf("%d ", node->left->val);
    if (node != nullptr)
        printf("%d ", node->val);
    if (node->right != nullptr)
        printf("%d\n", node->right->val);


    return 0;
}
