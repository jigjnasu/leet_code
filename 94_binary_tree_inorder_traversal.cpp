/*
  LeetCode.com
  Problem No: 94
  Problem: Binary Tree Inorder Traversal
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

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (root) {
            std::stack<TreeNode*> st;
            while (root || !st.empty()) {
                while (root) {
                    st.push(root);
                    root = root->left;
                }
                root = st.top(); st.pop();
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

inline void print(const std::vector<int>& v) {
    printf("------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n------------------------------------------------\n");
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution s;
    print(s.inorderTraversal(root));

    return 0;
}
