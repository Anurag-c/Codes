#include "vector.h"
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i = 0 ; i<n ; i++)
    {
        int x; cin>>x;
        arr.push_back(x);
    }
    cout<<"\n";
    for(int  i = 0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<arr.get_size()<<" "<<arr.get_capacity()<<"\n";
}