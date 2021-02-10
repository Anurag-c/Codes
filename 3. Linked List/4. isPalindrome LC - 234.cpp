ListNode *middle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

bool isPalindrome(ListNode* head) 
{
    if(head == NULL || head->next == NULL) return true;

    ListNode *firstStart = head;
    ListNode *mid = middle(head);
    ListNode *secondStart = reverse(mid->next);
    mid->next = NULL; // doesnt make any difference just for easy dry run
    
    ListNode *p1 = firstStart, *p2 = secondStart;
    bool ans = true;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1 -> val != p2 -> val) 
        {
            ans = false; 
            break; // we can return false but to revert changes on LL we used break
        }
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    mid->next = reverse(secondStart); //revert back changes
    return ans;
}