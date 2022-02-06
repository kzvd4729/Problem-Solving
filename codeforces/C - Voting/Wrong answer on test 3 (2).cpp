/****************************************************************************************
*  @author: kzvd4729#                                        created: Jul/07/2017 21:59                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/749/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,mark[200003],l,u,v;
string s;
queue<int>d,r;
int main()
{
    cin>>n;
    cin>>s;
    l=s.size();
    for(int i=0; i<l; i++)
    {
        if(s[i]=='D')d.push(i);
        else r.push(i);
    }
      while(true)
    {
        u=d.front();
        v=r.front();
        if(u<v)
        {
            d.push(l+u);
            d.pop();
            r.pop();
        }
        else
        {
            r.push(l+v);
            r.pop();
            d.pop();
        }
        if(!d.size())
        {
            cout<<"R"<<endl;
            return 0;
        }
        if(!r.size())
        {
            cout<<"D"<<endl;
            return 0;
        }
     }
    return 0;
}