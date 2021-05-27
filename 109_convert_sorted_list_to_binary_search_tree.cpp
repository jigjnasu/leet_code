/*
  Leetcode.com
  Problem No: 109
  Problem: Convert Sorted List to Binary Search Tree
  Author: cpp.rakesh@gmail.com
  Date: 27/05/2021
*/

#include <bits/stdc++.h>

struct ListNode {
    ListNode() {}
    ListNode(int val) : val(val) {}

    int val = 0;
    ListNode* next = nullptr;
};

struct TreeNode {
    TreeNode() {}
    TreeNode(int val) : val(val) {}

    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {}
    TreeNode* sortedVectorToBST(const std::vector<int>& v) {
        return buildFromVec(v, 0, v.size() - 1);
    }

private:
    TreeNode* buildFromVec(const std::vector<int>& v, int s, int e) {
        if (s > e)
            return nullptr;
        const int mid = (s+e) >> 1;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildFromVec(v, s, mid-1);
        root->right = buildFromVec(v, mid+1, e);
        return root;
    }
};

void preorder(TreeNode* node) {
    if (node == nullptr)
        return;
    printf("%d ", node->val);
    preorder(node->left);
    preorder(node->right);
}

void inorder(TreeNode* node) {
    if (node == nullptr)
        return;
    inorder(node->left);
    printf("%d ", node->val);
    inorder(node->right);
}

void postorder(TreeNode* node) {
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->val);
}

void bfs(TreeNode* node) {
    printf("-----------------------------------------------\n");
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
    printf("\n-----------------------------------------------\n");
}

void test_vec() {
    std::vector<int> v;
    for (int i = 0; i <= 20; ++i)
        v.emplace_back(i);
    Solution s;
    TreeNode* node = s.sortedVectorToBST(v);
    inorder(node); printf("\n");
    bfs(node);
}

int main() {
    test_vec();

    return 0;
}
