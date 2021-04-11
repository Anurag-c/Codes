#include<iostream>
using namespace std;

class stack
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

    int size;
    Node* head = NULL;
    Node* tail = NULL;

    void addFirst(int x)
    {
        Node* ne = new Node(x);
        if(head == NULL)
            head = tail = ne;
        else
        {
            ne->next = head;
            head = ne;
        }
        this->size++;
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
        this->size--;
        return ans;
    }

    public:

        stack()
        {
            this->size = 0;
        }

        void push(int x)
        {
            this->addFirst(x);
        }

        int pop()
        {
            int ans = -1;
            if(empty())
                cout<<"Stack is Empty ";
            else
                ans = this->removeFirst();
            
            return ans;
        }

        bool empty()
        {
            return head == NULL;
        }
};

int main()
{
    stack st;
    for(int i = 0; i < 10; i++)
    {
        st.push(i);
    }
    while(!st.empty())
    {
        cout<<st.pop()<<"\n";
    }
    cout<<st.pop()<<"\n";
}

