
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        ListNode* newList = new ListNode();
//        while (list1 && list2)
//        {
//            if (list1->val < list2->val)
//            {
//                // 1이 2보다 작으면 1먼저 삽입.
//                newList->val = list1->val;
//                list1 = list1->next;
//            }
//            else
//            {
//                newList->val = list2->val;
//                list2 = list2->next;
//            }
//            newList = newList->next;
//        }
//
//        return newList;
//    }
//};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 리턴할헤드
        ListNode* head = new ListNode();
        // 주소옮겨가며 값 변경할 포인터
        ListNode* current = head;

        // if(!list1 && !list2) head = nullptr;
        // list1/2 둘 다 맨 끝까지 이동하면서 null이 아닐 때만
        while (list1 && list2)
        {
            // 1이 2보다 작으면 1먼저 삽입
            if (list1->val < list2->val)
            {
                // if(head->val == 0)
                // {
                //     head->val = list1->val;
                //     list1 = list1->next;

                //     continue;
                // }

                //새변수선언
                current->next = new ListNode(list1->val);
                //다음 list1값 가리키기
                list1 = list1->next;

            }
            else // 2가 더 작으면 2먼저삽입
            {
                // if(head->val == 0) 
                // {
                //     head->val = list2->val;
                //     list2 = list2->next;

                //     continue;
                // }
                current->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            // 다음 연결된 노드로 ㄱㄱ
            current = current->next;
        }
        // 마지막에 한쪽이 null이 되어서 끝났다면 남은 list붙여줘야함
        // 1이 null아니다-> list1붙이기
        current->next = list1 ? list1 : list2;

        // 맨첨에 current = head 해서 연결했으니까 head->next해서 붙이기
        return head->next;
    }

};