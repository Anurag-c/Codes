#include <bits/stdc++.h>
using namespace std;

pair<int, string> countHi(string s, string cmprs)
{
    pair<int,string> p;
    
    if(s.length() <= 1) 
    {
        p.first = 0;
        (s.length() == 1) ? p.second = cmprs + s[0] : p.second = cmprs;
        return p;
    }
    
    if(s[0] == 'h' && s[1] == 'i') 
    {
        p = countHi(s.substr(2), cmprs);
        (p.first)++;
        return p;
    }
    return countHi(s.substr(1), cmprs + s[0]);
}


int main() 
{
    string s;
    int i;
    cin>>s>>i;
    pair<int,string>p = countHi(s, "");
    cout<<p.first<<"\n"<<p.second[i]<<"\n"<<p.second;
}

//2
#include <bits/stdc++.h>
using namespace std;

void subs(string s, int idx, string ans)
{
    if(idx == (int)s.size())
    {
        cout<<ans<<"\n";
        return;
    }
    subs(s, idx + 1, ans);
    subs(s, idx + 1, ans + s[idx]);
    subs(s, idx + 1, ans + to_string(s[idx]));       
}

void subs2(string s, int idx, vector<string>&ans)
{
    if(idx == (int)s.size()) return;
    
    int k = 0;
    int n = ans.size();
    while(k < n)
    {
        ans.push_back(s[idx] + ans[k]);
        k++;
    }
    k = 0;
    while(k < n)
    {
        ans.push_back(to_string(s[idx]) + ans[k]);
        k++;
    }
    subs2(s, idx + 1, ans);
}

int main() 
{
    string x;
    cin>>x;
    vector<string>ans = {""};
    subs2(x, 0, ans);
    cout<<ans.size()<<"\n";
    cout<<"[";
    for(int i = 1 ; i < (int)ans.size() ; i++) cout<<", "<<ans[i];
    cout<<"]\n";
    subs(x, 0, "");
}

//3
#include <bits/stdc++.h>
using namespace std;

vector<string>all;
void path(int size, int dice, string ans)
{
    if(size == 0)
    {
        all.push_back(ans);
        return;
    }
    
    for(int i = 1 ; i <= dice ; i++)
    {
        if(size - i >= 0) path(size - i, dice, ans + to_string(i));
        else break;
    }
}

int main() 
{
    int n,m;
    cin>>n>>m;
    path(n, m, "");
    cout<<all.size()<<"\n";
    cout<<"["<<all[0];
    for(int i = 1 ; i < all.size() ; i++) cout<<", "<<all[i];
    cout<<"]\n";
    for(int i = 0; i < all.size() ; i++) cout<<all[i]<<"\n";
}

//7
#include<bits/stdc++.h>
using namespace std;

int vis_c = 0;
int diag = 0;
int adiag = 0;

void toggle(int row, int col, int n)
{
    vis_c ^= (1<<col);
    diag ^= (1<<(row-col+n-1));
    adiag ^= (1<<(row+col));
}

int NQueens(int row, int queens, int n, string ans)
{
    if(queens == 0) 
    {
        cout<<ans<<"\n";
        return 1;
    }
    
    int count = 0;
    for(int col = 0; col < n; col++)
    {
        if( !((vis_c>>col)&1) && !((diag>>(row-col+n-1))&1) && !((adiag>>(row+col))&1) )
        {
            toggle(row, col, n);
            count += NQueens(row + 1, queens - 1, n, ans + "[" + to_string(row) + "-" + to_string(col) + "]");
            toggle(row, col, n);
        }
    }
    return count;
}

int main()
{
    int size,queens;
    cin>>size>>queens;
    NQueens(0, queens, size, "");
}

//
#include <bits/stdc++.h>
using namespace std;

void print(int n, int ans)
{
    cout<<ans<<"\n";
    for(int i = 0 ; i < 10 ; i++)
    {
        int x = (ans*10) + i;
        if(x < n) print(n, x);
        else return;
    }
}

int main() 
{
    int n;
    cin>>n;
    for(int i = 1 ; i < n && i < 10 ; i++) print(n, i);
}

//
#include<bits/stdc++.h>
using namespace std;

vector<string>perm;
void permute(string input, string output)  
{  
    if(input.length()==0)
    {
        perm.push_back(output);
        return;
    }
    
    for(int i = 0 ;i < (int)input.length();i++)
    {
        if(i > 0 && input[i - 1] == input[i]) continue;
        permute(input.substr(0,i)+input.substr(i+1,input.length()),output+input[i]);
    }
}  

int main()
{
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    permute(s, "");
    cout<<perm.size()<<"\n";
    for(string s : perm) cout<<s<<"\n";
}
