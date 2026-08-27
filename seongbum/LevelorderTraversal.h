//102. Binary Tree Level Order Traversal
//https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //리턴할 결과값
        vector<vector<int>> result;
        //노드 담을 큐
        std::queue<TreeNode*> queue;
        TreeNode* current = root;
        //루트 노드 큐에 push 후 순회 시작
        queue.push(current);
        while (!queue.empty())
        {
            //현재 큐 사이즈를 저장. 
            int queueSize = queue.size();
            //같은 depth의 노드 값을 담을 배열
            vector<int> temp;

            for (int i = 0; i < queueSize; i++)
            {
                //현재 노드 방문
                current = queue.front();
                queue.pop();
                if (current)
                {
                    //현재 노드가 존재할 때 val값 temp에 push
                    temp.push_back(current->val);
                    //현재 노드가 왼쪽 자식 노드가 있으면 자식 노드를 큐에 push (왼쪽 ->오른쪽 순으로 진행)
                    if (current->left)
                    {
                        queue.push(current->left);
                    }
                    //오른쪽도 진행
                    if (current->right)
                    {
                        queue.push(current->right);
                    }
                }
                else
                {
                    return {};
                }
            }
            //현재 depth 모두 끝나면 배열에 push
            result.push_back(temp);
        }
        return result;
    }
};