/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/16/2017 22:13                        
*  solution_verdict: Hacked                                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/825/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int i,j,x,d;
char mat[20][20];
bool check(int r,int c)
{
    if(c+4<=10)
    {
        x=0;
        d=0;
        if(mat[r][c]=='X')x++;
        if(mat[r][c+1]=='X')x++;
        if(mat[r][c+2]=='X')x++;
        if(mat[r][c+3]=='X')x++;
        if(mat[r][c+4]=='X')x++;
         if(mat[r][c]=='.')d++;
        if(mat[r][c+1]=='.')d++;
        if(mat[r][c+2]=='.')d++;
        if(mat[r][c+3]=='.')d++;
        if(mat[r][c+4]=='.')d++;
        if(x==4&&d==1)return true;
    }
     if(c-4>=1)
    {
        x=0;
        d=0;
        if(mat[r][c]=='X')x++;
        if(mat[r][c-1]=='X')x++;
        if(mat[r][c-2]=='X')x++;
        if(mat[r][c-3]=='X')x++;
        if(mat[r][c-4]=='X')x++;
         if(mat[r][c]=='.')d++;
        if(mat[r][c-1]=='.')d++;
        if(mat[r][c-2]=='.')d++;
        if(mat[r][c-3]=='.')d++;
        if(mat[r][c-4]=='.')d++;
        if(x==4&&d==1)return true;
    }
     if(r+4<=10)
    {
        x=0;
        d=0;
        if(mat[r][c]=='X')x++;
        if(mat[r+1][c]=='X')x++;
        if(mat[r+2][c]=='X')x++;
        if(mat[r+3][c]=='X')x++;
        if(mat[r+4][c]=='X')x++;
         if(mat[r][c]=='.')d++;
        if(mat[r+1][c]=='.')d++;
        if(mat[r+2][c]=='.')d++;
        if(mat[r+3][c]=='.')d++;
        if(mat[r+4][c]=='.')d++;
        if(x==4&&d==1)return true;
    }
     if(r-4>=1)
    {
        x=0;
        d=0;
        if(mat[r][c]=='X')x++;
        if(mat[r-1][c]=='X')x++;
        if(mat[r-2][c]=='X')x++;
        if(mat[r-3][c]=='X')x++;
        if(mat[r-4][c]=='X')x++;
         if(mat[r][c]=='.')d++;
        if(mat[r-1][c]=='.')d++;
        if(mat[r-2][c]=='.')d++;
        if(mat[r-3][c]=='.')d++;
        if(mat[r-4][c]=='.')d++;
        if(x==4&&d==1)return true;
    }
     if(r+4<=10&&c+4<=10)
    {
        x=0;
        d=0;
        if(mat[r][c]=='X')x++;
        if(mat[r+1][c+1]=='X')x++;
        if(mat[r+2][c+2]=='X')x++;
        if(mat[r+3][c+3]=='X')x++;
        if(mat[r+4][c+4]=='X')x++;
         if(mat[r][c]=='.')d++;
        if(mat[r+1][c+1]=='.')d++;
        if(mat[r+2][c+2]=='.')d++;
        if(mat[r+3][c+3]=='.')d++;
        if(mat[r+4][c+4]=='.')d++;
        if(x==4&&d==1)return true;
    }
     if(r-4>=1&&c+4>=1)
    {
        x=0;
        d=0;
        if(mat[r][c]=='X')x++;
        if(mat[r-1][c-1]=='X')x++;
        if(mat[r-2][c-2]=='X')x++;
        if(mat[r-3][c-3]=='X')x++;
        if(mat[r-4][c-4]=='X')x++;
         if(mat[r][c]=='.')d++;
        if(mat[r-1][c-1]=='.')d++;
        if(mat[r-2][c-2]=='.')d++;
        if(mat[r-3][c-3]=='.')d++;
        if(mat[r-4][c-4]=='.')d++;
        if(x==4&&d==1)return true;
    }
    return false;
 }
int main()
{
    for(i=1; i<=10; i++)
    {
        for(j=1; j<=10; j++)
        {
            cin>>mat[i][j];
        }
    }
    for(i=1; i<=10; i++)
    {
        for(j=1; j<=10; j++)
        {
            if(mat[i][j]=='X')
            {
                if(check(i,j))
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
     return 0;
}