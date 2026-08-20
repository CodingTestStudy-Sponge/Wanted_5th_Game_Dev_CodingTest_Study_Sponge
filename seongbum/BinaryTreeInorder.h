#pragma once
#include <vector>
using namespace std;
//94.Binary Tree Inorder Traversal
//https://leetcode.com/problems/binary-tree-inorder-traversal/description/?envType=problem-list-v2&envId=depth-first-search

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer = {};
        //root가 nullptr일 경우 그대로 answer 리턴
        if (root == nullptr)
        {
            return answer;
        }
        //TreeNode 포인터 담을 스택
        stack<TreeNode*> stack;

        TreeNode* current = root;
        //current가 nullptr이 아니고 stack이 안 빌 때까지
        while (current != nullptr || !stack.empty())
        {
            //먼저 왼쪽부터 스택에 push
            while (current != nullptr)
            {
                stack.push(current);
                current = current->left;
            }
            //왼쪽 다 채웠으면 현재 최상위 노드를 current에 저장하고 pop
            current = stack.top();
            stack.pop();
            //그 최상위 노드를 answer에 push
            answer.push_back(current->val);
            //오른쪽 트리로 이동
            current = current->right;
        }
        //위 과정을 반복하면 중위 순회 완료
        return answer;
    }
};