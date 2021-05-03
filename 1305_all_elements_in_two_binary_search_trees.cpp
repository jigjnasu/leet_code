/*
  Leetcode.com
  Problem No : 1305
  Problem : All Elements in Two Binary Search Trees
  Author : cpp.rakesh@gmail.com
  Date: 02/05/2021
*/

#include <bits/stdc++.h>

inline void print(const std::vector<int>& v) {
    printf("----------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n----------------------------------------------\n");
}

struct TreeNode {
    TreeNode() {}
    TreeNode(int v) : val(v) {}
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Solution {
public:
    TreeNode* insert(int val, TreeNode* root) {
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

    void traverse(TreeNode* node) {
        if (node == nullptr)
            return;
        traverse(node->left);
        printf("%d ", node->val);
        traverse(node->right);
    }

    std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> first;
        get(root1, first);
        std::vector<int> second;
        get(root2, second);
        std::vector<int> res;
        std::size_t i = 0, j = 0;
        while (i < first.size() && j < second.size())
            if (first[i] < second[j])
                res.emplace_back(first[i++]);
            else
                res.emplace_back(second[j++]);
        while (i < first.size())
            res.emplace_back(first[i++]);
        while (j < second.size())
            res.emplace_back(second[j++]);
        return res;
    }

private:

    void get(TreeNode* node, std::vector<int>& v) {
        if (node == nullptr)
            return;
        get(node->left, v);
        v.emplace_back(node->val);
        get(node->right, v);
    }
};


int main() {
    Solution s;
    TreeNode* root1 = nullptr;
    root1 = s.insert(100, root1);
    root1 = s.insert(50, root1);
    root1 = s.insert(300, root1);
    root1 = s.insert(10, root1);
    s.traverse(root1);
    printf("\n");
    TreeNode* root2 = nullptr;
    root2 = s.insert(1, root2);
    root2 = s.insert(2, root2);
    root2 = s.insert(3, root2);
    root2 = s.insert(4, root2);
    s.traverse(root2);
    printf("\n");
    print(s.getAllElements(root1, root2));

    return 0;
}
