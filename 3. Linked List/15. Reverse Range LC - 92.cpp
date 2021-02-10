class Solution
{
    ListNode* tempHead = NULL;
    ListNode* tempTail = NULL;
    
    void addFirst(ListNode* node)
    {
        if(tempHead == NULL) tempHead = tempTail = node;
        else
        {
            node->next = tempHead;
            tempHead = node;
        }
    }

    public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i = 1; i <= n; i++)
        {
            ListNode* forw = curr->next;
            if(i >= m)
            {
                curr->next = NULL;
                addFirst(curr);
            }
            else prev = curr;
            curr = forw;
        }
        tempTail->next = curr;
        (prev != NULL) ? prev->next = tempHead : head = tempHead; // cannot return tempHead as it is private
        return head;
    }
};