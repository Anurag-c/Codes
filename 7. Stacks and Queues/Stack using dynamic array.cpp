#include<iostream>
using namespace std;

class stack
{
    int* arr;
    int top;
    int size;
    int capacity;

    public:

        stack()
        {
            top = -1;
            size = 0;
            capacity = 1;
            arr = new int[1];
        }
        void push(int x)
        {
            if(size == capacity)
            {
                int* new_arr = new int[2 * capacity];
                for(int i = 0; i < capacity; i++)
                    new_arr[i] = arr[i];
                
                delete(arr);
                arr = new_arr;
                capacity = 2 * capacity;
            }
            
            top++;
            arr[top] = x;
            size++;
        }

        int pop()
        {
            int ans = -1;
            if(empty())
                cout<<"Stack is Empty\n";
            else
            {
                ans = arr[top];
                top--;
                size--;
            }
            return ans;
        }

        bool empty()
        {
            return size == 0;
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
}

