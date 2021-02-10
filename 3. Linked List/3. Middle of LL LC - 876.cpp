ListNode* middleNode(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//even case choose (len-1/2)th node
ListNode* middleNode(ListNode* head) 
{
    if(head == NULL) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) // instead you can also start fast from head->next
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}