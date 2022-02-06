/****************************************************************************************
*  @author: kzvd4729#                                        created: Jul/07/2017 21:48                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2700 KB                              
*  problem: https://codeforces.com/contest/749/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n,mark[200003];
string s;
queue<int>d,r;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='D')d.push(i);
        else r.push(i);
    }
    for(int i=0; i<s.size(); i++)
    {
        if(mark[i])continue;
        if(s[i]=='D')while(r.front()<i)r.push(r.front()+s.size()),r.pop();
        else while(d.front()<i)d.push(d.front()+s.size()),d.pop();
        if(s[i]=='D')mark[r.front()]=1,r.pop();
        else mark[d.front()]=1,d.pop();
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
     for(int i=0; i<s.size(); i++)
    {
        if(mark[i])continue;
        if(s[i]=='D')while(r.front()<i+s.size())r.push(r.front()+s.size()),r.pop();
        else while(d.front()<i+s.size())d.push(d.front()+s.size()),d.pop();
        if(s[i]=='D')mark[r.front()-s.size()]=1,r.pop();
        else mark[d.front()-s.size()]=1,d.pop();
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
    ///cout<<d.size()<<" "<<r.size()<<endl;
    return 0;
}