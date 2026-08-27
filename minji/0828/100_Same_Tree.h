#pragma once

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //둘 다 null이면 맞음
        if (!q && !p) return true;
        // 하나만 null이 되면 틀림
        if ((p && !q) || (!p && q)) return false;
        // 둘이 값 틀리면 틀림
        if (p->val != q->val) return false;

        // 전위 순회하여 노드 검사.
        // 전위 순회: 왼쪽 노드 검사 -> 오른쪽 노드 검사(재귀)
        if (!isSameTree(p->left, q->left))
            return false;

        if (!isSameTree(p->right, q->right))
            return false;

        return true;
    }
};
