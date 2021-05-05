/*
  LeetCode.com
  Problem Number: 1302
  Problem: Deepest Leaves Sum
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 02/04/2021
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

    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            sum = 0;
            for (int i = queue.size(); i > 0; --i) {
                TreeNode* node = queue.front(); queue.pop();
                sum += node->val;
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
        }
        return sum;
    }

    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        printf("%d ", node->val);
        inorder(node->right);
    }
};

int main() {
    Solution s;
    TreeNode* root = nullptr;
    root = s.insert(100, root);
    root = s.insert(50, root);
    root = s.insert(200, root);
    root = s.insert(10, root);
    root = s.insert(60, root);
    root = s.insert(1, root);
    root = s.insert(900, root);
    root = s.insert(140, root);
    root = s.insert(1000, root);
    s.inorder(root);
    printf("\n");
    printf("deppest sum == [%d]\n", s.deepestLeavesSum(root));
    return 0;
}
