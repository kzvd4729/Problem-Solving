/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/30/2017 20:50                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/834/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
char c1,c2,c,cc;
int n;
int main()
{
    cin>>c1>>c2>>n;
    n=n%4;
    if(c1=='v')
    {
        if(n==0)c='v';
        if(n==1)c='<';
        if(n==2)c='^';
        if(n==3)c='>';
    }
    if(c1=='<')
    {
        if(n==0)c='<';
        if(n==1)c='^';
        if(n==2)c='>';
        if(n==3)c='v';
    }
    if(c1=='^')
    {
        if(n==0)c='^';
        if(n==1)c='>';
        if(n==2)c='v';
        if(n==3)c='<';
    }
    if(c1=='>')
    {
        if(n==0)c='>';
        if(n==1)c='v';
        if(n==2)c='<';
        if(n==3)c='^';
    }
    if(c1=='v')
    {
        if(n==0)cc='v';
        if(n==3)cc='<';
        if(n==2)cc='^';
        if(n==1)cc='>';
    }
    if(c1=='<')
    {
        if(n==0)cc='<';
        if(n==3)cc='^';
        if(n==2)cc='>';
        if(n==1)cc='v';
    }
    if(c1=='^')
    {
        if(n==0)cc='^';
        if(n==3)cc='>';
        if(n==2)cc='v';
        if(n==1)cc='<';
    }
    if(c1=='>')
    {
        if(n==0)cc='>';
        if(n==3)cc='v';
        if(n==2)cc='<';
        if(n==1)cc='^';
    }
      if(c2==c&&c2==cc)cout<<"undefined"<<endl;
    else if(c==c2)cout<<"cw"<<endl;
    else cout<<"ccw"<<endl;
     return 0;
}