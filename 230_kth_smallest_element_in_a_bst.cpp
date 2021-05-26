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
    printf("-------------------------------------------------------------\n");
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
    printf("-------------------------------------------------------------\n");
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        st.push(root);
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            --k;
            if (k == 0)
                break;
            root = root->right;
        }
        return root->val;
    }
};

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 150);
    root = insert(root, 25);
    root = insert(root, 75);
    root = insert(root, 125);
    root = insert(root, 175);
    bfs(root);
    Solution s;
    int k = 1;
    printf("smallest [%d] == [%d]\n", k, s.kthSmallest(root, k));
    k = 4;
    printf("smallest [%d] == [%d]\n", k, s.kthSmallest(root, k));

    return 0;
}
