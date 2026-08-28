#pragma once
/*
LeetCode.206 Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:
Input: head = [1,2]
Output: [2,1]
Example 3:
Input: head = []
Output: []
*/


/*struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
*/

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* current = head;
        ListNode* previous = nullptr;

        while (current != nullptr)
        {
            // 다음 노드 기억.
            ListNode* remember = current->next;

            // 현재 노드의 next를 previous로 변경.
            current->next = previous;

            // previous를 current로 이동.
            previous = current;

            // current를 다음 노드로 이동.
            current = remember;
        }

        // 새로운 head 반환.
        return previous;
    }
};
