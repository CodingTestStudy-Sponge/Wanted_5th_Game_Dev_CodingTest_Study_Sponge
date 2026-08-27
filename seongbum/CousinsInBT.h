//993. Cousins in Binary Tree
//https://leetcode.com/problems/cousins-in-binary-tree/description/

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
    bool isCousins(TreeNode* root, int x, int y) {
        std::queue<TreeNode*> queue;
        TreeNode* current = root;
        //depth 값 (같은 depth의 노드들 처리가 완료될때마다 1증가)
        int depth = 0;
        // x,y의 부모 노드 값과 depth 값
        int xParent;
        int yParent;
        int xDepth;
        int yDepth;
        
        queue.push(current);
        while (!queue.empty())
        {
            
            int queueSize = queue.size();

            for (int i = 0; i < queueSize; i++)
            {
                //현재 노드 방문
                current = queue.front();
                queue.pop();
                if (current)
                {
                    //현재 노드의 왼쪽 자식노드가 있으면
                    if (current->left)
                    {
                        queue.push(current->left);
                        //왼쪽 자식노드의 값이 x면 x의 부모값과 x값의 노드 depth 저장
                        if (current->left->val == x)
                        {
                            xParent = current->val;
                            xDepth = depth;
                        }
                        //왼쪽 자식노드의 값이 y면 y의 부모값과 y값의 노드 depth 저장
                        if (current->left->val == y)
                        {
                            yParent = current->val;
                            yDepth = depth;
                        }
                    }
                    //현재 노드의 왼쪽 자식노드가 있으면
                    if (current->right)
                    {
                        queue.push(current->right);
                        //오른쪽 자식노드의 값이 x면 x의 부모값과 x값의 노드 depth 저장
                        if (current->right->val == x)
                        {
                            xParent = current->val;
                            xDepth = depth;
                        }
                        //오른쪽 자식노드의 값이 y면 y의 부모값과 y값의 노드 depth 저장
                        if (current->right->val == y)
                        {
                            yParent = current->val;
                            yDepth = depth;
                        }
                    }
                }
                else
                {
                    return {};
                }
            }
            //같은 depth값 모두 처리했으면 depth값 1 증가
            ++depth;
        }
        //x와 y의 부모값이 다르고 x와 y의 depth 값이 같으면 true 리턴. 아니면 false 리턴
        if ((xParent != yParent) && (xDepth == yDepth))
        {
            return true;
        }
        else return false;
    }
};