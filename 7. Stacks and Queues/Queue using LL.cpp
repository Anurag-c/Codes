#include<iostream>
using namespace std;

class queue
{
    class Node
    {
        public :
        int data;
        Node* next;
        
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

    int noOfElements;
    Node* head = NULL;
    Node* tail = NULL;

    void addLast(int x)
    {
        Node* ne = new Node(x);
        if(head == NULL)
            head = tail = ne;
        else
        {
            tail->next = ne;
            tail = ne;
        }
        this->noOfElements++;
    }

    int removeFirst()
    {
        Node* top = head;
        if(top == tail)
            head = tail = NULL;
        else
            head = top->next;
        
        top->next = NULL;
        int ans = top->data;
        delete(top);
        this->noOfElements--;
        return ans;
    }

    public:

        queue()
        {
            this->noOfElements = 0;
        }

        void push(int x)
        {
            this->addLast(x);
        }

        int pop()
        {
            int ans = -1;
            if(empty())
                cout<<"Queue is Empty ";
            else
                ans = this->removeFirst();
            
            return ans;
        }

        int front()
        {
            int ans = -1;
            if(empty())
                cout<<"Queue is Empty ";
            else
                ans = head->data;
            
            return ans;
        }

        bool empty()
        {
            return head == NULL;
        }

        int size()
        {
            return this->noOfElements;
        }
};

int main()
{
    queue q;
    for(int i = 0; i < 10; i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        cout<<q.size()<<" ";
        cout<<q.pop()<<" ";
        cout<<q.front()<<"\n";
    }
    cout<<q.size()<<" ";
    cout<<q.pop()<<" ";
    cout<<q.front()<<"\n";
}

