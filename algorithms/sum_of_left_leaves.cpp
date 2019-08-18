/*
  LeetCode.com
  Solution for sum of left leaves
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 19/08/2019
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root != nullptr) {
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                    if (node->left->left == nullptr &&
                        node->left->right == nullptr)
                        sum += node->left->val;
                }

                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return sum;
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
    s.insert(3);
    s.insert(9);
    s.insert(15);
    s.insert(7);

    s.level();

    printf("%d\n", s.sumOfLeftLeaves(s.root()));

    return 0;
}
