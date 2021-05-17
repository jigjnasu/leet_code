/*
  Leetcode.com
  Problem No: 109
  Problem: Convert Sorted List to Binary Search Tree
  Author: cpp.rakesh@gmail.com
  Date: 17/05/2021
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
    TreeNode* sortedListToBST(ListNode* head) {
        std::vector<int> v;
        while (head) {
            v.emplace_back(head->val);
            head = head->next;
        }
        return build(v, 0, static_cast<int>(v.size()) - 1);
    }

    ListNode* push_back(ListNode* head, int val) {
        if (head == nullptr)
            head = new ListNode(val);
        else {
            ListNode* node = head;
            while (node->next)
                node = node->next;
            node->next = new ListNode(val);
        }
        return head;
    }

    void traverse_list(ListNode* node) {
        printf("-----------------------------------------------------------------------\n");
        printf("                        list traversal\n");
        while (node) {
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n-----------------------------------------------------------------------\n");
    }

    void bfs(TreeNode* node) {
        if (node == nullptr)
            return;
        printf("-----------------------------------------------------------------------\n");
        printf("                        level order traversal\n");
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
        printf("-----------------------------------------------------------------------\n");
    }

private:
    TreeNode* build(const std::vector<int>& v, int s, int e) {
        if (s > e)
            return nullptr;
        const int mid = (s+e) >> 1;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = build(v, s, mid-1);
        root->right = build(v, mid+1, e);
        return root;
    }
};

int main() {
    Solution s;
    ListNode* head = nullptr;
    for (int i = 0; i <= 200; i += 10)
        head = s.push_back(head, i);
    s.traverse_list(head);
    s.bfs(s.sortedListToBST(head));

    return 0;
}
