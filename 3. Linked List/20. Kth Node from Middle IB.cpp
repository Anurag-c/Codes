int Solution::solve(ListNode* head, int n) 
{
    int c = 1;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        c++;
    }
    if(n >= c) return -1;
    
    int travel = (c - n);
    ListNode* ans = head;
    for(int i = 1; i < travel; i++) ans = ans->next;
    return ans->val;
}