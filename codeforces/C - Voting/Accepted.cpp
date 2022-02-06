/****************************************************************************************
*  @author: kzvd4729#                                        created: Jul/07/2017 22:09                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3200 KB                              
*  problem: https://codeforces.com/contest/749/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,u,v;
string s;
queue<int>d,r;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='D')d.push(i);
        else r.push(i);
    }
     while(true)
    {
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
        u=d.front();
        v=r.front();
        if(u<v)
        {
            d.push(n+u);
            d.pop();
            r.pop();
        }
        else
        {
            r.push(n+v);
            r.pop();
            d.pop();
        }
     }
}