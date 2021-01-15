
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public :
    string data;
    unordered_map<string, Node*>children;
    int count;
    bool isTerminal;

    Node(string data)
    {
        this->data = data;
        isTerminal = false;
        count = 0;
    }
};

class Trie
{
    public :
    Node *root;

    Trie()
    {
        root = new Node("\0");
    }

    void insert(string data)
    {
        Node *temp = root;
        for(int i = 0; i < data.length(); i++)
        {
            string ch = data[i] + "";
            if( (temp->children).find(ch) == (temp->children).end())
                (temp->children)[ch] = new Node(ch);
            
            
            temp = (temp->children)[ch];
            (temp->count)++;
        }
        temp->isTerminal = true;
    }

    int numPrefix(string data)
    {
        Node *temp = root;
        for(int i = 0; i < data.length(); i++)
        {
            string ch(1, data[i]);
            if( (temp->children).find(ch) != (temp->children).end()) temp = (temp->children)[ch];
            else return 0;
        }
        return temp->count;
    }
    
    bool search(string data)
    {
        Node *temp = root;
        for(int i = 0; i < data.length(); i++)
        {
            string ch(1, data[i]);
            if( (temp->children).find(ch) != (temp->children).end()) temp = (temp->children)[ch];
            else return false;
        }
        return temp->isTerminal;
    }
};

int main()
{
    Trie T;
    vector<string>arr = {"NO","NEWS","APE","APPLE","NOT"};
    for(string s : arr) T.insert(s);

    vector<string>pre = {"A","NOT","NO","AP","APPLE","NEW"};
    for(string s : pre) cout<<s<<" : "<<T.search(s)<<"\n";
}