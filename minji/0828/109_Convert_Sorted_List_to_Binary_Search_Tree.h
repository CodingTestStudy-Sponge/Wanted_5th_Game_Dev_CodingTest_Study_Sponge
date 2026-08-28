/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void MiddleRecursive(TreeNode*& node, vector<int>& v) 
    {
        // 중간값 만들어서 노드 삽입
        int middle = v.size() / 2;
        node = new TreeNode(v[middle]);

        // 총배열에서 왼쪽벡터 / 오른쪽벡터 구분
        vector<int> leftVec;
        for (int i = 0; i < middle; i++)
            leftVec.push_back(v[i]);

        vector<int> rightVec;
        for (int i = middle + 1; i < v.size(); i++)
            rightVec.push_back(v[i]);

        // 왼쪽 정렬 ㄱㄱ
        if (leftVec.size() > 0)
            MiddleRecursive(node->left, leftVec);
        else return;

        // 오른쪽 정렬 ㄱㄱ
        if (rightVec.size() > 0)
            MiddleRecursive(node->right, rightVec);
        else return;

    }

    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* tree;
        // 예외처리(null일때, next가 null일때)
        if (!head) return nullptr;

        if (!head->next)
        {
            tree = new TreeNode(head->val);
            return tree;
        }

        // head 중간값 구하기: 연결리스트 순회
        ListNode* current = head;
        vector<int> v;
        // 중간 값 구하기
        while (current)
        {
            // 연결리스트값을 벡터에넣어ㅓ버리기
            v.push_back(current->val);
            current = current->next;
        }
        // 중간값 재귀 ㄱㄱ
        MiddleRecursive(tree, v);
        return tree;
    }
};
