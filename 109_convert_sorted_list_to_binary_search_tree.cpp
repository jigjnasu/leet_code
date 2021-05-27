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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        return buildFromList(head, nullptr);
    }

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

    TreeNode* buildFromList(ListNode* head, ListNode* tail) {
        if (head == tail)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = buildFromList(head, slow);
        root->right = buildFromList(slow->next, tail);
        return root;
    }
};

/*
  List related functions
 */
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

void traverse(ListNode* head) {
    ListNode* node = head;
    printf("----------------------------------------------------\n");
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n----------------------------------------------------\n");
}

/*
  tree related functions
 */
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

void test_list() {
    ListNode* head = nullptr;
    for (int i = 0; i <= 20; ++i)
        head = push_back(head, i);
    traverse(head);

    Solution s;
    TreeNode* root = s.sortedListToBST(head);
    bfs(root);
}

int main() {
    //test_vec();
    test_list();

    return 0;
}
