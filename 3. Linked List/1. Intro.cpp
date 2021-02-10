#include<iostream>
using namespace std;

class LinkedList
{
    private: 
    class Node
    {
        public:
        int val;
        Node* next = NULL;
        
        Node(int val)
        {
            this->val = val;
        }
    };

    Node* head = NULL;
    int numberOfNodes = 0;

    void handleAddidxZero(Node* node)
    {
        node->next = head;
        this->head = node;
        this->numberOfNodes++;
    }

    void handleRemoveidxZero()
    {
        Node* temp = this->head;
        this->head = this->head->next;
        temp->next = NULL;
        this->numberOfNodes--;
    }

    Node* getNodeAt(int idx)
    {
        Node* temp = head;
        while(idx--) temp = temp->next;
        return temp;
    }

    void addNodeAt(Node* node, int idx)
    {
        if(idx < 0 || idx > size()) cout<<"Invalid Index\n";
        else if(idx == 0) handleAddidxZero(node);
        else 
        {
            Node* nodeAt = getNodeAt(idx - 1);
            Node* forw = nodeAt->next;
            nodeAt->next = node;
            node->next = forw;
            this->numberOfNodes++;
        }
    }

    void removeNodeAt(int idx)
    {
        if(idx < 0 || idx >= size()) cout<<"invalid Index\n";
        else if(idx == 0) handleRemoveidxZero();
        else
        {
            Node* before = getNodeAt(idx - 1);
            Node* delNode = before->next;
            before->next = delNode->next;
            delNode->next = NULL;
            this->numberOfNodes--;
        }
    }

    void display()
    {
        Node* temp = head;
        int x = size();
        while(x--) 
        {
            cout<<temp->val<<" --> ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    public:
    int size()
    {
        return this->numberOfNodes;
    }

    void addAt(int val, int idx)
    {
        Node* node = new Node(val);
        addNodeAt(node, idx);
    }

    void addFirst(int val)
    {
        addAt(val, 0);
    }

    void addLast(int val)
    {
        addAt(val, size());
    }

    void removeAt(int idx)
    {
        removeNodeAt(idx);
    }

    void removeFirst()
    {
        removeNodeAt(0);
    }

    void removeLast()
    {
        removeNodeAt(size() - 1);
    }

    void print()
    {
        display();
    }

};

int main()
{
    LinkedList* a = new LinkedList();
    
    a->removeLast();
    a->removeFirst();
    a->removeAt(2);

    a->addLast(2);
    a->addLast(3);
    a->addLast(4);
    a->addLast(5);
    a->addLast(6);
    a->addFirst(1);
    a->print();

    a->removeLast();
    a->print();

    a->removeFirst();
    a->print();

    a->removeAt(2);
    a->print();

    cout<<"size : "<<a->size();
}        