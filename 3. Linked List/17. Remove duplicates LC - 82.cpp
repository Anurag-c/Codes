ListNode* skip(ListNode* temp)
{
    while(temp->next != NULL && temp->val == temp->next->val)
        temp = temp->next;
    return temp->next;
}
ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* dummy = new ListNode(-1);
    ListNode* prev = dummy;
    ListNode* temp = head;
    while(temp != NULL)
    {
        if(temp->next != NULL && temp->val == temp->next->val) temp = skip(temp);
        else
        {
            prev->next = temp;
            prev = temp;
            temp = temp->next;
        }
    }
    prev->next = NULL;
    return dummy->next;
}