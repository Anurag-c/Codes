
// Link : https://www.interviewbit.com/problems/remove-nth-node-from-list-end/
ListNode* Solution::removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* second = dummy;
    ListNode* first = head;
    for(int i = 1 ; i < n + 1 || first != NULL; i++)
    {
        if(first == NULL && i < n + 1) break; // if given N is greater than length
        first = first->next;
        if(i >= n + 1) second = second->next;
    }
    second->next = second->next->next;
    return dummy->next;
}