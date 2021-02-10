
// link : https://www.hackerrank.com/challenges/crossword-puzzle/problem

#include<bits/stdc++.h>
using namespace std;

bool isSafeH(int r, int c, vector<string>& crossword, string word)
{
    int n = word.length();
    for(int i = 0; i < n; i++)
    {
        if(c + i < 10 && (crossword[r][c + i] == '-' || crossword[r][c + i] == word[i])) continue;
        else return false;
    }
    return true; 
}

bool isSafeV(int r, int c, vector<string>& crossword, string word)
{
    int n = word.length();
    for(int i = 0; i < n; i++)
    {
        if(r + i < 10 && (crossword[r + i][c] == '-' || crossword[r + i][c] == word[i])) continue;
        else return false;
    }
    return true; 
}

int placeH(int r, int c, vector<string>& crossword, string word)
{
    int vis = 0;
    int n = word.length();
    for(int i = 0; i < n; i++)
    {
        if(crossword[r][c + i] == '-')
        {
            crossword[r][c + i] = word[i];
            vis |= (1 << i);
        }
    }
    return vis;
}

int placeV(int r, int c, vector<string>& crossword, string word)
{
    int vis = 0;
    int n = word.length();
    for(int i = 0; i < n; i++)
    {
        if(crossword[r + i][c] == '-')
        {
            crossword[r + i][c] = word[i];
            vis |= (1 << i);
        }
    }
    return vis;
}

void unplaceH(int r, int c, vector<string>& crossword, string word, int vis)
{
    int n = word.length();
    for(int i = 0; i < n; i++)
    {
        if((vis & (1<<i))) crossword[r][c + i] = '-';
    }
}

void unplaceV(int r, int c, vector<string>& crossword, string word, int vis)
{
    int n = word.length();
    for(int i = 0; i < n; i++)
    {
        if((vis & (1<<i))) crossword[r + i][c] = '-';
    }
}

bool solve(vector<string>& crossword, vector<string>& words, int idx)
{
    if(idx == (int)words.size()) return true;

    for(int r = 0; r < 10; r++)
    {
        for(int c = 0; c < 10; c++)
        {
            if(crossword[r][c] == '-' || crossword[r][c] == words[idx][0])
            {
                if(isSafeH(r, c, crossword, words[idx]))
                {
                    int vis = placeH(r, c, crossword, words[idx]);
                    if(solve(crossword, words, idx + 1)) return true;
                    unplaceH(r, c, crossword, words[idx], vis);
                }
                if(isSafeV(r, c, crossword, words[idx]))
                {
                    int vis = placeV(r, c, crossword, words[idx]);
                    if(solve(crossword, words, idx + 1)) return true;
                    unplaceV(r, c, crossword, words[idx], vis);
                }
            }
        }
    }
    return false;
}

vector<string> crosswordPuzzle(vector<string>& crossword, string words) 
{
    vector<string>ws;
    string x = "";
    for(int i = 0 ; i < (int)words.length() ; i++)
    {
        if(words[i] == ';')
        {
             ws.push_back(x);
             x = "";
        }
        else x += words[i];
    }
    ws.push_back(x);
    solve(crossword, ws, 0);
    return crossword;
}