struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        // head가 null일 경우 바로 종료
        if (!head) return head;

        // 다음값이 존재할때까지 반복.
        while (current->next)
        {
            // 값이 다르면 다음값으로 이동
            if (current->val != current->next->val)
            {
                current = current->next;
            }

            else
            {
                // 같은 값이라면 다른 값 만날때까지 다음 노드와 연결
                while (current->val == current->next->val)
                {
                    //다음다음노드가 null이아니면 담담노드와 연결(한칸건너뛰기)
                    if (current->next->next) {
                        current->next = current->next->next;
                    }
                    else //담담노드 null이면 다음노드 null로 만들고 끝
                    {
                        current->next = nullptr;
                        break;
                    }

                }
            }
        }
        return head;
    }
};